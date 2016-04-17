#!/usr/bin/php
<?php
function check($match)
{
	$flag = 0;
	if ($match[2] >= 1 && $match[2] <= 31)
		$flag++;
	if ($match[4] >= 0 && $match[4] <= 2100)
		$flag++;
	if ($match[5] >= 0 && $match[5] <= 23)
		$flag++;
	if ($match[6] >= 0 && $match[6] <= 59)
		$flag++;
	if ($match[7] >= 0 && $match[7] <= 59)
		$flag++;
	if ($flag == 5)
		return true;
	else
		return false;
}

if ($argc == 2)
{
	$day = '^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)';
	$nday = ' ([\d]+)';
	$month = ' ([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre)';
	$year= ' ([\d]{4})';
	$h = ' ([\d]{2})';
	$m = ':([\d]{2})';
	$s = ':([\d]{2})$';
	preg_match("/".$day.$nday.$month.$year.$h.$m.$s."/", $argv[1], $match);
	date_default_timezone_set('UTC');
	if ($match && count($match) == 8 && check($match) == true)
	{
		if ($match[3] == "Janvier" || $match[3] == "janvier")
			$month = 1;
		else if ($match[3] == "Fevrier" || $match[3] == "fevrier")
			$month = 2;
		else if ($match[3] == "Mars" || $match[3] == "mars")
			$month = 3;
		else if ($match[3] == "Avril" || $match[3] == "avril")
			$month = 4;
		else if ($match[3] == "Mai" || $match[3] == "mai")
			$month = 5;
		else if ($match[3] == "Juin" || $match[3] == "juin")
			$month = 6;
		else if ($match[3] == "Juillet" || $match[3] == "juillet")
			$month = 7;
		else if ($match[3] == "Aout" || $match[3] == "aout")
			$month = 8;
		else if ($match[3] == "Septembre" || $match[3] == "septembre")
			$month = 9;
		else if ($match[3] == "Octobre" || $match[3] == "octobre")
			$month = 10;
		else if ($match[3] == "Novembre" || $match[3] == "novembre")
			$month = 11;
		else if ($match[3] == "Decembre" || $match[3] == "decembre")
			$month = 12;
		echo mktime($match[5], $match[6], $match[7], $month, $match[2], $match[4], 1)."\n";
	}
	else
		echo "Wrong Format\n";
}
?>
