<?php

/**
 *
 * form whose ajax-enabled and show a new table'
 *
 */
function bitsamericas_form($form, &$form_state) {
	$form['city'] = array(
    '#title' => t('Select the city'),
    '#type' => 'select',
    '#options' => array('Bogota' => 'Bogotá', 'Medellin' => 'Medellin', 'Calli' => 'Calli', 'Miami' => 'Miami'),
	);
  $form['submit'] = array(
	  '#value' => t("Guardar"),
	  '#type' => 'submit',
	  '#ajax' => array(
	    'callback' => 'ajax_city_callback',
	  ),
	  '#suffix' => "<div id='after_div'><h1>Table informatión</h1></div>"
	);

  return $form;
}

function settings_endpoint_form($form, &$form_state) {
	$form['endpoint_base'] = array(
		'#type' => 'textfield',
		'#title' => t('Endpoint base'),
		'#attributes'=> array('Placeholder' => t('Enter the endpoint base')),
		'#size' => 60,
		'#maxlength' => 60,
		'#required' => TRUE,
	);
	$form['appid'] = array(
		'#type' => 'textfield',
		'#title' => t('Appid'),
		'#attributes'=> array('Placeholder' => t('Enter the app id')),
		'#size' => 60,
		'#maxlength' => 60,
		'#required' => TRUE,
	);
	$form['units'] = array(
		'#type' => 'textfield',
		'#title' => t('Units'),
		'#attributes'=> array('Placeholder' => t('Enter the units')),
		'#size' => 60,
		'#maxlength' => 60,
		'#required' => TRUE,
	);
	$form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('ENVIAR'),
	);

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function settings_endpoint_form_submit($form, &$form_state) {
	$nid = db_insert('endponint_settings') -> fields(
  	array(
			'endpoint_base' => $form_state['values']['endpoint_base'],
			'appid'         => $form_state['values']['appid'],
			'units'         => $form_state['values']['units']
  	)
  )-> execute();  

  if ($nid) {
		watchdog('Bitsmaericas', 'successful connection', NULL, WATCHDOG_INFO);
		drupal_set_message(t('Congratulation, you are configured the endpoint connection'));
		drupal_goto('<front>');
	} 
}

