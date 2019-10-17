(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("span.locale-audio").click(function() {
        var $sid = $('[data-locale-audio]', this).attr('data-locale-audio');
        alert($sid);
      });
    }
  };

})(jQuery);
