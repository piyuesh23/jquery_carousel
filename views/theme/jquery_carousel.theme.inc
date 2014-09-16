<?php
/**
 * @file
 * Theme & preprocess functions for the jQuery Carousel module.
 */

/**
 * @param $vars
 */
function _jquery_carousel_preprocess_jquery_carousel(&$vars) {
  drupal_add_library('system', 'ui.widget');
  drupal_add_css(libraries_get_path('jquery-ui-carousel') . '/dist/css/jquery.rs.carousel.css');
  drupal_add_css(drupal_get_path('module', 'jquery_carousel') . '/css/jquery_carousel.css');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/dist/js/jquery.rs.carousel.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/dist/js/jquery.rs.carousel-autoscroll.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/dist/js/jquery.rs.carousel-continuous.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/dist/js/jquery.rs.carousel-touch.js');
  drupal_add_js(drupal_get_path('module', 'jquery_carousel') . '/js/jquery_carousel_init.js');
  $carousel_form = jquery_carousel_config_form();

  foreach ($vars['options'] as $key => $opt) {
    if ((isset($carousel_form[$key]['#boolean'])) && ($carousel_form[$key]['#boolean'])) {
      $vars['options'][$key] = (bool)$vars['options'][$key];
    }
  }
  drupal_add_js(array('jquery_carousel' => $vars['options']), 'setting');
}