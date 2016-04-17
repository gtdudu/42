<?php

class Jaime extends Lannister {

	function sleepWith($v) {
		if (get_class($v) === "Cersei" )
			print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
		else
			parent::sleepWith($v);
	}
}

?>
