(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("[data-laud]").click(function() {
        alert('clicked');
      });
    }
  };

})(jQuery);
