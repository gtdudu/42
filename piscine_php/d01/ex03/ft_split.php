<?php

function isok($str)
{
	if (empty($str) && $str != "0")
		return false;
	else
		return true;
}

function ft_split($str)
{
	$tab = explode(" ", $str);
	$subres = array_filter($tab, isok);
	sort($subres, SORT_STRING);
	$res = array_values($subres);
	return $res;
}
?>
