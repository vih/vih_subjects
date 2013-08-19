<?php
/**
 * @file
 * vih_subjects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vih_subjects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vih_subjects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function vih_subjects_node_info() {
  $items = array(
    'subject' => array(
      'name' => t('Subject'),
      'base' => 'node_content',
      'description' => t('Use when adding new subjects.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
