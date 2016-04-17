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
    <body id="home">
        <div class="clearfix" id="content">
            <?php include("header.php"); ?>
            <?php include("menu.php"); ?>
            <div id="content-home">
                <h2>Bienvenue !</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam cursus massa eu dolor porttitor aliquet. Aenean sagittis vitae libero sed aliquet. Nulla scelerisque at augue at aliquam. Donec porttitor libero ligula, a suscipit diam tempor eget. Proin dignissim maximus turpis eu tempus. Suspendisse luctus, lectus facilisis volutpat porta, urna massa convallis arcu, in gravida odio magna a libero. Morbi quis volutpat nibh. Sed nec felis suscipit, fringilla quam accumsan, eleifend erat. Aliquam nec odio sem. Phasellus feugiat neque massa, non tincidunt turpis consequat vel. Donec ac luctus arcu. Fusce et posuere orci, vitae sagittis leo. Aliquam in accumsan ligula.</p>
            </div>
            <div id="content-presentation">
            <?php
            $sql = "SELECT * FROM category_item WHERE category_id=1";
				$result = mysqli_query($conn, $sql);
				if (isset($result))
				{
					if (mysqli_num_rows($result) > 0)
					{
						while ($row = mysqli_fetch_assoc($result)) 
						{
							$sql2 = "SELECT * FROM item WHERE item_id="."'".$row['item_id']."'";
							$result2 = mysqli_query($conn, $sql2);
							while ($row2 = mysqli_fetch_assoc($result2)) 
                            {
                                ?>
								<div class="box">
									<img id="rep" src="<?php echo $row2['image'];?>">
									<span><?php echo $row2['name'];?></span>
                                    <?php echo "<a href='presentation.php?item=".$row2['name']."'><img id='ico' src='resources/ico-more.png'></a>";?>
                                    <p><?php echo $row2['price']." $";?></p>
								</div>
					           <?php
							}

						}
					}
                }
            ?>
            </div>
            <?php include("footer.php"); ?>
        </div>
    </body>
</html>

