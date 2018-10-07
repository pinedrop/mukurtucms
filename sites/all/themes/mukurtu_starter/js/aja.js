jQuery(document).ready(function($){
  //$('area:not([href])').data('maphilight', {fillOpacity: 0.4});
  $('area').tooltipster({
    side: 'right',
    delay: 200,
    distance: 3,
    interactive: true,
    contentAsHTML: true,
    content: 'Searching...',
    updateAnimation: 'fade',
    // 'instance' is basically the tooltip. More details in the "Object-oriented Tooltipster" section.
    functionBefore: function(instance, helper) {

      var $origin = $(helper.origin);
      var query = $origin.attr('data-query');
      var queryTerms = query.split(' ');

      // we set a variable so the data is only loaded once via Ajax, not every time the tooltip opens
      if ($origin.data('loaded') !== true) {

        $.get('http://178.128.54.20:8983/solr/ajafiles/select?q=bow:"' + query + '"&rows=20&facet=true&facet.field=bow_personal&facet.field=bow&facet.mincount=1&f.bow_personal.facet.limit=5&f.bow.facet.limit=10&facet.sort=count', function(data) {

          var docs = data.response.docs;
          if (docs.length == 0) {
            instance.content('No resources found.');
          }
          else {
            // people facet
            var bow_personal = data.facet_counts.facet_fields.bow_personal;
            var people = [];
            for (var n=0; n<bow_personal.length; n=n+2) {
              if (bow_personal[n] != "centre") {
                // var firstCapped = bow_personal[n].split(' ').map(name => name.charAt(0).toUpperCase() + name.substr(1));
                people.push('<li>' + bow_personal[n] + '&nbsp;<span class="badge">' + bow_personal[n+1] + '</span></li>');
              }
            }
            if (people.length == 0) people.push('<li>none</li>');

            // keywords facet
            var bow = data.facet_counts.facet_fields.bow;
            var keywords = [];
            for (var n=0; n<bow.length; n=n+2) {
              if (queryTerms.indexOf(bow[n]) == -1) {
                keywords.push('<li>' + bow[n] + '&nbsp;<span class="badge">' + bow[n+1] + '</span></li>');
              }
            }
            if (keywords.length == 0) keywords.push('<li>none</li>');

            var filenames = [];
            for (var i = 0; i < docs.length; i++) {
              var path = docs[i].path[0].split('\\').filter(component => component.length > 0).pop().replace(' ', '-');
              filenames.push('<li><a target="_blank" href="http://www.anindilyakwa.org.au/ajamurnda/lib/' + path + '/' + docs[i].filename + '">' + docs[i].filename + '</a></li>');
            }
            // call the 'content' method to update the content of our tooltip with the returned data.
            // note: this content update will trigger an update animation (see the updateAnimation option)
            instance.content('<h4>People</h4><ul class="aja-people">' + people.join('') + '</ul><h4>Keywords</h4><ul class="aja-keywords">' + keywords.join('') + '</ul><h4>Resources</h4><ul class="aja-resources">' + filenames.join('') + '</ul>');
          }
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
