<?php

function add_to_basket($item_name)
{
	include("is_item.php");
	session_start();
	if (isset($_SESSION['basket']) && ($item_id = is_item($item_name)) === true)
	{
		$tab = unserialize($_SESSION['basket']);
		if (isset($tab))
		{
			$flag = 0;
			foreach ($tab as $subtab)
			{
				if ($subtab['item_id'] === $item_id)
				{
					$subtab['quantity'] += 1;
					$flag = 1;
				}
			}
			$quantity = 1;
			if ($flag != 1)
				$tab[] = array("item_id" => $item_id, "quantity" => $quantity);
			$str = serialize($tab);
			$_SESSION['basket'] = $str;
		}
	}
}

?>
