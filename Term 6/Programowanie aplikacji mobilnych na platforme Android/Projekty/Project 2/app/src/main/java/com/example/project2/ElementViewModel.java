package com.example.project2;



import android.app.Application;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import java.util.List;

public class ElementViewModel extends AndroidViewModel {
    private final ElementRepository mRepository;
    private LiveData<List<Phone>> mAllElements;

    public ElementViewModel(@NonNull Application application) {
        super(application);
        mRepository = new ElementRepository(application);
        mAllElements = getAllPhones();
    }

    LiveData<List<Phone>> getAllPhones() {
        return mAllElements == null? mRepository.getAllElements():mAllElements;
    }
    public void insert(Phone phone)
    {
        mRepository.insert(phone);
    }
    public void deleteAll()
    {
        mRepository.deleteAll();
    }
    public void delete(Phone phone)
    {
        mRepository.delete(phone);
    }
    public void update(Phone phone)
    {
        mRepository.update(phone);
    }
}
