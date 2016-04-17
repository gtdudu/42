<?php
function delitem($id, $name, $price, $description, $image)
{
	include("connect.php");
	include("check_key.php");
	session_start();
	if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === true)
	{

		$safe_name = mysqli_real_escape_string($conn, $name);
		$safe_price = (int)mysqli_real_escape_string($conn, $price);
		$safe_description = mysqli_real_escape_string($conn, $description);
		$sql = "DELETE FROM `myDB`.`item` WHERE name="."'".$name."' AND price="."'".$safe_price."' AND  description="."'".$safe_description."'";
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again".mysqli_error($conn);
		else
			echo "cyouhou";
		$sql = 'DELETE FROM `myDB`.`category_item` WHERE item_id="'.$id.'"';
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again".mysqli_error($conn);
		else
			echo "deleted";
	}
}
?>
