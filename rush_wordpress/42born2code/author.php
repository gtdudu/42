<?php get_header() ?>

		<div id="content1">
		

<?php the_post() ?>

<?php rewind_posts() ?>

<?php 
$curauth = (isset($_GET['author_name'])) ? get_user_by('slug', $author_name) : get_userdata(intval($author));
?>

<?php $args = array(
	'post_type' => 'room',
	'author' => $curauth->ID	);
$query = new WP_Query( $args ); ?>
	<?php $count = 0; ?>

<?php while ( $query->have_posts() ) : $query->the_post() ?>
	<?php if ($count == 0) { ?>
	<div id="bloc">					
			<?php echo get_avatar( get_the_author_meta( 'ID' )); ?>
			<p>Facebook : <?php echo esc_attr ( get_the_author_meta( 'facebook', get_the_author_meta( 'ID' ) ) ); ?><br />
			Telephone : <?php echo esc_attr ( get_the_author_meta( 'telephone', get_the_author_meta( 'ID' ) ) ); ?></p>

			</div>
			<div id="bloc1">
			<h1>
			Bonjour, je m'appelle  <?php  echo get_the_author_meta('display_name', $userID); ?> !</h1>
			<?php $vardate = esc_attr ( get_the_author_meta( 'user_registered', get_the_author_meta( 'ID' ) ) ); ?><?php echo 'Membre depuis '; echo date("F Y", strtotime($vardate)); ?><br />
			<br />
			<br />
			<h3>Les chambres que je loue :</h3>

			</div>
	<?php $count = 1; } ?>
			<div id="bloc2">
				<p class="entry-title"><a href="<?php the_permalink() ?>" title="<?php printf( __('Permalink to %s', 'wpbx'), the_title_attribute('echo=0') ) ?>" rel="bookmark"><?php the_title() ?></a></p>
			</div>
<?php endwhile; ?>

			<div class="navigation clearfix">
				<div class="nav-previous"><?php next_posts_link(__( 'Precedent <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
				<div class="nav-next"><?php previous_posts_link(__( 'Suivant <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
			</div>

		</div><!-- #content -->

<?php get_footer() ?>