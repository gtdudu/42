
<div id="info">
<?php
if (!isset($_POST['ppShield']))
	$shield = 0;
else
	$shield = $_POST['ppShield'];
if (!isset($_POST['ppRepair']))
	$repair = 0;
else
	$repair = $_POST['ppRepair'];

if ($shield + $repair <= 10)
{

	if ($shield != 0)
	{
		echo "You've invested ".$shield." points in your shield, i'm sure you feel safer now";
		$ship->incShield($shield);
		$ship->incPpspent($shield);

		echo "<br />";
		echo "<br />";
	}

	if ($repair != 0)
	{
		echo "You've invested ".$repair." points in your repair, will it pay off ?";
		echo "<br />";
		$ship->incPpspent($repair);
		$tab = $game->roll_the_dice($repair);
		foreach ($tab as $elem)
		{
			echo "you rolled a : ";
			echo $elem;
			echo ' for repair';
			if ($elem == 6)
			{
				echo "   Well done Pc + 1 ! <br /> ";
				$ship->incPc();
			}
			else
				echo "   Too bad !  <br />";
		}
	}
	$game->reset_the_dice();
}
else
	echo "to many points attributed, nothing has been done. Keep playing";

if (isset($ship))
	include("stat.php");

if (!isset($_POST['pp']))
{
	$str = serialize($_POST);
	$_SESSION['pp'] = $str;
}

?>

</div>

<div id="info2">

<?php
$spend = 10 - $ship->getPpspent();
	echo "You've spent ". $ship->getPpspent() . " PP points so far. ".$spend." to go !";	
	echo "Ready to move";
?>

	<form action="move.php" method="post">
		<input type="number" name="move" min="0">
		<input type="submit" name="submit" value="Move">
	</form>

	<form action="turn.php" method="post">
		<input type="hidden" name="side" value="left">
		<input type="submit" name="submit" value="Turn Left">
	</form>


	<form action="turn.php" method="post">
		<input type="hidden" name="side" value="right">
		<input type="submit" name="submit" value="Turn Right">
	</form>
	<form action="main.php?preset=tir" method="post">
		<input type="submit" name="submit" value="Go shooting people">
	</form>

</div>
