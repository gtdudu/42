<?php
function auth($email, $passwd)
{
	if ($email === "" || $passwd === "")
		return false;
	$safe_email = mysqli_real_escape_string($conn, $email);
	$safe_passwd = hash("whirlpool", mysqli_real_escape_string($conn, $email));
	$sql = 'SELECT passwd FROM user WHERE email="'.$safe_email.'"';
   	$result = mysqli_query($conn, $sql);
	if (mysqli_num_rows($result) > 0)
	{
		while ($row = mysqli_fetch_assoc($result))
		{
			if ($row['passwd'] === $safe_passwd)
				return true;
		}
	}
	return false;
}

?>
