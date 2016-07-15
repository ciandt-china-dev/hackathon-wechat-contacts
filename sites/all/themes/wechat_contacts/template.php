<?php

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