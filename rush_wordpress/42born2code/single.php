<?php get_header() ?>
<div id="content">
	<?php the_post() ?>
	<div class="entry-single">
		<div class="entry-top">
			<h2 class="entry-title"><?php the_title() ?></h2>
			<div class="entry-meta-top">
				<span class="entry-date"><?php unset($previousday); printf( __( '%1$s', 'wpbx' ), the_date( 'D, j M Y', '', '', false ) ) ?></span>
				<span class="entry-meta-sep">|</span>
				<span class="entry-comm">Publié dans <?php the_category(', '); ?></span>
			</div>
		</div>
		<div class="entry-content clearfix">
			<?php the_content() ?>
		</div>
		<div class="entry-meta entry-bottom">
			<?php the_tags( __( '<span class="tag-links">Tags: ', 'wpbx' ), ", ", "</span>\n" ) ?>
		</div>
	</div><!-- .post -->
	<?php comments_template(); ?>
</div><!-- #content -->
<?php get_footer() ?>