<?php
include("connect.php");
session_start();
?>

<html>
    <head>
        <title>Bocal Renting</title>
        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="menu.css">
        <meta charset="utf-8">
    </head>
    <body id="admin">
        <div class="clearfix" id="content">
            <?php include("header.php");?>
            <div id="content-adm">
<?php 
			include("check_key.php");
            if (check_key($_SESSION['privilege']) === true)
            {
				include("connect.php");
				$sql = "SELECT * FROM user";
				$result = mysqli_query($conn, $sql);
?>
				<div>Gestion utilisateurs 
<?php
					while ($row = mysqli_fetch_assoc($result)) 
					{
?>
					<form action="manage_user.php" method="POST">
						<input type="text" style="display: none;" name="user_id" value="<?php echo $row['user_id']; ?>" />
						<input type="text" name="firstname" placeholder="Nom" value="<?php echo $row['firstname']; ?>" />
						<input type="text" name="lastname" placeholder="Prenom" value="<?php echo $row['lastname']; ?>" />
						<input type="text" name="email" placeholder="email" value="<?php echo $row['email']; ?>" />
						<input type="password" name="passwd" placeholder="Mot de passe" value="<?php echo $row['passwd']; ?>" />
						<select name="privilege">
						<option value="1" <?php if($row['privilege'] == 1) {echo "selected";} ?> >Utilisateur</option>
							<option value="2" <?php if($row['privilege'] == 2) {echo "selected";} ?>>Administrateur</option>
						</select>
						<input class="button" type="submit" name="submit" value="modify" />
						<input class="button" type="submit" name="submit" value="delete" />
					</form>
						<br />
<?php
					}
?>
					<form action="manage_user.php" method="POST">
					<br />
					<hr width="100%">
					<br />
					<input type="text" name="firstname" placeholder="Nom" value="" />
					<input type="text" name="lastname" placeholder="Prenom" value="" />
					<input type="text" name="email" placeholder="email" value="" />
					<input type="password" name="passwd" placeholder="Mot de passe" value="" />
					<select name="privilege">
					<option value="1">Utilisateur</option>
					<option value="2">Administrateur</option>
					</select>
					<input class="button" type="submit" name="submit" value="add" />
					</form>
				</div>

                <div>Gestion articles
<?php
					$sql = "SELECT * FROM item";
					$result = mysqli_query($conn, $sql);
					while ($row = mysqli_fetch_assoc($result)) 
					{
						$selected = array();
?>
					<form action="manage_item.php" method="POST">
						<input type="text" style="display: none;" name="item_id" value="<?php echo $row['item_id']; ?>" />
						<input type="text" name="name" placeholder="Nom" value="<?php echo $row['name']; ?>" />
						<input type="text" name="price" placeholder="Prix" value="<?php echo $row['price']; ?>" />
						<input id="desc" type="text" name="description" placeholder="Description" value="<?php echo $row['description']; ?>" />
						<input type="text" name="image" placeholder="Image" value="<?php echo $row['image']; ?>" />
<?php
						$sql2 = 'SELECT * FROM category_item';
						$result2 = mysqli_query($conn, $sql2);
						while ($row2 = mysqli_fetch_assoc($result2))
						{
							if ($row2['item_id'] === $row['item_id'])
								$selected[] = $row2['category_id'];
						}
						echo "<select multiple name='category[]'>";
						$sql1 = "SELECT * FROM category";
						$result1 = mysqli_query($conn, $sql1);
						while ($row1 = mysqli_fetch_assoc($result1)) 
						{
								echo "<option value=";
								echo $row1['name'];
								echo " style='";
							foreach ($selected as $elem)
							{
								if ($row1['category_id'] == $elem) 
									echo "color:red;";							
								else
									echo "color:black;";							
							}
								echo "' >".$row1['name']."</option>";
						}
?>
						</select>
						<input class="button" type="submit" name="submit" value="modify" />
						<input class="button" type="submit" name="submit" value="delete" />
                    </form>                       
						<br />
<?php
					}
?>
					<form action="manage_item.php" method="POST">
						<br />
						<hr width="100%">
						<br />
						<input type="text" style="display: none;" name="item_id" value="<?php echo $row['item_id']; ?>" />
						<input type="text" name="name" placeholder="Nom" value="" />
						<input type="text" name="price" placeholder="Prix" value="" />
						<input id="desc" type="text" name="description" placeholder="Description" value="" />
						<input type="text" name="image" placeholder="Image" value="" />
						<select multiple name="category[]">
<?php
						$sql1 = "SELECT * FROM category";
						$result1 = mysqli_query($conn, $sql1);
						$i = 0;
						while ($row1 = mysqli_fetch_assoc($result1)) 
						{
							if ($i === 0)
							{
								$i = 1;
								echo "<option value='".$row1['name']."' selected>".$row1['name']."</option>";
							}
							else
								echo "<option value='".$row1['name']."'>".$row1['name']."</option>";
						}
							

?>
						</select>
						<input class="button" type="submit" name="submit" value="add" />
                        </form>                       
                    </div>

			   <div>Gestion categories
<?php
					$sql = "SELECT * FROM category";
					$result = mysqli_query($conn, $sql);
					while ($row = mysqli_fetch_assoc($result)) 
					{
?>
					<form action="manage_category.php" method="POST">
						<input type="text" style="display: none;" name="category_id" value="<?php echo $row['category_id']; ?>" />
						<input type="text" name="name" placeholder="Nom" value="<?php echo $row['name']; ?>" />
						<input type="text" name="description" placeholder="description" value="<?php echo $row['description']; ?>" />
						<input class="button" type="submit" name="submit" value="modify" />
						<input class="button" type="submit" name="submit" value="delete" />
					</form>                        
						<br />
<?php
					}
?>
					<form action="manage_category.php" method="POST">
						<br />
						<hr width="100%">
						<br />
						<input type="text" style="display: none;" name="category_id" value="<?php echo $row['category_id']; ?>" />
						<input type="text" name="name" placeholder="Nom" value="" />
						<input type="text" name="description" placeholder="Description" value="" />
						<input class="button" type="submit" name="submit" value="add" />
					</form>                        
				</div>
            <?php
            }
            else
            {?>
                <h1>Petit Malin !</h1>
            <?php
            }
            ?>
            </div>
            <?php include("footer.php"); ?>
        </div>
    </body>
</html>
