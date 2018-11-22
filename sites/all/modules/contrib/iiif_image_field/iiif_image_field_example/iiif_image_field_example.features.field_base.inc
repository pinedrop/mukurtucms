<?php
/**
 * @file
 * iiif_image_field_example.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function iiif_image_field_example_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_linked_image'.
  $field_bases['field_linked_image'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_linked_image',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'iiif_image_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'iiif_image_field',
  );

  // Exported field_base: 'field_static_image'.
  $field_bases['field_static_image'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_static_image',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'iiif_image_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'iiif_image_field',
  );

  // Exported field_base: 'field_zoomable_image'.
  $field_bases['field_zoomable_image'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_zoomable_image',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'iiif_image_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'iiif_image_field',
  );

  return $field_bases;
}
