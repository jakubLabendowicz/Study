package com.example.lab2;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RadioGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class InteraktywnyAdapterTablicy extends RecyclerView.Adapter<InteraktywnyAdapterTablicy.OcenyViewHolder>{
    private List<ModelOceny> mListaOcen;
    private LayoutInflater mPompka;
    private int ocena;
    int wiersz;

    public InteraktywnyAdapterTablicy(Activity kontekst, List<ModelOceny> listaOcen)
    {
        mPompka = kontekst.getLayoutInflater();
        this.mListaOcen = listaOcen;
    }

    @NonNull
    @Override
    public OcenyViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int viewType)
    {
        View wiersz = mPompka.inflate(R.layout.wiersz_oceny, null);
        return new OcenyViewHolder(wiersz);
    }

    @Override
    public void onBindViewHolder(@NonNull OcenyViewHolder ocenyViewHolder, @SuppressLint("RecyclerView") int numerWiersza)
    {
        ocenyViewHolder.rg.setTag(mListaOcen.get(numerWiersza));
        this.wiersz = numerWiersza;
        ModelOceny ocena = mListaOcen.get(numerWiersza);

        ocenyViewHolder.tv.setTag(numerWiersza);
        ocenyViewHolder.tv.setText(ocena.getName());

        switch(ocena.getGrade())
        {
            case 2:
                ocenyViewHolder.rg.check(R.id.radioButton);
                break;

            case 3:
                ocenyViewHolder.rg.check(R.id.radioButton2);
                break;

            case 4:
                ocenyViewHolder.rg.check(R.id.radioButton3);
                break;

            case 5:
                ocenyViewHolder.rg.check(R.id.radioButton4);
                break;
        }
    }

    @Override
    public int getItemCount()
    {
        return mListaOcen.size();
    }

    public class OcenyViewHolder extends RecyclerView.ViewHolder implements RadioGroup.OnCheckedChangeListener
    {
        TextView tv;
        RadioGroup rg;
        View view;

        public OcenyViewHolder(@NonNull View glownyElementWiersza)
        {
            super(glownyElementWiersza);
            this.view = glownyElementWiersza;
            tv = glownyElementWiersza.findViewById(R.id.textView5);
            rg = glownyElementWiersza.findViewById(R.id.oceny);
            rg.setOnCheckedChangeListener(this);
        }

        @Override
        public void onCheckedChanged(RadioGroup group, int checkedId)
        {
            ModelOceny wartosc = (ModelOceny) group.getTag();
            ocena = checkedId;
            switch (checkedId)
            {
                case R.id.radioButton:
                    ocena = 2;
                    break;

                case R.id.radioButton2:
                    ocena = 3;
                    break;

                case R.id.radioButton3:
                    ocena = 4;
                    break;

                case R.id.radioButton4:
                    ocena = 5;
                    break;
            }
            wartosc.setGrade(ocena);
        }
    }
}
