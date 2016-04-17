<?php
function check_key($key)
{
	include("connect.php");
	$sql = "SELECT key_id FROM my_key";
	$result = mysqli_query($conn, $sql);
	if ($result === false)
		return false;
	while ($row = mysqli_fetch_assoc($result))
	{
		if ($row['key_id'] === $key)
			return true;
	}
	return false;
}
?>
