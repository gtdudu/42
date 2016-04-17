<?php
include("connect.php");
session_start();
$_SESSION['loggued_on_user'] = "";
if ($_SESSION['privilege'] != "")
{
	include("check_key.php");
	if (check_key($_SESSION['privilege']) === true)
	{
		$sql = "DELETE FROM my_key WHERE key_id="."'".$_SESSION['privilege']."'";
		echo $sql;
		if (mysqli_query($conn, $sql))
			echo "deleted session key";
		else
			echo "issue with session key delete";
	}
	$_SESSION['privilege'] = "";
}
header("Location: index.php");
?>
