<?php
function additem($id, $name, $price, $description, $image, $tab_id)
{
	include("connect.php");
	include("is_real_item_id.php");
	session_start();
	$safe_name = mysqli_real_escape_string($conn, $name);
	$safe_price = (int)mysqli_real_escape_string($conn, $price);
	$safe_description = mysqli_real_escape_string($conn, $description);
	$safe_image = mysqli_real_escape_string($conn, $image);


	if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === true)
	{
		$sql = 'INSERT INTO `myDB`.`item` (name, price, description, image) VALUES ('.'"'.$safe_name.'", '.'"'.$safe_price.'", '.'"'.$safe_description.'", '.'"'.$safe_image.'")';
		if (mysqli_query($conn, $sql))
		{
			$item_id = mysqli_insert_id($conn);
		}
		else
			echo "There has been an error, please try again";
		foreach ($tab_id as $elem)
		{
			$sql = 'INSERT INTO `myDB`.`category_item` (category_id, item_id) VALUES ('.'"'.$elem.'", "'.$item_id.'")';
			if (!mysqli_query($conn, $sql))
				echo "There has been an error, please try again".mysqli_error($conn);
		}
	}
}
?>
