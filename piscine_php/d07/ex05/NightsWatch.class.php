<?php

class NightsWatch implements IFighter {

	public function fight() {
	}

	public function recruit($nom) {
		$tab = class_implements(get_class($nom));
		foreach ($tab as $elem)
		{
			if ($elem === "IFighter")
				$nom->fight();
		}
	}
}

?>
