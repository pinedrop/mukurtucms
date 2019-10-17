(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("span[locale-audio]").click(function() {
        alert('clicked');
      });
    }
  };

})(jQuery);
