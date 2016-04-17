<?php
function deluser($firstname, $lastname, $email)
{
	include("connect.php");
	include("check_key.php");
	session_start();
	if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === true)
	{
		$safe_firstname = mysqli_real_escape_string($conn, $firstname);
		$safe_lastname = mysqli_real_escape_string($conn, $lastname);
		$safe_email = mysqli_real_escape_string($conn, $email);
		$sql = "DELETE FROM `myDB`.`user` WHERE firstname="."'".$safe_firstname."' AND lastname="."'".$safe_lastname."' AND  email="."'".$safe_email."'";
		if (!mysqli_query($conn, $sql))
			echo "There has been an error, please try again";
		else
			header("Location: admipanel.php");
	}
}
?>
