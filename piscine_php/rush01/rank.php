<?php
session_start();
require_once("includes/ManagePlayers.class.php");
require_once("includes/Game.class.php");
require_once("includes/Dice.class.php");
require_once("includes/Player.class.php");
require_once("includes/Room.class.php");
include("dbfunc.php");

$game = getGame();

include("head.php");
include("nav.php");
?>

    <!-- Page Content -->
    <div class="container">

        <div class="row">
            <div class="col-lg-12 text-center">

 <table id="rank">

<?php

if (file_exists("../private/players"))
{
	date_default_timezone_set('Europe/Paris');
	$handle = fopen("../private/players", "r");
	if ($handle && flock($handle, LOCK_EX | LOCK_SH))
	{
		echo '<tr>';
		echo '<td>Player Id</td>';
		echo '<td>Login</td>';
		echo '<td>Registered date</td>';
		echo '<td>Total game played</td>';
		echo '<td>Number of Victories</td>';
		echo '<td>Number of Defeats</td>';
		echo '</tr>';
		$str = file_get_contents("../private/players");
		$db = unserialize($str);
		foreach ($db as $player)
		{
			if (is_object($player))
			{
				echo '<tr>';
				echo '<td>'.$player->getId().'</td>';
				echo '<td>'.$player->getLogin().'</td>';
				echo '<td>'.date("H:i", $player->getRegistered()).'</td>';
				echo '<td>'.$player->getPlayedGames().'</td>';
				echo '<td>'.$player->getVictories().'</td>';
				echo '<td>'.$player->getDefeats().'</td>';
				echo '</tr>';
			}
		}
		flock($handle, LOCK_UN);
	}
	fclose($handle);
}
else
{
	?>
		<h1>Looks like this game has never been played...</h1>

	<?php
}

?>

</table>
            </div>

        </div>
        <!-- /.row -->
    </div>
        <!-- /.row -->


    <!-- /.container -->

    <!-- jQuery Version 1.11.1 -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

</body>

</html>
