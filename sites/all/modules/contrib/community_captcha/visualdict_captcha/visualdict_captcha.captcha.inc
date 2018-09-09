<?php

/**
 * @file
 * Functions for generating an image-recognition CAPTCHA.
 */

require_once 'visualdict_captcha.admin.inc';

/**
 * Generates image-recognition CAPTCHA.
 *
 * Besides providing the challenge form and solution, specifies a custom
 * validation function for the CAPTCHA.
 *
 * @return array
 *   Array as expected to be returned from hook_captcha() when $op is
 *   'generate'.
 */
function _visualdict_captcha_generate_captcha() {
  list($image_filenames, $solution) = _visualdict_captcha_get_challenge_image_filenames_and_solution();
  return array(
    'form' => _visualdict_captcha_build_challenge_form($image_filenames),
    'solution' => serialize($solution),
    'captcha_validate' => '_visualdict_captcha_validate',
  );
}

/****************************************************************************/
/* Challenge images selection                                               */
/****************************************************************************/

/**
 * Gets image filenames and solution for a challenge.
 *
 * The challenge images and their correct responses are shuffled.
 *
 * @return array
 *   An array containing:
 *   - An array of challenge image filenames.
 *   - An array of correct responses representing the solution.
 */
function _visualdict_captcha_get_challenge_image_filenames_and_solution() {
  $annotated_image_filenames = _visualdict_captcha_get_annotated_challenge_image_filenames();
  _visualdict_captcha_shuffle_annotated_image_filenames($annotated_image_filenames);
  $image_filenames = array_keys($annotated_image_filenames);
  $solution = array_values($annotated_image_filenames);
  return array($image_filenames, $solution);
}

/**
 * Gets annotated challenge image filenames.
 *
 * By "annotated", it is meant that each challenge image filename is annotated
 * with whether it is a correct or incorrect image.
 *
 * @return array
 *   An associative array where keys are challenge image filenames, and values
 *   are either 1 or 0. 1 indicates a correct challenge image; 0 indicates an
 *   incorrect challenge image.
 */
function _visualdict_captcha_get_annotated_challenge_image_filenames() {
  $annotated_image_filenames = array();
  $correct_image_filenames = _visualdict_captcha_get_correct_challenge_image_filenames();
  foreach ($correct_image_filenames as $correct_image_filename) {
    $annotated_image_filenames[$correct_image_filename] = 1;
  }
  $incorrect_image_filenames = _visualdict_captcha_get_incorrect_challenge_image_filenames();
  foreach ($incorrect_image_filenames as $incorrect_image_filename) {
    $annotated_image_filenames[$incorrect_image_filename] = 0;
  }
  return $annotated_image_filenames;
}

/**
 * Shuffles annotated image filenames in place.
 *
 * This ensures the images are rendered in a random order, and therefore their
 * correctness cannot be deduced from the order.
 *
 * @param array $unshuffled
 *   Annotated image filenames to be shuffled.
 */
function _visualdict_captcha_shuffle_annotated_image_filenames(array &$unshuffled) {
  $shuffled = array();
  $image_filenames = array_keys($unshuffled);
  shuffle($image_filenames);
  foreach ($image_filenames as $image_filename) {
    $shuffled[$image_filename] = $unshuffled[$image_filename];
  }
  $unshuffled = $shuffled;
}

/**
 * Gets correct challenge image filenames.
 *
 * These are the filenames of images corresponding to correct responses to the
 * challenge. Which image filenames are returned by this function is random;
 * how many is determined by module settings.
 *
 * @return string[]
 *   Correct challenge image filenames.
 */
function _visualdict_captcha_get_correct_challenge_image_filenames() {
  $num_correct_images = _visualdict_captcha_get_num_correct_images();
  $correct_image_filenames = _visualdict_captcha_get_correct_image_filenames();
  _visualdict_captcha_remove_nonexistent_image_filenames($correct_image_filenames);
  return _visualdict_captcha_sample_image_filenames_randomly($correct_image_filenames, $num_correct_images);
}

/**
 * Gets incorrect challenge image filenames.
 *
 * These are the filenames of images corresponding to incorrect responses to
 * the challenge. Which image filenames are returned by this function is
 * random; how many is determined by module settings.
 *
 * @return string[]
 *   Incorrect challenge image filenames.
 */
