#!/usr/bin/php
<?php

if ($argc == 4)
{
	if (trim($argv[2]) == "+")
		echo $argv[1] + $argv[3];
	else if (trim($argv[2]) == "-")
		echo $argv[1] - $argv[3];
	else if (trim($argv[2]) == "*")
		echo $argv[1] * $argv[3];
	else if (trim($argv[2]) == "/")
		echo $argv[1] / $argv[3];
	else if (trim($argv[2]) == "%")
		echo $argv[1] % $argv[3];
	echo "\n";
}
else
	echo "Incorrect Parameters\n";

?>
