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
            <div id="content-cat">
                <div id="content-presentation">

			<?php
			include("is_category.php");
			if (($category_id = is_category($_GET['category'])) !== false)
			{
				$sql = "SELECT * FROM category_item WHERE category_id="."'".$category_id."'";
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
									<span><?php echo $row2['name']; ?></span>
                                    <?php echo "<a href='presentation.php?item=".$row2['name']."'><img id='ico' src='resources/ico-more.png'></a>";?>
                                    <p><?php echo $row2['price']." $";?></p>
                                                                        

								</div>
					<?php
							}

						}
					}
				}
			}
			?>
                </div>
            </div>
            <?php include("footer.php"); ?>
        </div>
    </body>
</html>
