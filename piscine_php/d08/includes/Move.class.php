<?php
include_once("Frigate.class.php");
class Move
{
	const PIVOT = 0;
	const MOVE = 1;
	private $_current_mov = 0;
	private $_speed_points;
	private $total_dice;

	public function ft_pivot($ship)
	{
		if ($this->_current_mov >= $ship::MOVE || $ship->is_moving == FALSE)
		{

		}
	}
	public function ft_move($ship, $dices)
	{
		$total_dice = new Dice();
		$total_dice->roll_the_dice($dices['move']);
		$this->_speed_points = $ship->getSpeed() + $total_dice->merge_dice();
		if ($ship->getMoving() == false) {

		}
		else {
			if ($ship->prev_mov  )
		}

	}

}
?>
