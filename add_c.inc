<?php
	// Include the model, database functions and stuff like that
	include './model/db.inc';
	// Include the model for the 'image' table in the database. insert(), update() etc. 
	include './model/image.inc';
	// Load reCAPTCHA library
	require('./libs/recaptchalib.php');

	/** 
	 * Function for adding reCAPTCHA to forms in templates
	 */
	function captchaform(){
		// Set the reCAPTCHA public key
		$publickey = "6LdKjsISAAAAAPGSU-_hiN9V5NPQHW77dmgoMXaG"; // you got this from the signup page

		// Output the reCAPTCHA form
		echo recaptcha_get_html($publickey);
	}


	/**
	 * Receive a submission from an html form
	 */
	if($_SERVER['REQUEST_METHOD']=='POST') {
		// CAPTCHA STUFF
		// Set the reCAPTCHA private key
		$privatekey = "6LdKjsISAAAAADd4h6Fwx_Ui9CYCB0Dh1KYz4W0D";

		// Get the CAPTCHA form submission and check it with the reCAPTCHA library
		$resp = recaptcha_check_answer ($privatekey,
									$_SERVER["REMOTE_ADDR"],
									$_POST["recaptcha_challenge_field"],
									$_POST["recaptcha_response_field"]);

		/**
		 * If the captcha submitted is wrong
		 */
		if (!$resp->is_valid) {
		$message = "The reCAPTCHA wasn't entered correctly. Go back and try it again." .
			 "(reCAPTCHA said: " . $resp->error . ")";
		} else {
		
		/**
		 * If the captcha submitted is right
		 */

		// Initialise $submission to hold information from the form
		$submission = array();
		
		// Use the php filter function to process the description field before storing it in $submission (hopefully preventing XSS, SQL injection, etc.) .
		$submission['description'] = filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS);
		
		// Add form fields to the database  
		insert($submission);

		// Set a message that the form was submitted successfully.
		$message = "Your submission has been added to the database.";
		}
	}

	/**
	 * Don't know what this is for yet.
	 */
	if($_SERVER['REQUEST_METHOD']=='GET') {
		// Do stuff here
	}

