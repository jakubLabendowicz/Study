package com.company;

import javax.jws.WebService;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

@WebService(endpointInterface = "com.company.MyFirstSOAPInterface")
public class MyFirstWS implements MyFirstSOAPInterface{
    public String getHelloWorldAsString(String nazwa) {
        String message = "Witaj "+nazwa+"!";
        return message;
    }
    public long getDaysBetweenDates(String date1, String date2) {
        long numberOfDays=0;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd MM yyyy");
        try {
            LocalDate tempdate1 = LocalDate.parse(date1, dtf);
            LocalDate tempdate2 = LocalDate.parse(date2, dtf);
            numberOfDays = Duration.between(tempdate1.atStartOfDay(), tempdate2.atStartOfDay()).toDays();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return numberOfDays;
    }
}
