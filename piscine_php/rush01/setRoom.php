<?php
session_start();

include("auth.php");
require_once("includes/ManagePlayers.class.php");
require_once("includes/Game.class.php");
require_once("includes/Dice.class.php");
require_once("includes/Player.class.php");
require_once("includes/Room.class.php");
require("includes/Ship.class.php");
require("includes/Frigate.class.php");
require("includes/Drone.class.php");
require("includes/Amiral.class.php");
require('includes/NavalSpear.class.php');
include("dbfunc.php");
$game = getGame();

if (array_key_exists('id', $_GET))
    $roomId = $_GET['id'];

$room = $game->getRoomObject($roomId);
if ($room->getTotOnlinePlayers() < $room->getPlayerLimit())
{
	$player = $game->getPlayerObject($_SESSION['loggued_on_user']);
	if ($room->getActivePlayer() == 0)
		$room->setActivePlayer($player);
	$room->setOnlinePlayers("add", $player);
	updateGame($game);

}
$path = "Location: play.php?id=".$room->getId();
header($path);

?>