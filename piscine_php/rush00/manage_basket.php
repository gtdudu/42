<?php
session_start();

if (!empty($_POST['quantity']))
{
	$quantity = $_POST['quantity'];
	if (!is_numeric($quantity))
		$quantity = 1;
}
else
	$quantity = 1;

include("is_item.php");
include("get_item_info.php");

$name = $_POST['name'];
if (($item_id = is_item($name)) !== false)
{
    $price = $_POST['price'];
    $command = array("name" => $name, "prix" => $price, "quantity" => $quantity);
    $_SESSION['basket'] = $command[];
}


print_r $_SESSION['basket'];

//header("Location: $link");
?>
