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
if ($game == False)
{
    $game = new Game;
    updateGame($game);
}

if (array_key_exists('login', $_POST) && auth($_POST['login'], $_POST['passwd']) == true)
{
    $_SESSION['loggued_on_user'] = $_POST['login'];

    if (file_exists("../private/players"))
    {
        $flag = 0;
        date_default_timezone_set('Europe/Paris');
        $handle = fopen("../private/players", "r");
        if ($handle && flock($handle, LOCK_EX | LOCK_SH))
        {
            $str = file_get_contents("../private/players");
            $db = unserialize($str);
            foreach ($db as $player)
            {
                if (is_object($player) && $player->getLogin() == $_SESSION['loggued_on_user'] && $flag == 0)
                {
                    $flag = 1;
                    $game->setOnlinePlayers("add", $player);
                    updateGame($game);
                }
            }
            flock($handle, LOCK_UN);
        }
        fclose($handle);
 
    }

}

if (array_key_exists('maxPlayer', $_POST) && array_key_exists('mode', $_POST) && array_key_exists('fleetLimit', $_POST) && array_key_exists('roomName', $_POST))
{

    $player = $game->getPlayerObject($_SESSION['loggued_on_user']);
    if ($player->getRoomId() == 0)
    {
        $room = new Room;        
        $room->setName($_POST['roomName']);
        $room->setFleetValue($_POST['fleetLimit']);
        $room->setMode($_POST['mode']);
        $room->setPlayerLimit($_POST['maxPlayer']);
        $room->setId($game->getTotOnlineRooms() + 1);
        $room->setCreatedBy($_SESSION['loggued_on_user']);
        $room->setActivePlayer($_SESSION['loggued_on_user']);
        $game->setOnlineRooms('add', $room);
        $player->setRoomId($room->getId());
        updateGame($game);
    }
    else
        echo 'Each player can only create one room';
}

    include("head.php");
    include("nav.php");

    include("content.php");

?>


    <!-- /.container -->

    <!-- jQuery Version 1.11.1 -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

</body>

</html>