function _visualdict_captcha_get_incorrect_challenge_image_filenames() {
  $num_incorrect_images = _visualdict_captcha_get_num_incorrect_images();
  $incorrect_image_filenames = _visualdict_captcha_get_incorrect_image_filenames();
  _visualdict_captcha_remove_nonexistent_image_filenames($incorrect_image_filenames);
  return _visualdict_captcha_sample_image_filenames_randomly($incorrect_image_filenames, $num_incorrect_images);
}

/**
 * Removes (in place) image filenames of nonexistent files.
 *
 * Checks whether each image filename is present within the Image-Recognition
 * CAPTCHA images directory, and if not, removes it from the array of image
 * filenames.
 *
 * Important: This function provides defense against path traversal attacks.
 *
 * @param string[] $image_filenames
 *   Challenge image filenames.
 */
function _visualdict_captcha_remove_nonexistent_image_filenames(array &$image_filenames) {
  foreach ($image_filenames as $i => $image_filename) {
    if (!_visualdict_captcha_does_image_filename_exist($image_filename)) {
      unset($image_filenames[$i]);
    }
  }
}

/**
 * Samples image filenames randomly.
 *
 * @param string[] $image_filenames
 *   Image filenames.
 * @param int $num_filenames
 *   Number of filenames to sample.
 *
 * @return string[]
 *   Random sample of image filenames.
 */
function _visualdict_captcha_sample_image_filenames_randomly(array $image_filenames, $num_filenames) {
  return array_rand(array_flip($image_filenames), $num_filenames);
}

/**
 * Determines whether image filename is that of an existent file.
 *
 * @param string $image_filename
 *   Challenge image filename.
 *
 * @return bool
 *   TRUE if the image filename exists within the Image-Recognition CAPTCHA
 *   image directory; otherwise, FALSE.
 */
function _visualdict_captcha_does_image_filename_exist($image_filename) {
  $existent_image_filenames = _visualdict_captcha_get_image_filenames_from_images_directory();
  return in_array($image_filename, $existent_image_filenames);
}

/**
 * Gets image filenames from Image-Recognition CAPTCHA images directory.
 *
 * This function assumes all regular files in the images directory are images.
 */
function _visualdict_captcha_get_image_filenames_from_images_directory() {
  $image_filenames = array();
  $images_uri = _visualdict_captcha_get_images_uri();
  $images_dir_filenames = scandir($images_uri);

  // Remove non-regular file (e.g. directory) filenames.
  foreach ($images_dir_filenames as $images_dir_filename) {
    $image_uri = $images_uri . '/' . $images_dir_filename;
    if (is_file($image_uri)) {
      $image_filenames[] = $images_dir_filename;
    }
  }

  return $image_filenames;
}

/****************************************************************************/
/* Challenge form building                                                  */
/****************************************************************************/

/**
 * Builds challenge form.
 *
 * @param string[] $image_filenames
 *   Array of correct and incorrect challenge image filenames.
 *
 * @return array
 *   Form array for the challenge.
 */
function _visualdict_captcha_build_challenge_form(array $image_filenames) {
  $form = array();
  $form['#prefix'] = '<div class="visualdict-captcha">';
  _visualdict_captcha_add_challenge_form_elements($form, $image_filenames);
  $form['#suffix'] = '</div>';
  _visualdict_captcha_attach_css_to_challenge_form($form);
  _visualdict_captcha_attach_js_to_challenge_form($form);
  return $form;
}

/**
 * Adds elements to challenge form.
 *
 * The challenge form elements include the challenge prompt, the challenge
 * items, and a hidden response element.
 *
 * A "challenge item" is an individual image along with an element for the
 * visitor to indicate whether it is a correct or incorrect image.
 *
 * The response element is hidden because it is unneeded but required to
 * satisfy the CAPTCHA module. Normally, it is a textfield that contains the
 * visitor's response to the CAPTCHA. However, for the challenge form generated
 * by this module, responses are instead contained within each challenge item.
 *
 * @param array $form
 *   Challenge form, empty of elements.
 * @param string[] $image_filenames
 *   Array of correct and incorrect challenge image filenames.
 */
