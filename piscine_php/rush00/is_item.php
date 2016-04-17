<?php

function is_item($item_name)
{
	include("connect.php");
	if (isset($item_name))
	{
		$sql = "SELECT * FROM item";
		$request = mysqli_query($conn, $sql);
		if (isset($request))
		{
			while ($row = mysqli_fetch_assoc($request))
			{
				if ($row['name'] === $item_name)
					return $row['user_id'];
			}
		}
	}
	return false;
}

?>
