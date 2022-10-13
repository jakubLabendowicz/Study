package pl.pollub.projekt3;

import android.os.AsyncTask;
import android.os.Environment;
import android.widget.TextView;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;

import javax.net.ssl.HttpsURLConnection;

public class ZadanieAsynchroniczne extends
        // typ parametrów, postępu, wyniku
        AsyncTask<String, Integer, String>
{
    private static final int ROZMIAR_BLOKU = 1;
    private MainActivity mainActivity;
    private int rozmiarPliku;
    private String typPliku;
    public ZadanieAsynchroniczne(MainActivity activity)
    {
        this.mainActivity = activity;
        rozmiarPliku = 0;
        typPliku = null;
    }

    //obowiązkowa, wywoływana w osobnym wątku
    @Override
    protected String doInBackground(String... urls)
    {
        HttpsURLConnection polaczenie = null;
        FileOutputStream strumienDoPliku = null;
        InputStream StrumienZSieci = null;
        try {
            URL url = new URL(urls[0]);
            polaczenie = (HttpsURLConnection) url.openConnection();
            polaczenie.setRequestMethod("GET");

            rozmiarPliku = polaczenie.getContentLength();
            typPliku = polaczenie.getContentType();

            if (StrumienZSieci != null)
            {
                try {
                    StrumienZSieci.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            //odbieranie danych, zamykanie plików i połączenia..
        } catch (Exception e) {
            e.printStackTrace();
        }
        finally {
            if (polaczenie != null) polaczenie.disconnect();
        }

        //w trakcie wykonania zadania można wysłać informację o postępie
        //argumentem publishProgress też jest Integer.. params - stąd "dziwny" argument
        //publishProgress(new Integer[] {i+1});

        //po zakończeniu zadania zwracamy wynik
        return null;
    }

    //opcjonalna, wywoływana w wątku GUI
    @Override
    protected void onProgressUpdate(Integer... values)
    {
        //aktualizacja informacji o postępie
    }

    //opcjonalna wywoływana w wątku GUI
    @Override
    protected void onPostExecute(String string)
    {
        super.onPostExecute(string);
        this.mainActivity.ustawRozmiar(String.valueOf(rozmiarPliku));
        this.mainActivity.ustawTyp(typPliku);
    }
}

