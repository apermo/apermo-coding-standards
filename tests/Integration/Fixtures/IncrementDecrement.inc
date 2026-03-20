<?php
// phpcs:set Apermo.NamingConventions.MinimumVariableNameLength minLength 1
// phpcs:disable WordPress,Squiz,PSR1,SlevomatCodingStandard,Generic,PSR2,PEAR,Universal
// phpcs:disable Apermo.PHP,Apermo.WhiteSpace,Apermo.Formatting,Apermo.Arrays,Apermo.Hooks
// phpcs:disable Apermo.Functions,Apermo.DataStructures,Apermo.WordPress,Apermo.NamingConventions
// phpcs:disable Apermo.CodeQuality
// phpcs:enable SlevomatCodingStandard.Operators.RequireOnlyStandaloneIncrementAndDecrementOperators
// phpcs:enable Apermo.Operators.DisallowPreIncrementDecrement
// phpcs:enable Squiz.Operators.IncrementDecrementUsage
$a = 1;
$b = 1;
// Pre-increment — flagged by custom sniff (line 13).
++$a;
// Post-increment standalone — allowed (line 15).
$a++;
// Post-increment in for — allowed (line 17).
for ( $i = 0; $i < 10; $i++ ) { $a++; }
// Non-standalone: assignment with increment — flagged by Slevomat (line 19).
$b = $a++;
// Post-decrement standalone — allowed (line 21).
$a--;
// Manual increment — should not suggest pre-increment (line 23).
$a = $a + 1;
// Manual decrement — should not suggest pre-decrement (line 25).
$a = $a - 1;
