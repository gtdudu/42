<?php

$map = $game->getMap();


echo '<table>';
	$i = 0;
	while ($i < Game::HEIGHT)
	{
		echo '<tr>';
		$j = 0;
		while ($j < Game::WIDTH)
		{
			if ($map[$i][$j] == 0)
			{
				echo '<td>';
				echo '<span style="width:6px; height:6px; padding: 0px;"><span>';
			}
			else if ($map[$i][$j] == 1)
			{	
				$color = "blue";
				if ($active == "player1")
				{
					echo '<td id="player1" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';">';
					echo '<a href="main.php?preset=ordre&player=1&i='.$i.'&j='.$j.'" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';"></a>';
				}
				else
				{
					echo '<td id="player1" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';">';
					echo '<span style="width:6px; height:6px; padding: 0px; background-color: '.$color.';"><span>';
				}
			}
			else if ($map[$i][$j] == 2)
			{
				$color = "red";
				if ($active == "player2")
				{
					echo '<td id="player2" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';">';
					echo '<a href="main.php?preset=ordre&player=2&i='.$i.'&j='.$j.'" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';"></a>';
				}
				else
				{
					echo '<td id="player2" style="width:6px; height:6px; padding: 0px; background-color: '.$color.';">';
					echo '<span style="width:6px; height:6px; padding: 0px; background-color: '.$color.';"><span>';
				}
			}
			else if ($map[$i][$j] == 3)
			{
				echo '<td id="obst" style="width:6px; height:6px; padding: 0px; background-color: black;">';
				echo '<span style="width:6px; height:6px; padding: 0px; background-color: black;"><span>';
			}
			echo '</td>';
			$j++;
		}
		echo '</tr>';
		$i++;
	}
echo '</table>';

?>
