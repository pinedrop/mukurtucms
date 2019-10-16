(function ($) {

  Drupal.behaviors.localeAudio = {
    attach: function(context, settings) {
      $("i.laud").each(function() {
        var id = $(this).attr('data-laud');
      });
    }
  };

})(jQuery);
