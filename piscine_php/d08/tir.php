<?php
$victory = False;
if (!isset($recup['ppWeapon']))
	$weapon = 0;
else
	$weapon = $recup['ppWeapon'];
if (!isset($recup['ppMove']))
	$move = 0;
else
	$move = $recup['ppMove'];

echo "<br />";

$equip = $ship->getWeapon();
if ($equip[0]->load_weapon($weapon))
{
	$game->roll_the_dice($weapon);
	$dice = $game->merge_dice();
echo "<br />";
	$scope = $equip[0]->getScope( $dice );
echo "<br />";
	if ($scope == 0)
		echo "Avec un chiffre de ".$dice." la portee n 'est pas suffisante ";
	else
	{
		$ennemy = $game->getInactive($p1, $p2);
		$rockstar = $game->getActive($p1, $p2);
		$res = $equip[0]->check_target($ship->getCoords(), $game->getMap(), $ennemy->getId(), $scope);
		$target = $ennemy->getShipObject($res['h'], $res['w']);
			if ($res == false)
				echo "Pas de cible a portee ma poule, essaye encore";
			else
			{
				echo "You've hit the target with a wonderfull throw of ".$dice;
				$destroy = $equip[0]->shot($target, $ennemy);
				if ($destroy == True)
				{
					$game->del_ship($target->getId(), $target);
					$ennemy->destroy_ship($target->getId());
					if ($ennemy->alive() == False)
						$victory = True;
				}
			}
		if ($res != False && get_parent_class($target) == "Ship" )
		{
			echo '<div id="info">';
			echo "Targeted Ship : <br />";
			echo "Navire : ".Frigate::TYPE."<br />";
			echo "<br />PP: ".Frigate::PP."<br />";
			echo "Length : ".Frigate::HEIGHT."<br />";
		//	echo "Shield : ".$target->getShield()."<br />";
			echo "Pc : ".$target->getPc()."<br />";
			echo "Speed : ".Frigate::SPEED."<br />";
			foreach ($target->getWeapon() as $elem)
				echo "Weapon(s) :".$elem->getName()." <br />";
			echo "Inertie : ".Frigate::MOVE."<br />";
		}
		
	}
	$game->reset_the_dice();	
}
else
{
	echo "Votre arme n est pas charge et vous n avez utilise aucun PP pour cette noble cause ! ";
	echo "Fin du round";
}

?>
</div>
<div id="info2">
<?php


		if ($victory == True)
		{
			echo '<form action="victory.php" method="post">';
			echo '<input type="submit" name="sumit" value="Claim Victory"/>';
			echo '</form>';
		}
		else
		{
			$game->invertActive();
			$ship->resetPpspent();
			unset($_SESSION['ship']);
			unset($_SESSION['pp']);
			echo '<form action="main.php?preset=select" method="post">';
			echo '<input type="submit" name="sumit" value="Next round"/>';
			echo '</form>';
		}
?>
</div>

