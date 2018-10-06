********************************************************************************
Introduction
********************************************************************************
This is small module which provides tooltip using library Tooltipster.

Installation instructions:
*************************
1. First enable the module from Drush or by administrator interface.
2. Download tooltipster library - http://iamceege.github.io/tooltipster
3. Create a folder tooltipster in sites/all/libraries directory.
4. Put js and css files of library in tooltipster folder created in step 3.
5. Done.


Tooltip look and feel changes:
******************************
UX/UI changes needs to be done in tooltipster.css. File should be present in
sites/all/libraries/ path.
Right now we are using tooltipster-default class for rendeing tooltip.

CSS help:
********

Add below in tooltipster.css for xyz class which will be given while calling
tooltip. Please see example below how we call tooltip from code.

.xyz {
  -webkit-border-radius: 8px;
  -moz-border-radius: 8px;
  border-radius: 8px;
  border: 0;
  background: #005263;
  color: #fff;
}


.xyz .tooltipster-content {
  font-size: 14px;
  line-height: 16px;
  padding:20px;
  overflow: hidden;
}

How to render tooltip:
*********************
Callback function:
-----------------
tooltip_anywhere_initialize($selector, $type = NULL, $content = NULL,
$position = NULL, $others = NULL);

Description of arguments:
------------------------
$selector - id or class of element (Do not include hash or dot)
$type - selector given is an id or class. Pass 'id' or 'class' as per selector.
$content - The content which needs to be rendered in tooltip.
$position - left,right,bottom or top. by default bottom is provided.
$others - This is theming information part. Pass theme information like below..
Remember argument should be of array type containing key value pair.

$others = array('theme' => 'tooltipster-default');


********************************************************************************
ISSUES
********************************************************************************

Normally no issue should come as per my regression testing. But if occurs then..

Please use the project issue tracker to report problems
http://drupal.org/project/issues/tooltip_anywhere

Project page:
http://drupal.org/project/tooltip_anywhere

********************************************************************************
AUTHOR
********************************************************************************
USERNAME: nitin.k
FULLNAME: Nitin Kumar
EMAIL: bargoti.nitin@gmail.com
