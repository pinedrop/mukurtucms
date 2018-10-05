<?php

/**
 * @file
 * Admin page callback file for Image-Recognition CAPTCHA.
 */

/**
 * Form constructor for the Image-Recognition CAPTCHA settings form.
 *
 * @see system_settings_form()
 *
 * @ingroup forms
 */
function visualdict_captcha_settings_form() {
  $form['visualdict_captcha_challenge_prompt'] = array(
    '#type' => 'textfield',
    '#title' => t('Challenge prompt'),
    '#default_value' => _visualdict_captcha_get_challenge_prompt(),
    '#maxlength' => 180,
  );
  $form['visualdict_captcha_dictionary'] = array(
    '#type' => 'textarea',
    '#title' => t('Visual dictionary map'),
    '#default_value' => _visualdict_captcha_get_dictionary_value(),
    '#description' => t('Enter the audio filename followed by // then one or more image filenames separated by /.'),
  );
  $form['visualdict_captcha_num_correct_images'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of correct images to display'),
    '#default_value' => _visualdict_captcha_get_num_correct_images(),
    '#element_validate' => array('element_validate_integer_positive'),
    '#maxlength' => 2,
  );
  $form['visualdict_captcha_num_incorrect_images'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of incorrect images to display'),
    '#default_value' => _visualdict_captcha_get_num_incorrect_images(),
    '#element_validate' => array('element_validate_integer_positive'),
    '#maxlength' => 2,
  );
  return system_settings_form($form);
}

/****************************************************************************/
/* Settings retrieval functions                                             */
/****************************************************************************/
/**
 * Gets challenge prompt.
 */
function _visualdict_captcha_get_challenge_prompt() {
  $default_prompt = t("<strong>Select all images with trees:</strong>");
  $prompt = variable_get("visualdict_captcha_challenge_prompt", $default_prompt);
  return filter_xss($prompt);
}

/**
 * Gets dictionary value
 */
function _visualdict_captcha_get_dictionary_value() {
  $default_prompt = t("");
  $prompt = variable_get("visualdict_captcha_dictionary", $default_prompt);
  return filter_xss($prompt);
}

/**
 * Gets number of correct images.
 */
function _visualdict_captcha_get_num_correct_images() {
  return variable_get("visualdict_captcha_num_correct_images", 4);
}

/**
 * Gets number of incorrect images.
 */
function _visualdict_captcha_get_num_incorrect_images() {
  return variable_get("visualdict_captcha_num_incorrect_images", 6);
}


/****************************************************************************/
/* Convenience functions for interpreting settings                          */
/****************************************************************************/

function _visualdict_captcha_get_dictionary() {
  $value = _visualdict_captcha_get_dictionary_value();
  $items = _visualdict_captcha_get_image_filenames_from_image_filenames_value($value);
  $dict = array();
  foreach ($items as $item) {
    $bits = explode('//', $item);
    $dict[trim($bits[0])] = trim($bits[1]);
  }
  return $dict;
}


/**
 * Gets image filenames from an image filenames value.
 *
 * Converts the image filenames setting value into an array of
 * filenames, and returns that array.
 *
 * @param string $image_filenames_value
 *   An image filenames setting value.
 *
 * @return string[]
 *   Image filenames.
 */
function _visualdict_captcha_get_image_filenames_from_image_filenames_value($image_filenames_value) {
  $untrimmed_image_filenames = explode("\n", $image_filenames_value);
  $image_filenames = array_map('rtrim', $untrimmed_image_filenames);
  return $image_filenames;
}
