<?php
declare(strict_types=1);

/**
 * Flag query_posts() usage.
 *
 * @package Apermo\Sniffs\WordPress
 */

namespace Apermo\Sniffs\WordPress;

use Apermo\Sniffs\Helpers\FunctionCallDetectorTrait;
use PHP_CodeSniffer\Files\File;
use PHP_CodeSniffer\Sniffs\Sniff;

/**
 * Flags usage of query_posts() which corrupts the main WP_Query
 * and should always be replaced with WP_Query or get_posts().
 *
 * Error codes:
 * - Found: query_posts() usage detected
 */
class NoQueryPostsSniff implements Sniff {

	use FunctionCallDetectorTrait;

	/**
	 * Returns an array of tokens this sniff listens for.
	 *
	 * @return array<int>
	 */
	public function register() {
		return [ T_STRING ];
	}

	/**
	 * Processes a token.
	 *
	 * @param File $phpcsFile The file being scanned.
	 * @param int  $stackPtr  The position of the current token.
	 *
	 * @return void
	 */
	public function process( File $phpcsFile, $stackPtr ) {
		$tokens = $phpcsFile->getTokens();

		if ( strtolower( $tokens[ $stackPtr ]['content'] ) !== 'query_posts' ) {
			return;
		}

		if ( ! $this->isFunctionCall( $phpcsFile, $stackPtr ) ) {
			return;
		}

		$phpcsFile->addError(
			'query_posts() corrupts the main query; use WP_Query or get_posts() instead',
			$stackPtr,
			'Found',
		);
	}
}
