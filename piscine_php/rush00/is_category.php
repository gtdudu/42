<?php

function is_category($category)
{
	include("connect.php");
	if (isset($category))
	{
		$sql = "SELECT * FROM category";
		$request = mysqli_query($conn, $sql);
		if (isset($request))
		{
			while ($row = mysqli_fetch_assoc($request))
			{
				if ($row['name'] === $category)
					return $row['category_id'];
			}
		}
	}
	return false;
}

?>
