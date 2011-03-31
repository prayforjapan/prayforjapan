<?php
	/**
	 * @file Controller code for single.php, view a single image
	 */

	include './model/db.inc';				// Include the model, database functions and stuff like that
	include './model/image.inc';			// Include the model for the 'image' table in the database. insert(), update() etc. 
	include './libs/krumo/class.krumo.php';

	// Global variables 
	$message = '';							// Messages to display to the user
	$images = array();						// Pass information about the image to the view
	
	
	
	/**
	 * Prepare variable for the single.php view 
	 */
	if($_SERVER['REQUEST_METHOD']=='GET') 
	{
		if (check_request()){
			//global $message;
			//$message .= "Request is a valid integer<br />";
			global $request;
			$request = $_GET['page'];
		}
		else
		{
			//$message .= "Request is not a valid integer<br />";
			$request = 1;
		}
		
		if(process_request())
		{
			//$message .= "Processing request<br />";
		}
		else
		{
			//$message .= "Invalid request<br />";
			//die("<h1>Sorry, I don't know what that is.</h1>");
		}
	}
	
	/**
	 * Process the request 
	 */
	function process_request() 
	{
		global $message;
		
		global $request;
		$select_images = select_images($request);
		
		if ($select_images == TRUE)   
		{
			
			global $images; 
			$images = $select_images['images'];			

			global $pagination;
			$pagination['total_pages'] = (int) $select_images['total_pages'];
			$pagination['current_page'] = (int) $select_images['current_page'];
			
			$count = 0;
			while($count < count($images))
			{
				// Provide a short (80 character) version of description
				if (strlen($images[$count]['description']) > 80)
				{
					$images[$count]['short_description'] = substr($images[$count]['description'], 0, 79);
				}
				else
				{
					$images[$count]['short_description'] = $images[$count]['description'];
				}
			
				// Setup full location of image for the view
				$images[$count]['image_path'] = 'files/' . $images[$count]['filename'];#
				
				
				// Provide the url to the single image view for this image
				$images[$count]['page_url'] = 'single.php?image=' . $images[$count]['picture_id'];#
				
				$count += 1;
			}
			
			//$message .= "select_images returned true<br />";
			return TRUE;
		}
		else
		{	

			//$message .= "select_images returned false<br />";
			return FALSE;
		}
	}
	
	/** 
	 * Template function for pagination
	 */
	function pagination()
	{
		global $pagination;
		$pagination_html = '';
		
		// Should we show the 'previous' button? 
		if ($pagination['current_page'] > 1)
		{
			$pagination['previous_page'] = $pagination['current_page'] -1;
			$pagination_html .= '<a href="/?page=' . $pagination['previous_page'] . '" id="previous"><span class="arrows">&laquo;</span>Previous</a>';
		}
		else
		{
			$pagination['previous_page'] = FALSE;
		}

		// Should we show the 'next' button?
		if ($pagination['current_page'] < $pagination['total_pages'])
		{
			$pagination['next_page'] = $pagination['current_page'] + 1;
			$pagination_html .= '<a href="/?page=' . $pagination['next_page'] . '" id="next">Next <span class="arrows">&raquo;</span></a>';
		}
		else
		{
			$pagination['next_page'] = FALSE;
		}
		if(!empty($pagination_html)){
			$pagination_html = '<div id="pagination">' . $pagination_html;
			$pagination_html .= "</div><!-- #pagination -->";
		}
		return $pagination_html;
	
	}
	 
		
		
	/**
	 * Check get request is a valid integer
	 */
	function check_request(){
		global $message;
		// Get the request
		$request = $_GET["page"];

		// Check it is numeric
		if (filter_var($request, FILTER_VALIDATE_INT, array("options" => array("min_range"=>1)))) 
		{
			//$message .= "Request is a valid integer";
			return TRUE;
		} 
		else 
		{
			//$message .= 'Invalid request<br />';
			return FALSE;
		}
	}

	
	
	
