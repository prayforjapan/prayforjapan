<?php
	include './ui.inc';		// Common View Helper functions
	include './single_c.inc'; 	// Controller
	head("Pray For Japan > " . $image['short_description']);
?>
	
	<img src="/files/timthumb.php?src=/<?php echo $image['image_path']; ?>&w=620&zc=0" alt="<?php echo $image['short_description']; ?>" id="single_image"/>
	<div id="single_info">
		<p>Date: <span id="date"><?php echo $image['date']; ?></span></p>
		<p><?php echo $image['description']; ?></p>
		<div id="return"><a href="/"><span class="arrow">&larr;</span> Return to Gallery</a></div>
	</div>
	
	
	<p><strong><?php echo $message; // Prints messages to the user ?></strong></p>
	
<?php 
	foot();
?>
		
