<?php

/**
 * Implements hook_apps_app_info()
 */
function openpublic_workflow_basicapproval_apps_app_info() {
  return array(
    'configure form' => 'openpublic_workflow_basicapproval_configure',
  );
}

/**
 * Configuration form for workflow app
 */
function openpublic_workflow_basicapproval_configure($form, $form_state) {
  $form = array();

  $form['setup'] = array(
    '#type' => 'fieldset',
    '#title' => 'Workflow Setup',
  );

  $roles = user_roles();
  // exclude anonymous & admin
  $admin_rid = variable_get('user_admin_role', 0);
  unset($roles[DRUPAL_ANONYMOUS_RID]);
  unset($roles[$admin_rid]);

  $assigned_count = db_select('role_permission', 'p')
    ->condition('module', 'workbench_moderation', '=')
    ->condition('rid', array_keys($roles), 'IN')
    ->countQuery()->execute()->fetchField();
  
  $form['setup']['table'] = array(
    '#theme' => 'table',
    '#header' => array('Status', 'Step', 'Instructions', 'Action'),
    '#rows' => array(
      'perm' => array(
        'data' => array(
          theme('image', array('path' => 'misc/watchdog-ok.png', 'alt' => 'OK')),
          t('Assign moderation permissions'),
          t('To make the most of workflow settings, permissions should be enabled to allow appropriate roles the control to move between workflow states.'),
          l('Add default permissions', 'admin/config/workbench/moderation/transitions/defaults', array('query' => drupal_get_destination())),
        ),
      ),
    ),
  );

  if ($assigned_count == 0) {
    $form['setup']['table']['#rows']['perm']['data']['0'] = theme("image", array("path" => "misc/watchdog-warning.png", "alt"=>"Warning"));
    $form['setup']['table']['#rows']['perm']['class'][] = 'warning';
  }
  
  
  $form['enabled'] = array(
    '#type' => 'fieldset',
    '#title' => 'Content Types for Workflow',
  );

  $types = array();
  $types_selected = array();
  foreach(node_type_get_types() as $name => $type) {
    $types[$name] = $type->name;
    if (workbench_moderation_node_type_moderated($name)) {
      $types_selected[$name] = $name;
    }
  }

  $form['enabled']['content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Content types that should have workflow enabled',
    '#options' => $types,
    '#default_value' => $types_selected,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  
  return $form;
}

function openpublic_workflow_basicapproval_configure_submit($form, $form_state) {
  foreach ($form_state['values']['content_types'] as $type => $checked) {
    $options = variable_get('node_options_' . $type, array());
    if ($checked) {
      $options[] = 'revision';
      $options[] = 'moderation';
      $options = array_unique($options);
    }
    else {
      $key = array_search('moderation', $options);
      if ($key !== FALSE) {
        unset($options[$key]);
      }
    }
    variable_set('node_options_'. $type, $options);
  }
}