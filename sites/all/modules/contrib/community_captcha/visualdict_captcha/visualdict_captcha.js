/**
 * @file
 * Image-Recognition CAPTCHA JavaScript.
 */

(function ($) {

  'use strict';

  /**
   * Allows image selection by clicking image.
   *
   * This works by hiding the checkboxes used to select images in browsers
   * without JavaScript, but still toggling them by script when the image is
   * clicked.
   */
  Drupal.behaviors.irCaptchaImageSelectionByClick = {
    attach: function (context, settings) {
      $('.captcha', context).once('imageSelectionByClick', function () {
        var $captcha = $(this);

        // Hide checkboxes.
        $('.visualdict-captcha-item-response', $captcha).hide();

        // Handle image click.
        $('.visualdict-captcha-item-image', $captcha).click(function () {
          var $challenge_item = $(this).parent();

          // Toggle corresponding checkbox.
          var $checkbox = $challenge_item.find('.visualdict-captcha-item-response .form-checkbox');
          $checkbox.attr('checked', !$checkbox.attr('checked'));

          // Toggle selection indicator.
          $challenge_item.toggleClass('visualdict-captcha-item-image-selected');
        });
      });
    }
  };

})(jQuery);
