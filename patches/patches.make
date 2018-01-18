api = 2
core = 7.x


;;;;;;;;;;
;; Core ;;
;;;;;;;;;;

; Fix IE11 & Chrome scrolls to the top of the page after dragging the bottom item with jquery 1.5 <-> 1.11.
projects[drupal][patch][] = https://www.drupal.org/files/issues/2843240-22.patch

; Custom logo and favicon stored in private filesystem if it is the default.
projects[drupal][patch][] = https://www.drupal.org/files/issues/1087250.logo-public-filesystem.057.patch

; Ignore files dir contents but include files dir itself.
projects[drupal][patch][] = core/ignore_files_dir_contents_but_include_files_dir_itself.patch

; Mukurtu custom default.settings.php.
projects[drupal][patch][] = core/mukurtu_custom_default_settings_file.patch

; Multipatch combination of 3 separate custom patches from before this was cleaned up in drush patchfile:
; 1150608_use_comma_for_tax_delimiter_and_allow_quotes.patch
; 109315810-Change-delimiter-from-comma-to-semi-colon.patch
; 117661693-Stop-double-quoting-quotes-in-term-autocomplete.patch
projects[drupal][patch][] = core/multipatch-109315810-109315810-109315810.patch



;;;;;;;;;;;;;;;;;;;
;; Core Projects ;;
;;;;;;;;;;;;;;;;;;;
;;; These projects are contained in core, but must be specified here by their specific project name, not "Drupal"

;;; Color
; Show added palette fields. NOTE: this was not previously applied.
projects[color][patch][] = core/789554-show-added-palette-fields.patch
; Include newly added colorable elements.
projects[color][patch][] = core/include-newly-added-colorable-elements-1236098.patch

;;; Seven (theme)
; Use Mukurtu logo during install.
projects[seven][patch][] = core/use_mukurtu_logo_during_install.patch



;;;;;;;;;;;;;
;; Contrib ;;
;;;;;;;;;;;;;

;;; Bootstrap (theme)
; Add First and Last Classes to Lists
projects[bootstrap][patch][] = contrib/150281138-add-first-last-classes-to-lists.patch
; Do not skip over text format fields
projects[bootstrap][patch][] = contrib/150281089-Dont-skip-over-text_format-fields.patch

;;; Community Tags
; PHP Notice: Undefined variables: user and terms_to_add
projects[community_tags][patch][] = https://www.drupal.org/files/issues/community_tags-undefined-variables-7.x-1.x-2420969-1_0.patch

;;; Ctools
; Modal dialog position after ajax load is not refreshed
projects[ctools][patch][] = https://www.drupal.org/files/issues/ctools-fix_modal_position_after_ajax-1803104-25.patch

;;; Dummy Image
; The 'For missing images' option will always fail
projects[dummyimage][patch][] = https://www.drupal.org/files/issues/dummyimage_missing_1728026-5.patch

;;; Entity Reference
; Forbid to use duplicate entities in entityreference field
projects[entityreference][patch][] = https://www.drupal.org/files/2010488-forbid-duplicate-entities-in-entityreference-field_0.patch

;;; Feeds Tamper
; Alter required field tamper to allow 0 as value
projects[feeds_tamper][patch][] = contrib/0001-Alter-required-field-tamper-to-allow-0-as-value.patch

;;; Organic Groups
; Allow Groups Audience field for Feeds Mapping
projects[og][patch][] = https://www.drupal.org/files/1298238-feeds-og-audience-mapper.patch
; 1. Use custom mukurtu permission logic when editing nodes-in-CPs; 2. Fix bug where Community admins get edit perms on CP nodes therein, even if they should not have that permission.
projects[og][patch][] = contrib/132925713-Apply-Mukurtu-og-patches.patch

;;; Geofield & Geofield Gmap
; Feeds Import Not Saving Geofield
projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-feeds_import_not_saving-2534822-17.patch
; Google maps API fix
projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-google-api-key-2757953-42.patch
projects[geofield_gmap][patch][] = https://www.drupal.org/files/issues/fix-api-key-not-being-used-2746209-16.patch

