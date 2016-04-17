<?php
session_start();
require_once('includes/Ship.class.php');
require_once('includes/Obstacle.class.php');
require_once('includes/NavalSpear.class.php');
require_once('includes/Dice.class.php');
require_once('includes/Frigate.class.php');
require_once('includes/Player.class.php');
require_once('includes/Game.class.php');
$currentShip;
$currentpp;
$game = unserialize($_SESSION['save']);
$active = $game->getActiveName();
$p1 = unserialize($_SESSION['player1']);
$p2 = unserialize($_SESSION['player2']);
if (array_key_exists('ship', $_SESSION))
	$ship = unserialize($_SESSION['ship']);
if (array_key_exists('pp', $_SESSION))
	$pp = unserialize($_SESSION['pp']);
function err($p) {
	if ($p != "select" && $p != "ordre" && $p != "mouvement" && $p != "tir")
		throw new Exception('On change pas le preset ! C est deja suffisament complique comme ca !');
	return True;
}
?>
<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
	<link rel="stylesheet" href="css/style.css">
</head>
	<body>
		<div id="content">
			<div id="box">
<?php

	echo '<h1>'.Game::NAME.'</h1>';
include('map.php');
echo "<br />";
echo "<br />";
if (array_key_exists('preset', $_GET))
{
	try {
		err($_GET['preset']);
	} catch (Exception $e) {
		echo 'Exception recue : '. $e->getMessage() . "\n";
		echo '<a href="index.php">Get ready for a new game</a>';
	}
	if ($_GET['preset'] === 'select')
		include('select.php');
	if ($_GET['preset'] === 'ordre')
	{
		if (array_key_exists('i', $_GET))
			$h = $_GET['i'];
		if (array_key_exists('j', $_GET))
			$w = $_GET['j'];
		if ($active == "player1")
			$ship = $p1->getShipObject($h, $w);
		else
			$ship = $p2->getShipObject($h, $w);
		include('ordre.php');
	}
	if ($_GET['preset'] === 'mouvement')
		include('mouvement.php');
	if ($_GET['preset'] === 'tir')
		include('tir.php');
}

if (isset($ship))
{
	$currentShip = serialize($ship);
	$_SESSION['ship'] = $currentShip;
}

if (isset($pp))
{
	$currentpp = serialize($pp);
	$_SESSION['pp'] = $currentpp;
}
$player1 = serialize($p1);
$player2 = serialize($p2);
$save = serialize($game);
$_SESSION['save'] = $save;
$_SESSION['player1'] = $player1;
$_SESSION['player2'] = $player2;
?>
			</div>
		</div>
	</body>
</html>
