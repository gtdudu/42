<?php
include("connect.php");
session_start();

$safe_email = mysqli_real_escape_string($conn, $_POST['email']);
$safe_passwd = hash("whirlpool", mysqli_real_escape_string($conn, $_POST['passwd']));


$sql = "SELECT email, passwd, firstname, privilege FROM user WHERE email="."'".$safe_email."'";
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0)
{
	while ($row = mysqli_fetch_assoc($result))
	{
		if ($row['passwd'] === $safe_passwd)
		{
			$_SESSION['loggued_on_user'] = $row['firstname']; 
			if ($row['privilege'] == 2)
			{
				$generate = uniqid();
				$_SESSION['privilege'] = $generate;
				$sql =" INSERT INTO my_key (key_id) 
					VALUES ("."'".$generate."'".")";
				echo $sql."<br />";
				if (mysqli_query($conn, $sql))
					echo "generated protection";
				else
					echo "error".mysqli_error($conn);
			}
			else
				$_SESSION['privilege'] = "";
		}
	}
}
$link = $_COOKIE['link'];
if ($link === "")
	$link = "index.php";
header("Location: $link");

?>
