 <?php
 ?>
    <!-- Navigation -->
    <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="index.php">WarOnline</a>
            </div>
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav">

                <?php
                if (array_key_exists('loggued_on_user', $_SESSION) && $_SESSION['loggued_on_user'] != "")
                {
                    echo '<li><a href="#">Welcome, '.$_SESSION['loggued_on_user'].'</a></li>';
                    echo '<li> <a href="rank.php">Ranking</a> </li>';
                    echo '<li> <a href="mod.php">My Account</a> </li>';
                    echo '<li> <a href="logout.php">Loggout</a> </li>';
                
                }
                else
                {
                      ?>
                      <li><a href="create.php">Create Account</a></li>
                      <?php 
                    echo '<li> <a href="delete.php">destroy</a> </li>';

                 }

                ?>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container -->
    </nav>