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
		<meta name="description" content="Upload images to show your love and support for Japan in the aftermath of the massive earthquake and resulting tsunami that struck on the 11th of march" />
		<style type="text/css" media="screen">@import "styles.css";</style>
		<script src="js/swfobject.js" type="text/javascript" charset="utf-8"></script> 
		<script src="js/nonverblaster.js" type="text/javascript" charset="utf-8"></script> 
		<script type="text/javascript"> 
			var flashvars = {};
				flashvars.mediaURL = "media/pray_for_japan.mp3";
				flashvars.allowSmoothing = "true";
				flashvars.autoPlay = "false";
				flashvars.buffer = "6";
				flashvars.showTimecode = "false";
				flashvars.loop = "false";
				flashvars.controlColor = "0x000000";
				flashvars.controlBackColor = "0x000000";
				flashvars.scaleIfFullScreen = "true";
				flashvars.defaultVolume = "100";
				flashvars.showScalingButton = "true";
				// just leave the following away, if you want the player to be transparent
				// (params.wmode="transparent")
				flashvars.playerBackColor = "0xFFFFFF";
			
			
			var params = {};
				params.menu = "false";
				params.allowFullScreen = "true";
				params.allowScriptAccess = "always";
				params.wmode = "transparent";
			
			var attributes = {};
				attributes.id = "nonverblaster";
		
			swfobject.embedSWF("NonverBlaster.swf", "audioPlayer", "150", "17", "9", "js/expressinstall.swf", flashvars, params, attributes);
		
			registerForJavaScriptCommunication("nonverblaster");
		
			// Uncomment this function if you want to listen for the end of playback
			/*function computeEnd(){
				alert("end reached!");
			}*/
		</script> 
	 </head>
	 <body>
	 
	  <div id="page">
		<div id="head">
			<div id="head_inner">
				<a href="/"><img src="images/header-image.jpg" alt="Pray For Japan" id="header_image" /></a>
				<div id="facebook_like">
					<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="www.prayforjapan.org.uk" show_faces="false" width="450" font="verdana"></fb:like>
				</div><!-- #facebook_like -->
				<div id="buttons">
					<a href="http://www.japansociety.org.uk/earthquake/"><img src="images/donate.jpg" alt="donate" id="donate" /></a>
					<a href="add.php"><img src="images/submit-a-photo.jpg" alt="Submit a photo" id="submit_a_photo" /></a>
				</div><!-- #buttons -->
			</div><!-- #header_inner -->
		</div><!-- #header" -->
		<div id="gray_bar">
			<div id="gray_bar_inner">
				<img src="images/what-is-pray-for-japan.jpg" alt="What is Pray For Japan? Upload images to show your love and support for Japan in the aftermath of the massive earthquake and resulting tsunami that struck on the 11th of march" id="what_is_pfj" />
				
				
				<!-- Pray For Japan song and video -->
				<div id="unshin">
					
					<a href="http://prayforjapan.org.uk/song.php"><img src="images/unshin.jpg" alt="Watch Pray for Japan" id="watch"></a>
					<p id="pfj">
						<strong>Pray For Japan</strong><br />
						by Megumi Miyoshi
					</p>
					<div id="song">
						<div id="audioPlayer"> 
							<a href="http://www.adobe.com/shockwave/download/download.cgi?P1_Prod_Version=ShockwaveFlash" target="_blank">Get Flash</a> and enable Javascript.
						</div><!-- #audioPlayer -->
						<div id="text"><strong>Buy to support from:</strong><br />
						
						<a href="http://www.amazon.co.uk/Pray-For-Japan/dp/B004UIVW00">Amazon</a> |
						<a href="http://prayforjapan.org.uk/song.php">Info</a>
						</div>
					</div><!-- #song -->
						
					
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
						<li><a href="http://www.nytimes.com/interactive/2011/03/12/world/asia/20110312_japan.html#1">New York Times Pictures</a></li>
						<li><a href="http://www3.nhk.or.jp/news/">NHK News</a></li>
						<li><a href="http://www3.nhk.or.jp/daily/english/">NHK News English</a></li>
						<!--<li><a href="http://www.playforjapan.com">www.playforjapan.com</a></li>-->
						<!--<li><a href="http://www.japansociety.org.uk/">www.japansociety.org.uk</a></li>-->
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
				<a href="http://www.playforjapan.com" id="play_for_japan_link">
					<img src="images/play-for-japan-logo.jpg" alt="Play For Japan" id="play_for_japan" />
				</a>	
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
