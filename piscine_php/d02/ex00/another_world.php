#!/usr/bin/php
<?php

if ($argc >= 2)
{
	$str = preg_replace("/[ \t]+/", " ", $argv[1]);
	$str = preg_replace("/(^[ \t]+)|([ \t]+$)/", "", $str);
	echo $str."\n";
}

?>
