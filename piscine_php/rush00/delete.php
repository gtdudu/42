<?php
include("connect.php");
session_start();
$name = $_SESSION['loggued_on_user'];
$sql = "DELETE FROM user WHERE firstname="."'".$name."'";
if (mysqli_query($conn, $sql))
	echo "deleted";
else
	echo "pourauoi ca marche pas fils de chien";

header("Location: deco.php");
?>
