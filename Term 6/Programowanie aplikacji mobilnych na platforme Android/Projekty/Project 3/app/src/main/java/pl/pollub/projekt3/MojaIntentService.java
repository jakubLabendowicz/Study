package pl.pollub.projekt3;

import android.app.IntentService;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.TaskStackBuilder;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.widget.TextView;

import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;

import javax.net.ssl.HttpsURLConnection;


public class MojaIntentService extends IntentService
{
    //akcje które potrafi wykonać usługa (może być więcej niż jedna)
    private static final String AKCJA_ZADANIE1 = "com.example.intent_service.action.zadanie1";
    public final static String POWIADOMIENIE = "com.example.intent_service.odbiornik";
    public final static String INFO = "info";
    private static final int ID_POWIADOMIENIA = 1;
    //tekstowe identyfikatory parametrów potrzebnych do
    //wykonania akcji (może być więcej niż jeden)
    private static final String PARAMETR1 = "com.example.intent_service.extra.url";
    private NotificationManager mManagerPowiadomien;
    private static final String ID_KANALU = "kanal";
    //usługi wymagają wyświetlania powiadomień

    //statyczna metoda pomocnicza uruchamiająca zadanie (0czywiście parametrów może być
    //więcej)
    public static void uruchomUsluge(Context context, String parametr)
    {
        Intent zamiar = new Intent(context, MojaIntentService.class);
        zamiar.setAction(AKCJA_ZADANIE1);
        zamiar.putExtra(PARAMETR1, parametr);
        context.startService(zamiar);
    }

    //konstruktor
    public MojaIntentService()
    {
        super("MojaIntentService");
    }

    //metoda wykonująca zadanie
    @Override
    protected void onHandleIntent(Intent intent)
    {
        //usługi muszą wyświetlać powiadomienie i przejść na pierwszy plan
        mManagerPowiadomien = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        przygotujKanalPowiadomien();
        startForeground(ID_POWIADOMIENIA, utworzPowiadomienie());
        if (intent != null)
        {
            final String action = intent.getAction();
            //sprawdzenie o jaką akcję chodzi
            if (AKCJA_ZADANIE1.equals(action))
            {
                final String url = intent.getStringExtra(PARAMETR1);
                //wykonanie zadanie
                wykonajZadanie(url);
            }
            else
            {
                Log.e("intent_service","nieznana akcja");
            }
        }
        Log.d("intent_service", "usługa wykonała zadanie");
        mManagerPowiadomien.notify(ID_POWIADOMIENIA, utworzPowiadomienie());
    }

    private void wykonajZadanie(String strona)
    {
        HttpURLConnection polaczenie = null;
        FileOutputStream strumienDoPliku = null;
        int mPobranychBajtow = 0;
        InputStream strumienZSieci = null;
        PostepInfo progres = new PostepInfo();
        mPobranychBajtow = 0;
        try {
            URL url = new URL(strona);
            polaczenie = (HttpsURLConnection) url.openConnection();
            polaczenie.setRequestMethod("GET");
            File plikRoboczy = new File(url.getFile());
            File plikWyjsciowy = new File(Environment.getExternalStorageDirectory() + File.separator+ plikRoboczy.getName());
            if (plikWyjsciowy.exists())
            {
                plikWyjsciowy.delete();
            }
            DataInputStream czytnik = new DataInputStream(polaczenie.getInputStream());
            strumienDoPliku = new FileOutputStream(plikWyjsciowy.getPath());
            byte bufor[] = new byte[1024];
            progres.mRozmiar = polaczenie.getContentLength();
            progres.mStatus = 0;
            int pobrano = czytnik.read(bufor, 0, 1024);
            while (pobrano != -1)
            {
                    strumienDoPliku.write(bufor, 0, pobrano);
                    mPobranychBajtow += pobrano;
                    progres.mPobranychBajtow = mPobranychBajtow;
                    pobrano = czytnik.read(bufor, 0, 1024);
                    Log.d("intent_service","Pobrano " + mPobranychBajtow + " bajtow pliku " + plikWyjsciowy.getName());
                    wyslijBroadcast(progres);
            }
            progres.mStatus = 1;
            wyslijBroadcast(progres);
        }  catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (strumienDoPliku != null)
            {
                try {
                    strumienDoPliku.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (strumienZSieci != null)
            {
                try {
                    strumienZSieci.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (polaczenie != null) polaczenie.disconnect();
        }
    }

    private Notification utworzPowiadomienie()
    {

        Intent intencjaPowiadomienia = new Intent(this, MainActivity.class);
        //do intencji dodajemy dane, które mają być wyświetlone po powrocie do aplikacji
        intencjaPowiadomienia.putExtra("Intencja", MainActivity.class);
        //budujemy stos z aktywnościami, których użytkownik oczekuje po powrocie
        //w zadaniu mamy tylko jedną aktywność
        TaskStackBuilder budowniczyStosu = TaskStackBuilder.create(this);
        budowniczyStosu.addParentStack(MainActivity.class);
        budowniczyStosu.addNextIntent(intencjaPowiadomienia);
        PendingIntent intencjaOczekujaca = budowniczyStosu.getPendingIntent(0,PendingIntent.FLAG_UPDATE_CURRENT);
        //budujemy powiadomienie
        Notification.Builder budowniczyPowiadomien = new Notification.Builder(this);
        budowniczyPowiadomien.setContentTitle(getString(R.string.powiadomienie_tytul)).setProgress(100, wartoscPostepu(), false).setContentIntent(intencjaOczekujaca).setSmallIcon(R.drawable.ic_launcher_foreground).setWhen(System.currentTimeMillis()).setPriority(Notification.PRIORITY_HIGH);

        if (wartoscPostepu()<100) //jezeli pobieranie trwa...
        {
            //budowniczyPowiadomien.setProgress(100, (int) procentPobrania,false);
            budowniczyPowiadomien.setOngoing(false);
        }
        else
        {
            budowniczyPowiadomien.setOngoing(true);
        }

        //ustawiamy kanał powiadomień dla tworzonego powiadomienia
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.BASE)
        {
            budowniczyPowiadomien.setChannelId(ID_KANALU);
        }

        //tworzymy i zwracamy powiadomienie
        return budowniczyPowiadomien.build();
    }
    private int wartoscPostepu() //do zrobienia
    {
        return 0;
    }


    private void przygotujKanalPowiadomien()
    {
        mManagerPowiadomien = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

        //Android 8/Oreo wymaga kanału powiadomień
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.BASE)
        {
            CharSequence name = getString(R.string.app_name);
            //tworzymy kanał - nadajemy mu jakieś ID (stała typu String)
            NotificationChannel kanal = new NotificationChannel(ID_KANALU, name, NotificationManager.IMPORTANCE_LOW);

            //tworzymy kanał w menadżerze powiadomień
            mManagerPowiadomien.createNotificationChannel(kanal);
        }
    }
    public void wyslijBroadcast(PostepInfo postep)
    {
        Intent zamiar = new Intent(POWIADOMIENIE);
        zamiar.putExtra(INFO, postep);
        LocalBroadcastManager.getInstance(this).sendBroadcast(zamiar);
    }
}
