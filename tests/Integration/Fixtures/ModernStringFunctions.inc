<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1

// ERROR: strpos with false comparison.
if ( strpos( $haystack, $needle ) === false ) {}

// ERROR: strpos with 0 comparison.
if ( strpos( $haystack, $needle ) === 0 ) {}

// OK: strpos called directly without comparison.
strpos( $haystack, $needle );
