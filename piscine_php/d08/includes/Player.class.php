<?php

	class Player
	{
		protected		$_id;
		protected		$_name;
		protected		$_ships;
		public static	$verbose = FALSE;

		function		__construct( $id, $name, $ships )
		{
			if (self::$verbose)
				echo "New player instanced" . PHP_EOL;
			
			$this->_id		= $id; 
			$this->_name	= $name; 
			$this->_ships	= $ships; 
		}

		public	function	getId()    { return ($this->_id);    }
		public	function	getName()  { return ($this->_name);  }
		public	function	getShips() { return ($this->_ships); }

		public	function	alive()
		{
			if (empty($this->_ships))
				return FALSE;
			else
				return TRUE;
		}

		public	function	destroy_ship($id)
		{
			foreach ($this->_ships as $key => $val)
			{
				if ($val->getId() == $id)
				{
					unset($this->_ships[$key]);
				}
			}
		}

		public function getShipObject($h, $w) {
			foreach ($this->getShips() as $elem)
			{
				$coords = $elem->getCoords();
				$dir = $coords['dir'];
				$w1 = $coords['x'];
				$h1 = $coords['y'];
				$length = $elem->getLength() + 1;
				$i = 0;
				if ($dir == 2)
				{
					while ($i < $length)
					{
						if ($h1 - $i == $h && $w1 == $w)
							return ($elem);
						$i++;
					}
				}
				else if ($dir == 1)
				{
					while ($i < $length)
					{
						if ($h1 + $i == $h && $w1 == $w)
							return ($elem);
						$i++;
					}
				}
				else if ($dir == 4)
				{
					while ($i < $length)
					{
						if ($h1 == $h && $w1 - $i == $w)
							return ($elem);
						$i++;
					}
				}
				else if ($dir == 8)
				{
					while ($i < $length)
					{
						if ($h1 == $h && $w1 + $i == $w)
							return ($elem);
						$i++;
					}
				}
			}

		}

		function		__destruct()
		{
			if (self::$verbose)
				echo "Player destructed" . PHP_EOL;
		}
	}


?>
