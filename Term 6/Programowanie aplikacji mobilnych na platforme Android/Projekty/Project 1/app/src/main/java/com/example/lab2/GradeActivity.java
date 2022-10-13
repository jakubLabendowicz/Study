package com.example.lab2;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

import java.util.ArrayList;

public class GradeActivity extends AppCompatActivity {
    ArrayList<ModelOceny> grades;
    private int numberOfGrades;
    RecyclerView gradesList;



    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_grade);
        Button avgButton = (Button)findViewById(R.id.button2);
        String[] przedmioty = getResources().getStringArray(R.array.przedmioty);
        Bundle inputIntent = getIntent().getExtras();
        String stringNumber = inputIntent.getString("mNumberEditText");
        String name = inputIntent.getString("mImieEditText");
        String surname = inputIntent.getString("mNazwiskoEditText");

        try{
            numberOfGrades = Integer.parseInt(stringNumber);
        }catch (NumberFormatException e){
            numberOfGrades = 0;
        }

        grades = new ArrayList<>();

        for(int i = 0; i < numberOfGrades; i++) {
            grades.add(new ModelOceny(przedmioty[i],2));
        }

        InteraktywnyAdapterTablicy adapter = new InteraktywnyAdapterTablicy(this, grades);
        gradesList = findViewById(R.id.recyclerView);
        gradesList.setAdapter(adapter);
        gradesList.setLayoutManager(new LinearLayoutManager(this));


        avgButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                float avg = 0;
                for (int i = 0; i< numberOfGrades; i++)
                {
                    ModelOceny ocena = grades.get(i);
                    avg = avg + ocena.getGrade();
                }
                avg = avg / numberOfGrades;
                Intent intent = new Intent(view.getContext(), MainActivity.class);
                intent.putExtra("avg",String.valueOf(avg));

                setResult(RESULT_OK, intent);
                finish();

            }
        });
    }

    @Override
    public void onSaveInstanceState(Bundle outState)
    {
        super.onSaveInstanceState(outState);
       // outState
        for(int i = 0; i < numberOfGrades; i++)
        {

        }

    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState)
    {

    }

    public boolean onOptionsItemSelected(MenuItem item)
    {
        int id = item.getItemId();

        return true;
    }
}