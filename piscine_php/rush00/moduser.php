<?php
function moduser($user_id, $firstname, $lastname, $email, $passwd, $privilege)
{
	include("connect.php");
	session_start();
	$safe_firstname = mysqli_real_escape_string($conn, $firstname);
	$safe_lastname = mysqli_real_escape_string($conn, $lastname);
	$safe_email = mysqli_real_escape_string($conn, $email);
	$safe_passwd = hash("whirlpool", mysqli_real_escape_string($conn, $passwd));

	if ($_SESSION['privilege'] && check_key($_SESSION['privilege']) === false)
		$privilege = 1;
	$sql = 'UPDATE `myDB`.`user` SET firstname="'.$safe_firstname.'", lastname="'.$safe_lastname.'", email="'.$safe_email.'", passwd="'.$safe_passwd.'", privilege="'.$privilege.'" WHERE user_id='.$user_id;
	echo $sql;
	if (!mysqli_query($conn, $sql))
		echo "There has been an error, please try again".mysqli_error($conn);
	else
		echo "youuuuu";
}
?>
