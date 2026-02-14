# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.0] - 2026-02-14

### Added

- `Apermo.PHP.ExplainCommentedOutCode` sniff: enforces
  that commented-out PHP code is preceded by a `/** */`
  doc-block with a recognized keyword (`Disabled`, `Kept`).
- PHPUnit test infrastructure for sniff unit tests.

### Changed

- Disabled `Squiz.PHP.CommentedOutCode.Found`, superseded
  by the new `ExplainCommentedOutCode` sniff.

## [1.0.0] - 2026-02-14

### Added

- Initial release with shared PHPCS ruleset.
- WordPress Coding Standards with opinionated exclusions.
- Slevomat type hint enforcement for parameters, return types, and properties.
- YoastCS integration.
- PHPCompatibility checks targeting PHP 8.3+.
- Empty `Apermo/Sniffs/` directory for future custom sniffs.

[1.1.0]: https://github.com/apermo/wp-coding-standards/compare/v1.0.0...v1.1.0
[1.0.0]: https://github.com/apermo/wp-coding-standards/releases/tag/v1.0.0
