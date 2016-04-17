<?php

function is_user($loggued)
{
	include("connect.php");
	if (isset($loggued))
	{
		$sql = "SELECT * FROM user";
		$request = mysqli_query($conn, $sql);
		if (isset($request))
		{
			while ($row = mysqli_fetch_assoc($request))
			{
				if ($row['firstname'] === $loggued)
					return $row['user_id'];
			}
		}
	}
	return false;
}

?>
