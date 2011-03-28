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
		mysql_query($query);
		$query_row_id = mysql_insert_id();
		// Disconnect from the database
		disconnect();
		
		// Returns inserted row ID if successful, or FALSE if the query failed. 
		return $query_row_id;
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
		
		// Return the query result array
		return $result_array;
	}

	
	/**
	 * Function for selecting a page of images from the db table 'picture'.
	 */
	 function select_images($page=1) {
		// Connect to the database
		connect();
		$select_images = array();
		$select_images['rows_per_page'] = 10;
		
		// Prepare the database query
		$query = "SELECT COUNT(*) FROM picture";

		// Run the database query
		$result_resource = mysql_query($query) or die("Query failed: " . mysql_error());

		// Put the query result in to an array
		$result = mysql_fetch_row($result_resource);
		$select_images['number_of_rows'] = $result[0];
		$select_images['total_pages'] = (int) ceil($select_images['number_of_rows'] / $select_images['rows_per_page']);		
		
		// Check that $page is a valid page number
		if(!is_numeric($page) || $page < 1 || $page > $select_images['total_pages'])
		{
			disconnect();
			return FALSE;
		}
		
		$offset = ($page -1) * $select_images['rows_per_page'];
		$rows_per_page = $select_images['rows_per_page'];
		$query = "SELECT * FROM picture 
					LIMIT 	$offset, $rows_per_page";
		
		$result = mysql_query($query) or die("Query failed: " . mysql_error());
		
		$count = 0;
		while($row = mysql_fetch_assoc($result)) 
		{
			$select_images['images'][$count] = $row; 
			$count += 1;
		}
		
		
		
		// Disconnect from the database
		disconnect();
		
		// Return the query result array
		return $select_images;
	}

	
	
	
	
	
	
	
	
	
	