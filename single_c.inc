<?php
	/**
	 * @file Controller code for single.php, view a single image
	 */

	include './model/db.inc';				// Include the model, database functions and stuff like that
	include './model/image.inc';			// Include the model for the 'image' table in the database. insert(), update() etc. 
	include './libs/krumo/class.krumo.php';

	// Global variables 
	$message = '';							// Messages to display to the user
	$image = array();						// Pass information about the image to the view
	
	
	/**
	 * Prepare variable for the single.php view 
	 */
	if($_SERVER['REQUEST_METHOD']=='GET') 
	{
		if(process_request())
		{
			//$message .= "Processing request<br />";
		}
		else
		{
			//$message .= "Invalid request<br />";
			die("<h1>Sorry, I don't know what that is.</h1>");
		}
	}
	
	/**
	 * Process the request 
	 */
	function process_request() 
	{
		// If our checks are successful, 
		if(check_request())   
		{
			// Get the appropriate image from the database and populate variables for the view
			global $image; 
			$image = select_image($_GET["image"]);


			if ($image)
			{
				$request_succeeded = TRUE;
			}
			else
			{
				$request_succeeded = FALSE;
			}
		
			// Provide a short (240 character) version of description
			if (mb_strlen($image['description'], 'UTF-8') > 80)
			{
				$image['short_description'] = mb_substr($image['description'], 0, 79, 'UTF-8');
			}
			else
			{
				$image['short_description'] = $image['description'];
			}
			
			$image['image_path'] = 'files/' . $image['filename'];
			
			$image['date'] = $image['timestamp'];
		
		}
			
		
		// If select_image returned a value, we were successful, 
		// If it returned FALSE, we failed to process the request. 
		return $request_succeeded;
	}
		
		
	/**
	 * Check get request is a valid integer
	 */
	function check_request(){
		global $message;
		// Get the request
		$request = $_GET["image"];

		// Check it is numeric
		if (filter_var($request, FILTER_VALIDATE_INT, array("options" => array("min_range"=>1)))) 
		{
			//$message .= "Request is a valid integer";
			return TRUE;
		} 
		else 
		{
			$message .= 'Invalid request<br />';
			return FALSE;
		}
	}

	
	
	
