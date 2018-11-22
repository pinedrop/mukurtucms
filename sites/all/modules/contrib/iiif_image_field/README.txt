REQUIREMENTS
------------

 * The Open Seadragon library v2.2.1.

IIIF API SUPPORT
----------------

Supports API versions 1.0 or 2.0 (no mixing, as of yet).

INSTALLATION
------------

 * Download the Open Seadragon library v.2.2.1 from
   https://github.com/openseadragon/openseadragon/releases/tag/v2.2.1, and
   extract it to sites/all/libraries/openseadragon
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.

CONFIGURATION
-------------

 * You can configure your server and API version via the Modules manager or
   Admin > Config > Media > IIIF Image Field
 * Go to Structure > Content Types > YourContentType > Manage Fields
 * Add a IIIF Image field and the IIIF Image Formatter should be automatically
   selected.
 * Click on Manage Display and make sure your field is visible. Adjust settings
   for your view mode.
 * Edit content and add your IIIF Image ID and a label/caption/citation

UNINSTALLING
------------

Uninstall as you would any other Drupal module. Make sure that the IIIF Image
Field is deleted from all content-types that use it.

MAINTAINERS
-----------

 * Shaun Ellis (shaune) - https://www.drupal.org/user/2804475
 * Ben Kyriakou (ben.kyriakou) - https://www.drupal.org/user/1272308
