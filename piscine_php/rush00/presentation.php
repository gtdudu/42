<?php
session_start();
?>

<html>
    <head>
        <title>Bocal Renting</title>
        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="menu.css">
        <meta charset="utf-8">
    </head>
    <body id="home">
        <div class="clearfix" id="content">
            <?php include("header.php"); ?>
            <?php include("menu.php"); ?>
            <div id="content-presentation" class="present-page">
                <?php include ("is_item.php");
                $item = mysqli_real_escape_string($conn, $_GET['item']);
                if (($user_id = is_item($item)) !== false)
                {
                    $sql2 = "SELECT * FROM item WHERE name="."'".$item."'";
                    $result2 = mysqli_query($conn, $sql2);
				    while ($row2 = mysqli_fetch_assoc($result2)) 
                    {?>
                        <img id="big" src="<?php echo $row2['image'];?>">
                        <h1><?php echo $row2['name']; ?></h1>
                        <p><?php echo '" '.$row2['description'].' "';?></p>
                        <h2>Prix : <?php echo $row2['price'];?>$</h2>
                        <form action="manage_basket.php" method="post">
                            <input id="nb" type="number" name="quantity" placeholder="Quantité" value=""></input>
                            <input id="add" type="submit" name="submit" value="Valider">
                            <input type="hidden" name="name" value="<?php echo $row2['name']; ?>">
                            <input type="hidden" name="price" value="<?php echo $row2['price']; ?>">
                        </form>
                        <a href="index.php"><button type="button">Continuer les achats</button></a>
                        <a href="basket.php"><button type="button">Payer maintenant</button></a>
                    <?php
				    }
                }
                ?>
            </div>
            <?php include("footer.php"); ?>
        </div>
    </body>
</html>


