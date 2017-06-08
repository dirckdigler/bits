<?php

/**
*
*  get connection data
* 
* @return data connection
*	
*/
function _retrieve_connection_data() {
  $result = db_query('SELECT * FROM {endponint_settings}');
	$data = $result->fetchAll();

	return $data;
}    