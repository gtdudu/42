#!/usr/bin/php
<?php

if ($argc >= 3)
{
	$needle = $argv[1];
	$i = 0;
	$flag = 0;

	foreach($argv as $elem)
	{
		if ($i >= 2)
		{
			$tab = explode(":", $elem);
			if ($tab[0] == $needle)
			{
				$tmp = $tab[1];
				$flag = 1;
			}
		}
		$i++;
	}
	if ($flag == 1)
		echo $tmp."\n";
}

?>
