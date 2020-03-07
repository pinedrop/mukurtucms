<?php

/**
 * Menu callback. Saves a string translation coming as POST data.
 */
function locale_audio_i18n_string_l10n_client_save_string() {
  global $user, $language;

  if (user_access('use on-page translation')) {
    $textgroup = !empty($_POST['textgroup']) ? $_POST['textgroup'] : 'default';
    // Other textgroups will be handled by l10n_client module
    if (!i18n_string_group_info($textgroup)) {
      return locale_audio_l10n_client_save_string();
    }
    elseif (isset($_POST['source']) && isset($_POST['target']) && !empty($_POST['context']) && !empty($_POST['form_token']) && drupal_valid_token($_POST['form_token'], 'l10n_client_form')) {
      $name = $textgroup . ':' . $_POST['context'];
      if ($i18nstring = i18n_string_get_source($name)) {
        // Since this is not a real form, we double check access permissions here too.
        if ($error = $i18nstring->check_translate_access()) {
          $message = theme('l10n_client_message', array('message' => t('Not saved due to: !reason', array('!reason' => $error)), 'level' => WATCHDOG_WARNING));
        }
        else {
          $target = !$_POST['audio'] ? $_POST['target'] : locale_audio_ruby_annotation($_POST['target'], $_POST['audio']);
          $result = i18n_string_translation_update($name, $target, $language->language, $_POST['source']);
          if ($result) {
            $message = theme('l10n_client_message', array('message' => t('Translation saved locally for user defined string.'), 'level' => WATCHDOG_INFO));
          }
          elseif ($result === FALSE) {
            $message = theme('l10n_client_message', array('message' => t('Not saved due to insufficient permissions.')));
          }
          else {
            $message = theme('l10n_client_message', array('message' => t('Not saved due to unknown reason.')));
          }
        }
      }
      else {
        $message = theme('l10n_client_message', array('message' => t('Not saved due to source string missing.')));
      }
    }
    else {
      $message = theme('l10n_client_message', array('message' => t('Not saved due to missing form values.')));
    }
    drupal_json_output($message);
    exit;
  }
}

/**
 * Menu callback. Saves a string translation coming as POST data.
 */
function locale_audio_l10n_client_save_string() {
  global $user, $language;

  if (l10n_client_access()) {
    if (isset($_POST['source']) && isset($_POST['target']) && !empty($_POST['textgroup']) && !empty($_POST['form_token']) && drupal_valid_token($_POST['form_token'], 'l10n_client_form')) {
      // Ensure we have this source string before we attempt to save it.
      $lid = db_query("SELECT lid FROM {locales_source} WHERE source = :source AND context = :context AND textgroup = :textgroup", array(':source' => $_POST['source'], ':context' => $_POST['context'], ':textgroup' => $_POST['textgroup']))->fetchField();

      if (!empty($lid)) {
        include_once 'includes/locale.inc';
        $report = array('skips' => 0, 'additions' => 0, 'updates' => 0, 'deletes' => 0);
        $target = !$_POST['audio'] ? $_POST['target'] : locale_audio_ruby_annotation($_POST['target'], $_POST['audio']);
        _locale_import_one_string_db($report, $language->language, $_POST['context'], $_POST['source'], $target, $_POST['textgroup'], NULL, LOCALE_IMPORT_OVERWRITE);
        cache_clear_all('locale:', 'cache', TRUE);
        _locale_invalidate_js($language->language);

        if (!empty($report['skips'])) {
          $message = theme('l10n_client_message', array('message' => t('Not saved locally due to invalid HTML content.')));
        }
        elseif (!empty($report['additions']) || !empty($report['updates'])) {
          $message = theme('l10n_client_message', array('message' => t('Translation saved locally.'), 'level' => WATCHDOG_INFO));
        }
        elseif (!empty($report['deletes'])) {
          $message = theme('l10n_client_message', array('message' => t('Translation successfuly removed locally.'), 'level' => WATCHDOG_INFO));
        }
        else {
          $message = theme('l10n_client_message', array('message' => t('Unknown error while saving translation locally.')));
        }

        // Submit to remote server if enabled.
        if (empty($report['skips']) && variable_get('l10n_client_use_server', FALSE) && user_access('submit translations to localization server') && ($_POST['textgroup'] == 'default')) {
          if (!empty($user->data['l10n_client_key'])) {
            $remote_result = l10n_client_submit_translation($language->language, $_POST['source'], $_POST['target'], $user->data['l10n_client_key'], l10n_client_user_token($user));
            $message .= theme('l10n_client_message', array('message' => $remote_result[1], 'level' => $remote_result[0] ? WATCHDOG_INFO : WATCHDOG_ERROR));
          }
          else {
            $server_url = variable_get('l10n_client_server', 'http://localize.drupal.org');
            $user_edit_url = url('user/'. $user->uid .'/edit', array('absolute' => TRUE));
            $message .= theme('l10n_client_message', array('message' => t('You could share your work with !l10n_server if you set your API key at !user_link.', array('!l10n_server' => l($server_url, $server_url), '!user_link' => l($user_edit_url, 'user/'. $user->uid .'/edit'))), 'level' => WATCHDOG_WARNING));
          }
        }
      }
      else {
        $message = theme('l10n_client_message', array('message' => t('Not saved due to source string missing.')));
      }
    }
    else {
      $message = theme('l10n_client_message', array('message' => t('Not saved due to missing form values.')));
    }
  }
  else {
    $message = theme('l10n_client_message', array('message' => t('Not saved due to insufficient permissions.')));
  }
  drupal_json_output($message);
  exit;
}
