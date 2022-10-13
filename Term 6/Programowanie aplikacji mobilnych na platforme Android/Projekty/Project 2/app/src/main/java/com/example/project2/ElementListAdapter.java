package com.example.project2;


import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class ElementListAdapter extends RecyclerView.Adapter<ElementListAdapter.ElementViewHolder> {
    private List<Phone> mElementList;
    private LayoutInflater mLayoutInflater;
    private OnItemClickListener mOnItemClickListener;
    int wiersz;

    interface OnItemClickListener {
        void onItemClickListener(Phone phone);
    }

    public ElementListAdapter(Context context) {
        this.mLayoutInflater = LayoutInflater.from(context);
        try {
            mOnItemClickListener = (OnItemClickListener) context;
        } catch (ClassCastException ignored) {

        }
        this.mElementList = null;
    }




    @NonNull
    @Override
    public ElementViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        @SuppressLint("InflateParams") View row = mLayoutInflater.inflate(R.layout.wiersz_listy, null);
        return new ElementViewHolder(row);
    }

    @Override
    public void onBindViewHolder(@NonNull ElementViewHolder holder, @SuppressLint("RecyclerView") int position) {
        holder.bindToWordViewHolder(position);
        Phone phone = mElementList.get(position);
        this.wiersz = position;
        holder.tv1.setTag(position);
        holder.tv1.setText(phone.getProducer());
        holder.tv2.setTag(position);
        holder.tv2.setText(phone.getModel());
        holder.itemView.setOnClickListener(e -> mOnItemClickListener.onItemClickListener(phone));
    }

    public Phone getWordAtPosition (int position)
    {
        return mElementList.get(position);
    }

    @Override
    public int getItemCount() { return mElementList != null?mElementList.size():0; }

    @SuppressLint("NotifyDataSetChanged")
    public void setElementList(List<Phone> elementList) {
        this.mElementList = elementList;
        notifyDataSetChanged();
    }

    public class ElementViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        TextView tv1;
        TextView tv2;
        View view;
        public ElementViewHolder(@NonNull View itemView) {
            super(itemView);
            this.view = itemView;
            tv1 = itemView.findViewById(R.id.textView);
            tv2 = itemView.findViewById(R.id.textView2);
            itemView.setOnClickListener(this);
        }

        public void bindToWordViewHolder(int row) {

        }

        @Override
        public void onClick(View v) {

        }
    }

}