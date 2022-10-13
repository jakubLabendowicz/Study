package com.example.project2;


import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
interface ElementDao
{
    @Insert(onConflict = OnConflictStrategy.ABORT)
    void insert(Phone phone);

    @Query("DELETE FROM phone")
    void deleteAll();

    @Delete
    void delete(Phone phone);

    @Update(onConflict = OnConflictStrategy.REPLACE)
    void update(Phone phone);

    @Query("SELECT * FROM phone ORDER BY id ASC")
    LiveData<List<Phone>> getAlphabetizedElements();




}
