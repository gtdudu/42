<?php
function moditem($item_id, $name, $price, $description, $image, $tab_id)
{

	if (!is_numeric($price) || $price < 0)
		$price = 1;
	include("connect.php");
	session_start();
	$safe_name = mysqli_real_escape_string($conn, $name);
	$safe_description = mysqli_real_escape_string($conn, $description);
	$safe_image = mysqli_real_escape_string($conn, $image);


	if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === true)
	{
		$sql = 'DELETE FROM `myDB`.`category_item` WHERE item_id="'.$item_id.'"';
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again".mysqli_error($conn);
		else
			echo "uewyuqwefhuhouhou";

		$sql = 'UPDATE `myDB`.`item` SET name="'.$safe_name.'", description="'.$description.'", price="'.$price.'", image="'.$safe_image.'" WHERE item_id='.$item_id;
		echo "<br />";
		echo $sql;
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again".mysqli_error($conn);

		foreach ($tab_id as $elem)
		{
			$sql = 'INSERT INTO `myDB`.`category_item` (category_id, item_id) VALUES ('.'"'.$elem.'", "'.$item_id.'")';
			if (!mysqli_query($conn, $sql))
				echo "There has been an error, please try again".mysqli_error($conn);
		}
		
	}
}
?>
