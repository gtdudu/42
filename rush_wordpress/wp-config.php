<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier contient les réglages de configuration suivants : réglages MySQL,
 * préfixe de table, clefs secrètes, langue utilisée, et ABSPATH.
 * Vous pouvez en savoir plus à leur sujet en allant sur 
 * {@link http://codex.wordpress.org/fr:Modifier_wp-config.php Modifier
 * wp-config.php}. C'est votre hébergeur qui doit vous donner vos
 * codes MySQL.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d'installation. Vous n'avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en "wp-config.php" et remplir les
 * valeurs.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define('DB_NAME', 'db_database');

/** Utilisateur de la base de données MySQL. */
define('DB_USER', 'Admin');

/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', '123456');

/** Adresse de l'hébergement MySQL. */
define('DB_HOST', 'localhost');

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define('DB_CHARSET', 'utf8');

/** Type de collation de la base de données. 
  * N'y touchez que si vous savez ce que vous faites. 
  */
define('DB_COLLATE', '');

/**#@+
 * Clefs uniques d'authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant 
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clefs secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n'importe quel moment, afin d'invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'WM{-}h+D-3q#=$M+(QJ%T!#hzV9-W-z_PTlgq(fR]@62(S.wN2f0yfRguDkYR@kO');
define('SECURE_AUTH_KEY',  '6a8;?F:}wG7-Lm^3m91Q3We88K`1e^+;#r--Su-^{<:)k0A1?dP#jq#RMpPEp&[i');
define('LOGGED_IN_KEY',    '!& KZ}C(!q`&q|.$/$5DVOMl=#lFY}97p--f;0*($[VN9v<+}$]@J|KlW#;[+|wS');
define('NONCE_KEY',        '5pFM>@A Q3wWkDlqExWtAn.iU&`?s^xli7t&8#V*{swXV|~+|9(ll:&SbZ2>`D[F');
define('AUTH_SALT',        '9r|:=b/*6>V.(^JnJ>ah(wXmX@^D0ey!s2y.LQ`(h|t#)-v^ bn5V+z32|A&5-3)');
define('SECURE_AUTH_SALT', 'mcFx73CQytBVU#y$^yRTqZl=+8k7]RO~WZylFTt8nM}}~E0gypW._=h ?%1fTp#{');
define('LOGGED_IN_SALT',   '<P/xvK-K5u*qon4eF$)0*$|W+>cS2Omz_Fh!Q+(L*!a++Tt=>w[$d82U-slxFTMj');
define('NONCE_SALT',       'irghx_&|/Wk],+T.WVrzj*Fi9i/P1iadR+ }}?m6?^|Qz{Hn.) hU7H1-YE6SK|>');
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique. 
 * N'utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés!
 */
$table_prefix  = 'wp_';

/** 
 * Pour les développeurs : le mode deboguage de WordPress.
 * 
 * En passant la valeur suivante à "true", vous activez l'affichage des
 * notifications d'erreurs pendant votre essais.
 * Il est fortemment recommandé que les développeurs d'extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de 
 * développement.
 */ 
define('WP_DEBUG', false); 

/* C'est tout, ne touchez pas à ce qui suit ! Bon blogging ! */

/** Chemin absolu vers le dossier de WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once(ABSPATH . 'wp-settings.php');