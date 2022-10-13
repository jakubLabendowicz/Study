package com.example.project2;


import android.app.Application;

import androidx.lifecycle.LiveData;

import java.util.List;

public class ElementRepository {
    private ElementDao mElementDao;
    private LiveData<List<Phone>> mAllElements;

    ElementRepository(Application application) {
        ElementRoomDatabase elementRoomDatabase = ElementRoomDatabase.getDatabase(application);

        mElementDao = elementRoomDatabase.elementDao();
        mAllElements = getAllElements();
    }

    LiveData<List<Phone>> getAllElements()
    {
        return mElementDao.getAlphabetizedElements();
    }
    void insert(Phone phone) {
        ElementRoomDatabase.databaseWriteExecutor.execute(()-> mElementDao.insert(phone));
    }

    void delete(Phone phone) {
        ElementRoomDatabase.databaseWriteExecutor.execute(()-> mElementDao.delete(phone));
    }

    void update(Phone phone) {
        ElementRoomDatabase.databaseWriteExecutor.execute(()-> mElementDao.update(phone));
    }

    void deleteAll() {
        ElementRoomDatabase.databaseWriteExecutor.execute(()-> mElementDao.deleteAll());
    }
}
