<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" <?php language_attributes() ?>>
<head profile="http://gmpg.org/xfn/11">

<meta http-equiv="content-type" content="<?php bloginfo('html_type') ?>; charset=<?php bloginfo('charset') ?>" />
<meta name="description" content="" />
<meta name="keywords" content="" />
<title><?php wp_title( '-', true, 'right' ); echo wp_specialchars( get_bloginfo('name'), 1 ) ?></title>
<link rel="stylesheet" href="<?php bloginfo('stylesheet_directory'); ?>/style.css" type="text/css" media="screen" />

	<!--[if lte IE 6]><script type="text/javascript" src="<?php bloginfo('template_url'); ?>/js/supersleight-min.js"></script><![endif]-->
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/jquery.js'); ?>
<?php wp_enqueue_script('superfish', get_bloginfo('template_directory').'/js/superfish.js', array('jquery'), '1.7'); ?>
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/nav.js'); ?>
<?php if (trim(get_option('ft_header_code')) <> "") { echo stripslashes(get_option('ft_header_code')); } ?>
<?php if (is_singular()) wp_enqueue_script('comment-reply'); ?>

<?php wp_head(); ?> <!-- #NE PAS SUPPRIMER cf. codex wp_head() -->
</head>
<body <?php body_class() ?>>
<?php if ( is_home() ) { ?>
<div id="top">
<div id="header">
		<a href="<?php echo get_option('home'); ?>">
			<img id="site-logo" src="<?php bloginfo('template_directory'); ?>/images/logo.png" alt="<?php bloginfo('name'); ?>" />
		</a>
		<a href="<?php  	$url = admin_url( 'edit.php?post_type=room', 'http' );
			echo $url; ?>" id="button2" class="btn">Publiez une annonce</a>
		<p id="button1"><?php wp_loginout(); ?></p>
		<p id="button1"><?php wp_register('', ''); ?></p>

</div><!--  #header -->
	<div class="pads clearfix" id="middle">
		<h1 id="intro">BIENVENUE A LA MAISON</h1>
		<h3 id="subintro">Louez des logements uniques aupres d'hotes locaux dans 190+ pays</h3>
		<a href="http://wp.local.42.fr:8080/?p=11" id="button3">MODE D'EMPLOI</a>
	</div>
	<div id="blocsearch"> <?php get_search_form(); ?>
	</div>

</div>
 <?php } else { ?>
 <div id="tip">
 <nav><?php wp_nav_menu( array( 'theme_location' => 'primary-menu', 'sort_column' => 'menu_order', 'container_class' => 'nav' ) ); ?></nav>

 <div id="header-bis">
		<a href="<?php echo get_option('home'); ?>">
			<img id="site-logo2" src="<?php bloginfo('template_directory'); ?>/images/blacklogo.png" alt="<?php bloginfo('name'); ?>" />
		</a>
		<div id="blocsearch2"> 
		</div>

				<?php get_search_form(); ?>


				
		<a href="<?php  	$url = admin_url( 'edit.php?post_type=room', 'http' );
			echo $url; ?>" id="button2" class="btn">Publiez une annonce</a>
		<p id="button1"><?php wp_loginout(); ?></p>
		<p id="button1"><?php wp_register('', ''); ?></p>

</div><!--  #header -->

</div>
<?php } ?>
<div id="container">
	<div class="pads clearfix">