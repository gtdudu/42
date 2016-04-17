<?php if ( is_home() ) { ?>
<form id="searchform" method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
	<input type="text" value="<?php _e("Ou voulez vous aller ?"); ?>" name="s" id="searchbox" onfocus="if (this.value == '<?php _e("Ou voulez vous aller ?"); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e("Ou voulez vous aller ?"); ?>';}" />
	<input type="submit" id="searchsubmit" value="<?php _e("Rechercher"); ?>" />
</form>
 <?php } else { ?>
<form id="searchform" method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
	<input type="text" value="<?php _e("Ou voulez vous aller ?"); ?>" name="s" id="searchbox2" onfocus="if (this.value == '<?php _e("Ou voulez vous aller ?"); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e("Ou voulez vous aller ?"); ?>';}" />
</form>
<?php } ?>
