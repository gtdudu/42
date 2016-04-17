#!/usr/bin/php
<?php
if ($argc >= 2)
{
	$tab = array_filter(explode(" ", ($argv[1])));
	$i = 0;
	$c = count($tab) - 1;
	foreach ($tab as $elem)
	{
		echo $elem;
		if ($i != $c)
			echo " ";
		$i++;
	}
	if ($c != -1)
		echo "\n";
}
?>
