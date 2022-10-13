package com.example.lab2;


import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText mImieEditText;
    EditText mNazwiskoEditText;
    EditText mNumberEditText;
    Button mButton;
    Button exit;
    Boolean validateName = false;
    Boolean validateSurname = false;
    Boolean validateNumber = false;
    Boolean avgBool = true;
    TextView avgText;
    private ActivityResultLauncher<Intent> mActivityResultLauncher;

    private void  changeVisability(){
        if(validateName && validateSurname && validateNumber && avgBool){
            mButton.setVisibility(View.VISIBLE);
        }else{
            mButton.setVisibility(View.INVISIBLE);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout2);
        mButton = findViewById(R.id.avg);
        mButton.setVisibility(View.INVISIBLE);
        avgText = findViewById(R.id.avgText);
        exit = findViewById(R.id.exit);
        mImieEditText = findViewById(R.id.nameValue);
        mNazwiskoEditText = findViewById(R.id.surnameValue);
        mNumberEditText = findViewById(R.id.numOfValue);


    

        exit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
                System.exit(0);
            }
        });

        mActivityResultLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                (ActivityResultCallback<ActivityResult >) result -> {
                    if (result.getResultCode() == RESULT_OK) {
                        Intent resultIntent = result.getData();
                        String avg = resultIntent.getStringExtra("avg");
                        avgText.setText(avg);
                        avgBool = false;
                        mButton.setVisibility(View.INVISIBLE);
                        exit.setVisibility(View.VISIBLE);

                    }
                });
        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(view.getContext(), GradeActivity.class);

                intent.putExtra("mNumberEditText",mNumberEditText.getText().toString());


                mActivityResultLauncher.launch(intent);

            }
        });

        mImieEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                validateName = charSequence.toString().length() != 0;

            }

            @Override
            public void afterTextChanged(Editable editable) {
                changeVisability();
                if(!validateName){
                    Toast tost = Toast.makeText(MainActivity.this , getString(R.string.brak_imienia),Toast.LENGTH_SHORT);
                    tost.show();
                    mImieEditText.setError(getString(R.string.brak_imienia_error));
                }
            }
        });

        mImieEditText.setOnFocusChangeListener((view, b) -> {


        });


        mNazwiskoEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                validateSurname = charSequence.toString().length() != 0;
            }

            @Override
            public void afterTextChanged(Editable editable) {
                changeVisability();
                if(!validateSurname){
                    Toast tost = Toast.makeText(MainActivity.this ,getString(R.string.brak_nazwiska),Toast.LENGTH_SHORT);
                    tost.show();
                    mNazwiskoEditText.setError(getString(R.string.brak_nazwiska_error));
                }
            }
        });
        mNazwiskoEditText.setOnFocusChangeListener((view, b) -> {


        });

        mNumberEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                int num ;
                try{
                    num = Integer.parseInt(charSequence.toString());
                }catch (NumberFormatException e){
                    num = -1;
                }

                validateNumber = num > 4 && num < 16;
            }

            @Override
            public void afterTextChanged(Editable editable) {
                changeVisability();
                if(!validateNumber) {
                    Toast tost = Toast.makeText(MainActivity.this, getString(R.string.brak_ocen), Toast.LENGTH_SHORT);
                    tost.show();
                    mNumberEditText.setError(getString(R.string.brak_ocen_error));
                }
            }
        });
        mNumberEditText.setOnFocusChangeListener((view, b) -> {


        });



    }
    @Override
    protected void onSaveInstanceState(Bundle outState) {


        outState.putString("mImieEditText",mImieEditText.getText().toString());
        outState.putString("mNazwiskoEditText",mNazwiskoEditText.getText().toString());
        outState.putString("mNumberEditText",mNumberEditText.getText().toString());
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {

        mImieEditText.setText(savedInstanceState.getString("mImieEditText"));
        mNazwiskoEditText.setText(savedInstanceState.getString("mNazwiskoEditText"));
        mNumberEditText.setText(savedInstanceState.getString("mNumberEditText"));
    }



}