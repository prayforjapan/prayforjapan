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
