<?php
function getGame() {

	    if (!file_exists("../private") || !file_exists("../private/game"))
	    	return False;
        else
        {
            $str = file_get_contents("../private/game");
            $game = unserialize($str);
            return $game;
        }
}

function updateGame($tosave) {
   if (!file_exists("../private"))
        mkdir("../private");

    $str = serialize($tosave);
    file_put_contents("../private/game", $str);
   }

?>