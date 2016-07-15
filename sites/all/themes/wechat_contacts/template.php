<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */

/**
 * hook_js_alter()
 */
function wechat_contacts_js_alter(&$javascript) {
  
  // Update Jquery version
  // This is done using drupal_js_defaults in order to avoid
  // an "Undefined index: scope" error.
  // See: http://drupal.org/node/1306584
  $file = drupal_get_path('theme', 'wechat_contacts') . '/scripts/jquery-3.1.0.min.js';
  $javascript['misc/jquery.js'] = drupal_js_defaults($file);

  // Guarantee that jQuery is loaded before all other .js files
  $javascript['misc/jquery.js']['every_page'] = TRUE;
  $javascript['misc/jquery.js']['group'] = JS_LIBRARY;
  $javascript['misc/jquery.js']['weight'] = -20;
}