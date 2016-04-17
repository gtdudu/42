#!/usr/bin/php
<?php
$i = 0;
foreach($argv as $elem)
{
	if ($i != 0)
		echo $elem."\n";
	$i++;
	
}
?>
