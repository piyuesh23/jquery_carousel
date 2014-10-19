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
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Build the settings form for the view.
   */
  public function options_form(&$form, &$form_state) {
    $carousel_config_form = jquery_carousel_config_form();
    $form = array_merge($form, $carousel_config_form);

    foreach (array_keys($form) as $key) {
      $form[$key]['#default_value'] = isset($this->options[$key]) ? $this->options[$key] : $form[$key]['#default_value'];
    }
  }

  /**
   * Validates the settings form values.
   */
  public function options_validate(&$form, &$form_state) {
    $selector = $form_state['input']['style_options']['selector'];
    preg_match('/[a-zA-Z]*/', $selector, $matches);

    if ((count($matches) === 1) && ($matches[0] === $selector)) {
      // Validation passes since the text entered doesn't contain any special characters.
    }
    else {
      form_set_error('options][selector', t('Plese enter string without any special characters or spaces.'));
    }
  }
}
