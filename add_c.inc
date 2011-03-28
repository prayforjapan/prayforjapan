<?php

//OLDMAN: A little confused about the structure here, does it mattter what order these functions go in?
	//CHARLEY: No. It kicks off on the first call to process_form() which then calls the other functions. 
	// Maybe it would be easier to read if I put more of the logic inside of the first 'if' block.  

	
// It seems to me like it should go check_captcha(), check_file(), process_form(),your first if statement, submit_form_to_database(),store_submitted_file() 
// It must be late, because  what I just said was totally fucktarded. I take it that just like in java you are only declaring methoods here, 
// and instantiating / calling them at some other point.   
	//CHARLEY: Yes, I'm just declaring the functions. The program doesn't mind what order they are in, but it would be nicer for humans if they were in the order that they will be called. 

// I think it looks pretty good. one or two inline comments below, but probably mostly syntax confusions on my part 
// MAYBE if the project was any bigger you might have really tight resriction on method calls etc, so all the database access functionallity 
// is wrapped within a dbAccess class, no processing occurs in views etc (im pretty sure this is what you have done anyway, but without a better handle on php I'm a little confuzzled!)
// soz i couldnt be more help, good luck : )  
	//CHARLEY: I would like to do that. I copied the structure from 
	// http://toys.lerdorf.com/archives/38-The-no-framework-PHP-MVC-framework.html
	// He uses a class called db, but I couldn't figure it out so I wrote my own. 

	/**
	 * @file Controller code for add.php image upload form
	 */

	include './model/db.inc';				// Include the model, database functions and stuff like that
	include './model/image.inc';			// Include the model for the 'image' table in the database. insert(), update() etc. 
	require('./libs/recaptchalib.php');		// Load reCAPTCHA library
	include './libs/krumo/class.krumo.php';

	// Global variables 
	$message = '';							// Messages to display to the user
	$submission = array();					// User submission array to feed to the database
	
	
	/**
	 * Figure out if we are receiving a 'post' form submission 
	 */
	if($_SERVER['REQUEST_METHOD']=='POST') 
	{
		// If process_form() function is successful
		$query_id = process_form();
		if ($query_id)
		{
			$message .= "Success, your picture has been added  to the database<br /> You win.<br />";
			$message .= '<a href="/single.php?image=' . $submission['picture_id'] . '">View your submission</a>';
		}
		else
		{
			$message .= "You lose. <br />";			//OLDMAN: I love it
		}
	}


	/**
	 * Process the form submitted by the user
	 */
	function process_form() 
	{
		// If our checks are successful, try to store the submitted picture in our ./files
		// and store information about the file in the database.
		// Instead of calling the functions inside the if statement, 
		// store their values so we don't lose notifications by && 
		// ignoring the second function if the first one has already returned FALSE
		$check_captcha = check_captcha(); 	// Store success or failure of check_captcha();
		$check_file = check_file(); 		// Store success or failure of check_file();
		if($check_captcha && $check_file)   
		{
			// first store_submitted_file(), then if that is successful then submit_form_to_database()
			if (store_submitted_file() == TRUE) 	//OLDMAN: syntax newb again. Is if(store_submitted_file == true) implied automatically here? as in you dont need to code '==true' into it? 
														//CHARLEY: This could be written as if(store_submitted_file() == TRUE).  
			{
				$query_id = submit_form_to_database();
				return $query_id;
			}
		}
		return FALSE;
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
			//$message .= "CAPTCHA code correct";
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
		global $submission;

		
		// If the file  was uploaded succesfully, run some checks on it to determine the filetype 
		if($_FILES["file"]["error"] == 0 && !empty($_FILES["file"]["tmp_name"]))
		{

			$image_info = getimagesize($_FILES["file"]["tmp_name"]);
			$valid_image_type = FALSE;
			switch($image_info['mime'])
			{
				case 'image/png':
					$submission['file_extension'] = '.png';
					$valid_image_type = TRUE;
					break;
				case 'image/gif':
					$submission['file_extension'] = '.gif';
					$valid_image_type = TRUE;
					break;
				case 'image/jpeg':
					$submission['file_extension'] = '.jpg';
					$valid_image_type = TRUE;
					break;
				case 'image/pjpeg':
					$submission['file_extension'] = '.jpg';
					$valid_image_type = TRUE;
					break;
				default:
					$valid_image_type = FALSE;
			}
		}

		
		
		// File should be gif, jpeg or progressive jpeg, smaller than 2mb
		if (($valid_image_type)
		&& ($_FILES["file"]["size"] < 2000000))
		{
			// Uploaded file meets the requirements
			return TRUE;
		}
		else
		{
			$message .= 'You must submit a jpeg, gif or png image smaller than 2 megabytes<br />';
			return FALSE;
		}
	} 
	
	
	/**
 	 * Function for storing the submitted file
 	 */
	function store_submitted_file()
	{
		// Get the location of our uploaded file.
		$tmp_file_name = $_FILES["file"]["tmp_name"];

		// Remove '/tmp/' from $tmp_file_name 
		global $submission;
		$submission["filename"] = substr($tmp_file_name, 5);
		// append the correct file extension (.jpg, .png, .gif)
		$submission["filename"] .= $submission['file_extension'];
		
		// Don't overwrite existing files with the same name 
		if (!file_exists("files" . $submission["filename"]) 							// if there is no file with that name already
			&& move_uploaded_file($tmp_file_name, "files/" . $submission["filename"])) 	// then move_uploaded_file (&& skips the second test if the first one fails)
		{
			return TRUE;		
		}
		else
		{
			return FALSE;		//OLDMAN: to where? - is this meant to always return false, or does it need a condition? Is an else implied automatically? (probably being totallly thick about the syntax here!)
									//CHARLEY: I have re-written it to make more sense. Originally if it didn't get to return TRUE then it carried on and returned FALSE. 
		}	
	}									

	
	/**
	 * Function for submitting a submission to the database.
	 */
	function submit_form_to_database()
	{
		global $submission;
		global $message;
		// Use php filter_var()  (hopefully preventing XSS, SQL injection, etc.)
		$submission['description'] = filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS);
			
		// Add form fields to the database  
		$query_id = insert($submission);
		
		$submission['picture_id'] = (string) $query_id;
		
		return $query_id;
	}	
