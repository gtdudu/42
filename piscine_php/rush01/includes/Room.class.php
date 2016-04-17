<?php

class Room	{

	const			NORTH		= 1;
	const			SOUTH		= 2;
	const			EAST		= 4;
	const			WEST		= 8;
	const 			MAXPLAYER = 2;
	const 			HEIGHT = 100;
	const 			WIDTH= 150;
	protected 		$_name;
	protected 		$_createdBy;
	protected		$_id;		
	protected 		$_mode;
	protected		$_map;
	protected		$_playerLimit = 2;
	protected		$_fleetValue = 0;
	protected		$_activePlayer = 0;

	public static	$verbose 		= FALSE;

	use managePlayers;

	function			__construct()
	{
		if (self::$verbose)
			echo "New Game instanced" . PHP_EOL;
		$this->initMap();
	}

	public	function	getId()   				{ return ($this->_id);   				 }
	public	function	getName()  				{ return ($this->_name); 				 }
	public	function	getCreatedBy()  		{ return ($this->_createdBy); 			 }
	public	function	getMode()  				{ return ($this->_mode); 				 }
	public	function	getPlayerLimit()  		{ return ($this->_playerLimit); 		 }
	public	function	getFleetValue()  		{ return ($this->_fleetValue); 			 }
	public	function	getMap()  				{	return ($this->_map); 				 }
	public	function	getActivePlayer()  		{	return ($this->_activePlayer); 		 }

	public 	function 	setId($id) {
		$this->_id = $id;
	}

	public 	function 	setActivePlayer($player) {
		$this->_activePlayer = $player;
	}

	public 	function 	setCreatedBy($id) {
		$this->_createdBy = $id;
	}

	public 	function 	setName($n) {
		$this->_name = $n;
	}

	public 	function 	setMode($mode) {
		$this->_mode = $mode;
	}

	public 	function 	setPlayerLimit($limit) {
		$this->_playerLimit = $limit;
	}

	public 	function 	setFleetValue($limit) {
		$this->_fleetValue = $limit;
	}

	public 	function 	setMap($x, $y, $css) {

		$this->_map[$y][$x] = $css;
	}

	public 	function 	setDupMap($map) {
		$this->_map = $map;
	}

	private		function		initMap()
	{
		$this->_map = array(array());
		for ($y = 0; $y < 100; $y++)
		{
			for ($x = 0; $x < 150; $x++)
			{
				$this->_map[$y][$x] = -1;
			}
		}
		if (self::$verbose)
			echo "Map init" . PHP_EOL;
	}

		public function		add_ship( $player_id, $ships )
		{
			
			foreach ($ships as $ship)
			{
				$coords = $ship->getCoords();
				$y		= $coords['y'];
				$x		= $coords['x'];
				$dir	= $coords['dir'];
				$i		= 0;

				if ($dir == self::NORTH)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y + $i][$x] = $player_id;
						$i++;
					}
				}
				else if ($dir == self::SOUTH)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y - $i][$x] = $player_id;
						$i++;
					}
				}
				else if ($dir == self::EAST)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y][$x - $i] = $player_id;
						$i++;
					}
				}
				else if ($dir == self::WEST)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y][$x + $i] = $player_id;
						$i++;
					}
				}
			}
		}


		public function		__toString()
		{
			$return	= "";
			$i		= 0;

			while ($i < Game::HEIGHT)
			{
				$j = 0;
				while ($j < Game::WIDTH)
				{
					$return .= $this->_map[$i][$j];
					$j++;
				}
				$return .= "<br>";
				$i++;
			}
			return ($return);
		}

		function			__destruct()
		{
			if (self::$verbose)
				echo "Game destructed" . PHP_EOL;
		}
	}

	?>
