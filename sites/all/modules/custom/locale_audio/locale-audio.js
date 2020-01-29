(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      console.log(context);
      if (context == document) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      $(context).children().once('locale-audio', function() {
        findAndReplaceDOMText(this, {
          find: /\uFFF9(.*?)\uFFFA(.*?)\uFFFB/g,
          replace: function (portion, match) {
            console.log(match);
            var wrap = $("<span><span class='locale-audio'><i class='fas fa-lg fa-asterisk' data-locale-audio='" + match[2] + "'></i></span> " + match[1] + "</span>");
            return wrap[0];
          }
        });
        $('span.locale-audio', this).once('locale-audio', function () {
          $(this).click(function () {
            var $icon = $('[data-locale-audio]', this);
            var next = $icon.attr('data-locale-audio');
            var last = $('#locale-audio-player > div').attr('data-atom-id');
            var $aud = $('#locale-audio-player').find('audio');
            if (next == last) {
              $aud[0].pause();
              $aud[0].currentTime = 0.0;
              $aud[0].play();
            } else {
              if (last) {
                $aud[0].pause();
                $('[data-locale-audio=' + last + ']')[0].classList.remove('fa-spin');
              }
              $('#locale-audio-player').load('/locale_audio/atom/' + next, function () {
                var aud = $('#locale-audio-player').find('audio')[0];
                aud.onplay = function () {
                  $('[data-locale-audio=' + next + ']')[0].classList.add('fa-spin');
                };
                aud.onended = function () {
                  $('[data-locale-audio=' + next + ']')[0].classList.remove('fa-spin');
                };
                aud.play();
              });
            }
            return false; //stop jquery bubbling
          });
        });
      });
    }
  };

})(jQuery);
