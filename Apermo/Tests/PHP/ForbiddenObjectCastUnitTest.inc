<?php
// Warning: (object) cast.
$obj = (object) [ 'key' => 'value' ];

// Warning: (object) cast on variable.
$obj = (object) $array;

// OK: other casts are fine.
$int = (int) $value;
$str = (string) $value;
$arr = (array) $value;
$bool = (bool) $value;
