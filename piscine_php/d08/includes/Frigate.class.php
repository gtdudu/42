<?php

	class Frigate extends Ship
	{
		const	TYPE			= "Imperial_Frigate";
		const	SPEED			= 15;

		const	PP				= 10;
		const	MOVE			= 4;
		const	WIDTH			= 1;
		const	HEIGHT			= 5;
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
				echo "New Frigate Ship: ".$this->_id." instanced<br>" . PHP_EOL;
		}
						
		function		__destruct()
		{
			if (self::$verbose)
				echo "Frigate Ship: ".$this->_id." destructed<br>" . PHP_EOL;
		}
	}

?>
