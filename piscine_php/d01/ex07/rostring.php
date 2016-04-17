#!/usr/bin/php
<?php

function isok($str)
{
	if (empty($str) && $str != "0")
		return false;
	else
		return true;
}

if ($argc >= 2)
{
	$tab = array_filter(explode(" ", $argv[1]), isok);
	$tab = array_values($tab);
	$l = count($tab);
	if ($l != 0)
	{
		if ($l >= 2)
		{
			$i = 0;
			foreach($tab as $elem)
			{
				if ($i == 0)
					$first = $elem;
				if ($i > 0)
				{
					$tab[$i - 1] = $elem;
				}
				if ($i == $l - 1)
					$tab[$i] = $first;
				$i++;
			}

		}
	}
	$i = 0;
	foreach ($tab as $elem)
	{
		echo $elem;
		if ($i != ($l - 1))
			echo " ";
		$i++;
	}
	echo "\n";
}
?>
