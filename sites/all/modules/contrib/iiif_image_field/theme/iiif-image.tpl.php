<?php

/**
 * @file
 * Default theme implementation to display a IIIF image.
 *
 * Available variables:
 * - $link_url - The URL to link the image to. Optional.
 * - $image - A renderable array of image data.
 * - $image_caption - The escaped image caption. Optional.
 *
 * Other variables:
 * - $delta - The field item delta.
 * - $element - The raw field element containing potentially unsafe field data.
 * - $field - The complete field object.
 * - $settings - The display settings for the IIIF field.
 *
 * @see template_preprocess()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<figure>
  <?php if ($link_url): ?>
    <a href="<?php print $link_url; ?>">
      <?php print render($image); ?>
    </a>
  <?php else: ?>
    <?php print render($image); ?>
  <?php endif; ?>

  <?php if ($image_caption): ?>
    <ficaption>
      <?php print $image_caption; ?>
    </ficaption>
  <?php endif; ?>
</figure>
