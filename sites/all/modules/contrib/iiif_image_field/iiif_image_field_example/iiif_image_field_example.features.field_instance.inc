<?php
/**
 * @file
 * iiif_image_field_example.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function iiif_image_field_example_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-iiif_image-field_linked_image'.
  $field_instances['node-iiif_image-field_linked_image'] = array(
    'bundle' => 'iiif_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'iiif_image_field',
        'settings' => array(
          'behavior' => 'link_to_content',
          'display_caption' => 1,
          'display_first_only' => 0,
          'format' => 'jpg',
          'height' => '',
          'quality' => 'native',
          'region_h' => '',
          'region_w' => '',
          'region_x' => '',
          'region_y' => '',
          'rotation' => 0,
          'width' => 300,
        ),
        'type' => 'iiif_image_field_formatter',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_linked_image',
    'label' => 'Linked image',
    'required' => 0,
    'settings' => array(
      'allowed_types' => array(
        0 => 'libimages',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'iiif_image_field',
      'settings' => array(),
      'type' => 'iiif_image_field_widget',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-iiif_image-field_static_image'.
  $field_instances['node-iiif_image-field_static_image'] = array(
    'bundle' => 'iiif_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'iiif_image_field',
        'settings' => array(
          'behavior' => 'static_image',
          'display_caption' => 1,
          'display_first_only' => 0,
          'format' => 'jpg',
          'height' => '',
          'quality' => 'native',
          'region_h' => '',
          'region_w' => '',
          'region_x' => '',
          'region_y' => '',
          'rotation' => 0,
          'width' => 300,
        ),
        'type' => 'iiif_image_field_formatter',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_static_image',
    'label' => 'Static image',
    'required' => 0,
    'settings' => array(
      'allowed_types' => array(
        0 => 'libimages',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'iiif_image_field',
      'settings' => array(),
      'type' => 'iiif_image_field_widget',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-iiif_image-field_zoomable_image'.
  $field_instances['node-iiif_image-field_zoomable_image'] = array(
    'bundle' => 'iiif_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'iiif_image_field',
        'settings' => array(
          'behavior' => 'zoom',
          'display_caption' => 1,
          'display_first_only' => 0,
          'format' => 'jpg',
          'height' => '',
          'quality' => 'native',
          'region_h' => '',
          'region_w' => '',
          'region_x' => '',
          'region_y' => '',
          'rotation' => 0,
          'width' => 300,
        ),
        'type' => 'iiif_image_field_formatter',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_zoomable_image',
    'label' => 'Zoomable image',
    'required' => 0,
    'settings' => array(
      'allowed_types' => array(
        0 => 'libimages',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'iiif_image_field',
      'settings' => array(),
      'type' => 'iiif_image_field_widget',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Linked image');
  t('Static image');
  t('Zoomable image');

  return $field_instances;
}
