<?php
session_start();
if (file_exists("../private/chat"))
{
	date_default_timezone_set('Europe/Paris');
	$handle = fopen("../private/chat", "r");
	if ($handle && flock($handle, LOCK_EX | LOCK_SH))
	{
		$str = file_get_contents("../private/chat");
		$db = unserialize($str);
		if (count($db) > 4)
		{
			unset($db[0]['login']);
			unset($db[0]['msg']);
			unset($db[0]['time']);
			unset($db[0]);
		}
		foreach ($db as $tab)
		{
			?>
			<p>
			<?php
			echo "[".date("H:i", $tab['time'])."] ";
			echo "<b>".$tab['login']."</b>: ";
			echo $tab['msg'];
			?>
			</p>

			<?php
		}
		flock($handle, LOCK_UN);
	}
	fclose($handle);
}
?>
