<?php
include './model/db.inc';
include './model/image.inc';

if($_SERVER['REQUEST_METHOD']=='POST') {
	$submission = array();
	$submission['description'] = filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS);

	insert($submission);

}

if($_SERVER['REQUEST_METHOD']=='GET') {
	
}


?>