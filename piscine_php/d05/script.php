#!/usr/bin/php
<?php

$db_name = 'db_tdurand';
$server_name = "127.0.0.1";
$username = 'root';
$passwd = 'theteam';

$conn = mysqli_connect($server_name, $username, $passwd);
if (!$conn)
	die("Co Failed :".mysqli_error($conn));

$sql = "DROP DATABASE IF EXISTS db_tdurand";
mysqli_query($conn, $sql);

if ($argc != 2)
{
	echo "need param\n";
	$flag = 0;
}

$flag = $argv[1];


$sql = implode("\n", file('ex00/ex00.sql'));
mysqli_query($conn, $sql);

$sql = "USE db_tdurand";
mysqli_query($conn, $sql);

$str = fgets(STDIN);

if ($str !== false)
{

	$i = 1;
	while ($i <= $flag)
	{
		if ($i < 10)
			$path = "ex0".$i."/"."ex0".$i.".sql";
		else
			$path = "ex".$i."/"."ex".$i.".sql";
		$sql = implode("\n", file($path));
		if (!mysqli_query($conn, $sql))
			echo "error: ".mysqli_error($conn);
		else
			echo "ex".$i."  : OK\n";
		$i++;
	}
}


?>
