<?php
	if ( 'comments.php' == basename($_SERVER['SCRIPT_FILENAME']) )
		if (!empty($_SERVER['SCRIPT_FILENAME']) && 'comments.php' == basename($_SERVER['SCRIPT_FILENAME']))
?>

<div id="comments">
<?php
	if ( !empty($post->post_password) ) :
		if ( $_COOKIE['wp-postpass_' . COOKIEHASH] != $post->post_password ) :
?>
	<div class="nopassword"><?php _e( 'This post is protected. Enter the password to view any comments.', 'wpbx' ) ?></div>
</div><!-- #comments -->
<?php
		return;
	endif;
endif;
?>
<?php if ( $comments ) : ?>
<?php global $wpbx_comment_alt ?>

<?php // Number of pings and comments
$ping_count = $comment_count = 0;
foreach ( $comments as $comment )
	get_comment_type() == "comment" ? ++$comment_count : ++$ping_count;
?>
<?php if ( $comment_count ) : ?>
<?php $wpbx_comment_alt = 0 ?>

	<div id="comments-list" class="comments clearfix">
		<h3 class="section-title"><?php printf($comment_count > 1 ? __('<span>%d</span> Commentaires', 'wpbx') : __('<span>Un</span> Commentaire', 'wpbx'), $comment_count) ?></h3>

		<ul>
<?php wp_list_comments('type=comment&callback=wpbx_comment'); ?>


		</ul>

		<div id="nav-comm" class="navigation clearfix">
			<div class="alignleft"><?php previous_comments_link() ?></div>
			<div class="alignright"><?php next_comments_link() ?></div>
		</div>
	</div><!-- #comments-list .comments -->

<?php endif; // REFERENCE: if ( $comment_count ) ?>
<?php if ( $ping_count ) : ?>
<?php $wpbx_comment_alt = 0 ?>

	<div id="trackbacks-list" class="comments clearfix">
		<h3 class="section-title"><?php printf($ping_count > 1 ? __('<span>%d</span> Trackbacks', 'wpbx') : __('<span>One</span> Trackback', 'wpbx'), $ping_count) ?></h3>

		<ul>
<?php wp_list_comments('type=pings&callback=wpbx_comment'); ?>
		</ul>

		<div id="nav-pings" class="navigation clearfix">
			<div class="alignleft"><?php previous_comments_link( '&laquo; Older Trackbacks' ); ?></div>
			<div class="alignright"><?php next_comments_link( 'Newer Trackbacks &raquo;' ) ?></div>
		</div>
	</div><!-- #trackbacks-list .comments -->

<?php endif // REFERENCE: if ( $ping_count ) ?>

<?php else : // this is displayed if there are no comments so far ?>

	<?php if ('open' == $post->comment_status) : ?>
	<!-- If comments are open, but there are no comments. -->

	 <?php else : // comments are closed ?>
		<p class="nocomments"><?php _e( 'Les commentaires sont fermes.' , 'wpbx' ); ?></p>

	<?php endif; ?>
<?php endif; ?>

<?php if ( 'open' == $post->comment_status ) : ?>
<?php $req = get_option('require_name_email'); // Checks if fields are required. Thanks, Adam. ;-) ?>

	<div id="respond" class="clearfix">
		<h3 class="section-title"><?php comment_form_title(__( 'Laisser un commentaire' , 'wpbx' ), __( 'Laisser un commentaire a %s' , 'wpbx' )); ?></h3>

		<p class="comm-cancel"><?php cancel_comment_reply_link(__( 'Fermé' , 'wpbx' )); ?></p>

		<div class="formcontainer">
<?php if ( get_option('comment_registration') && !$user_ID ) : ?>
			<p id="login-req">
			<?php printf(__('Vous devez vous<a href="%s" title="Log in">identifier</a> pour laisser en commentaire.', 'wpbx'),
				get_bloginfo('wpurl') . '/wp-login.php?redirect_to=' . get_permalink() ) ?></p>
		</div>

