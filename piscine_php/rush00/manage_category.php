<?php
session_start();
include("check_key.php");
include("connect.php");

if (empty($_POST['name']) || empty($_POST['description']))
	setcookie("retry", "true");
else if ($_SESSION['privilege'] && (check_key($_SESSION['privilege']) === true))
{
			include("array_id.php");
			echo "fqewugh";
			$category_id = $_POST['category'];
			$category_id = array_id($_POST['category'], $id);
			print_r($category_id);
	$name = mysqli_real_escape_string($conn, $_POST['name']);
	$safe_description = mysqli_real_escape_string($conn, $_POST['description']);
	if ($_POST['submit'] === "delete")
	{
		$todel = 0;
		$sql = 'SELECT * FROM `myDB`.`category`';
		if (($result = mysqli_query($conn, $sql)))
			echo "There has been an error, please try again".mysqli_error($conn);
		while ($row = mysqli_fetch_assoc($conn, $result))
		{
			if ($row['name'] === $name)
			{
				$todel = $row['category_id'];
				$sql = 'DELETE FROM `myDB`.`category_item` WHERE name="'.$todel.'"';
				if (!mysqli_query($conn, $sql))
					echo "There has been an error, please try again".mysqli_error($conn);
			}
		}	

		$sql = 'DELETE FROM `myDB`.`category` WHERE name="'.$name.'"';
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again".mysqli_error($conn);

	}
	else if ($_POST['submit'] === "modify")
	{
		$sql = 'UPDATE `myDB`.`category` SET name="'.$name.'", description="'.$safe_description.'" WHERE category_id='.$category_id;
		$result = mysqli_query($conn, $sql);
	}
	else
	{
		$sql = "SELECT name FROM `myDB`.`category`";
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
			if ($_POST['submit'] === "add")
			{
				$sql = 'INSERT INTO `myDB`.`category` (name, description) VALUES ("'.$name.'", "'.$safe_description.'")';
				if (!mysqli_query($conn, $sql))
					echo "There has been an error, please try again".mysqli_error($conn);
				else
					echo "youhou add";
			}
		}
	}
}
header("Location: adminpanel.php");
?>
