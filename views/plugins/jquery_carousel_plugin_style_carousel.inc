<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in a Carousel.
 *
 * @ingroup views_style_plugins
 */
class JqueryCarouselPluginStyleCarousel extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Build the settings form for the view.
   */
  function options_form(&$form, &$form_state) {
    $carousel_config_form = jquery_carousel_config_form();
    $form = array_merge($form, $carousel_config_form);

    foreach (array_keys($form) as $key) {
      $form[$key]['#default_value'] = isset($this->options[$key]) ? $this->options[$key] : $form[$key]['#default_value'];
    }
  }
}
