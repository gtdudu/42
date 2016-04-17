<?php
include("connect.php");
session_start();
?>
<html>
    <head>
        <title>Bocal Renting</title>
        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="menu.css">
        <meta charset="utf-8">
    </head>
    <body id="basket">
        <div class="clearfix" id="content">
            <?php include("header.php"); ?>
            <div id="content-basket">
                <?php
                $_SESSION['basket'] = "ok";
                if (empty($_SESSION['basket']))
                {
                ?>
                    <h1>Ton Panier est Vide !</h1>    
                <?php
                }
                else
                {
                    ?>
                    <h1>Recapitulatif</h1>
                    <table>
                        <tr>
                            <th>Article</th>
                            <th>Prix</th> 
                            <th>Quantité</th>
                            <th>Sous-Total</th>
                        </tr>
                        <tr>
                            <td>Test</td>
                            <td>4224 $</td> 
                            <td>2</td>
                            <td>8448 $</td>
                        </tr>
                        <tr>
                            <td>Olivier Crouzet</td>
                            <td>255 $</td> 
                            <td>1</td>
                            <td>255 $</td>
                        </tr>
                    </table>
                    <table id="total">
                        <tr>
                            <th>Total</th>
                        </tr>
                    </table>
                
                <?php
                }
                ?>
                </div>
            <?php include("footer.php"); ?>
        </div>
    </body>
</html>