<?php
function adduser($firstname, $lastname, $email, $passwd, $privilege)
{
	include("connect.php");
	session_start();
	$safe_firstname = mysqli_real_escape_string($conn, $firstname);
	$safe_lastname = mysqli_real_escape_string($conn, $lastname);
	$safe_email = mysqli_real_escape_string($conn, $email);
	$safe_passwd = hash("whirlpool", mysqli_real_escape_string($conn, $passwd));


	include("check_key.php");
	if ($privilege === NULL)
		$privilege = 1;
	if ($privilege != 1)
	{
		if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === false)
			$privilege = 1;
	}
	$sql = 'INSERT INTO user (firstname, lastname, email, passwd, privilege) VALUES ('.'"'.$safe_firstname.'", '.'"'.$safe_lastname.'", '.'"'.$safe_email.'", '.'"'.$safe_passwd.'", '.$privilege.");";
	echo $sql;
	if (!mysqli_query($conn, $sql))
		echo "There has been an error, please try again";
	else
		return $safe_firstname;
}
?>
