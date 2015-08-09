<?php

/**
 * @file
 * Rules UI class.
 */

/**
 * UI for colorbox settings.
 */
class RulesDataUIFFCColorbox extends RulesDataUI implements RulesDataDirectInputFormInterface {
  public static function getDefaultMode() {
    return 'input';
  }

  public static function inputForm($name, $info, $settings, RulesPlugin $element) {
    $default_settings = isset($settings['ffc_colorbox_settings']) ? $settings['ffc_colorbox_settings'] : array();
    $view_mode = 'default';
    $instance['entity_type'] = 'node';
    $instance['display'][$view_mode]['settings'] = $default_settings + array(
        'colorbox_node_style' => '',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => '',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => '',
        'colorbox_caption_custom' => '',
      );
    $fake_field = $fake_form = $fake_form_state = array();
    $form[$name] = colorbox_field_formatter_settings_form($fake_field, $instance, $view_mode, $fake_form, $fake_form_state);
    $form[$name]['colorbox_gallery_custom']['#states']['visible'] = array(
      ':input[name$="[colorbox_gallery]"]' => array('value' => 'custom'),
    );
    $form[$name]['colorbox_caption_custom']['#states']['visible'] = array(
      ':input[name$="[colorbox_caption]"]' => array('value' => 'custom'),
    );
    unset($form[$name]['colorbox_token']);
    return $form;
  }

  public static function render($settings) {
    // tbd: add theme to show colorbox parameters
    $field = array();
    $view_mode = 'default';
    $instance['display'][$view_mode]['settings'] = $settings;
    return array(
      'content' => array('#markup' => colorbox_field_formatter_settings_summary($field, $instance, $view_mode)),
      '#attributes' => array('class' => array('rules-parameter-ffc-colorbox', 'rules-parameter-configuration')),
    );
  }
}