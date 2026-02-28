# Sniff Ideas for Agency WordPress Development

Collected from [WPCS open issues](https://github.com/WordPress/WordPress-Coding-Standards/issues) and agency-specific pain points.

## Security

| Sniff | Description | WPCS Issue |
|-------|-------------|------------|
| **FlagInlineScriptTags** | Flag manual construction of inline `<script>` tags — prefer `wp_add_inline_script()` | [#2575](https://github.com/WordPress/WordPress-Coding-Standards/issues/2575) |
| **NoHardcodedTableNames** ✅| SQL queries should use `$wpdb->prefix` / `$wpdb->tablename`, not hardcoded table names | [#2008](https://github.com/WordPress/WordPress-Coding-Standards/issues/2008) |
| **PreferWpdbIdentifierPlaceholder** ✅| Recommend `%i` placeholder for DB identifier names instead of direct `$wpdb->tablename` interpolation | [#2079](https://github.com/WordPress/WordPress-Coding-Standards/issues/2079) |
| **NoFilterSanitizeString** ✅| Flag use of deprecated `FILTER_SANITIZE_STRING` — it doesn't actually sanitize | [#2018](https://github.com/WordPress/WordPress-Coding-Standards/issues/2018) |
| **RequireNonceWithFilterInput** | Flag missing nonce verification when using `filter_input()` on POST/GET data | [#2299](https://github.com/WordPress/WordPress-Coding-Standards/issues/2299) |
| **UnsanitizedArrayKeys** | Flag unsanitized superglobal array keys (often overlooked attack vector) | [#2012](https://github.com/WordPress/WordPress-Coding-Standards/issues/2012) |

## WordPress API Correctness

| Sniff | Description | WPCS Issue |
|-------|-------------|------------|
| **RequireWpErrorHandling** ✅| Flag WP API calls that return `WP_Error` without checking the return value (`wp_remote_get`, `wp_insert_post`, etc.) | [#1974](https://github.com/WordPress/WordPress-Coding-Standards/issues/1974) |
| **SwitchToBlogRequiresRestore** ✅| Flag `switch_to_blog()` calls without a matching `restore_current_blog()` in the same scope | [#1987](https://github.com/WordPress/WordPress-Coding-Standards/issues/1987) |
| **NoUnsettingGlobals** | Flag unsetting WP global variables (`$post`, `$wp_query`, etc.) | [#1902](https://github.com/WordPress/WordPress-Coding-Standards/issues/1902) |
| **RequireOptionAutoload** ✅| Warn about missing `$autoload` parameter on `add_option()` / `update_option()` — common performance footgun | [#2473](https://github.com/WordPress/WordPress-Coding-Standards/issues/2473) |
| **DeprecatedHooksWarning** | Warn when using deprecated actions/filters | [#2071](https://github.com/WordPress/WordPress-Coding-Standards/issues/2071) |
| **NoPhpSessions** ✅ ⚠️ PHPStan| Discourage use of `session_start()`, `$_SESSION` — incompatible with object caching and many hosts. *Also solvable via [`spaze/phpstan-disallowed-calls`](https://github.com/spaze/phpstan-disallowed-calls).* | [#2475](https://github.com/WordPress/WordPress-Coding-Standards/issues/2475) |
| **EnqueueNullVersion** | Accept/require `null` as version argument for `wp_enqueue_style()`/`wp_enqueue_script()` to use WP version | [#1944](https://github.com/WordPress/WordPress-Coding-Standards/issues/1944) |
| **UnusedHookParameters** | Flag unused parameters in hook callbacks (accepting 3 params but only using 1) | [#1882](https://github.com/WordPress/WordPress-Coding-Standards/issues/1882) |
| **HookCallbackTypeHintConflict** | Alert when `add_filter` callback uses type hints that conflict with WP's untyped filter system | [#2014](https://github.com/WordPress/WordPress-Coding-Standards/issues/2014) |

## Modern PHP

| Sniff | Description | WPCS Issue |
|-------|-------------|------------|
| **PreferStrContains** | Flag `strpos($x, $y) !== false` — use `str_contains()` instead (PHP 8.0+) | [#2261](https://github.com/WordPress/WordPress-Coding-Standards/issues/2261) |
| **PreferStrStartsWith** | Flag `strpos($x, $y) === 0` — use `str_starts_with()` instead (PHP 8.0+) | [#2262](https://github.com/WordPress/WordPress-Coding-Standards/issues/2262) |
| **DisallowRelativeInclude** | Require absolute paths (via `__DIR__`, `plugin_dir_path()`) for include/require — prevents path resolution bugs | [#1953](https://github.com/WordPress/WordPress-Coding-Standards/issues/1953) |
| **WarnAliasedFunctions** | Flag PHP function aliases like `join()` → `implode()`, `chop()` → `rtrim()` | [#1966](https://github.com/WordPress/WordPress-Coding-Standards/issues/1966) |
| **NamespaceNamingConventions** | Validate that namespace names follow naming conventions | [#2304](https://github.com/WordPress/WordPress-Coding-Standards/issues/2304) |
| **NamespaceBlankLines** | Require blank line before and after namespace declaration | [#2305](https://github.com/WordPress/WordPress-Coding-Standards/issues/2305) |
| **ImportAliasNaming** | When aliasing use-imports, enforce naming conventions (e.g. PascalCase for classes) | [#2306](https://github.com/WordPress/WordPress-Coding-Standards/issues/2306) |

## Code Quality / Analysis

| Sniff | Description | WPCS Issue |
|-------|-------------|------------|
| **NoSprintfSingleArg** ✅| Flag `sprintf()` with a single argument (no placeholders) — indicates a mistake | [#2213](https://github.com/WordPress/WordPress-Coding-Standards/issues/2213) |
| **NoHtmlInFormatStrings** ✅| Detect HTML inside `sprintf()`/`printf()` format strings — fragile and hard to escape | [#1946](https://github.com/WordPress/WordPress-Coding-Standards/issues/1946) |
| **RequireSinceTag** | Enforce `@since` tags on public methods/functions for proper changelog tracking | [#1994](https://github.com/WordPress/WordPress-Coding-Standards/issues/1994) |
| **RequireThrowsTag** | Require `@throws` documentation when a method throws exceptions | [#1900](https://github.com/WordPress/WordPress-Coding-Standards/issues/1900) |
| **ForbidNewMagicMethods** | Forbid adding non-standard magic methods (e.g. `__wakeup`, `__serialize` misuse) | [#2445](https://github.com/WordPress/WordPress-Coding-Standards/issues/2445) |
| **PHPUnitNamingConventions** | Ensure test class/file names follow PHPUnit conventions | [#2484](https://github.com/WordPress/WordPress-Coding-Standards/issues/2484) |

## I18n

| Sniff | Description | WPCS Issue |
|-------|-------------|------------|
| **NoLeadingTrailingSpacesInTranslations** ✅| Flag translatable strings with leading/trailing whitespace | [#2501](https://github.com/WordPress/WordPress-Coding-Standards/issues/2501) |
| **RequireContextForX** | Flag `_x()` / `_ex()` calls with missing or empty context parameter | [#1952](https://github.com/WordPress/WordPress-Coding-Standards/issues/1952) |

## Agency-Specific (not from WPCS issues)

| Sniff | Description                                                                                              |
|-------|----------------------------------------------------------------------------------------------------------|
| **RequireTextDomain** ✅| Ensure all i18n functions use the correct text domain (configurable per project) - see yoastcs           |
| **NoDirectDatabaseQueries** | Warn when using `$wpdb->query()` directly instead of WP wrapper functions like `get_posts()`, `WP_Query` |
| **RequireCapabilityCheck** | Flag admin AJAX/REST handlers that don't call `current_user_can()`                                       |
| **NoDirectSuperglobalAccess** | Flag direct `$_GET`/`$_POST` access outside of defined input-handling layers                             |
| **RequireEarlyReturn** ✅ ⚠️ PHPStan| Flag deeply nested conditionals where early returns would improve readability. *Also solvable via [`sanmai/phpstan-rules`](https://github.com/sanmai/phpstan-rules) (guard clauses + nested if detection) or [`tomasvotruba/cognitive-complexity`](https://github.com/TomasVotruba/cognitive-complexity).* |
| **NoDirectFileOperations** | Flag `file_get_contents()`, `fopen()` etc. — prefer `WP_Filesystem`                                      |
| **RequireRestPermissionCallback** ✅| Flag `register_rest_route()` calls without a `permission_callback`                                       |
| **NoQueryPostsUsage** | Flag `query_posts()` usage — should always use `WP_Query` or `get_posts()`                               |
| **RequireNonceInForms** | Flag form output (`<form`) without a corresponding `wp_nonce_field()`                                    |

## Priority Recommendations

Tiered by impact for agency WordPress development. Implemented sniffs (✅) are omitted.

### Tier 1 — Security & Critical Bugs

| # | Sniff | Rationale |
|---|-------|-----------|
| 1 | **RequireRestPermissionCallback** | Open REST endpoints are a direct security hole — easy to miss, high exploit risk |
| 2 | **RequireCapabilityCheck** | Missing `current_user_can()` in AJAX/REST handlers = privilege escalation |
| 3 | **RequireNonceWithFilterInput** | `filter_input()` on POST/GET without nonce verification bypasses CSRF protection |
| 4 | **NoFilterSanitizeString** | Deprecated since PHP 8.1, never actually sanitized — false sense of security |
| 5 | **RequireNonceInForms** | Forms without `wp_nonce_field()` are vulnerable to CSRF attacks |

### Tier 2 — Common Bugs & Performance

| # | Sniff | Rationale |
|---|-------|-----------|
| 6 | **RequireOptionAutoload** | Missing `$autoload` param silently loads every option on every pageload |
| 7 | **NoQueryPostsUsage** | `query_posts()` corrupts the main query — always use `WP_Query` or `get_posts()` |
| 8 | **NoUnsettingGlobals** | Unsetting `$post`, `$wp_query` etc. causes hard-to-trace breakage |
| 9 | **DisallowRelativeInclude** | Relative paths break when files move or plugins load from unexpected contexts |
| 10 | **UnsanitizedArrayKeys** | Overlooked attack vector — array keys from superglobals are user input too |

### Tier 3 — Modernization & Best Practices

| # | Sniff | Rationale |
|---|-------|-----------|
| 11 | **PreferStrContains / PreferStrStartsWith** | Direct replacements for `strpos()` idioms — clearer intent, PHP 8.0+ |
| 12 | **FlagInlineScriptTags** | Manual `<script>` tags bypass `wp_add_inline_script()` and CSP headers |
| 13 | **NoDirectDatabaseQueries** | Direct `$wpdb->query()` skips caching and abstraction — prefer WP API |
| 14 | **NoDirectSuperglobalAccess** | Raw `$_GET`/`$_POST` access outside input-handling layers makes sanitization inconsistent |
| 15 | **NoDirectFileOperations** | `file_get_contents()`, `fopen()` etc. bypass `WP_Filesystem` and break on restricted hosts |
| 16 | **WarnAliasedFunctions** | `join()` → `implode()`, `chop()` → `rtrim()` — use canonical names for consistency |
| 17 | **RequireContextForX** | `_x()` / `_ex()` without a context string defeats the purpose of contextual translation |

### Tier 4 — Code Quality & Documentation

| # | Sniff | Rationale |
|---|-------|-----------|
| 18 | **DeprecatedHooksWarning** | Using removed actions/filters causes silent failures after WP updates |
| 19 | **UnusedHookParameters** | Accepting 3 params but using 1 is misleading and may mask bugs |
| 20 | **EnqueueNullVersion** | Passing `null` as version uses WP core version — avoids stale caches and arbitrary strings |
| 21 | **HookCallbackTypeHintConflict** | Type hints on filter callbacks conflict with WP's untyped filter system |
| 22 | **RequireSinceTag** | `@since` tags on public API enable proper changelog tracking |
| 23 | **RequireThrowsTag** | Missing `@throws` docs hide exception paths from callers |
| 24 | **ForbidNewMagicMethods** | Non-standard magic method abuse (`__wakeup`, `__serialize`) signals design issues |

### Tier 5 — Style & Convention

| # | Sniff | Rationale |
|---|-------|-----------|
| 25 | **NamespaceNamingConventions** | Consistent namespace naming across projects |
| 26 | **NamespaceBlankLines** | Blank lines around namespace declarations for readability |
| 27 | **ImportAliasNaming** | Enforce PascalCase (or chosen convention) on use-import aliases |
| 28 | **PHPUnitNamingConventions** | Test class/file naming consistency |
