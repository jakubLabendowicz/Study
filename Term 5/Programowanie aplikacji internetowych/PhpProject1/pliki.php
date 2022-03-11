<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <form action="pliki.php" method="post" id="form" style="display: flex; justify-content: center"><div id="formInner">
            <h1>Formularz zamówienia</h1>
            <div>Nazwisko: <input type="text" name="Nazwisko"></div><br>
            <div>Wiek: <input type="text" name="Wiek"></div><br>
            <div>Państwo: <input type="text" name="Panstwo"></div><br>
            <div>Adres e-mail: <input type="text" name="Mail"></div><br>
            <!-- Pole typu CHECKBOX -->
            <h3>Zamawiam tutorial z języka</h3>
            <?php
            // put your code here
                $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
                foreach ($jezyki as $value) {
                    echo '<input type="checkbox" name="Jezyki[]" value="' . $value . '">' . $value . '<br>';
                }
            ?>
            <h3>Sposób zapłaty</h3>
            <?php
                $zaplata = ["eurocard", "visa", "przelew bankowy"];
                foreach ($zaplata as $value) {
                    echo '<input type="radio" name="Zaplata" value="' . $value . '">' . $value . '<br>';
                }
            ?>
            <br><br><br>
            <?php
                
                $submit = ["Wyczyść", "Zapisz", "Pokaż", "PHP", "CPP", "Java", "Statystyki"];
                foreach ($submit as $value) {
                    echo '<input type="submit" name="submit" value="' . $value . '">';
                }
            ?>
            <?php
            include_once 'funkcje.php';
                //Skrypt właściwy do obsługi akcji (żądań):
                if (filter_input(INPUT_POST, "submit")) { //jeśli kliknięto przycisk o name=submit
                    $akcja = filter_input(INPUT_POST, "submit"); //odczytaj jego value
                    switch ($akcja) {
                        case "Zapisz":dodaj();break;
                        case "Pokaż":pokaz();break;
                        case "Java":pokaz_zamowienie("Java");break;
                        case "PHP":pokaz_zamowienie("PHP");break;
                        case "CPP":pokaz_zamowienie("CPP");break;
                        case "Statystyki":statystyki();break;
                 //pozostałe przypadki
                    }
                }
            ?>

        </div></form>
    </body>
</html>
