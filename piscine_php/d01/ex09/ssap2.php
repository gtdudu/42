#!/usr/bin/php
<?php

function isok($str)
{
	if (empty($str) && $str != "0")
		return false;
	else
		return true;
}

function ft_charalpha($c)
{
		if (($c >= "A" && $c <= "Z"))
			return true;	
		else if ($c >= "a" && $c <= "z")
			return true;
		else
			return false;
}

function ft_isalpha($s)
{
	$i = 0;
	while ($i < strlen($s))
	{
		if (ft_charalpha($s[$i]))
			$i++;
		else
			return false;
	}
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

$res_a = [];
$res_n = [];
$res_o = [];

foreach ($res as $elem)
{
	if (ft_isalpha($elem) != false)
		$res_a[] = $elem;
	else if (is_numeric($elem) != false)
		$res_n[] = $elem;
	else
		$res_o[] = $elem;
}
sort($res_a, SORT_FLAG_CASE | SORT_STRING);
sort($res_n, SORT_FLAG_CASE | SORT_STRING);
sort($res_o, SORT_FLAG_CASE | SORT_STRING);

$all = array_merge($res_a, $res_n, $res_o);
$i = 0;
$c = count($all) - 1;
foreach($all as $elem)
{
	echo $elem;
	if ($i != $c)
		echo "\n";
	$i++;
}
if ($c != -1)
	echo "\n";
?>
