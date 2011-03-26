<?php
	include './ui.inc';		// Common View Helper functions
	include './add_c.inc'; 	// Controller
	head();
?>
	<p><strong><?php echo $message; // Prints messages about whether the submission of the form was successful ?></strong></p>
	<form action="add.php" method="post" enctype="multipart/form-data">
		<p><label for="file">Upload a picture </label>
		<input type="file" name="file" id="file" /><br /> 
		(jpeg, gif or png image smaller than 2 megabytes)</p>
		<label for="description">Description: </label>
		<input type="text" name="description" /><br />
		<br />
		<?php
			captchaform(); 
		?>
		<p><input type="submit" value="submit" />
		</form>
	
<?php 
	foot();
?>
		
