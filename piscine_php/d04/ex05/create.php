<?php
if ($_POST['submit'] === "OK")
{
	if ($_POST['login'] === "" || $_POST['passwd'] === "")
		echo "ERROR\n";
	else
	{
		if (!file_exists("../private"))
			mkdir("../private");
		if (!file_exists("../private/passwd"))
		{
			$account = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
			$db[] = $account;
			$str = serialize($db);
			file_put_contents("../private/passwd", $str);
			echo "OK\n";
			header("Location: index.html"); 
		}
		else
		{
			$str = file_get_contents("../private/passwd");
			$db = unserialize($str);
			$flag = 0;
			foreach ($db as $account)
			{
				foreach ($account as $key => $value)
				{
					if ($key === "login" && $value === $_POST['login'])
						$flag = 1;
				}
			}
			if ($flag == 1)
				echo "ERROR\n";
			else
			{
				$account = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
				$db[] = $account;
				$str = serialize($db);
				file_put_contents("../private/passwd", $str);
				echo "OK\n";
				header("Location: index.html"); 
			}
		}
	}
}
else
	echo "ERROR\n";
?>
