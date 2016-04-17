#!/usr/bin/php
<?php

if ($argc >= 2)
{
	$line = @file_get_contents($argv[1]);
	preg_match_all("/<[aA][^>]*>*(.*)<\/[aA]>/isU", $line, $match);
	foreach ($match[0] as $elem)
	{
		$cpy = $elem;
		$i = 0;
		while ($i < strlen($cpy))
		{
			if ($cpy[$i] == "t" || $cpy[$i] == "T")
			{
				$j = $i;
				while ($j < strlen($cpy) && $cpy[$j] != "\"")
					$j++;
				$str = substr($cpy, $i, ($j - $i + 1));
				$str = preg_replace("/[ \t]+/", "", $str);
				$str = strtoupper($str);
				if ($str === "TITLE=\"")
				{
					$j++;
					while ($j < strlen($cpy) && $cpy[$j] != "\"")
					{
						$cpy[$j] = strtoupper($cpy[$j]);
						$j++;
					}
				}
			}	
			$i++;
		}
		$i = 0;
		while ($i < strlen($cpy))
		{
			if ($cpy[$i] == ">")
			{
				$j = $i + 1;
				while ($j < strlen($cpy) && $cpy[$j] != "<")
				{
					$cpy[$j] = strtoupper($cpy[$j]);
					$j++;
				}	
			}	
			$i++;
		}
	
		$line = str_replace($elem, $cpy, $line);
	}
	echo $line;
}

?>
