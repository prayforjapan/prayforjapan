
<p> Dirty: <?php echo $_POST["description"];?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"]); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_NO_ENCODE_QUOTES); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_LOW); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_HIGH); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_ENCODE_LOW); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_ENCODE_HIGH); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_STRING, FILTER_FLAG_ENCODE_AMP); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS, FILTER_FLAG_STRIP_LOW); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS, FILTER_FLAG_STRIP_HIGH); ?> </p>
<p> filter_var(): <?php echo filter_var($_POST["description"], FILTER_SANITIZE_SPECIAL_CHARS, FILTER_FLAG_ENCODE_HIGH); ?> </p>



