<?php
/**
 * @file
 * Theme & preprocess functions for the jQuery Carousel module.
 */

/**
 * @param $vars
 */
function _jquery_carousel_preprocess_jquery_carousel(&$vars) {
  _jquery_carousel_settings_format($vars['options']);
  _jquery_carousel_include_css_js($vars['options']);
}