#!/usr/bin/php
<?php

function isok($c)
{
	if ($c != " ")
		return true;
	else
		return false;
}

if ($argc == 2)
{
	$err = "Syntax Error\n";
	$str = str_replace(" ", "", $argv[1]);
	$i = 0;
	if ($str[0] == "-" || $str[0] == "+")
		$i++;
	$c = false;
	while ($i < strlen($str) && $c == false)
	{
	    if ($str[$i] == "*")
			$c = "*";
		else if ($str[$i] == "/")
			$c = "/";
		else if ($str[$i] == "%")
			$c = "%";
		else if ($str[$i] == "+")
			$c = "+";
		else if ($str[$i] == "-")
			$c = "-";
		$i++;
	}

	if ($c == false)
		echo $err;
	else
	{
		$str = str_replace(" ", "", $argv[1]);
		$l = strlen($argv[1]);
		$i = 0;
		if ($str[0] == "-" || $str[0] == "+")
			$i++;
		while ($str[$i] != $c)
			$i++;
		$s1 = substr($str, 0, $i);
		$s2 = substr($str, $i + 1, $l);
		$tab1 = array_filter(str_split($s1), isok);
		$tab2 = array_filter(str_split($s2), isok);
		$s1 = implode("", $tab1);
		$s2 = implode("", $tab2);
		if (is_numeric($s1) == false || is_numeric($s2) == false)
			echo $err;
		else
		{
			if ($c == "+")
				echo $s1 + $s2;
			else if ($c == "-")
				echo $s1 - $s2;
			else if ($c == "*")
				echo $s1 * $s2;
			else if ($c == "/")
				echo $s1 / $s2;
			else if ($c == "%")
				echo $s1 % $s2;
			echo "\n";
		}
	}
}
else
	echo "Incorrect Parameters\n";

?>
