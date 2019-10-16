(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("span[data-locale-audio]").each(function() {
        console.log('found one!')
      });
    }
  };

})(jQuery);
