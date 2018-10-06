jQuery(document).ready(function($){
  $('area:not([href])').data('maphilight', {fillOpacity: 0.4});
  $('area').tooltipster({
    side: 'right',
    delay: 200,
    distance: 3,
    trigger: 'custom',
    triggerOpen: {
      mouseenter: true,
      touchstart: true
    },
    triggerClose: {
      click: true,
      scroll: true,
      tap: true
    }
  });
});
