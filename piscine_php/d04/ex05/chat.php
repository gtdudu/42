<?php
if (file_exists("../private/chat"))
{
	date_default_timezone_set('Europe/Paris');
	$handle = fopen("../private/chat", "r");
	if ($handle && flock($handle, LOCK_EX | LOCK_SH))
	{
		$str = file_get_contents("../private/chat");
		$db = unserialize($str);
		foreach ($db as $tab)
		{
			echo "[".date("H:i", $tab['time'])."] ";
			echo "<b>".$tab['login']."</b>: ";
			echo $tab['msg']."<br />"."\n";
		}
		flock($handle, LOCK_UN);
	}
	fclose($handle);
}
?>
