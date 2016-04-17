<?php

Class Vertex {

	public static $verbose = False;
	private $_x = 0;  
	private $_y = 0;  
	private $_z = 0;  
	private $_w = 1.0;  
	private $_color;

	public function setX($v) { $this->_x = $v; return; }
	public function setY($v) { $this->_y = $v; return; }
	public function setZ($v) { $this->_z = $v; return; }
	public function setW($v) { $this->_w = $v; return; }
	public function setColor( Color $v ) { $this->_color = $v; return;	}

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }

	public function __construct( array $kwargs) {
		if (array_key_exists( 'x' , $kwargs ) )
			$this->setX( $kwargs['x'] );
		if (array_key_exists( 'y' , $kwargs ) )
			$this->setY( $kwargs['y'] );
		if (array_key_exists( 'z' , $kwargs ) )
			$this->setZ( $kwargs['z'] );
		if (array_key_exists( 'w' , $kwargs ) )
			$this->setW( $kwargs['w'] );
		if (array_key_exists( 'color' , $kwargs ) )
			$this->setColor( $kwargs['color'] );
		else
			$this->_color = new Color ( array ( 'rgb' => 0xFFFFFF ) );
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
		return file_get_contents( 'Vertex.doc.txt' );
	}

	public function __toString() {
		if ( self::$verbose == False )
		{
			$format = 'Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f)';
			return sprintf($format, $this->_x, $this->_y, $this->_z, $this->_w);
		}
		else
		{
			$format = 'Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, ';
			$str = $this->_color;
			return sprintf($format, $this->_x, $this->_y, $this->_z, $this->_w) . $str . ' )';
		}
	}

}


?>
