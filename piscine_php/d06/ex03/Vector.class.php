<?php

Class Vector {

	public static $verbose = False;
	private $_x = 0;  
	private $_y = 0;  
	private $_z = 0;  
	private $_w = 0.0;  

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }

	public function __construct( array $kwargs ) {
		if (array_key_exists( 'dest' , $kwargs ) )
		{
			if (!array_key_exists( 'orig' , $kwargs ) )
				$kwargs['orig'] = new Vertex( array( 'x' => 0, 'y' => 0, 'z' => 0, 'w' => 1.0) );
			$this->_x = $kwargs['dest']->getX() - $kwargs['orig']->getX();
			$this->_y = $kwargs['dest']->getY() - $kwargs['orig']->getY();
			$this->_z = $kwargs['dest']->getZ() - $kwargs['orig']->getZ();
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
		return file_get_contents( 'Vector.doc.txt' );
	}

	public function __toString() {
		if ( self::$verbose == False )
		{
			$format = 'Vector( x: %.2f, y: %.2f, z:%.2f, w:%.2f )';
			return sprintf($format, $this->_x, $this->_y, $this->_z, $this->_w);
		}
		$format = 'Vector( x: %.2f, y: %.2f, z:%.2f, w:%.2f )';
		return sprintf($format, $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function magnitude() {
		return sqrt(($this->_x * $this->_x) + ($this->_y * $this->_y) + ($this->_z * $this->_z));
	}

	public function normalize () {
		$newx = $this->getX() / $this->magnitude();
		$newy = $this->getY() / $this->magnitude();
		$newz = $this->getZ() / $this->magnitude();
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}

	public function add ( Vector $v) {
		$newx = $this->getX() + $v->getX();
		$newy = $this->getY() + $v->getY();
		$newz = $this->getZ() + $v->getZ();
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}

	public function sub ( Vector $v) {
		$newx = $this->getX() - $v->getX();
		$newy = $this->getY() - $v->getY();
		$newz = $this->getZ() - $v->getZ();
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}
	
	public function opposite () {
		$newx = $this->getX() * -1;
		$newy = $this->getY() * -1;
		$newz = $this->getZ() * -1;
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}

	public function scalarProduct ( $v) {
		$newx = $this->getX() * $v;
		$newy = $this->getY() * $v;
		$newz = $this->getZ() * $v;
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}

	public function dotProduct ( Vector $v) {
		$newx = $this->getX() * $v->getX();
		$newy = $this->getY() * $v->getY();
		$newz = $this->getZ() * $v->getZ();
		$product = $newx + $newy + $newz;
		return $product;
	}

	public function crossProduct ( Vector $v) {
		$newx = $this->getY() * $v->getZ() - $this->getZ() * $v->getY();
		$newy = $this->getZ() * $v->getX() - $this->getX() * $v->getZ();
		$newz = $this->getX() * $v->getY() - $this->getY() * $v->getX();
		$newdest = new Vertex( array( 'x' => $newx, 'y' => $newy, 'z' => $newz) );
		return new Vector( array( 'dest' => $newdest) );
	}

	public function cos ( Vector $v) {
		$len1 = $this->magnitude(); 
		$len2 = $v->magnitude();
		$dot = $this->dotProduct($v);
		return $dot / ($len1 * $len2);
	}

}

?>
