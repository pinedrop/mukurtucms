(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("span.locale-audio").click(function() {
        var $sid = $('[data-locale-audio]', this).attr('data-locale-audio');
        $('#locale-audio-player').load()
      });
    }
  };

  $("body").append('<div id-"locale-audio-player">Bingo bongo</div>');

})(jQuery);
