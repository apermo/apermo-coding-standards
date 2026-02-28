<?php
// phpcs:disable SlevomatCodingStandard.TypeHints.ParameterTypeHint
// phpcs:disable SlevomatCodingStandard.TypeHints.ReturnTypeHint
// phpcs:disable SlevomatCodingStandard.Variables.UnusedVariable

// ERROR: query_posts() usage.
query_posts( 'post_type=page' );

// ERROR: query_posts() with array argument.
query_posts( [ 'post_type' => 'page' ] );

// OK: method call, not global function.
$wp->query_posts();

// OK: static method call.
WP::query_posts();

// OK: nullsafe method call.
$wp?->query_posts();

// OK: function definition.
function query_posts( $args ) {
	return true;
}
