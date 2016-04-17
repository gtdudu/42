<?php

abstract class Fighter {

	public $type;

	public function __construct($v) {
		$this->type = $v;
	}

	abstract public function fight($v);

}

?>
