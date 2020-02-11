<?php

function locale_audio_admin()
{
  $form = array();

  $form['locale_audio_icon_settings'] = array(
    '#title' => t('Icons'),
    '#type' => 'fieldset',
    '#collapsed' => FALSE,
  );
  $form['locale_audio_icon_settings']['locale_audio_i_play'] = array(
    '#title' => t('Play icon'),
    '#type' => 'textfield',
    '#default_value' => variable_get('locale_audio_i_play', 'volume-up'),
    '#description' => t('Enter the FontAwesome class for the icon used to indicate that there is audio connected to some text. Clicking on this icon will play the audio.'),
    '#required' => TRUE,
  );
  $form['locale_audio_icon_settings']['locale_audio_i_stop'] = array(
    '#title' => t('Pause icon'),
    '#type' => 'textfield',
    '#default_value' => variable_get('locale_audio_i_stop', 'pause'),
    '#description' => t('Enter the FontAwesome class for the icon that may be displayed when the audio connected to some text is playing. Clicking on this icon will stop the audio.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

