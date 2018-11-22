/**
 * @file
 * Simple behavior to instantiate the IIIF viewer.
 */

(function($) {
  Drupal.behaviors.iiifImageViewer = {
    attach: function (context) {
      var $viewers = $('[id^="iiif-viewer"]', context);

      $viewers.each(function(idx, el) {
        Drupal.behaviors.iiifImageViewer.attachViewer(el.id);
      });
    },

    attachViewer: function(id) {
      $('#' + id).once('iiif', function() {
        OpenSeadragon({
          id: id,
          prefixUrl: '/sites/all/libraries/openseadragon/images/',
          sequenceMode: true,
          tileSources: Drupal.settings.iiifImageField[id].tileSources
        });
      });
    }
  };
})(jQuery);
