(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      highlight = function($l, t) {
        $l.markerAnimation({
          font_weight: null,
          duration: t.toString() + 's'
        });
      };

      if (context == document) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      $(context).children().once('locale-audio', function() {
        findAndReplaceDOMText(this, {
          find: /\uFFF9(.*?)\uFFFA(.*?)\uFFFB/g,
          replace: function (portion, match) {
            var wrap = $("<span data-locale-audio='" + match[2] + "'><span class='locale-audio-icon'><i class='fas fa-lg fa-" + Drupal.settings.locale_audio.iPlay + "'></i></span> <span class='locale-audio-text'>" + match[1] + "</span></span>");
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
              if ($aud[0].paused) {
                $aud[0].play();
              }
              else {
                $aud[0].pause();
                $aud[0].currentTime = 0.0;
                var $loc = $('[data-locale-audio=' + last + ']');
                var el = $loc.find('svg[data-icon]')[0];
                el.classList.remove('fa-' + Drupal.settings.locale_audio.iStop);
                el.classList.add('fa-' + Drupal.settings.locale_audio.iPlay);
                $loc.removeClass('playing');
                $loc.find('.locale-audio-text').markerAnimation('destroy');
              }
            } else {
              if (last) {
                $aud[0].pause();
                var $loc = $('[data-locale-audio=' + last + ']');
                var el = $loc.find('svg[data-icon]')[0];
                el.classList.remove('fa-' + Drupal.settings.locale_audio.iStop);
                el.classList.add('fa-' + Drupal.settings.locale_audio.iPlay);
                $loc.removeClass('playing');
              }
              $('#locale-audio-player').load('/locale_audio/atom/' + next, function () {
                var aud = $('#locale-audio-player').find('audio')[0];
                var $loc = $('[data-locale-audio=' + next + ']');
                var loaded = false;

                aud.onloadedmetadata = function() {
                  loaded = true;
                  highlight($loc.find('.locale-audio-text'), aud.duration);
                };
                aud.onplay = function () {
                  if (loaded) highlight($loc.find('.locale-audio-text'), aud.duration);
                  var el = $loc.find('svg[data-icon]')[0];
                  el.classList.remove('fa-' + Drupal.settings.locale_audio.iPlay);
                  el.classList.add('fa-' + Drupal.settings.locale_audio.iStop);
                  $loc.addClass('playing');
                };
                aud.onended = function () {
                  var el = $loc.find('svg[data-icon]')[0];
                  el.classList.remove('fa-' + Drupal.settings.locale_audio.iStop);
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
