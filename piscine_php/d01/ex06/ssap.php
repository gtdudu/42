#!/usr/bin/php
<?php

function isok($str)
{
	if (empty($str) && $str != "0")
		return false;
	else
		return true;
}

$res = [];
$i = 0;
foreach ($argv as $elem)
{
	if ($i != 0)
	{
		$tab = array_filter(explode(" ", $elem), isok);
		$res = array_merge($res, $tab);
	}
	$i++;
}
sort($res);
$i = 0;
$c = count($res) - 1;
foreach($res as $elem)
{
	echo $elem;
	if ($i != $c)
		echo "\n";
	$i++;
}
if ($c != -1)
	echo "\n";
?>
