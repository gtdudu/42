<?php
include("delitem.php");
include("additem.php");
include("moditem.php");
include("check_key.php");
include("array_id.php");
include("is_real_item_id.php");
include("connect.php");
if (empty($_POST['name']) || empty($_POST['price']) || empty($_POST['description']) || empty($_POST['image']))
	setcookie("retry", "true");
else
{
	$id = (int)mysqli_real_escape_string($conn, $_POST['item_id']);
	$name = mysqli_real_escape_string($conn, $_POST['name']);
	$tab = array();
	if (isset($_POST['category']))
	{
		foreach($_POST['category'] as $elem)
		{
			$safe_elem = mysqli_real_escape_string($conn, $elem);
			$tab[] = $safe_elem;
		}
	}
	$tab_id = array_id($tab, $id);

	if ($_POST['submit'] === "delete")
	{
		echo "delete";
		delitem($id, $_POST['name'], $_POST['price'], $_POST['description'], $_POST['image']);
	}
	else if ($_POST['submit'] === "modify")
	{
		echo "modify";
		if (is_real_item_id($id) === true)
			moditem($id, $_POST['name'], $_POST['price'], $_POST['description'], $_POST['image'], $tab_id);
	}
	else
	{
		if ($name === "")
			return false;
		$sql = "SELECT * FROM `myDB`.`item`";
		$result = mysqli_query($conn, $sql);
		$flag = 0;

		if (mysqli_num_rows($result) > 0)
		{
			while ($row = mysqli_fetch_assoc($result))
			{
				if ($row['name'] === $name)
					$flag = 1;
			}
		}
		if ($flag == 1)
			setcookie("taken", "true");
		else
		{
			$category = serialize($_POST['category']);
			if ($_POST['submit'] === "add")
			{
				additem($id, $_POST['name'], $_POST['price'], $_POST['description'], $_POST['image'], $tab_id);
			}
			else
				echo "non";
		}
	}
}
header("Location: adminpanel.php");
?>
