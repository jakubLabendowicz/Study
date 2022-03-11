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
        <?php
            //JĘZYK
            if (isset($_REQUEST['Jezyki'])&&($_REQUEST['Jezyki']!="")) {
                echo "Jezyki: ";
                echo implode(", ", $_REQUEST['Jezyki']);
                
                echo '<br />';
            } else echo "Nie zaznaczono języków <br />";

            //ZAPŁATA
            if (isset($_REQUEST['Zaplata'])&&($_REQUEST['Zaplata']!="")) {
                $nazwisko = htmlspecialchars(trim($_REQUEST['Zaplata']));
                echo "Sposób zapłaty: $nazwisko <br />";
            } else echo "Nie zaznaczono sposobu zapłaty<br />";
            
            echo '<br />';
            var_dump($_REQUEST)
        ?>
    </body>
</html>
