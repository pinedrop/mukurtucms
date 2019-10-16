(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      console.log('entered attach');
      $("span.data-locale-audio").each(function() {
        console.log('found one!')
      });
      $("div").each(function() {
        console.log('found div!')
      });
    }
  };

  console.log('entered locale audio');

})(jQuery);
