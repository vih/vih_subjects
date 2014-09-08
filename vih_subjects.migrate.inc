<?php

/**
 * @file
 *  Migrations for vih_subjects.
 */

class VIHSubjectsNode extends VIHMigration {

  public function __construct(array $arguments) {
    $this->arguments = $arguments;
    parent::__construct();
    $this->description = t('Import subject nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'vih_subjects') . '/import/subjects.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('subject');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_subject_teaser', 'teaser');
    $this->addFieldMapping('field_subject_teaser:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');

    $this->addFieldMapping('field_subject_video', 'video');
    $this->addFieldMapping('field_subject_video:file_class')->defaultValue('MigrateExtrasFileYoutube');

    $this->addFieldMapping('field_course_leader', 'teacher')
      ->sourceMigration('VIHEmployeesContext');

    $this->addFieldMapping('field_terms', 'category');
    $this->addFieldMapping('field_terms:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_subject_package', 'package');
    $this->addFieldMapping('field_subject_package:create_term')
      ->defaultValue(TRUE);

    // Featured image
    $this->addFieldMapping('field_featured_image', 'featured_image');
    $this->addFieldMapping('field_featured_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_featured_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'vih_subjects') . '/import/images');

    $this->addFieldMapping('field_pictures', 'all_images');
    $this->addFieldMapping('field_pictures:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_pictures:source_dir')
      ->defaultValue(drupal_get_path('module', 'vih_subjects') . '/import/images');
  }

  public function prepareRow($row) {
    $row->all_images = explode(',', $row->images);
  }

  function csvcolumns() {
    $columns[0] = array('id', 'Id');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('teaser', 'Teaser');
    $columns[3] = array('body', 'Body');
    $columns[4] = array('video', 'Video');
    $columns[5] = array('teacher', 'Teacher');
    $columns[6] = array('category', 'Category');
    $columns[7] = array('package', 'Package');
    $columns[8] = array('featured_image', 'Featured Image');
    $columns[9] = array('images', 'Images');
    return $columns;
  }
}

class VIHSubjectsPackageTaxonomy extends VIHMigration {

  public function __construct(array $arguments) {
    $this->arguments = $arguments;
    parent::__construct();
    $this->description = t('Import subject package taxonomies.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'vih_subjects') . '/import/package.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm('subject_packages');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);

    $this->addFieldMapping('name', 'name');

    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('description:format')
      ->defaultValue('panopoly_wysiwyg_text');
      
    $this->addFieldMapping('field_tags_picture', 'image');
    $this->addFieldMapping('field_tags_picture:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_tags_picture:source_dir')
      ->defaultValue(drupal_get_path('module', 'vih_subjects') . '/import/images');
  }

  function csvcolumns() {
    $columns[0] = array('id', 'Id');
    $columns[1] = array('name', 'Name');
    $columns[2] = array('description', 'Description');
    $columns[3] = array('image', 'Image');
    return $columns;
  }
}
