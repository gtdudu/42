<?php get_header() ?>
<div id="content">
			<?php the_post() ?>
	<div class="entry">
			<h2 class="page-title">
				<a href="<?php echo get_permalink($post->post_parent) ?>" title="<?php printf( __( 'Return to %s', 'wpbx' ), wp_specialchars( get_the_title($post->post_parent), 1 ) ) ?>" rev="attachment"><?php echo get_the_title($post->post_parent) ?>
				</a>
			</h2>
			<div class="clearfix">
				<div class="entry-meta">
					<span class="entry-date"><?php unset($previousday); printf( __( '%1$s', 'wpbx' ), the_date( 'D, j M Y', '', '', false ) ) ?></span>
				</div>
				<h2 class="entry-title">
					<a href="<?php the_permalink() ?>" title="<?php printf( __('Permalink to %s', 'wpbx'), the_title_attribute('echo=0') ) ?>" rel="bookmark"><?php the_title() ?>
					</a>
				</h2>
				<div class="entry-content">
					<div class="entry-attachment"><a href="<?php echo wp_get_attachment_url($post->ID); ?>" title="<?php echo wp_specialchars( get_the_title($post->ID), 1 ) ?>" rel="attachment"><?php echo wp_get_attachment_image( $post->ID, 'large' ); ?></a></div>
					<div class="entry-caption"><?php if ( !empty($post->post_excerpt) ) the_excerpt() ?></div>
					<?php the_content() ?>
				</div>
			</div>
	</div><!-- #entry -->
	<div id="nav-images" class="navigation clearfix">
		<div class="nav-next"><?php next_image_link() ?></div>
		<div class="nav-previous"><?php previous_image_link() ?></div>
	</div>
<?php comments_template() ?>
</div><!-- #content -->

<?php get_sidebar() ?>
<?php get_footer() ?>