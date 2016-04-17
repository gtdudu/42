<?php

function archive($basket, $loggued)
{
	include("is_user.php");
	include("connect.php");
	if (isset($basket) && ($user_id = is_user($loggued)) !== false)
	{
		include("new_order.php");
		$order_id = new_order($user_id);
		if ($order_id !== NULL)
		{
			$tab = unserialize($basket);
			foreach ($tab as $subtab)
			{
				$safe_item_id =(int) mysqli_real_escape_string($conn, $subtab['item_id']); 
				$safe_quantity = (int)mysqli_real_escape_string($conn, $subtab['quantity']); 
				$sql = "INSERT INTO `myDB`.`order_item` (`orders_id`, `item_id`, 'number') VALUES (`".$order_id."`, `".$safe_item_id."`, '".$safe_quantity."')";
				if ($mysqli_query($conn, $sql))
					echo "archiving basket";
				else
					echo "failed miserably";
			}
		}
		else
			echo "failed to archive";
	}
}

?>
