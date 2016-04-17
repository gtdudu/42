#!/usr/bin/php
<?php

$path = $argv[1];
$part = explode("/", $argv[1]);
if ($part[0] !== "http:")
{
	$dir = $path;
	if (substr($part[0], 0, 4) === "www.")
		$newpath = "http://".$path;
	else
		$newpath = "http://www.".$path;
}
else
{
	$dir = $part[2];
	if (substr($part[2], 0, 4) === "www.")
		$newpath = $path;
	else
		$newpath = "http://www.".$part[2];
}
$content = file_get_contents($newpath);
preg_match_all("/<img.*(?<=src=\")(.*)\"/iUs", $content, $links);
foreach ($links[1] as $elem)
{
	$part = explode("/", $elem);
	if ($part[0] === "http:")
		$newelem = $elem;
	else
	{
		if ($part[0] !== "..")
			$newelem = $newpath."/".$elem;
		else
			exit;
	}
	$img = $part[count($part) - 1];
	@mkdir($dir);
	$handle = fopen($dir."/".$img, "w");
	$img = file_get_contents($newelem);
	fwrite($handle, $img);
	fclose($handle);
}

?>
