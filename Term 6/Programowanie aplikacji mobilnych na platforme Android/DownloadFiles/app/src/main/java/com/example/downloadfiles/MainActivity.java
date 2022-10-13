package com.example.downloadfiles;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.app.DownloadManager;
import android.content.Context;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static final int PERMISSION_STORAGE_CODE=1000;
    EditText url;
    Button downloadButton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        url=findViewById(R.id.urlEt);
        downloadButton=findViewById(R.id.downloadUrl);


        downloadButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.M){
                        if(checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE)== PackageManager.PERMISSION_DENIED)
                        {
                            //odmowa dostepu
                            String[] permissions ={Manifest.permission.WRITE_EXTERNAL_STORAGE};
                            requestPermissions(permissions,PERMISSION_STORAGE_CODE);

                        }
                        else
                        {
                                    //pobieranie
                            startDownloading();
                        }
                    }else
                    {
                        startDownloading();
                    }
            }
        });

    }

    private void startDownloading() {

        String url_1=url.getText().toString().trim();
        DownloadManager.Request request = new DownloadManager.Request(Uri.parse(url_1));
        request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_WIFI);
        request.setTitle("Pobieranie");
        request.setDescription("Pobieranei pliku....");
        request.allowScanningByMediaScanner();
        request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED);
        request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS,""+System.currentTimeMillis());

        DownloadManager manager = (DownloadManager) getSystemService(Context.DOWNLOAD_SERVICE);
        manager.enqueue(request);



    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case PERMISSION_STORAGE_CODE:
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    startDownloading();
                } else {
                    Toast.makeText(this, "Odmowa dostepu", Toast.LENGTH_SHORT).show();
                }
            default:
                break;
        }
    }
}