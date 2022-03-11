<?php
    //Funkcje pomocnicze:
    function dopliku() {
        $dane = "";
        
        if(isset($_REQUEST["Nazwisko"])){
            $dane .= $_REQUEST["Nazwisko"];
            $dane .= " ";
        }
        
        if(isset($_REQUEST["Wiek"])){
            $dane .= $_REQUEST["Wiek"];
            $dane .= " ";
        }
        
        if(isset($_REQUEST["Panstwo"])){
            $dane .= $_REQUEST["Panstwo"];
            $dane .= " ";
        }
        
        if(isset($_REQUEST["Mail"])){
            $dane .= $_REQUEST["Mail"];
            $dane .= " ";
        }
        
        if (isset($_REQUEST["Jezyki"])) {
            $dane .= join(", ", $_REQUEST["Jezyki"]);
            $dane .= " ";
        }
        
        if(isset($_REQUEST["Zaplata"])){
            $dane .= $_REQUEST["Zaplata"];
        }
        
        $dane .= "\n";
        $file = fopen("dane.txt", "a");
        fwrite($file, $dane);
        fclose($file);
        
        echo "<br><br>"."Zapisano:"."<br>".$dane;
    //zbierz pozostałe dane z formularza – dodając je do łańcucha $dane
    //zapisz łańcuch z danymi do pliku dane.txt w postaci wiersza np.:
    //Agatowska 21 Polska agatka@gmail.com PHP,CPP,Java Visa
    }  
    
    //Nowa funkcja
    function walidacja() {
        $args = ['Nazwisko' => ['filter' => FILTER_VALIDATE_REGEXP,
        'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/']
        ],
        'Panstwo' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
        'Jezyki' => ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
        'flags' => FILTER_REQUIRE_ARRAY
        ],
        'Mail' => FILTER_VALIDATE_EMAIL,
        'Wiek' => FILTER_VALIDATE_INT,
        ];
        
        //przefiltruj dane z GET/POST zgodnie z ustawionymi w $args filtrami:
        $dane = filter_input_array(INPUT_POST, $args);
        //pokaż tablicę po przefiltrowaniu - sprawdź wyniki filtrowania:
        var_dump($dane);
        //Sprawdź czy dane w tablicy $dane nie zawierają błędów walidacji:
        $errors = "";
        foreach ($dane as $key => $val) {
           if ($val === false or $val === NULL) {
              $errors .= $key . " ";
           }
        }
        if ($errors === "") {
            //Dane poprawne - zapisz do pliku
            //wykorzystaj pomocniczą funkcję:
            dopliku();
        } else {
            echo "<br>Nie poprawnie dane: " . $errors;
        }
    }
    
    function dodaj(){
        echo "<h3>Dodawanie do pliku:</h3>";
        walidacja();
    }
    
    function pokaz() {
        echo "<h3>Dane odczytane z pliku</h3>";
    //odczytaj wszystkie dane z pliku i wyświetl wierszami...
        $file = file("dane.txt");
        foreach ($file as $value) {
            $exp = explode("; ", $value);
            foreach ($exp as $value2) {
                echo $value2 . "<br>";
            }
        }
    }
    
    function pokaz_zamowienie($tut) {
        $plik = fopen("dane.txt", "r", 1);
        if($plik){
            echo "<h3>Zamówienia ".$tut."</h3>";
            while($line = fgets($plik)){
                if(strpos($line, $tut)){
                    echo "<p>.$line.</p>";
                }
            }
        }
        fclose($plik);
    }
    
     function statystyki() {
        $plik = fopen("dane.txt", "r", 1);
        if($plik){
            $licznik1=0;
            $licznik2=0;
            $licznik3=0;
            while($line = fgets($plik)){
                $eksp= explode(" ", $line);
                $licznik1+=1;
                if ($eksp[1]<18){
                    $licznik2+=1;
                }
                if ($eksp[1]>=50){
                    $licznik3+=1;
                }
            }

            echo "<h3>liczba wszystkich zamowien: ".$licznik1."</h3>";
            echo "<h3>liczba zamowien osob w wieku <18 lat: ".$licznik2."</h3>";
            echo "<h3>liczba zamowien osob w wieki >=50 lat: ".$licznik3."</h3>";
        }
        fclose($plik);
    }
?>
