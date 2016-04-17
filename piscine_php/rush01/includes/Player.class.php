<?php

	class Player {
		protected		$_id;
		protected		$_login;
		protected		$_registered;
		protected		$_roomId		= 0;
		protected		$_playedGames	= 0;
		protected		$_victories 	= 0;
		protected		$_defeats 		= 0;
		protected		$_totShips		= 0;
		protected		$_fleet 		= array();
		public static	$verbose 		= FALSE;


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

		use dice;

//METHODE GET
		public	function	getId()   			{ return ($this->_id);   		 }
		public	function	getLogin()  		{ return ($this->_login); 		 }
		public	function	getRegistered()  	{ return ($this->_registered);   }
		public	function	getRoomId()  		{ return ($this->_roomId);  	 }
		public	function	getPlayedGames()  	{ return ($this->_playedGames);  }
		public	function	getVictories()  	{ return ($this->_victories);  	 }
		public	function	getDefeats() 		{ return ($this->_defeats); 	 }
		public 	function 	getTotShips()		{ return ($this->_totShips); 	 }
		public	function	getFleet() 			{ return ($this->_fleet); 		 }

		public 	function 	setId($id) {
			$this->_id = $id;
		}

		public 	function 	setLogin($login) {
			$this->_login = $login;
		}

		public 	function 	setRegistered($time) {
			$this->_registered = $time;
		}

		public 	function 	setRoomId($id) {
			$this->_roomId = $id;
		}

		public 	function 	setPlayedGames($nb) {
			$this->_playedGames = $this->getPlayedGames() + $nb;
		}

		public 	function 	setVictories($nb) {
			$this->_victories = $this->getVictories + $nb;
		}

		public 	function 	setDefeats($nb) {
			$this->_defeats = $this->getDefeats + $nb;
		}

		public 	function 	setTotShips($nb) {
			$this->_totShips = $this->getTotShips() + $nb;
		}

		public function 	setFleet( $method, $s){
			if ($method == "add")
			{
				array_push($this->_fleet, $s);
				$this->setTotShips(1);
			}
			if ($method == "del")
			{
				foreach ($this->getFleet() as $ship)
				{
					if ($ship->getId() == $s->getId())
					{
						unset($ship);
					}
				}
				$this->_fleet = array_values($this->_fleet);
				$this->setTotShips(-1);
			}	
		}

	}


?>