function _visualdict_captcha_add_challenge_form_elements(array &$form, array $image_filenames) {
  $form['prompt'] = _visualdict_captcha_build_audio_prompt();
  foreach ($image_filenames as $i => $image_filename) {
    $form["captcha_item_$i"] = _visualdict_captcha_build_challenge_item($i, $image_filename);
  }
  $form['captcha_response'] = _visualdict_captcha_build_hidden_captcha_response_element();
}

/**
 * Builds hidden CAPTCHA response element.
 *
 * @return array
 *   Form element for the CAPTCHA response.
 */
function _visualdict_captcha_build_hidden_captcha_response_element() {
  return array('#type' => 'hidden');
}

/**
 * Builds audio prompt.
 *
 * @return array
 *   Form element for the challenge prompt.
 */
function _visualdict_captcha_build_audio_prompt() {
  $audio_uri = _visualdict_captcha_get_image_uri_from_filename(_visualdict_captcha_get_audio_prompt());
  return array(
    '#prefix' => '<div class="visualdict-audio-prompt">',
    '#markup' => '<audio controls autoplay><source src="' .file_create_url($audio_uri). '" type="audio/mpeg">Your browser does not support audio.</audio>',
    '#suffix' => '</div>',
  );
}
/**
 * Builds challenge prompt.
 *
 * @return array
 *   Form element for the challenge prompt.
 */
function _visualdict_captcha_build_challenge_prompt() {
  return array(
    '#prefix' => '<div class="visualdict-captcha-prompt">',
    '#markup' => _visualdict_captcha_get_challenge_prompt(),
    '#suffix' => '</div>',
  );
}

/**
 * Builds challenge item.
 *
 * A challenge item is a container that contains an image and a checkbox for
 * the response. The visitor checks the checkbox to indicate that they believe
 * it is a correct response to challenge prompt.
 *
 * @param int $i
 *   Index of the challenge item.
 * @param string $image_filename
 *   A challenge image filename.
 *
 * @return array
 *   Challenge item form array.
 */
function _visualdict_captcha_build_challenge_item($i, $image_filename) {
  $item = _visualdict_captcha_build_challenge_item_container();
  $item["captcha_item_response_$i"] = _visualdict_captcha_build_challenge_item_response_checkbox();
  $item['image'] = _visualdict_captcha_build_challenge_item_image($image_filename);
  return $item;
}

/**
 * Attaches CSS to the challenge form.
 *
 * This CSS styles the challenge. For one, the CSS adjusts the layout of the
 * CAPTCHA items.
 *
 * @param array $form
 *   Challenge form array.
 */
function _visualdict_captcha_attach_css_to_challenge_form(array &$form) {
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'visualdict_captcha') . '/visualdict_captcha.css',
  );
}

/**
 * Attaches JavaScript to the challenge form.
 *
 * This JavaScript allows indicating responses by clicking images rather than
 * checking a checkbox.
 *
 * @param array $form
 *   Challenge form array.
 */
function _visualdict_captcha_attach_js_to_challenge_form(array &$form) {
  $form['#attached']['js'][] = array(
    'type' => 'file',
    'data' => drupal_get_path('module', 'visualdict_captcha') . '/visualdict_captcha.js',
  );
}

/**
 * Builds challenge item container.
 *
 * @return array
 *   Form element for challenge item container.
 */
function _visualdict_captcha_build_challenge_item_container() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('visualdict-captcha-item'),
    ),
  );
}

/**
 * Builds challenge item response checkbox.
 *
 * @return array
 *   Form element for challenge item response checkbox.
 */
function _visualdict_captcha_build_challenge_item_response_checkbox() {
  return array(
    '#type' => 'checkbox',
    '#prefix' => '<div class="visualdict-captcha-item-response">',
    '#suffix' => '</div>',
  );
}

/**
 * Builds challenge item image.
 *
 * Renders the image within the markup of a Form API item element. Form API
 * "item" is not to be confused with a challenge "item".
 *
 * @param string $image_filename
 *   Challenge item image filename.
 *
 * @return array
 *   Form element for challenge item image.
 */
function _visualdict_captcha_build_challenge_item_image($image_filename) {
  $image = _visualdict_captcha_render_challenge_item_image($image_filename);
  return array(
    '#prefix' => '<div class="visualdict-captcha-item-image">',
    '#markup' => $image,
    '#suffix' => '</div>',
  );
}

