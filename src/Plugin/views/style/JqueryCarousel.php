<?php

/**
 * @file
 * Definition of Drupal\views\Plugin\views\style\Grid.
 */

namespace Drupal\jquery_carousel\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render each item in a grid cell.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "jquery_carousel",
 *   title = @Translation("jQuery Carousel plugin"),
 *   help = @Translation("Display the results as a jquery Carousel."),
 *   theme = "views_view_jquery_carousel",
 *   display_types = {"normal"}
 * )
 */
class JqueryCarousel extends StylePluginBase {

  /**
   * {@inheritdoc}
   */
  protected function defineOptions() {
    $options = parent::defineOptions();
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
	  $carousel_config_form = jquery_carousel_config_form();
	  $form = array_merge($form, $carousel_config_form);
  }

	/**
	 * {@inheritdoc}
	 */
	public function validateOptionsForm(&$form, FormStateInterface $form_state) {

		$selector = $form_state->getValue(array('style_options', 'selector'));
		$error = _jquery_carousel_config_validate('options][selector', $selector, 'view');
		if($error) {
			$form_state->setErrorByName('selector', t("Selector should any special characters or spaces. Only special character allowed is '-'"));
		}
	}

}
