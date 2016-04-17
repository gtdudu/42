<?php

	require_once("IWeapons.class.php");

	class NavalSpear implements Weapons
	{
		const			FRONT		= TRUE;
		const			REAR		= FALSE;
		const			S_SCOPE		= 30;
		const			I_SCOPE		= 60;
		const			L_SCOPE		= 90;
		const			NAME		= "Naval Spear";

		private			$_load		= 0;
		private			$_used		= FALSE;
		public static	$verbose	= FALSE;
		
		function		__construct()
		{
			if (self::$verbose)
				echo "New NavalSpear Instanced<br>" . PHP_EOL;
		}

		public function getName() { return static::NAME;}

		public	function	load_weapon($pp_spent)
		{
			$this->_load += $pp_spent;
			if ($this->_load && !$this->_used)
				return TRUE;
			else
				return FALSE;
		}

		public	function	getScope( $dice )
		{
			if ($dice >= 6)
				return self::L_SCOPE;
			else if ($dice >= 5)
				return self::I_SCOPE;
			else if ($dice >= 4)
				return self::S_SCOPE;
			else
				return (0);
		}

		public	function	check_target($coords, $map, $target_id, $scope)
		{
			$x		= $coords['x']; 
			$y		= $coords['y']; 
			$dir	= $coords['dir']; 
			$i		= 0;

			if ($dir == Game::WEST )
			{
				while (($x - $i) >= 0)
				{
					if ($map[$y][$x - $i] == $target_id && $i <= $scope)
						return array( 'h' => $y, 'w' => $x - $i);
					$i++;
				}
			}
			else if ($dir == Game::EAST )
			{
				while (($x + $i) < Game::WIDTH)
				{
					if ($map[$y][$x + $i] == $target_id && $i <= $scope)
						return array( 'h' => $y, 'w' => $x + $i);
					$i++;
				}
			}
			else if ($dir == Game::SOUTH )
			{
				while (($y + $i) < Game::HEIGHT)
				{
					echo ".";
					if ($map[$y + $i][$x] == $target_id && $i <= $scope)
						return array( 'h' => $y + $i, 'w' => $x);
					$i++;
				}
			}
			else if ($dir == Game::NORTH )
			{
				while (($y - $i) >= 0)
				{
					if ($map[$y - $i][$x] == $target_id && $i <= $scope)
						return array( 'h' => $y - $i, 'w' => $x);
					$i++;
				}
			}
			return FALSE;
		}

		public	function	shot($target_ship, $ennemi)
		{
			$shield	= $target_ship->getShield();
			$pc		= $target_ship->getPc();

			if ($shield)
				$target_ship->decShield();
			else
				$target_ship->decPc();
			
			if ($target_ship->getPc() == 0)
				return True;
	
			$this->_used = TRUE;
		}

		function		__destruct()
		{
			if (self::$verbose)
				echo "NavalSpear desctructed<br>" . PHP_EOL;
		}
	}

?>
