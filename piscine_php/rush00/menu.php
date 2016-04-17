<div id="staticmenu"></div>
<div id="fixedmenu">
    <ul id="physique">
    <?php
    include("connect.php");
	$sql = "SELECT * FROM `myDB`.`category`";
	$result = mysqli_query($conn, $sql);
	if (isset($result))
	{
		while ($row = mysqli_fetch_assoc($result))
		{
			echo "<a href='category.php?category=".$row['name']."'><li>".$row['name']."</li></a>";
		}
	}
    ?>
    </ul>
</div>
