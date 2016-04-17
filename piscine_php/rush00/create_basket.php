<?php

function create_basket($item_name)
{
	include("is_item.php");
	session_start();
	if (($item_id = is_item($item_name)) === true)
	{
		$quantity = 1;
		$tab[] = array("item_id" => $item_id, "quantity" => $quantity);
		$str = serialize($tab);
		$_SESSION['basket'] = $str;
	}
}
