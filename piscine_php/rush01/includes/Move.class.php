<?php
include_once("Frigate.class.php");
trait Move
{
	private $_current_mov = 0;
	private $_speed_points;
	private $total_dice;

	public function ft_pivot($dir)
	{
		if ($this->_current_mov >= MOVE || $this->is_moving == FALSE)
		{
			if ($dir == 1 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 1 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 1 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 1 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 2 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 2 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 2 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
			elseif ($dir == 2 && $this->getCoord()['dir'] == self::NORTH)
			{

			}
		}
	}
	public function ft_move($ship, $SpeedVal)
	{
		$this->_speed_points = $this->getSpeed() + $SpeedVal;

	}



}
?>
