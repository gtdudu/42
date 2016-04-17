<?php get_header() ?>

		<div id="content">

<?php the_post() ?>

<?php if ( is_day() ) : ?>
			<h2 class="tag-page-title"><?php printf( __( 'Daily Archives: <span>%s</span>', 'wpbx' ), get_the_time(get_option('date_format')) ) ?></h2>
<?php elseif ( is_month() ) : ?>
			<h2 class="tag-page-title"><?php printf( __( 'Monthly Archives: <span>%s</span>', 'wpbx' ), get_the_time('F Y') ) ?></h2>
<?php elseif ( is_year() ) : ?>
			<h2 class="tag-page-title"><?php printf( __( 'Yearly Archives: <span>%s</span>', 'wpbx' ), get_the_time('Y') ) ?></h2>
<?php elseif ( isset($_GET['paged']) && !empty($_GET['paged']) ) : ?>
			<h2 class="tag-page-title"><?php _e( 'Blog Archives', 'wpbx' ) ?></h2>
<?php endif; ?>

<?php rewind_posts() ?>

<?php while ( have_posts() ) : the_post() ?>

		<div class="entry">
			<div class="entry-top">

				<h2 class="entry-title"><a href="<?php the_permalink() ?>" title="<?php printf( __('Permalink to %s', 'wpbx'), the_title_attribute('echo=0') ) ?>" rel="bookmark"><?php the_title() ?></a></h2>

				<div class="entry-meta-top">
					<span class="entry-date"><?php unset($previousday); printf( __( '%1$s', 'wpbx' ), the_date( 'D, j M Y', '', '', false ) ) ?></span>
					<span class="entry-meta-sep">|</span>
					<span class="entry-comm">Publié dans <?php the_category(', '); ?></span>
				</div>
<h3><?php if(function_exists('the_views')) { the_views(); } ?></h3>

			</div>

				<div class="entry-content clearfix">

					<div class= "entry-list-thumb">
						<a href="<?php the_permalink(); ?>" title="<?php printf(__( 'Read %s', 'wpbx' ), wp_specialchars(get_the_title(), 1)) ?>">
						<?php the_post_thumbnail(); ?>
						</a>
					</div>

					<div class="entry-content">
						<?php the_excerpt(); ?>
					</div>
				</div>

				<div class="entry-meta">
					<span class="entry-comm"><?php comments_popup_link( __( 'Pas de Commentaires', 'wpbx' ), __( '1 Commentaire', 'wpbx' ), __( '% Commentaires', 'wpbx' ) ) ?></span>
					<span class="entry-meta-sep">|</span>
					<span class="entry-more"><a href="<?php the_permalink() ?>" title="<?php printf(__('Continue reading %s'), wp_specialchars(get_the_title(), 1)) ?>"><?php _e( 'Lire plus', 'wpbx' ) ?></a></span>
				</div>
		</div><!-- .post -->

<?php endwhile; ?>

			<div class="navigation clearfix">
				<div class="nav-previous"><?php next_posts_link(__( 'Precedent <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
				<div class="nav-next"><?php previous_posts_link(__( 'Suivant <span class="meta-nav">Articles</span>', 'wpbx' )) ?></div>
			</div>

		</div><!-- #content -->

<?php get_sidebar() ?>
<?php get_footer() ?>