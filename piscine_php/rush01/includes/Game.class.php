<?php

	class Game
	{
		protected		$_name					= "Rush of the death";
		protected		$_totPlayers				= 0;
		protected		$_totGames				= 0;
		protected		$_totOnlineRooms		= 0;
		protected		$_onlineRooms			= array();
		public static	$verbose 				= FALSE;


		use managePlayers;


		function		__construct()
		{
			if (self::$verbose)
				echo "New player instanced" . PHP_EOL;
		}

		function		__destruct()
		{
			if (self::$verbose)
				echo "Player destructed" . PHP_EOL;
		}



//GETer
		public	function	getName()  			{ return ($this->_name);  			}
		public	function	getTotPlayers()		{ return ($this->_totPlayers);  	}
		public	function	getTotGames()		{ return ($this->_totGames);  		}
		public	function	getTotOnlineRooms()	{ return ($this->_totOnlineRooms);  }
		public	function	getOnlineRooms() 	{ return ($this->_onlineRooms);		}

//SETer
		public function 	setTotPlayers( $nb ){
			$this->_totPlayers = $this->getTotPlayers() + $nb;
		}

		public function 	setTotGames( $nb ){
			$this->_totGames = $this->getTotGames() + $nb;
		}
		
		public function 	setTotOnlineRooms( $method, $nb ){
		if ($method == "inc")
			$this->_totOnlineRooms = $this->getTotOnlineRooms() + $nb;
		else if ($method == "dec")
			$this->_totOnlineRooms = $this->getTotOnlineRooms() - $nb;
		}

		public function 	setOnlineRooms($method, $p) {
			if ($method === "add")
			{
				$this->_onlineRooms[] = $p;
				$this->setTotOnlineRooms("inc", 1);
			}
			if ($method === "del")
			{
				$c = 0;
				foreach ($this->getOnlineRooms() as $room)
				{
					if ($room->getId() == $p->getId())
					{
						unset($this->_onlineRooms[$c]);
						$this->setTotOnlineRooms("dec", 1);
					}
					$c++;
				}
			}	
		}

	public function 	getRoomObject($id) {
			foreach ($this->getOnlineRooms() as $room)
			{
				if ($room->getId() == $id)
				{
					return $room;
				}
			}
			return False;
	}
	}


?>
