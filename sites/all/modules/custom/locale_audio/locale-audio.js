(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      if (!$('#locale-audio-player').length) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      $('span.locale-audio', context).once('locale-audio', function() {
        $(this).click(function() {
          var $icon = $('[data-locale-audio]', this);
          var $sid = $icon.attr('data-locale-audio');
          if ($('#locale-audio-player > div').attr('data-atom-id') == $sid) {
            $('#locale-audio-player').find('audio')[0].stop().play();
          } else {
            $('#locale-audio-player').load('/locale_audio/atom/' + $sid, function () {
              $('#locale-audio-player').find('audio')[0].play();
              $icon.addClass('fa-spin');
            });
          }
        });
      });
    }
  };

})(jQuery);
