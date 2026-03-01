<?php
// phpcs:disable SlevomatCodingStandard.TypeHints
// phpcs:disable SlevomatCodingStandard.Functions.FunctionLength

// WARNING: 7 parameters exceeds default max of 6.
function too_many( $a, $b, $c, $d, $e, $f, $g ) {
	return $a;
}

// OK: exactly 6 parameters (at the limit).
function at_limit( $a, $b, $c, $d, $e, $f ) {
	return $a;
}

// OK: 3 parameters (well under limit).
function few_params( $a, $b, $c ) {
	return $a;
}

// OK: no parameters.
function no_params() {
	return true;
}

// WARNING: closure with 7 parameters.
$fn = static function ( $a, $b, $c, $d, $e, $f, $g ) {
	return $a;
};

// WARNING: arrow function with 7 parameters.
$fn = static fn( $a, $b, $c, $d, $e, $f, $g ) => $a;

// phpcs:set Apermo.CodeQuality.ExcessiveParameterCount maxParameters 3

// WARNING: 4 parameters exceeds custom max of 3.
function custom_limit( $a, $b, $c, $d ) {
	return $a;
}

// OK: 3 parameters (at custom limit).
function within_custom( $a, $b, $c ) {
	return $a;
}

// phpcs:set Apermo.CodeQuality.ExcessiveParameterCount maxParameters 6
