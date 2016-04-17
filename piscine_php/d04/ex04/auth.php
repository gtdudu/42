<?php
function auth($login, $passwd)
{
	if ($login === "" || $passwd === "")
		return false;
	if (file_exists("../private") && file_exists("../private/passwd"))
	{
		$str = file_get_contents("../private/passwd");
		$db = unserialize($str);
		foreach ($db as $account)
		{
			if ($account['login'] === $login && $account['passwd'] === hash("whirlpool", $passwd))
				return true;
		}
	}
	return false;
}
?>
