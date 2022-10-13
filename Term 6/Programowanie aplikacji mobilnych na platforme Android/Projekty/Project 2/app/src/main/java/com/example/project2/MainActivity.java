package com.example.project2;


import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;



import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


import com.google.android.material.floatingactionbutton.FloatingActionButton;


public class  MainActivity extends AppCompatActivity implements ElementListAdapter.OnItemClickListener {
    private ElementViewModel mElementViewModel;
    private ElementListAdapter mAdapter;
    Intent data;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        mAdapter = new ElementListAdapter(this);
        recyclerView.setAdapter(mAdapter);

        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        mElementViewModel = new ViewModelProvider(this).get(ElementViewModel.class);

        mElementViewModel.getAllPhones().observe(this, elements -> mAdapter.setElementList(elements));

        ItemTouchHelper itemTouchHelper = new ItemTouchHelper(
                new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {
                    @Override
                    public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
                        return false;
                    }

                    @Override
                    public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                        int adapterPosition = viewHolder.getAdapterPosition();
                        Phone phone = mAdapter.getWordAtPosition(adapterPosition);
                        mElementViewModel.delete(phone);
                    }
                });
        itemTouchHelper.attachToRecyclerView(recyclerView);
        FloatingActionButton fab = findViewById(R.id.fabMain);
        fab.setOnClickListener(v -> {
            Intent intencja = new Intent(MainActivity.this, EditPhoneActivity.class);
            //noinspection deprecation
            startActivityForResult(intencja, 1);
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.pierwsza_opcja) {
            mElementViewModel.deleteAll();
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent newData) {

        super.onActivityResult(requestCode, resultCode, newData);
        if(requestCode == 1 && resultCode == RESULT_OK) {
            this.data = newData;
            Bundle bundle = data.getExtras();
            String producer = bundle.getString("producer");
            String model = bundle.getString("model");
            String version = bundle.getString("version");
            String url = bundle.getString("url");
            Phone phone = new Phone(producer,model,version,url);
            mElementViewModel.insert(phone);
        }
        else if(requestCode == 2 && resultCode == RESULT_OK) {
            this.data = newData;
            Bundle bundle = data.getExtras();
            String producer = bundle.getString("producer");
            String model = bundle.getString("model");
            String version = bundle.getString("version");
            String url = bundle.getString("url");
            int id = bundle.getInt("id");

            Phone phone = new Phone(id,producer,model,version,url);
            mElementViewModel.update(phone);
        }
    }

    @Override
    public void onItemClickListener(Phone phone) {
        Intent intent = new Intent(this, EditPhoneActivity.class);
        intent.putExtra("model", phone.getModel());
        intent.putExtra("producer", phone.getProducer());
        intent.putExtra("url", phone.getUrl());
        intent.putExtra("version", phone.getVersion());
        intent.putExtra("id", phone.getId());

        //noinspection deprecation
        startActivityForResult(intent,2);
    }
}