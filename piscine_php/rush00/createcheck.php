<?php
if ($_POST['firstname'] === "" || $_POST['lastname'] === "" || $_POST['email'] === "" || $_POST['passwd'] === "")
{
	setcookie("retry", "true");
	header("Location: index.php#openModal");
}
else
{
	include("connect.php");
	$email = mysqli_real_escape_string($conn, $_POST['email']);
	if ($email === "")
		return false;
	$sql = "SELECT email FROM user";
	$result = mysqli_query($conn, $sql);
	$flag = 0;

	if (mysqli_num_rows($result) > 0)
	{
		while ($row = mysqli_fetch_assoc($result))
		{
			if ($row['email'] === $email)
				$flag = 1;
		}
	}
	if ($flag == 1)
	{
		setcookie("taken", "true");
		header("Location: index.php#openModal");
	}
	else
	{
		include("adduser.php");
		include("check_key.php");
		$tmp = adduser($_POST['firstname'], $_POST['lastname'], $_POST['email'], $_POST['passwd'], NULL);
		$_SESSION['loggued_on_user'] = $tmp;
		if (check_key($_SESSION['privilege']) === false)
			$_SESSION['privilege'] = "";
		header("Location: index.php");
	}
}
?>