;;; Partial Date
; Add property info callback
projects[partial_date][patch][] = https://www.drupal.org/files/issues/add_property_info-2781135-2.patch

;;; Owl Carousel
; Add ID to handle multiple carousels
projects[owlcarousel][patch][] = contrib/0001-Add-ID-to-handle-multiple-carousels.patch

;;; Scald
; Use simple dewplayer for audio
projects[scald][patch][] = contrib/use_simple_dewplayer_for_audio.patch
; Make whole scald drawer atom row draggable
projects[scald][patch][] = contrib/make_whole_scald_drawer_atom_row_draggable.patch
; Change default scald audio html5 template
projects[scald][patch][] = contrib/Change-default-scald-audio-html5-template.patch
; Add custom hook in scald for media warnings
projects[scald][patch][] = contrib/Add-custom-hook-in-Scald-for-media-warnings.patch
; Uploaded video dimension fix. Copies the code from scald_youtube. NOTE: this was not previously applied.
projects[scald][patch][] = contrib/uploaded_video_dimension_fix.patch
; Upload video do no fill dimensions on upload. NOTE: this was not previously applied.
projects[scald][patch][] = contrib/uploaded_video_do_not_fill_dimenions_on_upload.patch

;;; Scald Feeds
; Add scald feeds metadata support
projects[scald_feeds][patch][] = contrib/83564940-add_scald_metadata_support.patch

;;; Scald Soundcloud
; Respect quoted strings in Soundcloud tags
projects[scald_soundcloud][patch][] = contrib/Respect-quoted-strings-in-Soundcloud-tags.patch

;;; Search API
; Fix 'For missing images' option will always fail
projects[search_api][patch][] = https://www.drupal.org/files/issues/search_api-fix_access_info_indexing.patch
; Modify dictionary search results based on custom sort
projects[search_api_db][patch][] = contrib/modify_dictionary_search_results_based_on_custom_sort.patch

;;; Search API DB
; Change Seach API DB to pull regex from Search API
projects[search_api_db][patch][] = contrib/0001-Change-Search-API-DB-to-pull-regex-from-Search-API.patch

;;; Search API Glossary
; 1. Index display and sort ALL characters. 2. Option to skip padding
projects[search_api_glossary][patch][] = contrib/index_display_and_sort_ALL_characters_and_option_to_skip_padding.patch

;;; Services
; Fix services issue with multivals
; see https://www.drupal.org/project/services/issues/2224803
projects[services][patch][] = contrib/fix_services_multivals-2224803-comment-8844431

;;; Tree (treeable)
; Skip treeable field formatter patch
projects[tree][patch][] = contrib/skip_treeable_field_formatter.patch

;;; Views
; Taxonomy term "Representative node" views with filters and sorts don't work
projects[views][patch][] = https://www.drupal.org/files/issues/views-representative_view-1417090-82.patch
; Change delimiter from coma to semi-colon
projects[views][patch][] = contrib/109315810-Views-Change-delimiter-from-comma-to-semi-colon.patch

;;; WYSIWYG (as already patched by Open Atrium)
; Do not disable ckeditor, as it is used in Mukurtu for Scald in text fields.
projects[wysiwyg][patch][] = contrib/do_not_disable_ckeditor.patch



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Open Atrium owned Projects ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

