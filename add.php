<?php
	include './ui.inc';		// Common View Helper functions
	include './add_c.inc'; 	// Controller
	head();
?>
	<form action="add.php" method="post">
		<textarea name="description" cols="40" rows="10"></textarea>
		<p><input type="submit" value="submit" />
	</form>
	
<?php 
	foot();
?>
		