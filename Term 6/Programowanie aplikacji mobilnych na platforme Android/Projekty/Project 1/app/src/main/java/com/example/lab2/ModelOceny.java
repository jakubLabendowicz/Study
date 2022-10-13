package com.example.lab2;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Data
@NoArgsConstructor
@Getter
@Setter
public class ModelOceny {

    private String name;
    private int grade;

    public ModelOceny( String name, int grade) {
        this.grade = grade;
        this.name = name;
    }

    public ModelOceny(String name) {
        this.name = name;
    }

    public String getName(){
        return  this.name;
    }

    public int getGrade(){
        return  this.grade;
    }

    public void setGrade(int grade){
        this.grade = grade;
    }
}
