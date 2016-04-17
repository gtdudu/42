<?php

class UnholyFactory {

	public static $check = array('foot soldier' => 0, 'archer' => 0, 'assassin' => 0, 'llama' => 0);

	public function absorb($v) {
		if (array_key_exists($v->type, self::$check) && get_parent_class($v) == "Fighter")
		{
			if (self::$check[$v->type] != 0)
				print('(Factory already absorbed a fighter of type ' . $v->type . ')' . PHP_EOL);
			else
				print('(Factory absorbed a fighter of type ' . $v->type . ')' . PHP_EOL);

			self::$check[$v->type]++;
		}
		else
			print("(Factory can't absorb this, it's not a fighter)". PHP_EOL);
	}

	public function fabricate($v) {
		if (array_key_exists($v, self::$check))
		{
			if (self::$check[$v] != 0)
			{
				print("(Factory fabricates a fighter of type " . $v . ")". PHP_EOL);
				if ($v == "foot soldier")
					return new footsoldier;
				else
					return new $v;
			}
			else
				print("(Factory hasn't absorbed any fighter of type " . $v . ")". PHP_EOL);
		}
	}


}

?>
