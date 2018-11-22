<?php
/**
 * @file
 * iiif_image_field_example.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function iiif_image_field_example_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function iiif_image_field_example_node_info() {
  $items = array(
    'iiif_image' => array(
      'name' => t('IIIF Image'),
      'base' => 'node_content',
      'description' => t('An example content-type with a IIIF image field.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
