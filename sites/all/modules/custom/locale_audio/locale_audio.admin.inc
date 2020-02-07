<?php

function locale_audio_admin()
{
  $form = array();

  $form['locale_audio_icon_settings'] = array(
    '#title' => t('Icons'),
    '#type' => 'fieldset',
    '#collapsed' => FALSE,
  );
  $form['locale_audio_icon_settings']['locale_audio_play_icon'] = array(
    '#title' => t('Play audio icon'),
    '#type' => 'textfield',
    '#default_value' => variable_get('locale_audio_play', 'fa-volume-up'),
    '#description' => t('Enter the FontAwesome class for the icon used to indicate that there is audio connected to some text. Clicking on this icon will play the audio.'),
    '#required' => TRUE,
  );
  $form['locale_audio_icon_settings']['locale_audio_playing_icon'] = array(
    '#title' => t('Audio is playing icon'),
    '#type' => 'textfield',
    '#default_value' => variable_get('locale_audio_playing', 'fa-pause-circle'),
    '#description' => t('Enter the FontAwesome class for the icon that may be displayed when the audio connected to some text is played.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

