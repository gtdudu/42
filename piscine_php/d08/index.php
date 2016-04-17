<?php

	session_start();
	require("includes/Dice.class.php");
	require("includes/Game.class.php");
	require("includes/Player.class.php");
	require("includes/Ship.class.php");
	require("includes/Obstacle.class.php");
	require("includes/Frigate.class.php");
	require('includes/NavalSpear.class.php');

	Game::$verbose = False;
	Player::$verbose = False;
	Ship::$verbose = False;

	$ships_p1	= array (
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 0, 'y' => 0, 'dir' => Game::NORTH)),
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 40, 'y' => 90, 'dir' => Game::NORTH)),
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 140, 'y' => 90, 'dir' => Game::NORTH)),
				);

	$ships_p2	= array (
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 0, 'y' => 40, 'dir' => Game::NORTH)),
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 80, 'y' => 10, 'dir' => Game::NORTH)),
					new Frigate(array ('name' => 'bateau de Raf1', 'x' => 120, 'y' => 10, 'dir' => Game::NORTH)),
				);
	
	$ships_p3	= array (
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 50, 'y' => 50, 'dir' => Game::NORTH)),
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 51, 'y' => 50, 'dir' => Game::NORTH)),
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 120, 'y' => 80, 'dir' => Game::WEST)),
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 100, 'y' => 80, 'dir' => Game::EAST)),
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 0, 'y' => 30, 'dir' => Game::WEST)),
					new Obstacle(array ('name' => 'bateau de Raf', 'x' => 110, 'y' => 37, 'dir' => Game::WEST)),
				);

	$player1	= array (
					"id" => 1,
					"name" => "Tommy",
					"ships" => $ships_p1
				);

	$player2	= array (
					"id" => 2,
					"name" => "Anthony",
					"ships" => $ships_p2
				);

	$obst	= array (
					"id" => 9,
					"name" => "Obstacle",
					"ships" => $ships_p3
				);

	$game = new Game;

	$p1 = $game->add_player($player1);
	$p2 = $game->add_player($player2);
	$p3 = $game->add_player($obst);

	$game->add_ship('1', $p1->getShips());
	$game->add_ship('2', $p2->getShips());
	$game->add_ship('3', $p3->getShips());

	echo '<h1><a href="main.php?preset=select&i=0&j=0">Let\'s kick some ass !</a></h1>';
	$player1 = serialize($p1);
	$player2 = serialize($p2);
	$save = serialize($game);
	$_SESSION['save'] = $save;
	$_SESSION['player1'] = $player1;
	$_SESSION['player2'] = $player2;

?>
