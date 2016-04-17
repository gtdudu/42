<div id="content-presentation">
<?php

include("connect.php");
$sql = "SELECT * FROM category_item WHERE category_id='1'";
$result = mysqli_query($conn, $sql);

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
				<img id="rep" src="<?php $row2['image']?>">
				<span><?php $row2['name'] ?></span>
				<a href="#"><img id="ico" src="resources/ico-panier.png"></a>
			</div>
<?php
		}

	}
}
?>
</div>
