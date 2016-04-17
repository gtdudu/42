<?php
session_start();
include("auth.php");
require_once("includes/ManagePlayers.class.php");
require_once("includes/Game.class.php");
require_once("includes/Dice.class.php");
require_once("includes/Player.class.php");
require_once("includes/Room.class.php");
include("dbfunc.php");

$game = getGame();
$player = $game->getPlayerObject($_SESSION['loggued_on_user']);
$game->setOnlinePlayers("del", $player);
updateGame($game);
$_SESSION['loggued_on_user'] = "";
header("Location: index.php")
?>
