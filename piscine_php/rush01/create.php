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
$flag = 0;

    include("head.php");
    include("nav.php");
?>
   <div >
    </div>
    <!-- Page Content -->
    <div class="container">

        <div class="row">
            <div class="col-lg-12 text-center">

 
<?php
if (array_key_exists('submit', $_POST) && $_POST['submit'] == "OK")
{
    if ($_POST['login'] === "" || $_POST['passwd'] === "")
        echo "ERROR\n";
    else
    {                                                                   //MANAGING PASSWORD DATABASE
        if (!file_exists("../private"))
            mkdir("../private");
        if (!file_exists("../private/passwd"))
        {
            $account = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
            $db[] = $account;
            $str = serialize($db);
            file_put_contents("../private/passwd", $str);
            echo "OK\n";
        }
        else
        {
            $str = file_get_contents("../private/passwd");
            $db = unserialize($str);
            $flag = 0;
            foreach ($db as $account)
            {
                foreach ($account as $key => $value)
                {
                    if ($key === "login" && $value === $_POST['login'])
                        $flag = 1;
                }
            }
            if ($flag == 1)
                echo "Someone alreadly registered under this name.\n";
            else
            {
                $account = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
                $db[] = $account;
                $str = serialize($db);
                file_put_contents("../private/passwd", $str);
                echo "OK\n";

                                                                                //MANAGING PLAYERS DATABASE            }
             }
        }
    }
    if ($flag != 1)
    {
        $player = new Player;
        $player->setId($game->getTotPlayers());
        $player->setLogin($_POST['login']);
        $player->setRegistered(time());
        $game->setTotPlayers(1);

        updateGame($game);
  
        date_default_timezone_set('Europe/Paris');
        if (!file_exists("../private/players"))
        {
            //NEED TO CREATE OBJECT PLAYER HERE INSTEAD OF JUST ADDING THE LOGIN

            $dbp[] = $player;
            $str = serialize($dbp);
            file_put_contents("../private/players", $str);
            echo "OK\n";
        }
        else
        {
            $handle = fopen("../private/players", "r");
            if ($handle && flock($handle, LOCK_EX | LOCK_SH))
            {
                $str = file_get_contents("../private/players");
                $dbp = unserialize($str);

                $dbp[] = $player;                      
                $str = serialize($dbp);
                file_put_contents("../private/players", $str);
                flock($handle, LOCK_UN);
                echo "OK\n";
            }
            fclose($handle);
        }
    }

     header("Location: index.php"); 

}
else
{
	?>

            <form action="create.php" method="post">
                Identifiant: <input type="text" name="login" />
                <br />
                Mot de passe: <input type="text" name="passwd" />
                <input type="submit" name="submit" value="OK">
            </form>

	<?php
}
?>


            </div>

        </div>
        <!-- /.row -->
    </div>

    </div>
        <!-- /.row -->


    <!-- /.container -->

    <!-- jQuery Version 1.11.1 -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

</body>

</html>
