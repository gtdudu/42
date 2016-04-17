<?php

$servername = "localhost";
$username = "root";
$password = "theteam";

$conn = mysqli_connect($servername, $username, $password, 'myDB');
if (!$conn)
{
	$conn = mysqli_connect($servername, $username, $password);
	$sql = "CREATE DATABASE myDB";
	if (mysqli_query($conn, $sql))
		echo "Database created"."<br />";
	$conn = mysqli_connect($servername, $username, $password, 'myDB');
	if (!$conn)
		die("Connection failed: ".mysqli_connect_error());

	$sql = "CREATE TABLE user (
	user_id INT(255) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	firstname VARCHAR(255) NOT NULL,
	lastname VARCHAR(255) NOT NULL,
	email VARCHAR(255) NOT NULL,
	reg_date TIMESTAMP,
	passwd VARCHAR(255) NOT NULL,
	privilege INT(6) UNSIGNED NOT NULL
	)";
	if (mysqli_query($conn, $sql))
		echo "user table  created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";

	$sql = "CREATE TABLE item (
	item_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(255) NOT NULL,
	description VARCHAR(255) NOT NULL,
	image VARCHAR(255),
	price INT(10) UNSIGNED NOT NULL
	)";

	if (mysqli_query($conn, $sql))
		echo "item table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";

	$sql = "CREATE TABLE category (
	category_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(255) NOT NULL,
	description VARCHAR(255) NOT NULL
	)";
	if (mysqli_query($conn, $sql))
		echo "category table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";


	$sql = "CREATE TABLE category_item (
	category_id INT(6) UNSIGNED,
	item_id INT(6) UNSIGNED
	)";
	if (mysqli_query($conn, $sql))
		echo "category_item table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";

	$sql = "CREATE TABLE orders (
	orders_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	amount INT(6) UNSIGNED,
	user_id INT(6) UNSIGNED,
	FOREIGN KEY (user_id) REFERENCES user(user_id)
	)";
	if (mysqli_query($conn, $sql))
		echo "orders table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";

	$sql = "CREATE TABLE order_item (
	orders_id INT(6) UNSIGNED,
	item_id INT(6) UNSIGNED,
	number INT(6) UNSIGNED,
	FOREIGN KEY (orders_id) REFERENCES orders(orders_id)
	)";
	if (mysqli_query($conn, $sql))
		echo "order_item table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";

	$sql = "CREATE TABLE my_key (
	key_id VARCHAR(255)
	)";
	if (mysqli_query($conn, $sql))
		echo "order_item table created"."<br />";
	else
		echo "error:  ".mysqli_error($conn)."<br />";
															//INSERTING DATA
	$flag = true;
	if ($flag)
	{
		$pass1 = hash("whirlpool", "stewie");
		$pass2 = hash("whirlpool", "admin");
		$pass3 = hash("whirlpool", "password");
		$sql = "INSERT INTO user (user_id, firstname, lastname, email, passwd, privilege) VALUES (1, 'Stewie', 'Griffin', 'peter@griffin.com',"."'".$pass1."'".", 2)";
		if (mysqli_multi_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO user (user_id, firstname, lastname, email, passwd, privilege) VALUES (2, 'Administrator', 'admin', 'admin',"."'".$pass2."'".", 2)";
		if (mysqli_multi_query($conn, $sql))
			echo "inserting ok"."<br />";
		$sql = "INSERT INTO user (user_id, firstname, lastname, email, passwd, privilege) VALUES (3, 'User', 'login', 'login',"."'".$pass3."'".", 1)";
		if (mysqli_multi_query($conn, $sql))
			echo "inserting ok"."<br />";
		$sql = "INSERT INTO item (item_id, name, description, image, price) VALUES ('1', 'Ol', 'Le seul, le vrai', 'resources/ol.png', '42')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		$sql = "INSERT INTO `mydb`.`item` (`item_id`, `name`, `description`, `image`, `price`) VALUES ('2', 'Zaz', 'Il est la !', 'resources/mmontinet.png', '80')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
        $sql = "INSERT INTO `mydb`.`item` (`item_id`, `name`, `description`, `image`, `price`) VALUES ('3', 'Thor', 'Le voila !', 'resources/dgiron.png', '150')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
        
                $sql = "INSERT INTO `mydb`.`item` (`item_id`, `name`, `description`, `image`, `price`) VALUES ('0', 'Beeone', 'Tadaaaa !', 'resources/sbenoit.png', '80')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
        
                $sql = "INSERT INTO `mydb`.`item` (`item_id`, `name`, `description`, `image`, `price`) VALUES ('0', 'Mathieu', 'Le meilleur !', 'resources/mmahe.png', '500')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
        
        
		$sql = "INSERT INTO `mydb`.`orders` (`orders_id`, `user_id`, `amount`) VALUES ('1', '1', '43')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		$sql = "INSERT INTO `mydb`.`orders` (`orders_id`, `user_id`, `amount`) VALUES ('2', '2', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`order_item` (`orders_id`, `item_id`, `number`) VALUES ('1', '1', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`order_item` (`orders_id`, `item_id`, `number`) VALUES ('1', '2', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`order_item` (`orders_id`, `item_id`, `number`) VALUES ('2', '2', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);


		$sql = "INSERT INTO `mydb`.`category` (`category_id`, `name`, `description`) VALUES ('1', 'Promotions', 'Des prix incroyables !')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        $sql = "INSERT INTO `mydb`.`category` (`category_id`, `name`, `description`) VALUES ('2', 'Barbus', 'Une bonne barbichette !')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        $sql = "INSERT INTO `mydb`.`category` (`category_id`, `name`, `description`) VALUES ('3', 'Chevelus', 'Taaa daaaaa !')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        $sql = "INSERT INTO `mydb`.`category` (`category_id`, `name`, `description`) VALUES ('4', 'Bruns', 'Les bruns et les brunes !')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        $sql = "INSERT INTO `mydb`.`category` (`category_id`, `name`, `description`) VALUES ('5', 'Blonds', 'Les execptions !')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);

		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('1', '2')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('1', '3')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);

		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('1', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        
        		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('2', '2')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('2', '3')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);

		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('2', '4')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        
        		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('3', '2')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('3', '5')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);

		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('4', '4')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        
        $sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('4', '3')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('4', '2')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);

		$sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('5', '1')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
        
        $sql = "INSERT INTO `mydb`.`category_item` (`category_id`, `item_id`) VALUES ('5', '5')";
		if (mysqli_query($conn, $sql))
			echo "inserting ok"."<br />";
		else
			echo "error".mysqli_error($conn);
	}
	header("Location: index.php");
}

mysqli_close($conn);

?>
