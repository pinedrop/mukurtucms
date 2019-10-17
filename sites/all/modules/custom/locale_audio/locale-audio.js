(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      if (!$('#locale-audio-player').length) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      $('span.locale-audio', context).once('locale-audio', function() {
        $(this).click(function() {
          var $sid = $('[data-locale-audio]', this).attr('data-locale-audio');
          $('#locale-audio-player').load('/locale_audio/atom/'+$sid);
        });
      });
    }
  };

})(jQuery);
