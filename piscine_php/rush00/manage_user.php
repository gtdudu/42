<?php
include("deluser.php");
include("adduser.php");
include("moduser.php");
include("is_real_id.php");
include("check_key.php");
include("connect.php");
if ($_POST['firstname'] === "" || $_POST['lastname'] === "" || $_POST['email'] === "" || $_POST['passwd'] === "")
	setcookie("retry", "true");
else
{
	if ($_POST['submit'] === "delete")
		deluser($_POST['firstname'], $_POST['lastname'], $_POST['email']);
	else if ($_POST['submit'] === "modify")
	{
		$id = (int)mysqli_real_escape_string($conn, $_POST['user_id']);
		$privilege = (int)mysqli_real_escape_string($conn, $_POST['privilege']);
		
		if (is_real_id($id) === true)
		{
			echo "fkqehe";
			moduser($id, $_POST['firstname'], $_POST['lastname'], $_POST['email'], $_POST['passwd'], $privilege);
		}
	}
	else
	{
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
			setcookie("taken", "true");
		else
		{
			$privilege = mysqli_real_escape_string($conn, $_POST['privilege']);
			if ($_POST['submit'] === "add")
				adduser($_POST['firstname'], $_POST['lastname'], $_POST['email'], $_POST['passwd'], $privilege );
		}
	}
}
header("Location: adminpanel.php");
?>
