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
            var wrap = $("<span data-locale-audio='" + match[2] + "'><span class='locale-audio-icon'><i class='fas fa-lg fa-" + Drupal.settings.locale_audio.iPlay + "'></i></span> " + match[1] + "</span>");
            return wrap[0];
          }
        });
        $('span[data-locale-audio]', this).once('locale-audio', function () {
          $('span.locale-audio-icon', this).click(function () {
            var $icon = $('i.fas', this);
            var next = $(this).parent().attr('data-locale-audio');
            var last = $('#locale-audio-player > div').attr('data-atom-id');
            var $aud = $('#locale-audio-player').find('audio');
            if (next == last) {
              $aud[0].pause();
              $aud[0].currentTime = 0.0;
              $aud[0].play();
            } else {
              if (last) {
                $aud[0].pause();
                var $loc = $('[data-locale-audio=' + last + ']');
                var el = $loc.find('svg[data-icon]')[0];
                el.classList.remove('fa-' + Drupal.settings.locale_audio.iPlaying);
                el.classList.add('fa-' + Drupal.settings.locale_audio.iPlay);
                $loc.removeClass('playing');
              }
              $('#locale-audio-player').load('/locale_audio/atom/' + next, function () {
                var aud = $('#locale-audio-player').find('audio')[0];
                aud.onplay = function () {
                  var $loc = $('[data-locale-audio=' + next + ']');
                  var el = $loc.find('svg[data-icon]')[0];
                  el.classList.remove('fa-' + Drupal.settings.locale_audio.iPlay);
                  el.classList.add('fa-' + Drupal.settings.locale_audio.iPlaying);
                  $loc.addClass('playing');
                };
                aud.onended = function () {
                  var $loc = $('[data-locale-audio=' + next + ']');
                  var el = $loc.find('svg[data-icon]')[0];
                  el.classList.remove('fa-' + Drupal.settings.locale_audio.iPlaying);
                  el.classList.add('fa-' + Drupal.settings.locale_audio.iPlay);
                  $loc.removeClass('playing');
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
