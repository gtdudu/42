<?php
if ($_POST['submit'] === "OK")
{
	if ($_POST['login'] === "" || $_POST['oldpw'] === "" || $_POST['newpw'] === "")
		echo "ERROR\n";
	else
	{
		if (file_exists("../private") && file_exists("../private/passwd"))
		{
			$str = file_get_contents("../private/passwd");
			$db = unserialize($str);
			$i = -1;
			foreach ($db as $account)
			{
				$i++;
				$flag = 0;
				foreach ($account as $key => $value)
				{
					if ($key === "login" && $value === $_POST['login'])
						$flag++;
					if ($key === "passwd" && $value === hash("whirlpool", $_POST['oldpw']))
						$flag++;
				}
				if ($flag == 2)
				{
					$newaccount = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['newpw']));
					$db[$i] = $newaccount;
					$str = serialize($db);
					file_put_contents("../private/passwd", $str);
					echo "OK\n";
					header("Location: index.html");
					break;
				}
			}
			if ($flag != 2)
				echo "ERROR\n";
		}
		else
			echo "ERROR\n";
	}
}
else
	echo "ERROR\n";
?>
