<?php
	include './index_c.inc'; 	// Controller
	include './ui.inc';		// Common View Helper functions


	head("Pray For Japan");
?>
	<!-- <?php echo $message; // Prints messages to the user ?> -->
	<h1>Pray For Japan</h1>	
	<?php 
	if ($images){
		foreach($images as $image)
		{ ?>
			<div class="submission">
				<a href="<?php echo $image['page_url']; ?>">
					<img src="/files/timthumb.php?src=/<?php echo $image['image_path']; ?>&h=192&w=300&zc=1" alt="<?php echo $image['short_description']; ?>" class="picture" />
					<p><?php echo $image['short_description']; ?></p>
					<p class="view_link">View &raquo;</p>
				</a>
			</div><!-- .submission -->
			
		<?php }
		} ?>

	<br style="clear: both;" />	
	
	
		<?php echo pagination(); ?>
	


<?php 
	foot();
?>
		
