(function ($) {
  Drupal.behaviors.responsiveImageMaps = {
    attach: function(context) {
      $('img[usemap]').rwdImageMaps();
    }
  }
})(jQuery);
