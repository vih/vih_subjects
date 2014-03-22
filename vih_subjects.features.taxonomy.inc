<?php
/**
 * @file
 * vih_subjects.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vih_subjects_taxonomy_default_vocabularies() {
  return array(
    'subject_category' => array(
      'name' => 'Subject Category',
      'machine_name' => 'subject_category',
      'description' => 'Used for categorization according to the weekly schedule.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'subject_packages' => array(
      'name' => 'Subject Packages',
      'machine_name' => 'subject_packages',
      'description' => 'Used to group subjects based on interest.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 9,
    ),
  );
}
