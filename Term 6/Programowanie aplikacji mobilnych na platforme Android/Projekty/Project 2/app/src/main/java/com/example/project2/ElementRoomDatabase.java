package com.example.project2;


import android.content.Context;

import androidx.annotation.NonNull;
import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;
import androidx.sqlite.db.SupportSQLiteDatabase;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

@Database(entities = {Phone.class}, version = 2, exportSchema = false)
public abstract class ElementRoomDatabase extends RoomDatabase {
    public abstract ElementDao elementDao();

    private static volatile ElementRoomDatabase INSTANCE;

    static ElementRoomDatabase getDatabase(final Context context) {
        if (INSTANCE == null) {
            synchronized (ElementRoomDatabase.class) {
                if (INSTANCE == null) {
                    INSTANCE = Room.databaseBuilder(context.getApplicationContext(), ElementRoomDatabase.class, "phone")
                            .addCallback(sRoomDatabaseCallback)
                            .fallbackToDestructiveMigration()
                            .build();
                }
            }
        }
        return INSTANCE;
    }

    private static final int NUMBER_OF_THREADS = 4;
    static final ExecutorService databaseWriteExecutor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);

    private static RoomDatabase.Callback sRoomDatabaseCallback = new RoomDatabase.Callback()
    {
        @Override
        public void onCreate(@NonNull SupportSQLiteDatabase db)
        {
            super.onCreate(db);

            databaseWriteExecutor.execute(()-> {
                ElementDao dao = INSTANCE.elementDao();
                Phone phone = new Phone("Apple", "iPhone 13 mini ", "13", "www.google.com");
                Phone phone2 = new Phone("Apple", "iPhone 13 Pro ", "13", "www.google.com");
                dao.insert(phone);
                dao.insert(phone2);

            });




        }
    };
}
