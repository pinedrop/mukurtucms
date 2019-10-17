(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      if (!$('#locale-audio-player').length) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      $('span.locale-audio', context).once('locale-audio', function() {
        $(this).click(function() {
          var $icon = $('[data-locale-audio]', this);
          var $next = $icon.attr('data-locale-audio');
          var $last = $('#locale-audio-player > div').attr('data-atom-id');
          if ($next == $last) {
            var aud = $('#locale-audio-player').find('audio')[0];
            aud.pause();
            aud.currentTime = 0.0;
            aud.play();
          } else {
            $('#locale-audio-player').load('/locale_audio/atom/' + $next, function () {
              $('#locale-audio-player').find('audio')[0].play();
              $icon[0].classList.remove('fa-podcast');
              $icon[0].classList.remove('fa-lg');
              $icon[0].classList.add('fa-circle-notch');
              $icon[0].classList.add('fa-spin');
            });
          }
        });
      });
    }
  };

})(jQuery);
