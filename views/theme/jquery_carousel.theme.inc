<?php

/**
 * @param $vars
 */
function _jquery_carousel_preprocess_jquery_carousel(&$vars) {
  drupal_add_library('system', 'ui.widget');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/src/js/jquery.rs.carousel.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/src/js/jquery.rs.carousel-autoscroll.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/src/js/jquery.rs.carousel-continuous.js');
  drupal_add_js(libraries_get_path('jquery-ui-carousel') . '/src/js/jquery.rs.carousel-touch.js');
  drupal_add_js(drupal_get_path('module', 'jquery_carousel') . '/js/jquery_carousel_init.js');
  drupal_add_js(array('jquery_carousel' => $vars['options']), 'setting');
  drupal_add_css(libraries_get_path('jquery-ui-carousel') . '/src/css/jquery.rs.carousel.css');
}