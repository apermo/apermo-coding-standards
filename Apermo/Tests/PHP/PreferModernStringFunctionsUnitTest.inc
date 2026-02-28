<?php
// phpcs:disable SlevomatCodingStandard.TypeHints.ParameterTypeHint
// phpcs:disable SlevomatCodingStandard.TypeHints.ReturnTypeHint
// phpcs:disable SlevomatCodingStandard.Variables.UnusedVariable
// phpcs:disable SlevomatCodingStandard.ControlStructures.RequireNullCoalesceOperator

// ERROR: strpos with false -> str_contains.
if ( strpos( $haystack, $needle ) === false ) {}

// ERROR: strpos with false (negated) -> str_contains.
if ( strpos( $haystack, $needle ) !== false ) {}

// ERROR: strpos with 0 -> str_starts_with.
if ( strpos( $haystack, $needle ) === 0 ) {}

// ERROR: strpos with 0 (negated) -> str_starts_with.
if ( strpos( $haystack, $needle ) !== 0 ) {}

// ERROR: reversed false === strpos -> str_contains.
if ( false === strpos( $haystack, $needle ) ) {}

// ERROR: reversed 0 === strpos -> str_starts_with.
if ( 0 === strpos( $haystack, $needle ) ) {}

// ERROR: strstr with false -> str_contains.
if ( strstr( $haystack, $needle ) === false ) {}

// ERROR: reversed false !== strstr -> str_contains.
if ( false !== strstr( $haystack, $needle ) ) {}

// OK: strpos without strict comparison (not our concern).
if ( strpos( $haystack, $needle ) ) {}

// OK: strpos result stored, no comparison.
$pos = strpos( $haystack, $needle );

// OK: method call, not global function.
$obj->strpos( $haystack, $needle );

// OK: static method call.
Str::strpos( $haystack, $needle );

// OK: strstr with 0 is not flagged (strstr returns string, not int).
if ( strstr( $haystack, $needle ) === 0 ) {}
