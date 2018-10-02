jQuery(document).ready(function($){
  $('area.inactive').data('maphilight', {fillOpacity: 0.6});
  $('area.active').data('maphilight', {stroke: true, strokeColor: '000000'});
});
