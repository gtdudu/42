<?php
if ($email === "")
	return false;
$sql = "SELECT email FROM user";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0)
{
	while ($row = mysqli_fetch_assoc($result))
	{
		if ($row['email'] == $email)
			return true;
	}
}
return false;
}

?
