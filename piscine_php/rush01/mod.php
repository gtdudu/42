<?php
session_start();
    include("head.php");
    include("nav.php");
?>

    <div >
    </div>
    <!-- Page Content -->
    <div class="container">

            <div class="col-lg-12 text-center">

 
<?php
if (array_key_exists('submit', $_POST) && $_POST['submit'] == "OK")
{
    if ($_POST['login'] === "" || $_POST['oldpw'] === "" || $_POST['newpw'] === "")
        echo "ERROR\n";
    else
    {
        if (file_exists("../private") && file_exists("../private/passwd"))
        {
            $str = file_get_contents("../private/passwd");
            $db = unserialize($str);
            $i = -1;
            foreach ($db as $account)
            {
                $i++;
                $flag = 0;
                foreach ($account as $key => $value)
                {
                    if ($key === "login" && $value === $_POST['login'])
                        $flag++;
                    if ($key === "passwd" && $value === hash("whirlpool", $_POST['oldpw']))
                        $flag++;
                }
                if ($flag == 2)
                {
                    $newaccount = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['newpw']));
                    $db[$i] = $newaccount;
                    $str = serialize($db);
                    file_put_contents("../private/passwd", $str);
                    echo "OK\n";
                    header("Location: index.php");
                    break;
                }
            }
            if ($flag != 2)
                echo "ERROR\n";
        }
        else
            echo "ERROR\n";
    }
}
else
{
	?>

        <form action="mod.php" method="post">
            Identifiant: <input type="text" name="login" />
            <br />
            Ancien mot de passe: <input type="text" name="oldpw" />
            <br />
            Nouveau mot de passe: <input type="text" name="newpw" />
            <input type="submit" name="submit" value="OK">
        </form>

	<?php
}
?>



        </div>
        <!-- /.row -->
    </div>

    </div>
        <!-- /.row -->


    <!-- /.container -->

    <!-- jQuery Version 1.11.1 -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

</body>

</html>
