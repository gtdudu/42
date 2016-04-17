#!/usr/bin/php
<?php
function ft_is_sort_up($tab)
{
	$i = 0;
	$l = count($tab) - 1;
	while ($i < $l)
	{
		if (strcmp($tab[$i], $tab[$i + 1]) >= 0)
			$i++;
		else
			return false;
	}
	return true;
}

function ft_is_sort_down($tab)
{
	$i = 0;
	$l = count($tab) - 1;
	while ($i < $l)
	{
		if (strcmp($tab[$i], $tab[$i + 1]) <= 0)
			$i++;
		else
			return false;
	}
	return true;
}

function ft_is_sort($tab)
{
	if (ft_is_sort_up($tab) || ft_is_sort_down($tab))
		return true;
	else
		return false;
}
?>
