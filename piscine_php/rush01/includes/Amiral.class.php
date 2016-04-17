<?php

	class Amiral extends Ship
	{
		const	TYPE			= "Migthy Amiral Ship";
		const	SPEED			= 10;
		const 	WEAPON 			= "Naval Spear";
		const	PP				= 20;
		const	MOVE			= 4;
		const	WIDTH			= 1;
		const	HEIGHT			= 10;
		const	MAXPC			= 15;
		const 	COST 			= 1200;
	
		protected $_pc	=	5;
		
		function		__construct( $kwargs )
		{
			parent::$_i++;
			$this->_name	= $kwargs['name'];
			$this->_id		= parent::$_i;
			$this->setCoords($kwargs['x'], $kwargs['y'], $kwargs['dir']);
			$this->_weapon[] = new NavalSpear;

			if (self::$verbose)
				echo "New Amiral ship: ".$this->_id." instanced<br>" . PHP_EOL;
		}
						
		function		__destruct()
		{
			if (self::$verbose)
				echo "Amiral ship: ".$this->_id." destructed<br>" . PHP_EOL;
		}
	}

?>
