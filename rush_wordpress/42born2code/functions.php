

<?php add_action( 'init', 'create_post_type' );
function create_post_type() {
  register_post_type( 'room',
    array(
      'labels' => array(
        'name' => __( 'Rooms' ),
        'singular_name' => __( 'Room' )
      ),
      'public' => true,
      'supports' => array('title', 'editor', 'comments', 'thumbnail')
    )
  );
}
register_taxonomy( 'location', 'room', array( 
	'hierarchical' => true, 'label' => 'Location', 'query_var' => true, 'rewrite' => true ) )

?>

<?php
//Ici on ajoute les actions/exécutions
add_action( 'admin_menu', 'my_create_post_meta_box' );
add_action( 'save_post', 'my_save_post_meta_box');

function my_create_post_meta_box() {
//*Cf Codex pour voir les différents paramètres de la fonction add_meta_box()
	add_meta_box( 'meta_price', 'Prix par nuit', 'room_price', 'room', 'normal', 'high' );
	add_meta_box( 'meta_type', 'Type de Propriete', 'housing_type', 'room', 'normal', 'high' );
	add_meta_box( 'meta_equipement', 'Equipements', 'equipements', 'room', 'normal', 'high' );
}

function room_price($post){
  $val = get_post_meta($post->ID,'price',true);
  echo '<label for="prix-par-nuit">Prix par nuit</label>';
  echo '<input id="prix-par-nuit" type="number" name="price" value="'.$val.'" />';
}

function housing_type($post){
		$val = get_post_meta($post->ID,'type',true);
		echo '<select name="type">';
		echo '<option value="flat"';
		if ($val == 'flat')
			echo 'selected';
		echo '>Appartement</option>';
		echo '<option value="house"';
		if ($val == 'house')
			echo 'selected';
		echo '>Maison</option>';
		echo '</select>';
}

function equipements($post){
		$val0 = get_post_meta($post->ID,'kitchen',true);
		$val1 = get_post_meta($post->ID,'heat',true);
		$val2 = get_post_meta($post->ID,'internet',true);
		echo '<label for="cuisine">Cuisine </label>';
		echo '<input id="cuisine" type="checkbox" name="kitchen" value="yes"';
		if ($val0 == 'yes')
			echo ' checked';
		echo '>';
		echo '<label for="heat">Chauffage </label>';
		echo '<input id="heat" type="checkbox" name="heat" value="yes"';
		if ($val1 == 'yes')
			echo ' checked';
		echo '>';
		echo '<label for="internet">Internet </label>';
		echo '<input id="internet" type="checkbox" name="internet" value="yes"';
		if ($val2 == 'yes')
			echo ' checked';
		echo '>';
}

function my_save_post_meta_box($post_ID) {
if(isset($_POST['price'])){
		update_post_meta($post_ID,'price', esc_html($_POST['price']));
	}
if(isset($_POST['type'])){
		update_post_meta($post_ID,'type', esc_html($_POST['type']));
	}
if(isset($_POST['kitchen'])){
		update_post_meta($post_ID,'kitchen', esc_html($_POST['kitchen']));
	} else {
		update_post_meta($post_ID,'kitchen', '');
	}
	if(isset($_POST['heat'])){
		update_post_meta($post_ID,'heat', esc_html($_POST['heat']));
	} else {
		update_post_meta($post_ID,'heat', '');
	}
	if(isset($_POST['internet'])){
		update_post_meta($post_ID,'internet', esc_html($_POST['internet']));
	} else {
		update_post_meta($post_ID,'internet', '');
	}	
}
?>


<?php

add_action( 'init', 'register_my_menus' );
function register_my_menus() {
	register_nav_menus(
		array(
			'primary-menu' => __( 'main_menu' ),
		));
}

add_theme_support( 'post-thumbnails' );
set_post_thumbnail_size( 200, 150, true ); // Normal post thumbnails

add_custom_background();

