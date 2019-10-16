(function ($) {

  Drupal.behaviors.localeAudio = {
    console.log('entered behavior');
    attach: function(context, settings) {
      console.log('entered attach');
      $("span.data-locale-audio").each(function() {
        console.log('found one!')
      });
    }
  };

})(jQuery);
