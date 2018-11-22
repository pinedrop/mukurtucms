<?php

/**
 * @file
 * Default theme implementation to display a IIIF viewer.
 *
 * Available variables:
 * - $attributes - The attributes for the viewer element. Contains the ID.
 *
 * Other variables:
 * - $entity - The parent entity.
 * - $element - The raw field element containing potentially unsafe field data.
 * - $field - The complete field object.
 * - $settings - The display settings for the IIIF field.
 *
 * @see template_preprocess().
 * @see template_process().
 *
 * @ingroup themeable.
 */
?>
<div <?php print $attributes; ?>></div>
