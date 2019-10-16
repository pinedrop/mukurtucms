(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      console.log('entered attach');
      $("span.data-locale-audio").each(function() {
        console.log('found one!')
      });
    }
  };

  console.log('entered locale audio');
  
})(jQuery);
