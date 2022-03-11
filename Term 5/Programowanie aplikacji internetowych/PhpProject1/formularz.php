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
        <form action="odbierz3.php" method="post" id="form" style="display: flex; justify-content: center"><div id="formInner">
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
            <!-- Przycisk WYŚLIJ -->
            <input type="submit" value="Wyślij">
            <!-- Przycisk WYCZYŚĆ DANE -->
            <input type="reset" value="Wyczyść dane">
        </div></form>
    </body>
</html>
