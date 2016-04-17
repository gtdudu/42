<?php

class Lannister {

	function sleepWith($v) {
		if (get_parent_class($v) !== get_parent_class($this))
			print("Let's do this." . PHP_EOL);
		else
			print("Not even if I'm drunk !" . PHP_EOL);
	}

}

?>
