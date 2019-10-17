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
          $('#locale-audio-player').load('/locale_audio/atom/'+$sid, function() {
            console.log('success');
            $('#locale-audio-player').find('audio')[0].play();
            $icon.addClass('fa-spin');
          });
        });
      });
    }
  };

})(jQuery);
