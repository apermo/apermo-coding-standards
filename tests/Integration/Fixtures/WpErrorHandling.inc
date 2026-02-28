<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1
// phpcs:disable SlevomatCodingStandard.TypeHints
// phpcs:disable SlevomatCodingStandard.Variables.UnusedVariable

// WARNING: unchecked wp_remote_get().
function bad( string $u ): string {
	$r = wp_remote_get( $u );
	return wp_remote_retrieve_body( $r );
}

// OK: checked with is_wp_error().
function good( string $u ): string {
	$r = wp_remote_get( $u );
	if ( is_wp_error( $r ) ) {
		return '';
	}
	return wp_remote_retrieve_body( $r );
}
