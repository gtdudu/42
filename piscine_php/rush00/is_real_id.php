<?php

function is_real_id($loggued)
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
				if ($row['user_id'] == $loggued)
					return true;
			}
		}
	}
	return false;
}

?>
