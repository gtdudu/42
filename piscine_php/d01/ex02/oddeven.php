#!/usr/bin/php
<?php
$flag = 1;
while ($flag)
{
	echo "Entrez un nombre: ";
	$buffer = fgets(STDIN);
	if ($buffer == NULL)
	{
		$flag = 0;
		echo "\n";
	}
	else
	{
		$buffer = trim($buffer, "\n");
		if (is_numeric($buffer))
		{
			if (($buffer % 2) == 0)
				echo "Le chiffre $buffer est Pair\n";
			else
				echo "Le chiffre $buffer est Impair\n";
		}
		else
		{
			echo "'$buffer'"." n'est pas un chiffre\n";
		}
	}
}
?>
