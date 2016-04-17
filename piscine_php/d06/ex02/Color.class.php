<?php

Class Color {

	public static $verbose = False;
	public $red = 0;
	public $green = 0;
	public $blue = 0;

	public function setRed($v) {
		if ( $v >= 0 && $v <= 255)
			$this->red = $v;
		return;
	}

	public function setGreen($v) {
		if ( $v >= 0 && $v <= 255)
			$this->green = $v;
		return;
	}

	public function setBlue($v) {
		if ( $v >= 0 && $v <= 255)
			$this->blue = $v;
		return;
	}

	public function __construct( array $kwargs) {
		if ( array_key_exists( 'rgb', $kwargs) )
		{
			$this->setRed( ( intval( $kwargs['rgb'], 0 ) >> 16 ) & 0xFF );
			$this->setGreen( ( intval( $kwargs['rgb'], 0 ) >> 8 ) & 0xFF );
			$this->setBlue( intval( $kwargs['rgb'], 0 )  & 0xFF );
		}
		else
		{
			if ( array_key_exists( 'red', $kwargs ) )
				$this->setRed( intval( $kwargs['red'], 0) );
			if ( array_key_exists( 'green', $kwargs ) )
				$this->setGreen( intval( $kwargs['green'], 0) );
			if ( array_key_exists( 'blue', $kwargs ) )
				$this->setBlue( intval( $kwargs['blue'], 0) );
		}
		if ( self::$verbose == True)
			print($this . ' constructed. ' . PHP_EOL);
		return;
	}

	public function __destruct() {
		if ( self::$verbose == True)
			print($this . ' destructed. ' . PHP_EOL);
		return;
	}

	public static function doc() {
		return file_get_contents( 'Color.doc.txt' );
	}

	public function __toString() {
		$format = 'Color( red: %3d, green: %3d, blue: %3d )';
		return sprintf($format, $this->red, $this->green, $this->blue);
	}

	public function add( Color $rhs ) {
		return  new Color( array( 'red' => ($rhs->red + $this->red), 'green' => ($rhs->green + $this->green), 'blue' => ($rhs->blue + $this->blue) ) );
	}

	public function sub( Color $rhs ) {
		return  new Color( array( 'red' => ($this->red - $rhs->red), 'green' => ($this->green - $rhs->green), 'blue' => ($this->blue - $rhs->blue) ) );
	}

	public function mult( $f ) {
		return  new Color( array( 'red' => ($f * $this->red), 'green' => ($f * $this->green), 'blue' => ($f * $this->blue) ) );
	}

}


?>
