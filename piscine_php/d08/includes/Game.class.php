<?php

	class Game
	{
		const			NAME		= "Awesome Starships Battles In The Dark Grim Future Of The Grim Dark 41st Millenium";
		const			WIDTH		= 150;
		const			HEIGHT		= 100;
		const			NORTH		= 1;
		const			SOUTH		= 2;
		const			EAST		= 4;
		const			WEST		= 8;
		private			$_map;
		private			$_active		= "player2";
		public static	$verbose	= False;

		use Dice;

		function			__construct()
		{
			if (self::$verbose)
				echo "New Game instanced" . PHP_EOL;
			$this->init_map();
		}

		public function getActiveName() { return $this->_active;}

		public function getActive($p1, $p2) { 
			if ($this->_active == "player1")
				return  $p1;
			else
				return  $p2;
		}

		public function getInactive($p1, $p2) { 
			if ($this->_active == "player2")
				return  $p1;
			else
				return  $p2;
		}

		public function invertActive() { 
			if ($this->getActiveName() == "player2")
				$this->_active = "player1";
			else
				$this->_active = "player2";
		}

		public		function		looser($p1, $p2)
		{
			$i = 0;
			foreach ( $p1->getShips() as $e )
				$i++;
			if (!$i)
				return (1);
			$i = 0;
			foreach ( $p2->getShips() as $e )
				$i++;
			if (!$i)
				return (2);
			return (0);
		}

		private		function		init_map()
		{
			$i = 0;
			while ($i < self::HEIGHT)
			{
				$j = 0;
				while ($j < self::WIDTH)
				{
					$this->_map[$i][$j] = 0;
					$j++;
				}
				$i++;
			}
			if (self::$verbose)
				echo "Map init" . PHP_EOL;
		}

		public function		getMap() { return ($this->_map); }


		public		function		add_player( $kwargs )
		{
			return ( new Player( $kwargs['id'], $kwargs['name'], $kwargs['ships'] ));
		}	


		/*
		 * ID DU JOUER + TABLEAU DE TABLEAU de bateau
		 * */
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

		public function		del_ship($player_id, $ship )
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
						$this->_map[$y + $i][$x] = 0;
						$i++;
					}
				}
				else if ($dir == self::SOUTH)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y - $i][$x] = 0;
						$i++;
					}
				}
				else if ($dir == self::EAST)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y][$x - $i] = 0;
						$i++;
					}
				}
				else if ($dir == self::WEST)
				{
					while ($i < $ship->getLength())
					{
						$this->_map[$y][$x + $i] = 0;
						$i++;
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
