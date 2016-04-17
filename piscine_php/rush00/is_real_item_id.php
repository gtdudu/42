<?php

function is_real_item_id($loggued)
{
	include("connect.php");
	if (isset($loggued))
	{
		$sql = "SELECT * FROM item";
		$request = mysqli_query($conn, $sql);
		if (isset($request))
		{
			while ($row = mysqli_fetch_assoc($request))
			{
				if ($row['item_id'] == $loggued)
					return true;
			}
			print_r($row);
		}
	}
	return false;
}

?>
