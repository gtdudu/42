<?php
	class Obstacle extends Ship
	{
		const	TYPE			= "Asteroides";
		const	SPEED			= 15;

		const	PP				= 10;
		const	MOVE			= 4;
		const	WIDTH			= 1;
		const	HEIGHT			= 20;
		const	MAXPC			= 5;
	
		protected $_pc	=	5;
		
		function		__construct( $kwargs )
		{
			parent::$_i++;
			$this->_name	= $kwargs['name'];
			$this->_id		= parent::$_i;
			$this->setCoords($kwargs['x'], $kwargs['y'], $kwargs['dir']);
			$this->_weapon[] = new NavalSpear;

			if (self::$verbose)
				echo "New Asteroides: ".$this->_id." instanced<br>" . PHP_EOL;
		}
						
		function		__destruct()
		{
			if (self::$verbose)
				echo "Asteroides: ".$this->_id." destructed<br>" . PHP_EOL;
		}
	}
?>
