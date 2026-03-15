<?php
// phpcs:disable WordPress,Squiz,PSR1,Generic,PSR2,PEAR,Universal
// phpcs:disable Apermo.PHP,Apermo.WhiteSpace,Apermo.Formatting,Apermo.Arrays,Apermo.Hooks
// phpcs:disable Apermo.Functions,Apermo.DataStructures,Apermo.WordPress,Apermo.NamingConventions
// phpcs:disable Apermo.CodeQuality,Apermo.Operators
// phpcs:disable SlevomatCodingStandard.Namespaces.AlphabeticallySortedUses
// phpcs:disable SlevomatCodingStandard.Namespaces.UnusedUses
// phpcs:disable SlevomatCodingStandard.TypeHints
// phpcs:disable SlevomatCodingStandard.Variables,SlevomatCodingStandard.Functions
// phpcs:disable SlevomatCodingStandard.Classes,SlevomatCodingStandard.Complexity
// phpcs:disable SlevomatCodingStandard.ControlStructures,SlevomatCodingStandard.Arrays
// phpcs:disable SlevomatCodingStandard.PHP,SlevomatCodingStandard.Operators

namespace App\Test;

// Inline FQN instead of use import — flagged (line 16).
$obj = new \App\Service\Mailer();
// use from same namespace — flagged (line 18).
use App\Test\Helper;
// Global function without backslash — flagged (line 20).
$exists = function_exists( 'my_function' );
// Global constant without backslash — flagged (line 22).
$version = PHP_VERSION;
// Properly imported class — allowed (line 24).
use App\Service\Logger;
$logger = new Logger();
