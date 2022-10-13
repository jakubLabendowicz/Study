import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.stream.Collectors;

public class Cities {
    String temp_url;
    URL url;
    InputStream is;
    String source;
    JSONObject json;
    JSONArray recieveddata;

    public Cities(String temp_url) throws IOException {
        this.temp_url = temp_url;
        this.laczenie();
        this.wysylanieZapytania();
        this.popbieranieOdpowiedzi();
        this.przetwarzanieDanych();
    }

    void laczenie() throws MalformedURLException {
        this.url = new URL(this.temp_url);
    }

    void wysylanieZapytania() throws IOException {
        System.out.println("Wysyłanie zapytania...");
        this.is = this.url.openStream();
    }

    void popbieranieOdpowiedzi() {
        System.out.println("Pobieranie odpowiedzi...");
        this.source = new BufferedReader(new InputStreamReader(this.is)).lines().collect(Collectors.joining("\n"));
    }

    void przetwarzanieDanych() {
        System.out.println("Przetwarzanie danych...");
        this.json = new JSONObject(this.source);
        this.recieveddata = (JSONArray) json.get("cities");
    }

    public JSONArray getRecieveddata() {
        return recieveddata;
    }
}
