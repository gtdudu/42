<header>
    <a href="basket.php">
        <div id="basket">
            <img src="resources/ico-panier.png">
            <span>Mon panier</span>
        </div>
    </a>
    <div id="account">
        <img src="resources/ico-user.png">
        <?php
        include("check_key.php");
        if ($_SESSION['loggued_on_user'] && $_SESSION['loggued_on_user'] != "")
        {
        ?>
        <div id="gestion">
            <br>
            <a href="deco.php"><button type="button">Deconnexion</button></a>
            <br><br>
            <?php
        	if (check_key($_SESSION['privilege']) === false)
            {
                ?>
                <a href="delete.php"><button type="button">Supprimer le compte</button></a>
                <?php
            }
            ?>
        </div>
        <?php
            echo "<span>Bienvenue    ".$_SESSION['loggued_on_user']."</span>";
        }
        else
        {   
            setcookie("link", "http://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]");
        ?>
        <div id="gestion">
            <form action="login.php" method="POST">
                <input type="text" name="email" placeholder="email" />
                <input type="password" name="passwd" placeholder="Mot de passe" />
                <input class="button" type="submit" name="submit" value="Connexion" />
            </form>
            <a href="#openModal"><button type="button">Creer un compte</button></a>
            <div id="openModal" class="modalDialog">
                <div>
                    <a href="#close" title="Close" class="close">X</a>
                    <h2>Creer un compte</h2>
                    <?php
                    if ($_COOKIE["retry"] === "true")
                    {
                        setcookie("retry", "false");
                        echo "Tout les champs doivent être remplis.";
                    }
                    if ($_COOKIE['taken'] == "true")
                    {                                
                        setcookie("taken", "false");
                        echo "Cette adresse mail est déja utilisée.";
                    }
                    ?>
                    <form action="createcheck.php" method="POST">
                        <br>
                        <input type="text" name="firstname" placeholder="Nom" />
                        <input type="text" name="lastname" placeholder="Prenom" />
                        <input type="text" name="email" placeholder="email" />
                        <input type="password" name="passwd" placeholder="Mot de passe" />
                        <input class="button" type="submit" name="submit" value="Creer" />
                    </form>
                    </div> 
                </div>
            </div>
        <span>Mon compte</span>
        <?php
        }
        ?>
    </div>
    <?php
    if (check_key($_SESSION['privilege']) === true)
    {
    ?>
        <a href="adminpanel.php">
            <div id="admin">
                <img src="resources/admin.png">
                <span>Panel Admin</span>
            </div>
        </a>
    <?php
    }
    ?>
    <a href="index.php"><h1>Bocal Renting</h1></a>
</header>