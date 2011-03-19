<?php
	include './ui.inc';		// Common View Helper functions
	include './add_c.inc'; 	// Controller
	head();
?>
	<p><strong><?php echo $message; // Prints messages about whether the submission of the form was successful ?></strong></p>
	<form action="add.php" method="post">
		<textarea name="description" cols="40" rows="10"></textarea>
		<?php 
			captchaform(); 
		?>
		<p><input type="submit" value="submit" />
		</form>
	
<?php 
	foot();
?>
		