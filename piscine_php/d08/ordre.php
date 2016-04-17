<div id="info">

<?php
include("stat.php");
?>

</div>

<div id="info2">
<p>Il vous est possible d'attribuer des points de jeu (PP) a differentes actions ! Attention le nombre de PP est limiter, etudiez votre navire en detail avant de vous decider. Cliquer sur Valider pour passer a l'etape suivante</p>
<form action="main.php?preset=mouvement" method="post">
	Boost bouclier : <input type="number" name="ppShield" min="0" /><br />
	Boost Armes : <input type="number" name="ppWeapon" min="0"/><br />
	Reparations : <input type="number" name="ppRepair" min="0" /><br />
	Boost deplacement : <input type="number" name="ppMove" min="0"/>&nbsp;&nbsp;
	<input type="submit" name="submit" value="Valider"><br />
	
</form>

</div>

