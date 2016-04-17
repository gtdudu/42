<?php

function remove_from_basket($item_name)
{
	include("is_item.php");
	session_start();
	if (isset($_SESSION['basket']) && ($item_id = is_item($item_name)) === true)
	{
		$tab = unserialize($_SESSION['basket']);
		if (isset($tab))
		{
			$i = 0;
			while ($i < count($tab))
			{
				if ($tab[$i] === $item_id)	
				{
					unset($tab[$i]);
					$tab = array_values($tab);
				}
				$i++;

			}
			$str = serialize($tab);
			$_SESSION['basket'] = $str;
		}
	}
}

?>
