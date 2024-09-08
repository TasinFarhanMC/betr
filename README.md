
# Betr

**Betr** \(/ˈbɛtər/\) is a helper project designed to standardize naming conventions in existing C++ projects. Its main purpose is to bring consistency to codebases by applying naming conventions inspired by Rust's guidelines.

## General Naming Conventions

For a detailed version, refer to [CONVENTIONS.md](CONVENTIONS.md).

In general, Rust uses `UpperCamelCase` for type-level constructs (types and traits) and `snake_case` for value-level constructs. The proposed conventions are:

| Item               | Convention           |
| ------------------ | --------------------- |
| Types              | `UpperCamelCase`      |
| Enum variants      | `UpperCamelCase`      |
| Functions          | `snake_case`          |
| Methods            | `snake_case`          |
| Local variables    | `snake_case`          |
| Static variables   | `SCREAMING_SNAKE_CASE`|
| Constant variables | `SCREAMING_SNAKE_CASE`|

## License

This project is licensed under the [MIT License](https://choosealicense.com/licenses/mit/).

## Acknowledgements

- [RFC \#0430](https://github.com/rust-lang/rfcs/blob/master/text/0430-finalizing-naming-conventions.md)

