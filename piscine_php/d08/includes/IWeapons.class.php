<?php

	interface Weapons 
	{
		function	getName();
		function	load_weapon($pp_spent);
		function	getScope( $dice );
		function	check_target($coords, $map, $target_id, $scope);
		function	shot($target_ship, $ennemi);
	}
?>
