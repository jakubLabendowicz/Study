package com.example.project2;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class EditPhoneActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.tabelka);
        Button page = (Button)findViewById(R.id.page);
        Button cancel = (Button)findViewById(R.id.cancel);
        Button save = (Button)findViewById(R.id.save);
        EditText producer = (EditText)findViewById(R.id.producer);
        EditText model = (EditText)findViewById(R.id.model);
        EditText version = (EditText)findViewById(R.id.version);
        EditText url = (EditText)findViewById(R.id.url);


        Bundle bundle = getIntent().getExtras();
        if(bundle != null) {
            String Producent = bundle.getString("producer");
            producer.setText(Producent);
            String Model = bundle.getString("model");
            model.setText(Model);
            String Wersja = bundle.getString("version");
            version.setText(Wersja);
            String Strona = bundle.getString("url");
            url.setText(Strona);
            int id = bundle.getInt("id");
            save.setOnClickListener(v -> {
                String Producent1 = producer.getText().toString();
                String Model1 = model.getText().toString();
                String Wersja1 = version.getText().toString();
                String Strona1 = url.getText().toString();

                if(Producent1.length() == 0) {
                    producer.setError(getString(R.string.producerErrorEmpty));
                }
                if (Model1.length() == 0) {
                    model.setError(getString(R.string.modelErrorEmpty));
                }
                if (Wersja1.length() == 0) {
                    version.setError(getString(R.string.versionErrorEmpty));
                }
                if (Strona1.length() == 0) {
                    url.setError(getString(R.string.urlEmptyError));
                }
                else {
                    Intent intent = new Intent();
                    Bundle bundle1 = new Bundle();
                    bundle1.putString("producer", Producent1);
                    bundle1.putString("model", Model1);
                    bundle1.putString("version", Wersja1);
                    bundle1.putString("url", Strona1);
                    bundle1.putInt("id", id);
                    intent.putExtras(bundle1);
                    setResult(RESULT_OK, intent);
                    finish();
                }
            });
        }
        page.setOnClickListener(v -> {
            String tekst = url.getText().toString();
            Intent zamiarPrzegladarki = new Intent("android.intent.action.VIEW", Uri.parse(tekst));
            if(tekst.startsWith("http://")) {
                startActivity(zamiarPrzegladarki);
            }
            else {
                Toast zlyAdres = Toast.makeText(EditPhoneActivity.this, R.string.urlErrorWrongAddress, Toast.LENGTH_LONG);
                zlyAdres.show();
            }

        });

        cancel.setOnClickListener(v -> finish());

        if (bundle == null) {
            save.setOnClickListener(v -> {
                String Producent = producer.getText().toString();
                String Model = model.getText().toString();
                String Wersja = version.getText().toString();
                String Strona = url.getText().toString();
                if(Producent.length() == 0) {
                    producer.setError(getString(R.string.producerErrorEmpty));
                }
                if (Model.length() == 0) {
                    model.setError(getString(R.string.modelErrorEmpty));
                }
                if (Wersja.length() == 0) {
                    version.setError(getString(R.string.versionErrorEmpty));
                }
                if (Strona.length() == 0) {
                    url.setError(getString(R.string.urlEmptyError));
                } else {
                    Intent intent = new Intent();
                    Bundle bundle12 = new Bundle();
                    bundle12.putString("producer", Producent);
                    bundle12.putString("model", Model);
                    bundle12.putString("version", Wersja);
                    bundle12.putString("url", Strona);
                    intent.putExtras(bundle12);
                    setResult(RESULT_OK, intent);
                    finish();
                }

            });
        }
    }
}
