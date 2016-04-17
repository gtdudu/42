#!/usr/bin/php
<?php
	function ft_strcmp($a, $b)
	{
		return (strcmp($a['line'], $b['line']));
	}

	$str = file_get_contents("/var/run/utmpx", "r", NULL, 1256);
	$i = 0;
	$tab = [];
	while ($i < strlen($str))
	{
		$tab[] = unpack("a256user/a4id/a32line/ipid/itype/itime", substr($str, $i));
		$i += 628;
	}
	usort($tab, "ft_strcmp");
	date_default_timezone_set('Europe/Paris');
	foreach ($tab as $elem)
	{
		$format = "%b %e %H:%M";
		if ($elem['type'] !== 8)
			echo preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $elem['user'])."  ".preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $elem['line'])."  ".strftime($format, $elem['time'])." \n";
	}
?>
