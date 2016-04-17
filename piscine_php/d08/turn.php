<?php
session_start();
require_once('includes/Ship.class.php');
require_once('includes/Obstacle.class.php');
require_once('includes/NavalSpear.class.php');
require_once('includes/Dice.class.php');
require_once('includes/Frigate.class.php');
require_once('includes/Player.class.php');
require_once('includes/Game.class.php');
$game = unserialize($_SESSION['save']);
$active = $game->getActiveName();
$p1 = unserialize($_SESSION['player1']);
$p2 = unserialize($_SESSION['player2']);
if (array_key_exists('ship', $_SESSION))
	$ship = unserialize($_SESSION['ship']);

$actif = $game->getActive($p1, $p2);
$game->del_ship($actif->getId(), $ship);

$coords = $ship->getCoords();
$length = $ship->getLength();
$length = ($length / 2);

if ($_POST['side'] == "left")
{
	if ($coords['dir'] == 1)
	{
		$coords['x'] = $coords['x'] - $length + 1;
		$coords['y'] = $coords['y'] + $length;
		$coords['dir'] = 8;
	}
	else if ($coords['dir'] == 2)
	{
		$coords['x'] = $coords['x'] + $length;
		$coords['y'] = $coords['y'] - $length + 1;
		$coords['dir'] = 4;
	}
	else if ($coords['dir'] == 4)
	{
		$coords['x'] = $coords['x'] - $length;
		$coords['y'] = $coords['y'] - $length;
		$coords['dir'] = 1;
	}
	else if ($coords['dir'] == 8)
	{
		$coords['x'] = $coords['x'] + $length - 1;
		$coords['y'] = $coords['y'] + $length - 1;
		$coords['dir'] = 2;
	}
}
else if ($_POST['side'] == "right")
{
	if ($coords['dir'] == 1)
	{
		$coords['x'] = $coords['x'] + $length;
		$coords['y'] = $coords['y'] + $length;
		$coords['dir'] = 4;
	}
	else if ($coords['dir'] == 2)
	{
		$coords['x'] = $coords['x'] - $length + 1;
		$coords['y'] = $coords['y'] - $length + 1;
		$coords['dir'] = 8;
	}
	else if ($coords['dir'] == 4)
	{
		$coords['x'] = $coords['x'] - $length;
		$coords['y'] = $coords['y'] + $length - 1;
		$coords['dir'] = 2;
	}
	else if ($coords['dir'] == 8)
	{
		$coords['x'] = $coords['x'] + $length - 1;
		$coords['y'] = $coords['y'] - $length;
		$coords['dir'] = 1;
	}
}
$ship->setCoords($coords['x'], $coords['y'], $coords['dir']);
$game->add_ship($actif->getId(), array($ship));
$ship->incPpspent($_POST['move']);
echo $length;



if (isset($ship))
	$currentShip = serialize($ship);
$player1 = serialize($p1);
$player2 = serialize($p2);
$save = serialize($game);
$_SESSION['save'] = $save;
$_SESSION['ship'] = $currentShip;;
$_SESSION['player1'] = $player1;
$_SESSION['player2'] = $player2;
header("Location: main.php?preset=mouvement");
?>
