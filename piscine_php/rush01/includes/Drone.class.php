<?php

	class Drone extends Ship
	{
		const	TYPE			= "Lousy drone";
		const	SPEED			= 25;
		const 	WEAPON 			= "Naval Spear";
		const	PP				= 5;
		const	MOVE			= 4;
		const	WIDTH			= 1;
		const	HEIGHT			= 4;
		const	MAXPC			= 2;
		const 	COST 			= 300;
	
		protected $_pc	=	5;
		
		function		__construct( $kwargs )
		{
			parent::$_i++;
			$this->_name	= $kwargs['name'];
			$this->_id		= parent::$_i;
			$this->setCoords($kwargs['x'], $kwargs['y'], $kwargs['dir']);
			$this->_weapon[] = new NavalSpear;

			if (self::$verbose)
				echo "New drone ship: ".$this->_id." instanced<br>" . PHP_EOL;
		}
						
		function		__destruct()
		{
			if (self::$verbose)
				echo "drone ship: ".$this->_id." destructed<br>" . PHP_EOL;
		}
	}

?>
