(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      console.log('entered attach');
      $("span").each(function() {
        console.log($(this).text());
      });
      $("div").each(function() {
        console.log('found div!')
      });
    }
  };

  console.log('entered locale audio');

})(jQuery);
