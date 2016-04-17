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
include("head.php");
include("nav.php");
if (array_key_exists('id', $_GET))
    $roomId = $_GET['id'];
$game = getGame();
?>

    <!-- Page Content -->
    <div id="play" class="container-fluid">
            <div class="col-md-6 text-center">

 
<?php

if (array_key_exists('loggued_on_user', $_SESSION) && $_SESSION['loggued_on_user'] != "")
{
    $room = $game->getRoomObject($roomId);  
    echo '<h1>'.$room->getName().'</h1>';
    include("printMap.php");
}

?>

        </div>
            <div id="info" class="col-md-6 text-center">
                <?php
                include("stat.php")
                ?>
        <!-- /.row -->
            </div>
    </div>


<script>

var phase = "select";
var selected;
var roomId;

var x;
var y;

var count = 0;
if (phase == "select")
{
    $( "body" ).on( "click", "span", function() {
    var cl = $(this).attr("class");

    selected = $(this).attr("id");
    newdiv = document.createElement("div");
    newdiv.innerHTML = selected + " selected ! Click on the map to choose it s position.<br /><br />";
    info = document.getElementById("info");
    if (selected != "")
    {
        child = document.getElementById("info").firstChild;
          document.getElementById("info").removeChild(child);
    }
    document.getElementById("info").insertBefore(newdiv, info.firstChild);  
    console.log(selected);
    });

    $( "body" ).on( "click", "td", function() {
        var id = $(this).attr("id");
        var coord = id.split('/');
        roomId = coord[0];
        x = coord[1];
        y = coord[2];
        var cl = $(this).attr("class");

        if (cl == "empty" && selected != null)
        {
          $.getJSON('engine.php', {'roomId': roomId, 'x': y, 'y': x, 'class': cl, 'phase': phase, 'selected': selected}, function(e) {
            console.log('Result from PHP: ' + e.result);

            });
        }

            console.log(id);
            console.log(cl);
            console.log(x);
            console.log(y);
            console.log(roomId);
            console.log(selected);
         
    });
}
</script>
    <!-- jQuery Version 1.11.1 -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

</body>

</html>
