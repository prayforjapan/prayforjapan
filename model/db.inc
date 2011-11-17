<?php
	// Function for connecting to the database.
	function connect() {
		$user = "";
		$password = "";
		$database = "";
		mysql_connect(localhost, $user, $password);
		@mysql_select_db($database) or die("Unable to select database");
		$message .= "Database OK\n";
	}

	// Function for disconnecting from the database when we are finished.
	function disconnect() {
		mysql_close();
	}