// Custom comment listing
function wpbx_comment($comment, $args, $depth) {
	$GLOBALS['comment'] = $comment;
	$commenter = get_comment_author_link();
	if ( ereg( '<a[^>]* class=[^>]+>', $commenter ) ) {
		$commenter = ereg_replace( '(<a[^>]* class=[\'"]?)', '\\1url ' , $commenter );
	} else {
		$commenter = ereg_replace( '(<a )/', '\\1class="url "' , $commenter );
	}
	$avatar_email = get_comment_author_email();
    $avatarURL = get_bloginfo('template_directory');
	$avatar = str_replace( "class='avatar", "class='avatar", get_avatar( $avatar_email, 40, $default = $avatarURL . '/images/gravatar-blank.jpg' ) );
?>
	<li <?php comment_class(); ?> id="comment-<?php comment_ID() ?>">
		<div id="div-comment-<?php comment_ID(); ?>">
			<div class="comment-author vcard">
				<?php echo $avatar . ' <span class="fn n">' . $commenter . '</span>'; ?>
			</div>
			<div class="comment-meta">
				<?php printf(__('%1$s <span class="meta-sep">|</span> <a href="%3$s" title="Permalink to this comment">Permalink</a>', 'wpbx'),
					get_comment_date('j M Y', '', '', false),
					get_comment_time(),
					'#comment-' . get_comment_ID() );
					edit_comment_link(__('Edit', 'wpbx'), ' <span class="meta-sep">|</span> <span class="edit-link">', '</span>');
				?>
				<span class="reply-link">
					<span class="meta-sep">|</span> <?php comment_reply_link(array_merge( $args, array('add_below' => 'div-comment', 'depth' => $depth, 'max_depth' => $args['max_depth']))) ?>
				</span>
			</div>

			<?php if ($comment->comment_approved == '0') _e("\t\t\t\t\t<span class='unapproved'>Your comment is awaiting moderation.</span>\n", 'wpbx') ?>

			<div class="comment-content"><?php comment_text() ?></div>
		</div>
<?php
}
// wpbx_comment()

// For category lists on category archives: Returns other categories except the current one (redundant)
function wpbx_cat_also_in($glue) {
	$current_cat = single_cat_title( '', false );
	$separator = "\n";
	$cats = explode( $separator, get_the_category_list($separator) );
	foreach ( $cats as $i => $str ) {
		if ( strstr( $str, ">$current_cat<" ) ) {
			unset($cats[$i]);
			break;
		}
	}
	if ( empty($cats) )
		return false;

	return trim(join( $glue, $cats ));
}

// For tag lists on tag archives: Returns other tags except the current one (redundant)
function wpbx_tag_also_in($glue) {
	$current_tag = single_tag_title( '', '',  false );
	$separator = "\n";
	$tags = explode( $separator, get_the_tag_list( "", "$separator", "" ) );
	foreach ( $tags as $i => $str ) {
		if ( strstr( $str, ">$current_tag<" ) ) {
			unset($tags[$i]);
			break;
		}
	}
	if ( empty($tags) )
		return false;

	return trim(join( $glue, $tags ));
}

// Generate custom excerpt length
function wpbx_excerpt_length($length) {
	return 75;
}
add_filter('excerpt_length', 'wpbx_excerpt_length');


// Widgets plugin: intializes the plugin after the widgets above have passed snuff
function wpbx_widgets_init() {
	if ( !function_exists('register_sidebars') ) {
		return;
	}
	// Formats the theme widgets, adding readability-improving whitespace
	$p = array(
		'before_widget'  =>   '<li id="%1$s" class="widget %2$s">',
		'after_widget'   =>   "</li>\n",
		'before_title'   =>   '<h3 class="widget-title">',
		'after_title'    =>   "</h3>\n"
	);
	register_sidebars( 1, $p );
	register_sidebar( array(
		'name' => 'Footer',
		'before_widget' => '<div>',
		'after_widget' => "</div>\n",
		'before_title' => '<h3>',
		'after_title' => "</h3>\n"
));
} // ici on ferme la fonction function wpbx_widgets_init()


// Runs our code at the end to check that everything needed has loaded
add_action( 'init', 'wpbx_widgets_init' );

// Adds filters for the description/meta content
add_filter( 'archive_meta', 'wptexturize' );
add_filter( 'archive_meta', 'convert_smilies' );
add_filter( 'archive_meta', 'convert_chars' );
add_filter( 'archive_meta', 'wpautop' );

// Translate, if applicable
load_theme_textdomain('wpbx');


// Construct the WordPress header
remove_action('wp_head', 'start_post_rel_link');
remove_action('wp_head', 'index_rel_link');
remove_action('wp_head', 'adjacent_posts_rel_link');
remove_action('wp_head', 'next_post_rel_link');
remove_action('wp_head', 'previous_post_rel_link');

/* Disable WordPress Admin Bar for all users but admins. */
  show_admin_bar(false);

