package pl.pollub.projekt3;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import android.Manifest;
import android.app.Activity;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.app.TaskStackBuilder;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.net.URL;

import javax.net.ssl.HttpsURLConnection;

public class MainActivity extends Activity
{
    PostepInfo postep;


    TextView typ;

    TextView pobrano;
    TextView rozmiar;
    float procentPobrania;
    int status;
    private BroadcastReceiver mOdbiorcaRozgloszen = new BroadcastReceiver()
    {
        @Override
        //obsługa odebrania komunikatu
        public void onReceive(Context context, Intent intent)
        {

            Bundle bundle = intent.getExtras();
            postep = bundle.getParcelable(MojaIntentService.INFO);
            pobrano = (TextView) findViewById(R.id.textView7);
            String pobrane = Integer.toString(postep.mPobranychBajtow);
            rozmiar = (TextView) findViewById(R.id.textView3);
            ProgressBar progres = (ProgressBar) findViewById(R.id.progressBar);
            String size = Integer.toString(postep.mRozmiar);
            procentPobrania = 100.0f * postep.mPobranychBajtow/postep.mRozmiar;
            status = postep.mStatus;
              progres.setProgress((int) procentPobrania);
            pobrano.setText(pobrane);
            rozmiar.setText(size);

        }
    };


    private static final int WRITE_EXTERNAL_STORAGE_REQUEST_CODE = 1;
    private static final int KOD_WRITE_EXTERNAL_STORAGE = 2;
    private int requestCode=0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button przycisk = (Button) findViewById(R.id.button);
        Button przycisk2 = (Button) findViewById(R.id.button2);
        EditText strona = (EditText) findViewById(R.id.editTextTextPersonName);
        String adres_url = strona.getText().toString();

        typ = (TextView) findViewById(R.id.textView5);


        //Service.startForeground(ID_POWIADOMIENIA, utworzPowiadomienie());
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE) == getPackageManager().PERMISSION_GRANTED) {
            //mamy uprawnienie możemy rozpocząć pobieraniu pliku
            //...
        } else {
            //czy użytkownik wcześniej odmówił uprawnienia (this = kontekst)
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
                //wyjaśniamy mu po co nam jest ono potrzebne...
            }

            //(po ewentualnym wyjaśnieni) prosimy o uprawnienia (this = kontekst);
            //jak widać uprawnienia są w tablicy - można poprosić o wiele równocześnie
            //KOD_WRITE_EXTERNAL_STORAGE - na tej samej zasadzie co w przypadku wielu
            //aktywności
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, KOD_WRITE_EXTERNAL_STORAGE);
        }

        przycisk.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                new ZadanieAsynchroniczne(MainActivity.this).execute(adres_url);
            }
        });

        przycisk2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MojaIntentService.uruchomUsluge(MainActivity.this, adres_url);
            }
        });
    }

    public void ustawRozmiar(String size)
    {
        TextView rozmiar = (TextView)findViewById(R.id.textView3);
        rozmiar.setText(size);
    }

    public void ustawTyp(String type)
    {
        TextView rozmiar = (TextView)findViewById(R.id.textView5);
        rozmiar.setText(type);
    }



    @Override
    public void onRequestPermissionsResult(int kodZadania, @NonNull String[] uprawnienia, @NonNull int[] decyzje) {
        super.onRequestPermissionsResult(requestCode, uprawnienia, decyzje);
        switch (kodZadania) {
            case WRITE_EXTERNAL_STORAGE_REQUEST_CODE:
                if (uprawnienia.length > 0 && uprawnienia[0].equals(Manifest.permission.WRITE_EXTERNAL_STORAGE) && decyzje[0] == PackageManager.PERMISSION_GRANTED) {
                    //otrzymaliśmy uprawnienia możemy rozpocząć np. pobieranie pliku
                } else {
                    //nie otrzymaliśmy uprawnień
                }
                break;
            default:
                //nieznany kod żądania - poprawić kod aplikacji i dodać obsługę kodu
                break;
        }
    }

    @Override //zarejestrowanie odbiorcy
    protected void onResume()
    {
        super.onResume();
        LocalBroadcastManager.getInstance(this).registerReceiver(mOdbiorcaRozgloszen, new IntentFilter(MojaIntentService.POWIADOMIENIE));

    }

    @Override //wyrejestrowanie odbiorcy
    protected void onPause()
    {
        super.onPause();
        LocalBroadcastManager.getInstance(this).unregisterReceiver(mOdbiorcaRozgloszen);
    }

    @Override
    public void onSaveInstanceState(Bundle outState)
    {


            outState.putString("pobrano", pobrano.getText().toString());
            outState.putString("rozmiar", rozmiar.getText().toString());

        outState.putString("typ", typ.getText().toString());

        super.onSaveInstanceState(outState);
    }

    @Override
    public void onRestoreInstanceState(@Nullable Bundle savedInstanceState)
    {
        super.onRestoreInstanceState(savedInstanceState);

            pobrano.setText(savedInstanceState.getString("pobrano"));
            rozmiar.setText(savedInstanceState.getString("rozmiar"));

        typ.setText(savedInstanceState.getString("typ"));
    }








}