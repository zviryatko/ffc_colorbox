<?php
/**
 * @file
 * Rules integration for Field formatter conditions Colorbox.
 */

/**
 * Implements hook_rules_action_info().
 */
function ffc_colorbox_rules_action_info() {
  $base_parameters = array(
    'ffc_element' => array(
      'type' => 'element',
      'label' => t('Element'),
      'optional' => TRUE,
    ),
    'ffc_field' => array(
      'type' => 'element',
      'label' => t('Field'),
      'optional' => TRUE,
    ),
  );

  return array(
    'ffc_colorbox_rules_change_settings' => array(
      'label' => t('Change colorbox settings'),
      'group' => t('Field formatter conditions'),
      'parameter' => $base_parameters + array(
        'ffc_colorbox_settings' => array(
          'allow null' => TRUE,
          'optional' => TRUE,
          'type' => 'ffc_colorbox_settings',
          'label' => t('Colorbox settings'),
          'ui class' => 'RulesDataUIFFCColorbox',
        ),
      ),
    ),
  );
}

/**
 * Rules callback: change image style.
 */
function ffc_colorbox_rules_change_settings($ffc_element, $ffc_field, $empty, $configuration) {
  $settings = $configuration['ffc_colorbox_settings'];
  $ffc_element->fired = TRUE;
  foreach (element_children($ffc_element->element[$ffc_field]) as $key) {
    $ffc_element->element[$ffc_field][$key]['#display_settings'] = $settings;
  }
}
