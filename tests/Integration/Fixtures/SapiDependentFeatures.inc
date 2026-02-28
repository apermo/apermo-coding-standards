<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1
// phpcs:disable SlevomatCodingStandard.Variables.UnusedVariable

// ERROR: INPUT_REQUEST is unsupported.
$v = filter_input( INPUT_REQUEST, 'key' );

// WARNING: INPUT_SERVER is SAPI-dependent.
$v = filter_input( INPUT_SERVER, 'REQUEST_URI' );

// OK: INPUT_GET is safe.
$v = filter_input( INPUT_GET, 'page' );
