jQuery(document).ready(function($){
  $('area:not([href])').data('maphilight', {fillOpacity: 0.4});
  $('area').tooltipster({
    side: 'right',
    delay: 200,
    distance: 3,
    interactive: true,
    content: 'Loading...',
    // 'instance' is basically the tooltip. More details in the "Object-oriented Tooltipster" section.
    functionBefore: function(instance, helper) {

      var $origin = $(helper.origin);
      var query = $origin.attr('data-query');

      // we set a variable so the data is only loaded once via Ajax, not every time the tooltip opens
      if ($origin.data('loaded') !== true) {

        $.get('http://178.128.54.20:8983/solr/ajafiles/select?q=bow:"' + query + '"', function(data) {

          var docs = data.response.docs;
          var filenames = [];
          for (var i=0; i<docs.length; i++) {
            filenames.push(docs[i].filename);
          }
          // call the 'content' method to update the content of our tooltip with the returned data.
          // note: this content update will trigger an update animation (see the updateAnimation option)
          instance.content(filenames.join('<br/>'));

          // to remember that the data has been loaded
          $origin.data('loaded', true);
        });
      }
    }
    /*trigger: 'custom',
    triggerOpen: {
      mouseenter: true,
      touchstart: true
    },
    triggerClose: {
      click: true,
      scroll: true,
      tap: true
    }*/
  });
});
