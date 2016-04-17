<?php
session_start();
if ($_GET['submit'] === "OK")
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
<html><body>

<form action="index.php" method="get">
	Identifiant: <input type="text" value="<?php echo $_SESSION['login']; ?>" name="login" />
	<br />
	Mot de passe: <input type="text" value="<?php echo $_SESSION['passwd']; ?>"  name="passwd" />
	<input type="submit" name="submit" value="OK">
</form>
</body></html>
