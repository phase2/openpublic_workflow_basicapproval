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