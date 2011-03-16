<?php
/*
	picture_id	int(11)		auto_increment	 	 	 	 	 	 	
	description	text		utf8_unicode_ci 	NULL		 	 	 				 
	filename	tinytext	utf8_unicode_ci				 	 	 	 	 	 	 
	timestamp	timestamp						 	 	 	 	 	 	
	moderate	binary(1) 			 			1		 	 	 	 	 	 	
*/

function insert($item) {
	$query = "INSERT INTO picture VALUES (
		'', 
		'" . $item['description'] . "', 
		'john.jpg',
		now(),
		'1'
		)";
	connect();
	mysql_query($query);	
	disconnect();
}
