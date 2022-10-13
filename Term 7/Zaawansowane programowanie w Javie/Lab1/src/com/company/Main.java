package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
        //zad1
        ArrayList<String> list = new ArrayList<>();
        list.add("Architektura i programowanie w .NET");
        list.add("Procesy wytwarzania oprogramowania");
        list.add("Komponentowe podejście do wytwarzania aplikacji");
        list.add("Zaawansowane programowanie w Javie");
        Stream<String> stream = list.stream()
                .filter(element -> element.contains("Zaaw"));


        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(2);
        list2.add(3);
        list2.add(4);
        list2.add(5);
        list2.add(5);
        Stream<Integer> stream2 = list2.stream()
                .map(element -> element);

        Map map3 = list2.stream()
                .collect(
                        Collectors.groupingBy(
                                Function.identity(),
                                Collectors.counting()
                        )
                );



        //zad2
        File file = new File("WynikZapisu.txt");
        try {
            FileWriter fileWriter = new FileWriter(file, true);
            for (int i = 0; i < 10; i++) {
                fileWriter.append("To jest dopisana linijka tekstu nr: " + i + "\n");
            }
            fileWriter.close();
        } catch (IOException ex) {
            System.err.println(ex.getCause());
        }



        //zad3
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(new File("WynikZapisu.txt")));
            String linia = null;
            while ((linia = bufferedReader.readLine()) != null) {
                System.out.println(linia);
            }
            bufferedReader.close();
        } catch (FileNotFoundException ex) {
            System.out.println("Pliku nie odnaleziono!");
            System.err.println(ex.getCause());
        } catch (IOException ex) {
            System.out.println("Błąd odczytu pliku spowodowany:");
            System.err.println(ex.getCause());
        }
    }
}
