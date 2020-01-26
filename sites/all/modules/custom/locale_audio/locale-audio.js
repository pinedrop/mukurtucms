(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      if (!$('#locale-audio-player').length) {
        $("body").append('<div id="locale-audio-player"></div>');
      }
      findAndReplaceDOMText(document.body, {
        find: /\uFFF9(.*?)\uFFFA(.*?)\uFFFB/g,
        wrap: "span",
        wrapClass: "locale-audio",
        replace: function(portion, match) {
          return  "<i class='fas fa-lg fa-asterisk' data-locale-audio='" + match[2] + "'></i></span> " + match[1];
          console.log("portion:");
          console.log(portion);
          console.log("match");
          console.log(match);
          return portion.index;
        }
        //replace: "<span class='locale-audio'><i class='fas fa-lg fa-asterisk' data-locale-audio='$2'></i></span> $1"
      });
      $('span.locale-audio', context).once('locale-audio', function() {
        $(this).click(function() {
          var $icon = $('[data-locale-audio]', this);
          var next = $icon.attr('data-locale-audio');
          var last = $('#locale-audio-player > div').attr('data-atom-id');
          var $aud = $('#locale-audio-player').find('audio');
          if (next == last) {
            $aud[0].pause();
            $aud[0].currentTime = 0.0;
            $aud[0].play();
          }
          else {
            if (last) {
              $aud[0].pause();
              $('[data-locale-audio='+last+']')[0].classList.remove('fa-spin');
            }
            $('#locale-audio-player').load('/locale_audio/atom/' + next, function () {
              var aud = $('#locale-audio-player').find('audio')[0];
              aud.onplay = function() {
                $('[data-locale-audio='+next+']')[0].classList.add('fa-spin');
              };
              aud.onended = function() {
                $('[data-locale-audio='+next+']')[0].classList.remove('fa-spin');
              };
              aud.play();
            });
          }
          return false; //stop jquery bubbling
        });
      });
    }
  };

})(jQuery);
