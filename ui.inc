<?php

	/**
	 * Function for use in templates to display the 'header' of the page.
	 */
	function head($title="Default") { ?>
	<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
			"http://www.w3.org/TR/html4/loose.dtd">
	<html lang="en">
	 <head>
		<title><?php echo $title; ?></title>
		<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">

		<style type="text/css" media="screen">@import "styles.css";</style>
	 </head>
	 <body>
	  <div id="page">
		<div id="head">
			<div id="head_inner">
				<a href="/"><img src="images/header-image.jpg" alt="Pray For Japan" id="header_image" /></a>
				<div id="buttons">
					<a href="http://www.redcross.org.uk/japantsunami"><img src="images/donate.jpg" alt="donate" id="donate" /></a>
					<a href="add.php"><img src="images/submit-a-photo.jpg" alt="Submit a photo" id="submit_a_photo" /></a>
				</div><!-- #buttons -->
			</div><!-- #header_inner -->
		</div><!-- #header" -->
		<div id="gray_bar">
			<div id="gray_bar_inner">
				<img src="images/what-is-pray-for-japan.jpg" alt="What is Pray For Japan? Upload images to show your love and support for Japan in the aftermath of the massive earthquake and resulting tsunami that struck on the 11th of march" id="what_is_pfj" />
				<div id="unshin">
					<a href="http://www.facebook.com/pages/Pray-For-Japan/113675088711654"><img src="images/unshin.jpg" alt="Unshin" /></a>
					<p id="watch_pfj">Watch '<a href="http://www.facebook.com/pages/Pray-For-Japan/113675088711654">Pray For Japan</a>'
					Music Video by <strong>Megumi Miyoshi</strong>.</p>
				</div><!-- unshin -->
			</div><!-- #gray_bar_inner -->
		</div><!-- #gray_bar -->
		<div id="main_content">
			<div id="main_content_inner">
				<?php 
				global $message;
				if(!empty($message)) { ?>
					<div id="message"><p><?php echo $message; // Prints messages about whether the submission of the form was successful ?></p></div>
				<?php } ?>
	<?php
	}

	/**
	 * Function for use in templates to display the footer of the page. 
	 */ 
	function foot() { ?>
			</div><!-- #main_content_inner -->
		</div><!-- #main_content -->
		<div id="foot">
			<div id="foot_inner">
				<img src="images/footer-logo.jpg" alt="Pray For Japan" />
				<div id="foot_content">
					<h4>Links</h4>
					<ul>
						<li><a href="http://www.facebook.com/PlayPrayPay.A.Little.Something4JapanAid">Play For Japan Facebook group</a></li>
						<li><a href="http://www.facebook.com/pages/Pray-for-Japan/153055688050960">Pray For Japan Facebook group</a></li>
						<li><a href="http://www.facebook.com/pages/Pray-For-Japan/113675088711654?sk=app_178091127385">Pray For Japan song</a></li>
						<li><a href="http://www.facebook.com/musicforjapan">Music For Japan Facebook group</a></li>
						<li><a href="http://www.redcross.org.uk/japantsunami">Japan Tsunami Appeal</a></li>
					</ul>
					<h4>Contact</h4>
					<ul>
						<li><a href="mailto:info@prayforjapan.org.uk">info@prayforjapan.org.uk</a></li>
					</ul>
					<h4>Site design/build</h4>
					<ul>
						<li><a href="http://onehundredrivers.com">onehundredrivers.com</a></li>
					</ul>
				</div><!-- #foot_content -->
			</div><!-- #foot_inner -->
		</div><!-- #foot -->
	  </div><!-- #page -->
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
