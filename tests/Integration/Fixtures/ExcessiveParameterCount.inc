<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1
// phpcs:disable SlevomatCodingStandard.TypeHints

// WARNING: too many parameters.
function excessive( $a, $b, $c, $d, $e, $f, $g ) {
	return $a . $b . $c . $d . $e . $f . $g;
}

// OK: within limit.
function ok_count( $a, $b, $c ) {
	return $a . $b . $c;
}
