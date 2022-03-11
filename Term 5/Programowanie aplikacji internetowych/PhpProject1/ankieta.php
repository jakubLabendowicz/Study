<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<!DOCTYPE html>
 
<html>
 
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
 
    <body>
        <form action="ankieta.php?" method="POST" autocomplete="on">
            <?php
            //wyświetlanie formularza
            $tech = ["C", "CPP", "Java", "C#", "Html", "CSS", "XML", "PHP", "JavaScript"];
            for ($i = 0; $i < count($tech); $i++) {
                echo "<input type='checkbox' name='tech[]' value='" . $tech[$i] . "'>" . $tech[$i] . "<br>";
            }
 
            foreach ($tech as $i) {
                $arr[$i] = 0;
            }
            //tworzenie pliku (tylko raz)
            //file_put_contents("ankieta.txt",json_encode($arr));
 
            if (isset($_REQUEST["submit"])) {
                $arr2 = (array) json_decode(file_get_contents("ankieta.txt"));
                if (isset($_REQUEST['tech']) && ($_REQUEST['tech'] != "")) {
                    foreach ($_REQUEST['tech'] as $i) {
                        $arr2[$i]++;
                    }
                }
                file_put_contents("ankieta.txt", json_encode($arr2));
            }
            ?>
 
            <input type='submit' name='submit' value='Wyślij'>
        </form>
    </body>
