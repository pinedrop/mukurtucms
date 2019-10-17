(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {

      if ($("body").length) {
        alert('body');
      }
      else {
        alert('no body');
      }

      $("span.locale-audio").click(function() {
        var $sid = $('[data-locale-audio]', this).attr('data-locale-audio');
        $('#locale-audio-player').load('/locale_audio/atom/'.$sid);
      });
    }
  };


  $("body").append('<div id="locale-audio-player">Bingo bongo</div>');

})(jQuery);
