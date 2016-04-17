<?php
function array_id($tab, $id)
{
	include("connect.php");
	$category = array();
	$sql = "SELECT * FROM category";
	$result = mysqli_query($conn, $sql);
	if (isset($result))
	{
		while ($row = mysqli_fetch_assoc($result))
		{
			foreach ($tab as $elem)
			{
				if ($row['name'] === $elem)
				{
					$category[] = $row['category_id'];
				}
			}
		}
	}
	return $category;
}
?>
