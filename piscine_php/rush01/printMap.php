<?php

$map = $room->getMap();
$RoomId = $room->getId();
$player = $room->getActivePlayer();
$active = "player2";
echo $player->getId();
echo '<table>';
	$i = 0;
	while ($i < Room::HEIGHT)
	{
		echo '<tr>';
		$j = 0;
		while ($j < Room::WIDTH)
		{

			if ($map[$i][$j] == $player->getId())
				echo '<td id="'.$roomId.'/'.$i.'/'.$j.'" class="player1" style="width:6px; height:6px; padding: 0px; background-color: red;"></td>';
			else if ($map[$i][$j] == -1)
				echo '<td id="'.$roomId.'/'.$i.'/'.$j.'" class="empty"><span style="width:6px; height:6px; padding: 0px;"><span></td>';
			$j++;
		}
		echo '</tr>';
		$i++;
	}
echo '</table>';

?>
