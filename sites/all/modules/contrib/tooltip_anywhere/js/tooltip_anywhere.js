/**
 * @file
 * Includes tooltip anywhere module js handling.
 */

(function ($) {
  'use strict';
  Drupal.behaviors.tooltip_anywhere = {
    attach: function (context, settings) {
      if (typeof Drupal.settings.vars !== 'undefined') {
        if (typeof Drupal.settings.vars.selector !== 'undefined') {
          var type_tooltip = '';
          var sel = Drupal.settings.vars.selector.length;
          var inputObj = '';
          for (var i = 0; i < sel; i++) {

            var processed = false;
            type_tooltip = Drupal.settings.vars.type[i];
            switch (type_tooltip) {
              case 'id':
              case 'class':
                if ($(Drupal.settings.vars.selector[i]).hasClass('tooltipstered')) {
                  processed = true;
                }
                break;

              default:
                if ($(Drupal.settings.vars.selector[i]).hasClass('tooltipstered')) {
                  processed = true;
                }
                break;
            }

            if (!processed) {
              inputObj = {
                content: Drupal.settings.vars.content[i],
                position: Drupal.settings.vars.position[i],
                theme: Drupal.settings.vars.properties[i].theme
              };
              $(Drupal.settings.vars.selector[i]).tooltipster(inputObj);
            }

          }
        }
      }
    }
  };
})(jQuery);
