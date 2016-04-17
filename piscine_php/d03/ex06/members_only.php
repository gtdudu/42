<?php

if ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER['PHP_AUTH_PW'] === "jaimelespetitsponeys")
{
	echo "<html><body>"."\n";
	echo "Bonjour Zaz"."<br />"."\n";
	echo "<img src='data:image/png;base64,".base64_encode(file_get_contents("http://j03.local.42.fr:8080/img/42.png"))."'>\n";
	echo "</html></body>"."\n";

}
else
{
	header('WWW-Authenticate: Basic realm="Espace Membres"');
	header('HTTP/1.0 401 Unauthorized');
	echo "<html><body>";
	echo "Cette zone est accessible uniquement aux membres du site";
	echo "</html></body>"."\n";
}

?>
