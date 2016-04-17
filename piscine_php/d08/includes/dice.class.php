<?php

trait Dice{
	private $_dice_list = array();

	public function roll_the_dice($nb_dice)
	{
		while($nb_dice != 0)
		{
			$this->_dice_list[] = rand(1,6);
			$nb_dice--;
		}
		return ($this->_dice_list);
	}

	public function merge_dice()
	{
		return (array_sum($this->_dice_list));
	}

	public function reset_the_dice()
	{
		$this->_dice_list = array();
	}
}

?>