<?php else : ?>

<script type="text/javascript">
	function sanitizeCommentFields(form) {
		if (form.url.value == 'Website') {
			form.url.value = '';
		}
		if (form.comment.value == 'Comment') {
			form.comment.value = '';
		}
		return true;
}
</script>

			<form id="commentform" class="clearfix" action="<?php bloginfo('wpurl') ?>/wp-comments-post.php" method="post" onsubmit="javascript:sanitizeCommentFields(this);">

<?php if ( $user_ID ) : ?>
				<p id="login">
				<?php printf( __( '<span class="loggedin">Connecté en tant que <a href="%1$s" title="Connecté en tant que %2$s">%2$s</a>.</span> <span class="logout"><a href="%3$s" title="Se retirer du compte">Se retirer?</a></span>', 'wpbx' ),
					get_bloginfo('wpurl') . '/wp-admin/profile.php',
					wp_specialchars( $user_identity, 1 ),
					get_bloginfo('wpurl') . '/wp-login.php?action=logout&amp;redirect_to=' . get_permalink() )
				?>
				</p>
<?php else : ?>

				<p class="comm-notes"><?php _e( 'Ajoutez un commentaire maintenant' , 'wpbx' ); ?></p>

				<p class="comm-notes"><?php _e( 'Votre email ne sera <em>jamais</em> partager.', 'wpbx' ) ?> <p> <?php if ($req) _e( 'Obligatoire <span class="required">*</span>', 'wpbx' ) ?></p></p>

				<div class="form-input"><input id="author" name="author" class="text<?php if ($req) echo ' required'; ?>" type="text" value="<?php _e( 'Nom', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>" onfocus="if (this.value == '<?php _e( 'Nom', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e( 'Nom', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>';}" size="30" maxlength="50" tabindex="3" /></div>

				<div class="form-input"><input id="email" name="email" class="text<?php if ($req) echo ' required'; ?>" type="text" value="<?php _e( 'Email', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>" onfocus="if (this.value == '<?php _e( 'Email', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e( 'Email', 'wpbx' ) ?><?php if ($req) _e( '*', 'wpbx' ) ?>';}" size="30" maxlength="50" tabindex="4" /></div>

				<div class="form-input"><input id="url" name="url" class="text" type="text" value="<?php _e( 'Site web', 'wpbx' ) ?>" onfocus="if (this.value == '<?php _e( 'Site web', 'wpbx' ) ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e( 'Site web', 'wpbx' ) ?>';}" size="30" maxlength="50" tabindex="5" /></div>
<?php endif // REFERENCE: * if ( $user_ID ) ?>

				<div>
<?php comment_id_fields(); ?>
					<input type="hidden" name="redirect_to" value="<?php echo htmlspecialchars($_SERVER["REQUEST_URI"]); ?>" />
				</div>

				<div class="form-textarea"><textarea id="comment" name="comment" class="text required"  onfocus="if (this.value == '<?php _e( 'Commentaire', 'wpbx' ) ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e( 'Commentaire', 'wpbx' ) ?>';}" cols="45" rows="6" tabindex="6"><?php _e( 'Commentaire', 'wpbx' ) ?></textarea></div>

				<div class="form-submit"><input id="submit" name="submit" class="button" type="submit" value="<?php _e( 'Envoyer', 'wpbx' ) ?>" tabindex="7" /><input type="hidden" name="comment_post_ID" value="<?php echo $id ?>" /></div>

				<div class="form-option"><?php do_action( 'comment_form', $post->ID ) ?></div>

			</form><!-- #commentform -->
		</div><!-- .formcontainer -->
<?php endif // REFERENCE: if ( get_option('comment_registration') && !$user_ID ) ?>

	</div><!-- #respond -->
<?php endif // REFERENCE: if ( 'open' == $post->comment_status ) ?>

</div><!-- #comments -->
