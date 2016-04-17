<?php
session_start();

if (array_key_exists('loggued_on_user', $_SESSION) && $_SESSION['loggued_on_user'] && $_SESSION['loggued_on_user'] !== "")
{
	if (array_key_exists('msg', $_POST) && $_POST['msg'] && $_POST['msg'] != "")
	{
		if (!file_exists("../private/chat"))
		{

			$tab = array('login' => $_SESSION['loggued_on_user'], 'time' => time(), 'msg' => $_POST['msg']);
			$db[] = $tab;
			$str = serialize($db);
			file_put_contents("../private/chat", $str);
		}
		else
		{
			$handle = fopen("../private/chat", "r+");
			if (flock($handle, LOCK_EX | LOCK_SH))
			{
				$str = file_get_contents("../private/chat");
				$db = unserialize($str);
				$db = array_values($db);
				if (count($db) > 15)
				{		
	
					unset($db[0]);
				}
				$tab = array('login' => $_SESSION['loggued_on_user'], 'time' => time(), 'msg' => $_POST['msg']);
				$db[] = $tab; 
				$str = serialize($db);
				file_put_contents("../private/chat", $str);
				flock($handle, LOCK_UN);
			}
			fclose($handle);
		}
	}
	echo '<html>'."\n";
	echo '<head>'."\n";
	echo '<title>BLS</title>'."\n";
	echo '<script langage="javascript">top.frames["chat"].location = "chat.php";</script>'."\n";
	echo '</head>'."\n";
	echo '<body>'."\n";
	echo '<form action="speak.php" method="post">'."\n";
	echo '<input type="text" name="msg">'."\n";
	echo '<input type="submit" value="OK">'."\n";
	echo '</form>'."\n";
	echo '</body>'."\n";
	echo '</html>'."\n";
}
else
{
	echo "ERROR\n";
}
?>
