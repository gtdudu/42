<?php

function new_order($user_id)
{
	include("connect.php");
	$order_id = NULL;
	$sql = "INSERT INTO `myDB`.`orders` (`user_id`) VALUES ('".$user_id."')";
	if (mysqli_query($conn, $sql))
	{
		$order_id = mysql_insert_id($conn);
		echo "added new order";
	}
	else
		echo "failed new order";
	return $order_id;
}

?>
