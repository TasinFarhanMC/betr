
# Betr

Betr is a Healper Project for Existing C++ Projects Its Main Purpose Is to Standerdize

It's based on [The Rust Naimng Convection](https://rust-lang.github.io/api-guidelines/naming.html)
## General naming conventions

In general, Rust tends to use `UpperCamelCase` for "type-level" constructs
(types and traits) and `snake_case` for "value-level" constructs. More
precisely, the proposed (and mostly followed) conventions are:

| Item | Convention |
| ---- | ---------- |
| Modules | `snake_case` |
| Types | `UpperCamelCase` |
| Concepts | `UpperCamelCase` |
| Enum variants | `UpperCamelCase` |
| Functions | `snake_case` |
| Methods | `snake_case` |
| Conversion constructors | `from_some_other_type` |
| Local variables | `snake_case` |
| Static variables | `SCREAMING_SNAKE_CASE` |
| Constant variables | `SCREAMING_SNAKE_CASE` |
| Type parameters | concise `UpperCamelCase`, usually single uppercase letter: `T` |

### Fine points

In `UpperCamelCase`, acronyms count as one word: use `Uuid` rather than
`UUID`.  In `snake_case`, acronyms are lower-cased: `is_xid_start`.

In `UpperCamelCase` names multiple numbers can be separated by a `_`
for clarity: `Windows10_1709` instead of `Windows101709`.

In `snake_case` or `SCREAMING_SNAKE_CASE`, a "word" should never
consist of a single letter unless it is the last "word". So, we have
`btree_map` rather than `b_tree_map`, but `PI_2` rather than `PI2`.

## License

[MIT License](https://choosealicense.com/licenses/mit/)

[Apache License, Version 2.0](https://opensource.org/license/apache-2-0)

## Acknowledgements

 - [RFC 430](https://github.com/rust-lang/rfcs/blob/master/text/0430-finalizing-naming-conventions.md)

