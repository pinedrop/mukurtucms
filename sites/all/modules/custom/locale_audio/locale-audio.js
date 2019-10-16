(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("i[data-laud]").click(function() {
        alert('clicked');
      });
    }
  };

})(jQuery);
