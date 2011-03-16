<?php
	function connect() {
		$user = admin_prayfj;
		$password = mLg1nayP;
		$database = admin_prayfj;
		mysql_connect(localhost, $user, $password);
		@mysql_select_db($database) or die("Unable to select database");
		print "Database OK\n";
	}

	function disconnect() {
		mysql_close();
	}