<?php

	/**
	 * Function for use in templates to display the 'header' of the page.
	 */
	function head($title="Default") { ?>
	<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
			"http://www.w3.org/TR/html4/loose.dtd">
	<html lang="en">
	 <head>
	  <title><?php echo $title?></title>
	  <style type="text/css" media="screen">@import "styles.css";</style>
	 </head>
	 <body>
	  <br />
	  <div class="main">
	<?php
	}

	/**
	 * Function for use in templates to display the footer of the page. 
	 */ 
	function foot() { ?>
	  </div>
	  </body>
	</html>
	<?php
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
