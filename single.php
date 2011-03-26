<?php
	include './ui.inc';		// Common View Helper functions
	include './single_c.inc'; 	// Controller
	head($image['short_description']);
?>
	<p><strong><?php echo $message; // Prints messages to the user ?></strong></p>
	<h1><?php echo $image['short_description']; ?></h1>	
	<p><?php echo $image['description']; ?></p>
	<p><img src="<?php echo $image['image_path']; ?>" alt="<?php echo $image['short_description']; ?>" />

<?php 
	foot();
?>
		
