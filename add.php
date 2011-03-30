<?php
	include './ui.inc';		// Common View Helper functions
	include './add_c.inc'; 	// Controller
	head("Pray For Japan");
?>
	<div id="submit_photo">
	<form action="add.php" method="post" enctype="multipart/form-data">
		<div id="upload_1">
			<img src="images/upload-01.jpg" alt="1 Upload your image" /><br />
			<input type="file" name="file" id="file" class="button" /><br /> 
			(jpeg, gif or png image smaller than 2 megabytes)
		</div>
		<div id="upload_2">
			<img src="images/upload-02.jpg" alt="2 Enter description" /><br />
			<label for="description">Description: </label>
			<input type="text" name="description" /><br />
		</div>
		<div id="upload_3">
			<img src="images/upload-03.jpg" alt="3 Submit" /> 
			<?php captchaform(); ?>
			<input type="submit" value="submit" class="button" />
		</div>
		</form>
	</div><!-- #submit_photo -->
<?php 
	foot();
?>
		
