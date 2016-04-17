    <!-- Page Content -->
    <div class="container">

      <div class="row">

        <?php
        if (array_key_exists('loggued_on_user', $_SESSION) && $_SESSION['loggued_on_user'] != "")
        {
          echo '<div class="col-lg-6 text-center">';
          echo '<iframe name="chat" width="100%" height="550px" src="chat.php"></iframe>'."\n";
          echo '<iframe name="speak" width="100%" height="50px" src="speak.php"></iframe>'."\n";
          echo '<br />';
          echo '<br />';


          ?>
        </div>
        <div class="col-lg-1 text-center"></div>
   <div id="setupBox" class="col-lg-4 text-center">
          <form action="index.php" method="post">
          <br />
            Max player number: <input type="number" name="maxPlayer" min='2' max='4'/><br />
            Room name: <input type="text" name="roomName" /><br />
            <br />
            <select name="mode">
              <option>Melee game</option>
              <option>Squad game</option>
            </select><br />
            <select name="fleetLimit">
              <option>500 points</option>
              <option>1500 points</option>
              <option>3000 points</option>
            </select><br />
            <input type="submit" name="makeRoom" value="Create New Room">
          </form>      
        </div>
        <div class="col-lg-1 text-center"></div>
      </div>

      <div class="row">

              <div id="openRooms" class="col-lg-12 text-center">
          <table>
            <?php
            echo '<tr>';
            echo '<td>Id de la Room</td>';
            echo '<td>Room s name</td>';
            echo '<td>Game type</td>';
            echo '<td>Current player</td>';
            echo '<td>Max player</td>';
            echo '<td>Fleet Value</td>';
            echo '</tr>';



            if ($game->getTotOnlineRooms() >= 0)
            {
              foreach($game->getOnlineRooms() as $room)
              {
                echo '<tr>';
                echo '<td>'.$room->getId().'</td>';
                echo '<td>'.$room->getName().'</td>';
                echo '<td>'.$room->getMode().'</td>';

                echo '<td>'.$room->getTotOnlinePlayers().'</td>';
                echo '<td>'.$room->getPlayerLimit().'</td>';
                echo '<td>'.$room->getFleetValue().'</td>';
                if ($room->getTotOnlinePlayers() < $room->getPlayerLimit())
                    echo '<td><a href="setRoom.php?id='.$room->getId().'">Join room</td>';
                if ($room->getCreatedBy() == $_SESSION['loggued_on_user'])
                    echo '<td><a href="deleteRoom.php?id='.$room->getId().'">Delete Room</td>';
                echo '</tr>';

              }

            }
            ?>

          </table>
        </div>
    
      </div>


      <?php 
    }
    else
    {
      echo '<div class="col-lg-12 text-center">';

      ?>
      <h1>Log in to join the fight!</h1>

      <form action="index.php" method="post">
        Identifiant: <input type="text" name="login" />
        <br />
        Mot de passe: <input type="password" name="passwd" />
        <input type="submit" name="submit" value="OK">
      </form>                     
      <?php 
    }

    ?>
