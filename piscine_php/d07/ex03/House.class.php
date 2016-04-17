<?php

class House {

	function introduce() {
		print('House ' . static::getHouseName() . ' of ' . static::getHouseSeat() . ' : "' . static::getHouseMotto() . '"'. PHP_EOL);
	}
}

?>
