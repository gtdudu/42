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

$roomId = $_GET['roomId'];
$x = $_GET['x'];
$y = $_GET['y'];
$class = $_GET['class'];
$selected = $_GET['selected'];
$phase = $_GET['phase'];

$room = $game->getRoomObject($roomId);
$player = $room->getActivePlayer();
if ($phase == "select" && $class == "empty")
{
	if ($selected == "frigate")
		$ship =  new Frigate(array ('name' => $class, 'x' => $x, 'y' => $y, 'dir' => Room::NORTH));
	if ($selected == "drone")
		$ship =  new Drone(array ('name' => $class, 'x' => $x, 'y' => $y, 'dir' => Room::NORTH));
	if ($selected == "Amiral")
		$ship =  new Amiral(array ('name' => $class, 'x' => $x, 'y' => $y, 'dir' => Room::NORTH));
	$player->setFleet("add", $ship);
	$room->add_ship($player->getId(), $player->getFleet());
	updateGame($game);
}
echo json_encode(array("result" => $player->getId()));


?>