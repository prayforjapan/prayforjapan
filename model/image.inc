<?php
	/**
	 *	The database table 'image' looks like this:
	 *
	 *	COLUMN		TYPE		OTHER				DEFAULT VALUE
	 *	picture_id	int(11)		auto_increment	 	 	 	 	 	 	
	 *	description	text		utf8_unicode_ci 	NULL		 	 	 				 
	 *	filename	tinytext	utf8_unicode_ci				 	 	 	 	 	 	 
	 * 	timestamp	timestamp						 	 	 	 	 	 	
	 *	moderate	binary(1) 			 			1		 	 	 	 	 	 	
	 */

	/**
	 * Function for adding a row to the database table 'image'.
	 */
	 function insert($item) {
		global $message; // Pass messages to the user
		// Prepare the database query
		$query = "INSERT INTO picture VALUES (
			'', 
			'" . $item['description'] . "' , 
			'" . $item['filename'] . "',
			now(),
			'1'
			)";
		// Connect to the database
		connect();
		// Run the database query
		$query_success = mysql_query($query);
		
		// Disconnect from the database
		disconnect();
		
		return $query_success;
	}

	/**
	 * Function for selecting a row from the db table 'image'.
	 */
	 function select_image($id) {
		// Connect to the database
		connect();

		// Prepare the database query
		$query = "SELECT * FROM picture WHERE picture_id = " . $id;

		// Run the database query
		$result_resource = mysql_query($query) or die("Query failed: " . mysql_error());

		// Put the query result in to an array
		$result_array = mysql_fetch_assoc($result_resource);
	
		// Disconnect from the database
		disconnect();
		
		krumo($result_array);
		// Return the query result array
		return $result_array;
	}