/**
 * Renders challenge item image.
 *
 * @param string $image_filename
 *   Challenge item image filename.
 *
 * @return string
 *   Markup of rendered image.
 */
function _visualdict_captcha_render_challenge_item_image($image_filename) {
  $image_uri = _visualdict_captcha_get_image_uri_from_filename($image_filename);
  $variables = array(
    'path' => $image_uri,
    'style_name' => 'medium',
    'attributes' => array(),
  );
  return theme('image_style', $variables);
}

/**
 * Gets image URI from a challenge image filename.
 *
 * The image URI is the URI of the image file within the directory that stores
 * Image-Recognition CAPTCHA images. For example, this function might return
 * "public://visualdict_captcha/foo.png".
 *
 * @param string $image_filename
 *   Challenge image filename.
 *
 * @return string
 *   Challenge image URI.
 */
function _visualdict_captcha_get_image_uri_from_filename($image_filename) {
  $images_uri = _visualdict_captcha_get_images_uri();
  return $images_uri . $image_filename;
}

/**
 * Gets images URI.
 *
 * The images URI is the URI of the directory that contains Image-Recognition
 * CAPTCHA images.
 *
 * @return string
 *   Image-Recognition CAPTCHA images URI.
 */
function _visualdict_captcha_get_images_uri() {
  return 'public://community_captcha/visualdict_captcha/';
}

/**
 * Custom validation function for the challenge form.
 *
 * This is called from the CAPTCHA module and used in place of the normal
 * validation of equality between the solution and the value in the
 * 'captcha_response' element.
 *
 * Retrieves challenge item responses into an array, then serializes it, and
 * compares with the solution.
 *
 * This validation is needed because the Image-Recognition CAPTCHA responses
 * are contained in multiple checkboxes instead of a single textfield.
 *
 * @param string $solution
 *   Solution.
 * @param string $captcha_response
 *   CAPTCHA response value (empty string in this usage).
 * @param array $element
 *   CAPTCHA element.
 * @param array $form_state
 *   Form state.
 *
 * @return bool
 *   TRUE if the validation succeeds; otherwise, FALSE.
 */
function _visualdict_captcha_validate($solution, $captcha_response, array $element, array &$form_state) {
  $item_responses = _visualdict_captcha_get_challenge_item_responses_from_form_state($form_state);
  $captcha_response = serialize($item_responses);
  return $solution == $captcha_response;
}

/**
 * Gets challenge item responses from form state.
 *
 * @param array $form_state
 *   Form state.
 *
 * @return int[]
 *   An array of challenge item responses, represented by either 1 or 0.
 */
function _visualdict_captcha_get_challenge_item_responses_from_form_state(array &$form_state) {
  $item_responses = array();
  $num_items = _visualdict_captcha_get_num_challenge_items();
  for ($i = 0; $i < $num_items; $i++) {
    $item_response = $form_state['values']["captcha_item_response_$i"];
    $item_responses[] = $item_response;
  }
  return $item_responses;
}

/****************************************************************************/
/* Other functions                                                          */
/****************************************************************************/

/**
 * Determines whether form is using an Image-Recognition CAPTCHA.
 */
function _visualdict_captcha_is_form_using_visualdict_captcha($form) {
  $captcha_type = _visualdict_captcha_get_global_captcha_type();
  return (isset($form['captcha'])
    && $form['captcha']['#captcha_type'] == $captcha_type);
}

/**
 * Clears challenge item responses.
 *
 * By "clearing" a challenge item response, it is meant that the checkboxes
 * indicating the responses are unchecked.
 */
function _visualdict_captcha_clear_challenge_item_responses(&$form) {
  $num_items = _visualdict_captcha_get_num_challenge_items();
  for ($i = 0; $i < $num_items; $i++) {
    $response = &$form['captcha']['captcha_widgets']["captcha_item_$i"]["captcha_item_response_$i"];
    $response['#checked'] = 0;
  }
}

/**
 * Gets total number of challenge items.
 */
function _visualdict_captcha_get_num_challenge_items() {
  return _visualdict_captcha_get_num_challenge_images();
}

/**
 * Gets total number of challenge images.
 */
function _visualdict_captcha_get_num_challenge_images() {
  return _visualdict_captcha_get_num_correct_images() + _visualdict_captcha_get_num_incorrect_images();
}
