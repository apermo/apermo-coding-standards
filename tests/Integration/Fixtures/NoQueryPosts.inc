<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1

// ERROR: query_posts() corrupts the main query.
query_posts( 'post_type=page' );
