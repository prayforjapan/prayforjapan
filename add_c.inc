<?php
	/**
	 * @file Controller code for add.php image upload form
         */

	// Include the model, database functions and stuff like that
	include './model/db.inc';

	// Include the model for the 'image' table in the database. insert(), update() etc. 
	include './model/image.inc';

	// Load reCAPTCHA library
	require('./libs/recaptchalib.php');

	// Global variables 
	$message = 'Messages to the user<br />';	 // Messages to display to the user
	$submission = array();				 // User submission array to feed to the database
	
	/**
	 * Figure out if we are receiving a 'post' form submission 
	 */
	if($_SERVER['REQUEST_METHOD']=='POST') 
	{
		process_form();
	}
	elseif($_SERVER['REQUEST_METHOD']=='GET')
	{
		// Do stuff like passing data from the model to the view	
		$message .= 'Processing a "get" request<br />';
	}

	/**
	 * Process the form submitted by the user
	 */
	function process_form() 
	{
		global $message;
		$message .= 'Checking CAPTCHA and uploaded file<br />';

		// Check if submitted CAPTCHA is correct with the check_captcha() function
		$captcha_success = check_captcha();

		// Check if submitted file is valid with the check_file() function
		$valid_file = check_file(); // Does the uploaded file pass our tests?

		// If our checks are successful, try to store the submitted picture and text description 
		// with store_submitted_file() and submit_form_to_database()
		if($valid_file && $captcha_success){
			$message .= 'Submitting form to database<br />';
			store_submitted_file();
			submit_form_to_database();
		}
	}
	
	/**
 	 * Function for storing the submitted file
 	 */
	function store_submitted_file()
	{
		global $message;
		global $submission;
		// Get the location of our uploaded file.
		$tmp_file_name = $_FILES["file"]["tmp_name"];

		// Remove '/tmp/' from $tmp_file_name
		$store_file_name = substr($tmp_file_name, 5) . ".jpg";
		//$message .= $store_file_name . "<br />";	
		//print_r($_FILES["file"]);

		// Don't overwrite existing files with the same name
		if(!file_exists("files" . $store_file_name)){
			$store_file_success = move_uploaded_file($tmp_file_name, "files/" . $store_file_name);
		}
		else
		{
			$message .= "Can't overwrite an existing file. Try again. Sorry.";
		}

		// Notify the user and copy the file to our 'files' directory
		if ($store_file_success){
			$message .= "Stored uploaded file: " . $store_file_name . "<br />";
			$submission["filename"] = $store_file_name;
		}
		else
		{
			$message .= "Failed to store uploaded file<br />";
		}
	}		

	/**
	 * Function for submitting a submission to the database.
	 */
	function submit_form_to_database()
	{
		global $message;
		global $submission;
	
		// Use php filter_var()  (hopefully preventing XSS, SQL injection, etc.)
		$submission['description'] = filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS);
			
		// Add form fields to the database  
		$db_query_success = insert($submission);
		
		// Notify the user of success or failure adding their submission to the database
		if($db_query_success){
			// Set a message that the form was submitted successfully.
			$message .= "Your submission has been added to the database.<br />";
		}
		else
		{	
			$message .= "The database query failed.<br />";
		}
	}	

	/** 
	 * Function for adding reCAPTCHA to forms in templates
	 */
	function captchaform(){
		// Set the reCAPTCHA public key
		$publickey = "6LdKjsISAAAAAPGSU-_hiN9V5NPQHW77dmgoMXaG"; 

		// Output the reCAPTCHA form
		echo recaptcha_get_html($publickey);
	}
	
		
	/**
	 * Check CAPTCHA submission 
	 */
	function check_captcha(){
		global $message;
		// Set the reCAPTCHA private key
		$privatekey = "6LdKjsISAAAAADd4h6Fwx_Ui9CYCB0Dh1KYz4W0D";
		// Get the CAPTCHA form submission and check it with the reCAPTCHA library
		$resp = recaptcha_check_answer ($privatekey,
			$_SERVER["REMOTE_ADDR"],
			$_POST["recaptcha_challenge_field"],
			$_POST["recaptcha_response_field"]);
		if ($resp->is_valid) 
		{
			$message .= 'CAPTCHA code correct<br />';
			return TRUE;
		} 
		else 
		{
			$message .= 'CAPTCHA code incorrect<br />';
			return FALSE;
		}
	}
	
		
	/** 
	 * Check submitted picture 
	 */
	function check_file(){
		global $message;
		// File should be gif, jpeg or progressive jpeg, smaller than 2mb
		if ((($_FILES["file"]["type"] == "image/gif")
		|| ($_FILES["file"]["type"] == "image/jpeg")
		|| ($_FILES["file"]["type"] == "image/pjpeg"))
		&& ($_FILES["file"]["size"] < 2000000))
		{
			$message .= 'Uploaded file meets the requirements<br />';
			return TRUE;
		}
		else
		{
			$message .= 'Uploaded file does not meet the requirements<br />';
			return FALSE;
		}
	} 