projects[wysiwyg][patch][1489096] = http://drupal.org/files/wysiwyg-table-format.patch
projects[wysiwyg][patch][1786732] = http://drupal.org/files/wysiwyg-arbitrary_image_paths_markitup-1786732-3.patch
projects[wysiwyg][patch][2884691] = https://www.drupal.org/files/issues/wysiwyg-theme-css-v24-2884691-8.patch
projects[wysiwyg][patch][2884761] = https://www.drupal.org/files/issues/wysiwyg-tinymce-css-array-2884761-5.patch
projects[wysiwyg][patch][2890066] = https://www.drupal.org/files/issues/wysiwyg-isnode-2890066-2.patch
projects[wysiwyg_filter][patch][1687794] = https://www.drupal.org/files/wysiwyg_filter-1687794-1-skip-validation-if-filter-disabled.patch
projects[linkit][patch][2651404] = https://www.drupal.org/files/issues/linkit-add-to-any-element-2651404-3.patch
projects[image_resize_filter[patch][1929710] = https://www.drupal.org/files/issues/image_resize_filter-query_string-1929710-14-D7.patch
projects[caption_filter][patch][2455253] = https://www.drupal.org/files/issues/caption_filter-single-quotes-to-entities.patch
libraries[tinymce][patch][1561882] = http://drupal.org/files/1561882-cirkuit-theme-tinymce-3.5.8.patch
libraries[tinymce][patch][2876031] = https://www.drupal.org/files/issues/tinymce-chrome58-fix-2876031-5.patch
libraries[markitup][patch][1715642] = http://drupal.org/files/1715642-adding-html-set-markitup-editor.patch
projects[radix_layouts][patch][2656890] = https://www.drupal.org/files/issues/radix-layouts-selby-2656890-2.patch
projects[radix_layouts][patch][26568901] = https://www.drupal.org/files/issues/radix-layouts-selby-flipped-2656890-2.patch
projects[radix_layouts][patch][2656908] = https://www.drupal.org/files/issues/radix-layouts-content-area-2656908-6.patch
projects[manualcrop][patch][2521962] = https://www.drupal.org/files/issues/manualcrop_dont_show_crop_for_video-2521962-1.patch
projects[file_entity][patch][2360043] = https://www.drupal.org/files/issues/file_entity-destination-token-decode-2360043-1.patch
projects[file_entity][patch][2386015] = https://www.drupal.org/files/issues/2386015-file_entity-trigger-1.patch
projects[file_entity][patch][2067671] = https://www.drupal.org/files/issues/file_entity-REVERT_2067671-EntityFieldQuery-altering-35.patch
projects[media][patch][2372907] = https://www.drupal.org/files/issues/media-replace-fake-button-2372907-2.patch
projects[media][patch][2473481] = https://www.drupal.org/files/issues/clicking_images_in-2473481-1.patch
projects[media][patch][2528428] = https://www.drupal.org/files/issues/media_browser_view_javascript_not_loaded-2528428-4.patch
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch
projects[search_api_db][patch][2855634] = https://www.drupal.org/files/issues/2855634-23--fix_update_7107_for_different_db.patch
projects[admin][patch][1334804] = http://drupal.org/files/1334804-admin-jquery-updated-6.patch
projects[navbar][patch][1757466] = http://drupal.org/files/navbar-conflict-1757466-14.patch
projects[navbar][patch][2050559] = http://drupal.org/files/z-index-heart-cools-2050559-1.patch
projects[breakpoints][patch][2415363] = https://www.drupal.org/files/issues/2415363-breakpoints-menu_rebuild-13.patch
projects[ctools][patch][2607626] = https://www.drupal.org/files/issues/ctools-close-modal-2607626-5.patch
projects[ctools][patch][2787045] = https://www.drupal.org/files/issues/ctools-jquery_compatibility-2787045-14.patch
projects[ctools][patch][2897965] = https://www.drupal.org/files/issues/ctools-wizard-destination-2897965-2.patch
projects[ctools][patch][1901106] = https://www.drupal.org/files/issues/1901106-ctools-views_content-override-ajax-34.patch
projects[ctools][patch][2023705] = https://www.drupal.org/files/issues/2023705-ctools-autosubmit-15.patch
projects[ctools][patch][2448989] = https://www.drupal.org/files/issues/2448989-ctools-from_field_children-8.patch
projects[ctools][patch][2483415] = https://www.drupal.org/files/issues/ctools-more_than_one_comment_pager-2483415-1.patch
projects[ctools][patch][2555469] = https://www.drupal.org/files/issues/2555469-ctools-comments-node_tag_new-2.patch
projects[panels][patch][1570120] = https://www.drupal.org/files/issues/move-image-1570120-31.patch
projects[panels][patch][2897658] = https://www.drupal.org/files/issues/panels-menu-block-ipe-2897658-3.patch
projects[panelizer][patch][1549608] = https://www.drupal.org/files/issues/panelizer-n1549608-26.patch
projects[panelizer][patch][2788851] = https://www.drupal.org/files/issues/panelizer-administer-panelizer-2788851-2.patch
projects[fieldable_panels_panes][patch][2826205] = https://www.drupal.org/files/issues/fieldable_panels_panes-n2826205-39.patch
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = https://www.drupal.org/files/issues/1735096-views-multiple-instance-exposed-form-15.patch
projects[views][patch][2411922] = https://www.drupal.org/files/issues/2411922-views-group_name-3.patch
projects[views][patch][2473389] = https://www.drupal.org/files/issues/2473389-views-arg-15.patch
projects[views_autocomplete_filters][patch][2374709] = http://www.drupal.org/files/issues/views_autocomplete_filters-cache-2374709-2.patch
projects[views_autocomplete_filters][patch][2317351] = http://www.drupal.org/files/issues/views_autocomplete_filters-content-pane-2317351-4.patch
projects[views_autocomplete_filters][patch][2404893] = https://www.drupal.org/files/issues/2404893-grammar_correction-11.patch
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch
projects[entity][patch][1782134] = http://drupal.org/files/entity-translatable_fields_not_overriding_und_with_empty_values-1782134-5.patch
projects[entity][patch][1788568] = http://drupal.org/files/issues/entity-1788568-21-entity_metadata_wrapper_revisions.patch
projects[entity][patch][2407905] = http://drupal.org/files/issues/entity_unsupported_operand-2407905-1.patch
projects[entity][patch][2236229] = https://www.drupal.org/files/issues/add_create_op_to_metadata_comment_access-2236229-1.patch
projects[entity][patch][2289693] = https://www.drupal.org/files/issues/entity_undefined_entity_get_info-2289693-2.patch
projects[entity][patch][2807275] = https://www.drupal.org/files/issues/op_update_should_be_create-2807275-2.patch
projects[date][patch][2375235] = https://www.drupal.org/files/issues/calendar_pager_broken-2375235-35.patch
projects[entityreference][patch][1837650] = https://www.drupal.org/files/issues/1837650-142-entityreference-referencing-specific-revision-reroll-134_1.patch
projects[entityreference][patch][1492260] = https://www.drupal.org/files/issues/1492260-54.patch
projects[field_group][patch][2649648] = https://www.drupal.org/files/issues/php7_uniform_variable-2649648-5.patch
projects[link][patch][2666912] = https://www.drupal.org/files/issues/revert-url-validation-2666912.patch
projects[apps][patch][2753413] = https://www.drupal.org/files/issues/apps-manifest-2753413-3.patch
projects[apps][patch][2367191] = https://www.drupal.org/files/issues/apps_page_load_is_slow-2367191-5.patch
projects[defaultconfig][patch][1900574] = http://drupal.org/files/1900574.defaultconfig.undefinedindex_11.patch
projects[defaultcontent][patch][1754428] = http://drupal.org/files/1754428-allow-node-export-alter.patch
projects[defaultcontent][patch][1757782] = http://drupal.org/files/1757782-cannot-import-menu-hierarchy-8.patch
projects[bootstrap_library][patch][2244553] = https://www.drupal.org/files/issues/bootstrap_library-jquery_version_check-2244553-8.patch
projects[conditional_fields][patch][2027307] = https://www.drupal.org/files/issues/2027307-conditional_fields-export-clean-3.patch
projects[feeds][patch][2127787] = https://www.drupal.org/files/issues/2127787-feeds-feed_nid-3.patch
projects[feeds][patch][2828605] = https://www.drupal.org/files/issues/feeds-moved-module-2828605-7.patch
projects[htmlmail][patch][1692966] = https://www.drupal.org/files/1692966-htmlmail-mailsystem-html-to-text.patch
projects[message][patch][2046591] = http://drupal.org/files/message-token_replace-2046591-1.patch
projects[message][patch][2040735] = http://drupal.org/files/message.target_bundles.2040735-3.patch
projects[mimemail][patch][1568680] = https://www.drupal.org/files/issues/mimemail-1568680-message-var-for-theming.patch
projects[mimemail][patch][2552613] = https://www.drupal.org/files/issues/mimemail_broken_images_urls-2552613-9.patch
projects[og][patch][2363599] = http://drupal.org/files/issues/og-2363599-1-infinite-loop-entityreference-revisions-load.patch
projects[og][patch][2403619] = https://www.drupal.org/files/issues/2403619-og_widget_settings-1.patch
projects[og][patch][2411041] = https://www.drupal.org/files/issues/2411041-og-og_is_member-5-12.patch
projects[og][patch][2717489] = https://www.drupal.org/files/issues/og_context_infinite_loop-2717489-10.patch
projects[og_vocab][patch][2039009] = https://www.drupal.org/files/issues/2039009-og_vocab-share-29.patch
projects[og_vocab][patch][2399883] = https://www.drupal.org/files/issues/2399883-og_vocab-menuitem-4.patch
projects[og_vocab][patch][2503991] = https://www.drupal.org/files/issues/og_vocab_support_custom_widget_settings-2503991-1.patch
projects[og_vocab][patch][2242387] = https://www.drupal.org/files/issues/og_vocab_override_widget_settings-2242387-2.patch
projects[og_vocab][patch][2503997] = https://www.drupal.org/files/issues/og_vocab_add_support_for_select2widget-2503997-1.patch
projects[paragraphs][patch][2458801] = https://www.drupal.org/files/issues/paragraphs-instructions_setting-2458801-14.patch
projects[paragraphs][patch][2481627] = https://www.drupal.org/files/issues/paragraphs-modal_targets_wrong_id-2481627-3.patch
projects[paragraphs][patch][2560601] = https://www.drupal.org/files/issues/2560601-paragraphs-join_extra-2.patch
projects[reference_option_limit][patch][1986532] = https://www.drupal.org/files/issues/1986532-reference_option_limit-og-7.patch
projects[reference_option_limit][patch][1986526] = http://drupal.org/files/1986526_reference_option_limit_12.patch
libraries[plupload][patch][1903850] = https://drupal.org/files/issues/plupload-1_5_8-rm_examples-1903850-16.patch
projects[simpletest_clone][patch][1666560] = https://www.drupal.org/files/vars_refresh.patch
projects[panels_everywhere][patch][2656312] = https://www.drupal.org/files/issues/panels_everywhere-node-changes-shown-twice-2656312-3.patch
projects[panels_everywhere][patch][1139918] = https://www.drupal.org/files/issues/panels_everywhere-n1139918-64.patch
projects[mailhandler][patch][2931124] = https://www.drupal.org/files/issues/2931124-remove-make-2.patch
projects[fullcalendar][patch][2044391] = http://drupal.org/files/fullcalendar-legend-entityreference_taxonomy-2044391-1.patch
projects[fullcalendar][patch][2333883] = http://drupal.org/files/issues/fullcalendar-update-fullcalendar-download-url-2333883-1.patch
projects[colors][patch][1814972] = http://drupal.org/files/og-7.x-2.x_0.patch
projects[colors][patch][2044395] = http://drupal.org/files/colors-entityreference_taxonomy-2044395-1.patch
projects[geophp][patch][2144775] = https://www.drupal.org/files/issues/absolute-path_0.patch
projects[geofield][patch][2757953] = https://www.drupal.org/files/issues/geofield-google-api-key-2757953-42.patch
projects[dhtml_menu][patch][1985486] = http://drupal.org/files/1985486-dhtml_theme_inc_file_include.patch
projects[media_colorbox][patch][2087565] = http://drupal.org/files/media_colorbox_private-file-permission-2087565-1.patch
projects[plupload][patch][2386741] = https://www.drupal.org/files/issues/2386741-plupload-modal-2.patch
libraries[plupload][patch][1903850] = https://www.drupal.org/files/issues/plupload-1_5_8-rm_examples-1903850-21.patch
projects[comment_alter][patch][2540782] = https://www.drupal.org/files/issues/comment_alter_overwrites_fields-2540782-1.patch
