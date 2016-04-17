<?php
/*
Template Name: Single Room
*/
?>


<?php get_header('room') ?>

<?php $title = get_the_title(); ?>
<div id="wrapper">

	<div id="container">
		<div id="contentfull">
			<?php the_post() ?>

			<div class="entry-wide">

				<div class="tofit">
					<?php echo get_avatar( get_the_author_meta( 'ID' )); ?>
					<p>
				 	<?php $test = the_author_posts_link()?>
					<?php echo '<a href="' ?>
				 	<?php echo $test ?>
				 	<?php echo '">' ?>
					<?php echo '</a>' ?>
				 	</p>
				</div>
				<div class="tofit2">			
				<h2 class="page-title"><?php the_title() ?></h2>
				<p>Type de propriete: 
				 	<?php echo get_post_meta($post->ID, 'type', true) ?><br />
				Cuisine: 
				 	<?php echo get_post_meta($post->ID, 'kitchen', true) ?><br />
				Internet: 
				 	<?php echo get_post_meta($post->ID, 'internet', true) ?><br />
				 Chauffage: 
				 	<?php echo get_post_meta($post->ID, 'heat', true) ?>
								 </p>

					<p><?php the_content() ?></p>

				</div>
				<div class="tofit"> 
				<?php if ( get_post_custom_values('comments') ) comments_template() ?>
		 		<?php echo get_post_meta($post->ID, 'price', true) ?>
		 		 $ /par nuit</div>

			</div><!-- entry -->
				
				<?php comments_template(); ?> 


		</div><!-- #contentfull -->
	</div><!-- #container -->
</div><!-- #wrapper -->
<?php get_footer() ?>
