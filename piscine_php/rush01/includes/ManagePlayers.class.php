<?php

trait managePlayers{


	protected		$_totOnlinePlayers		= 0;	
	protected		$_onlinePlayers = array();



	public	function	getOnlinePlayers() { return ($this->_onlinePlayers);  }
	public	function	getTotOnlinePlayers()  	{ return ($this->_totOnlinePlayers);  }



	public function 	setTotOnlinePlayers( $method, $nb){
		if ($method == "inc")
			$this->_totOnlinePlayers = $this->getTotOnlinePlayers() + $nb;
		else if ($method == "dec")
			$this->_totOnlinePlayers = $this->getTotOnlinePlayers() - $nb;

	}

	public function 	setOnlinePlayers($method, $p){
		if ($method === "add")
		{
			$this->_onlinePlayers[] = $p;
			$this->setTotOnlinePlayers("inc", 1);
		}
		if ($method === "del")
		{
			$c = 0;
			foreach ($this->getOnlinePlayers() as $player)
			{
				if ($player->getId() == $p->getId())
				{
					unset($this->_onlinePlayers[$c]);
					$this->setTotOnlinePlayers("dec", 1);
				}
				$c++;
			}
		}	
	}

	public function 	getPlayerObject($login) {
			foreach ($this->getOnlinePlayers() as $player)
			{
				if ($player->getLogin() == $login)
				{
					return $player;
				}
			}
	}
}

?>
