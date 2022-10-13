package com.example.project2;



import androidx.annotation.NonNull;
import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "phone")
public class Phone {


    @PrimaryKey(autoGenerate = true)
    @ColumnInfo(name = "id")
    private int id;

    @NonNull
    @ColumnInfo(name = "producer")
    private String producer;

    @NonNull
    @ColumnInfo(name = "model")
    private String model;

    @NonNull
    @ColumnInfo(name = "version")
    private String version;

    @NonNull
    @ColumnInfo(name = "url")
    private String url;

    public Phone(){
        super();
        producer = "";
        model = "";
        version = "";
        url = "";
    }
    public Phone(@NonNull String producer, @NonNull String model, @NonNull String version, @NonNull String url) {
        this.producer = producer;
        this.model = model;
        this.version = version;
        this.url = url;
    }


    public Phone(int id, @NonNull String producer, @NonNull String model, @NonNull String version, @NonNull String url) {
        this.id = id;
        this.producer = producer;
        this.model = model;
        this.version = version;
        this.url = url;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @NonNull
    public String getProducer() {
        return producer;
    }

    public void setProducer(@NonNull String producer) {
        this.producer = producer;
    }

    @NonNull
    public String getModel() {
        return model;
    }

    public void setModel(@NonNull String model) {
        this.model = model;
    }

    @NonNull
    public String getVersion() {
        return version;
    }

    public void setVersion(@NonNull String version) {
        this.version = version;
    }

    @NonNull
    public String getUrl() {
        return url;
    }

    public void setUrl(@NonNull String url) {
        this.url = url;
    }
}
