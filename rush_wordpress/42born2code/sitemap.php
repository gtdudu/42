<?php
/*
Template Name: plandusite
*/
?>
<?php get_header() ?>
<div id="wrapper">
	<div id="container">
		<div id="contentfull">
		<?php get_template_part( 'loop', 'page' ); ?>
			<h3><?php _e('Les pages') ?></h3>
		<ul>
			<?php wp_list_pages('depth=0&sort_column=menu_order&title_li=' ); ?>
		</ul>
			<h3><?php _e('Les cat&eacute;gories') ?></h3>
		<ul>
			<?php wp_list_categories('title_li=&hierarchical=0&show_count=1') ?>
		</ul>
			<h3>Les articles par cat&eacute;gories</h3>
			<?php $saved = $wp_query;
			$cats = get_categories();
			foreach ($cats as $cat) {
			query_posts('showposts=999&cat='.$cat->cat_ID);
			?>
			<h4><?php echo $cat->cat_name; ?></h4>
		<ul>
			<?php while (have_posts()) : the_post(); ?>
			<li style="font-weight:normal !important;"><a href="<?php the_permalink() ?>"><?php the_title(); ?></a> - <?php _e('Commentaires') ?> (<?php echo $post->comment_count ?>)
			</li>
			<?php endwhile;  ?>
		</ul>
		<?php } $wp_query = $saved; ?>
		<br />
		</div><!-- #contentfull -->
	</div><!-- #container -->
</div><!-- #wrapper -->
<?php get_footer() ?>