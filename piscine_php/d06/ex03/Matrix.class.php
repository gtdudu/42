<?php

	

class Matrix {

	public static $verbose = False;
	public $m = array();
	const IDENTITY = 1;
	const SCALE = 2;
	const RX = 3;
	const RY = 4;
	const RZ = 5;
	const TRANSLATION = 6;
	const PROJECTION = 7;

	public function __construct($kwargs) {
		if (array_key_exists('preset', $kwargs))
		{
			if ($kwargs['preset'] == 1)
				$this->identityMatrix();
			if ($kwargs['preset'] == 2)
			{
				if (array_key_exists('scale', $kwargs))
					$this->scaleMatrix( $kwargs['scale'] );
			}
			if ($kwargs['preset'] == 3)
			{
				if (array_key_exists('angle', $kwargs))
					$this->rxMatrix( $kwargs['angle'] );
			}
			if ($kwargs['preset'] == 4)
			{
				if (array_key_exists('angle', $kwargs))
					$this->ryMatrix( $kwargs['angle'] );
			}
			if ($kwargs['preset'] == 5)
			{
				if (array_key_exists('angle', $kwargs))
					$this->rzMatrix( $kwargs['angle'] );
			}
			if ($kwargs['preset'] == 6)
			{
				if (array_key_exists('vtc', $kwargs))
					$this->translationMatrix( $kwargs['vtc'] );
			}
			if ($kwargs['preset'] == 7)
			{
				if (array_key_exists('fov', $kwargs ) &&
					array_key_exists('ratio', $kwargs ) && 
					array_key_exists('near', $kwargs ) && 
					array_key_exists('far', $kwargs ) )
				{
					$this->projectionMatrix( $kwargs['fov'], $kwargs['ratio'], $kwargs['near'], $kwargs['far'] );
				}
			}
		}

		if ( self::$verbose == True )
		{
			if ($kwargs['preset'] == 1)
				$name = "IDENTITY";
			if ($kwargs['preset'] == 2)
				$name = "SCALE preset";
			if ($kwargs['preset'] == 3)
				$name = "Ox ROTATION preset";
			if ($kwargs['preset'] == 4)
				$name = "Oy ROTATION preset";
			if ($kwargs['preset'] == 5)
				$name = "Oz ROTATION preset";
			if ($kwargs['preset'] == 6)
				$name = "TRANSLATION preset";
			if ($kwargs['preset'] == 7)
				$name = "PROJECTION preset";	
			print('Matrix ' . $name . ' instance constructed' . PHP_EOL);
		}

	}

	public function __destruct() {
		if ( self::$verbose == True )
			print('Matrix instance destructed' . PHP_EOL);

	}

	public static function doc() {
		return file_get_contents( 'Matrix.doc.txt' );
	}

	public function __toString() {
		$line1 = 'M | vtcX | vtcY | vtcZ | vtxO'."\n";	
		$line = '-----------------------------'."\n";
		$line2 = 'x | %4.2f | %4.2f | %4.2f | %4.2f'."\n";
		$line3 = 'y | %4.2f | %4.2f | %4.2f | %4.2f'."\n";
		$line4 = 'z | %4.2f | %4.2f | %4.2f | %4.2f'."\n";
		$line5 = 'w | %4.2f | %4.2f | %4.2f | %4.2f';
		$format = $line1 . $line . $line2 .$line3 . $line4 .$line5;
		return sprintf($format, 
			$this->m[0][0], $this->m[0][1], $this->m[0][2], $this->m[0][3], 
			$this->m[1][0], $this->m[1][1], $this->m[1][2], $this->m[1][3], 
			$this->m[2][0], $this->m[2][1], $this->m[2][2], $this->m[2][3], 
			$this->m[3][0], $this->m[3][1], $this->m[3][2], $this->m[3][3]);
	}

	private function emptyMatrix() {
		$tmp = array();
		$i = 0;
		while ($i < 4)
		{
			$j = 0;
			while ($j < 4)
			{
				$tmp[$i][$j] = 0;
				$j++;
			}
			$i++;
		}
		$tmp[0][0] = 1;
		$tmp[1][1] = 1;
		$tmp[2][2] = 1;
		$tmp[3][3] = 1;
		return $tmp;
	}
	
	private function identityMatrix() {
		$tmp = $this->emptyMatrix();
		$tmp[0][0] = 1;
		$tmp[1][1] = 1;
		$tmp[2][2] = 1;
		$tmp[3][3] = 1;
		$this->m = $tmp;
	}

	private function scaleMatrix( $scale ) {
		$tmp = $this->emptyMatrix();
		$tmp[0][0] = $scale;
		$tmp[1][1] = $scale;
		$tmp[2][2] = $scale;
		$this->m = $tmp;
	}

	private function rxMatrix( $angle ) {
		$tmp = $this->emptyMatrix();
		$tmp[1][1] = cos( $angle );
		$tmp[1][2] = -1 * sin( $angle );
		$tmp[2][1] = sin( $angle );
		$tmp[2][2] = cos( $angle );
		$this->m = $tmp;
	}

	private function ryMatrix( $angle ) {
		$tmp = $this->emptyMatrix();
		$tmp[0][0] = cos( $angle );
		$tmp[0][2] = sin( $angle );
		$tmp[2][0] = -1 * sin( $angle );
		$tmp[2][2] = cos( $angle );
		$this->m = $tmp;
	}

	private function rzMatrix( $angle ) {
		$tmp = $this->emptyMatrix();
		$tmp[0][0] = cos( $angle );
		$tmp[1][0] = sin( $angle );
		$tmp[0][1] = -1 * sin( $angle );
		$tmp[1][1] = cos( $angle );
		$this->m = $tmp;
	}

