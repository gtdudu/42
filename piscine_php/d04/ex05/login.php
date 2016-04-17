<html>
	<head>
		<title>BLL</title>
		<style>
			iframe {
				display: block;
			}
		</style>
	</head>
	<body>

<?php
include("auth.php");
session_start();
if (auth($_POST['login'], $_POST['passwd']) == true)
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	echo '<iframe name="chat" width="100%" height="550px" src="chat.php"></iframe>'."\n";
	echo '<iframe name="speak" width="100%" height="50px" src="speak.php"></iframe>'."\n";
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo "ERROR\n";
}

?>
	</body>
</html>
