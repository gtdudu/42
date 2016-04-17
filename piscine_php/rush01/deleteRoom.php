<?php
session_start();
require_once("includes/ManagePlayers.class.php");
require_once("includes/Game.class.php");
require_once("includes/Dice.class.php");
require_once("includes/Player.class.php");
require_once("includes/Room.class.php");
include("dbfunc.php");

$game = getGame();
if ($game != False)
{
    $game = getGame();
    if ($game->getTotOnlineRooms() >= 0)
    {
      foreach($game->getOnlineRooms() as $room)
      {
      	if ($room->getId() == $_GET['id'])
			$game->setOnlineRooms("del", $room);

      }
    }
    foreach ($game->getOnlinePlayers() as $player)
    {
        if ($player->getLogin() == $_SESSION['loggued_on_user'])
        {
            $player->setRoomId(0);
        }
    }
    updateGame($game);

      header("Location: index.php");

}
?>