	private function translationMatrix( Vector $vtc ) {
		$tmp = $this->emptyMatrix();
		$tmp[0][3] = $vtc->getX();
		$tmp[1][3] = $vtc->getY();
		$tmp[2][3] = $vtc->getZ();
		$this->m = $tmp;
	}

	private function projectionMatrix( $fov, $ratio, $near, $far ) {
		$tmp = $this->emptyMatrix();
		$tmp[0][0] = 1 / ( $ratio * tan ( deg2rad( $fov ) / 2 ) );
		$tmp[1][1] =  1 / tan ( deg2rad( $fov ) / 2 );
		$tmp[2][2] = ( -1 * ( $far + $near ) ) / ( $far - $near );
		$tmp[2][3] = ( -2 * $far * $near ) / ( $far - $near );
		$tmp[3][2] = -1;
		$tmp[3][3] = 0;
		$this->m = $tmp;
	}

	public function mult( Matrix $rhs ) {

		$a = $this->m[0][0] * $rhs->m[0][0] + $this->m[0][1] * $rhs->m[1][0] + $this->m[0][2] * $rhs->m[2][0] + $this->m[0][3] * $rhs->m[3][0];
		$b = $this->m[0][0] * $rhs->m[0][1] + $this->m[0][1] * $rhs->m[1][1] + $this->m[0][2] * $rhs->m[2][1] + $this->m[0][3] * $rhs->m[3][1];
		$c = $this->m[0][0] * $rhs->m[0][2] + $this->m[0][1] * $rhs->m[1][2] + $this->m[0][2] * $rhs->m[2][2] + $this->m[0][3] * $rhs->m[3][2];
		$d = $this->m[0][0] * $rhs->m[0][3] + $this->m[0][1] * $rhs->m[1][3] + $this->m[0][2] * $rhs->m[2][3] + $this->m[0][3] * $rhs->m[3][3];

		$e = $this->m[1][0] * $rhs->m[0][0] + $this->m[1][1] * $rhs->m[1][0] + $this->m[1][2] * $rhs->m[2][0] + $this->m[1][0] * $rhs->m[3][0];
		$f = $this->m[1][0] * $rhs->m[0][1] + $this->m[1][1] * $rhs->m[1][1] + $this->m[1][2] * $rhs->m[2][1] + $this->m[1][1] * $rhs->m[3][1];
		$g = $this->m[1][0] * $rhs->m[0][2] + $this->m[1][1] * $rhs->m[1][2] + $this->m[1][2] * $rhs->m[2][2] + $this->m[1][2] * $rhs->m[3][2];
		$h = $this->m[1][0] * $rhs->m[0][3] + $this->m[1][1] * $rhs->m[1][3] + $this->m[1][2] * $rhs->m[2][3] + $this->m[1][3] * $rhs->m[3][3];

		$i = $this->m[2][0] * $rhs->m[0][0] + $this->m[2][1] * $rhs->m[1][0] + $this->m[2][2] * $rhs->m[2][0] + $this->m[2][3] * $rhs->m[3][0];
		$j = $this->m[2][0] * $rhs->m[0][1] + $this->m[2][1] * $rhs->m[1][1] + $this->m[2][2] * $rhs->m[2][1] + $this->m[2][3] * $rhs->m[3][1];
		$k = $this->m[2][0] * $rhs->m[0][2] + $this->m[2][1] * $rhs->m[1][2] + $this->m[2][2] * $rhs->m[2][2] + $this->m[2][3] * $rhs->m[3][2];
		$l = $this->m[2][0] * $rhs->m[0][3] + $this->m[2][1] * $rhs->m[1][3] + $this->m[2][2] * $rhs->m[2][3] + $this->m[2][3] * $rhs->m[3][3];

		$m = $this->m[3][0] * $rhs->m[0][0] + $this->m[3][1] * $rhs->m[1][0] + $this->m[3][2] * $rhs->m[2][0] + $this->m[3][3] * $rhs->m[3][0];
		$n = $this->m[3][0] * $rhs->m[0][1] + $this->m[3][1] * $rhs->m[1][1] + $this->m[3][2] * $rhs->m[2][1] + $this->m[3][3] * $rhs->m[3][1];
		$o = $this->m[3][0] * $rhs->m[0][2] + $this->m[3][1] * $rhs->m[1][2] + $this->m[3][2] * $rhs->m[2][2] + $this->m[3][3] * $rhs->m[3][2];
		$p = $this->m[3][0] * $rhs->m[0][3] + $this->m[3][1] * $rhs->m[1][3] + $this->m[3][2] * $rhs->m[2][3] + $this->m[3][3] * $rhs->m[3][3];

		$new = array(
			array($a, $b, $c, $d),
			array($e, $f, $g, $h),
			array($i, $j, $k, $l),
			array($m, $n, $o, $p),
		);

		$rs = clone $this;
		$rs->m = $new;
		return $rs;
	}

	public function transformVertex( Vertex $vtx ) {
		$newx = $this->m[0][0] * $vtx->getX() + $this->m[0][1] * $vtx->getY() + $this->m[0][2] * $vtx->getZ() + $this->m[0][3] * $vtx->getW();
		$newy = $this->m[1][0] * $vtx->getX() + $this->m[1][1] * $vtx->getY() + $this->m[1][2] * $vtx->getZ() + $this->m[1][3] * $vtx->getW();
		$newz = $this->m[2][0] * $vtx->getX() + $this->m[2][1] * $vtx->getY() + $this->m[2][2] * $vtx->getZ() + $this->m[2][3] * $vtx->getW();
		$neww = 1;

		return New Vertex ( array ( 'x' => $newx, 'y'=> $newy, 'z' => $newz, 'w' => $neww) );
	}
}


?>
