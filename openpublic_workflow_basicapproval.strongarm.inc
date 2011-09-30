<?php
/**
 * @file
 * openpublic_workflow_basicapproval.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function openpublic_workflow_basicapproval_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_editors_choice';
  $strongarm->value = 1;
  $export['workbench_access_node_type_editors_choice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_home_page_feature';
  $strongarm->value = 1;
  $export['workbench_access_node_type_home_page_feature'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_press_release';
  $strongarm->value = 1;
  $export['workbench_access_node_type_press_release'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_site_page';
  $strongarm->value = 1;
  $export['workbench_access_node_type_site_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_editors_choice';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_editors_choice'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_home_page_feature';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_home_page_feature'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_press_release';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_press_release'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_site_page';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_site_page'] = $strongarm;

  return $export;
}
