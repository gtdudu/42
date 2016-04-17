
<?php
	echo "<br />";
	echo "Navire : ".Frigate::TYPE."<br />";
	echo "<br />PP: ".Frigate::PP."<br />";
	echo "Length : ".Frigate::HEIGHT."<br />";
	echo "Shield : ".$ship->getShield()."<br />";
	echo "Pc : ".$ship->getPc()."<br />";
	echo "Speed : ".Frigate::SPEED."<br />";
	foreach ($ship->getWeapon() as $elem)
		echo "Weapon(s) :".$elem->getName()." <br />";
	echo "Inertie : ".Frigate::MOVE."<br />";
?>
