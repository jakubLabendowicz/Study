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
    <body style="margin: 0px; padding: 0px;">
        <div style="display: flex; justify-content: center; height: 100vh; align-items: center; font-size: 20px;">
            <div>
                <?php
                
                    //IMIĘ
                    if (isset($_REQUEST['Imię'])&&($_REQUEST['Imię']!="")) {
                        $imie = htmlspecialchars(trim($_REQUEST['Imię']));
                        echo "Imię: $imie <br />";
                    } else echo "Nie wpisano imienia <br />";

                    //NAZWISKO
                    if (isset($_REQUEST['Nazwisko'])&&($_REQUEST['Nazwisko']!="")) {
                        $nazwisko = htmlspecialchars(trim($_REQUEST['Nazwisko']));
                        echo "Nazwisko: $nazwisko <br />";
                    } else echo "Nie wpisano nazwiska <br />";

                    //PŁEĆ
                    if (isset($_REQUEST['Płeć'])&&($_REQUEST['Płeć']!="")) {
                        $plec = htmlspecialchars(trim($_REQUEST['Płeć']));
                        echo "Płeć: $plec <br />";
                    } else echo "Nie zaznaczono płci <br />";

                    //WIEK
                    if (isset($_REQUEST['Wiek'])&&($_REQUEST['Wiek']!="")) {
                        $wiek = htmlspecialchars(trim($_REQUEST['Wiek']));
                        echo "Wiek: $wiek <br />";
                    } else echo "Nie zaznaczono wieku <br />";

                    //MUZYKA
                    if (isset($_REQUEST['Muzyka'])&&($_REQUEST['Muzyka']!="")) {
//                        $muzyka = htmlspecialchars(trim($_REQUEST['Muzyka']));
                        echo "Muzyka: ";
                        foreach ($_REQUEST['Muzyka'] as $value) {
                            print($value);
                            echo ', ';
                        }
                        echo '<br />';
                    } else echo "Nie zaznaczono muzyki <br />";

                    //PRZEGLĄDARKA
                    if (isset($_REQUEST['Przeglądarka'])&&($_REQUEST['Przeglądarka']!="")) {
                        $przegladarka = htmlspecialchars(trim($_REQUEST['Przeglądarka']));
                        echo "Przeglądarka: $przegladarka <br />";
                    } else echo "Nie zaznaczono przeglądarki <br />";

                    //SYSTEM OPERACYJNY
                    if (isset($_REQUEST['SystemOperacyjny'])&&($_REQUEST['SystemOperacyjny']!="")) {
//                        $system_operacyjny = htmlspecialchars(trim($_REQUEST['SystemOperacyjny']));
                        echo "System operacyjny: ";
                        foreach ($_REQUEST['SystemOperacyjny'] as $value) {
                            print($value);
                            echo ', ';
                        }
                        echo '<br />';
                    } else echo "Nie zaznaczono systemu operacyjnego <br />";

                    //KOMENTARZ
                    if (isset($_REQUEST['Komentarz'])&&($_REQUEST['Komentarz']!="")) {
                        $komentarz = htmlspecialchars(trim($_REQUEST['Komentarz']));
                        echo "Komentarz: $komentarz <br />";
                    } else echo "Nie wpisano komentarza <br />";
                ?>
            </div>
        </div>
    </body>
</html>
