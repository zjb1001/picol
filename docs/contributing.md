---
layout: default
title: Contributing
---

# Contributing to Picol

Thank you for your interest in contributing to the Picol project! This document provides guidelines and information to help you get started.

## Code of Conduct

Please be respectful and considerate of others when contributing to this project. We aim to maintain a friendly and inclusive environment for everyone.

## Getting Started

1. **Fork the repository**: Create your own fork of the project on GitHub
2. **Clone your fork**: `git clone https://github.com/yourusername/picol.git`
3. **Set up the development environment**: Make sure you have the necessary tools installed (C compiler, etc.)
4. **Run the tests**: Ensure that everything is working correctly before making changes

## Development Workflow

1. **Create a new branch**: `git checkout -b my-feature`
2. **Make your changes**: Implement your feature or bug fix
3. **Write tests**: Add tests to cover your changes
4. **Run the tests**: Make sure all tests pass
5. **Update documentation**: Update any relevant documentation
6. **Commit your changes**: Use clear, descriptive commit messages
7. **Push to your fork**: `git push origin my-feature`
8. **Create a pull request**: Open a pull request against the main repository

## Coding Standards

### C Code

- Use 4 spaces for indentation (no tabs)
- Follow the existing code style
- Keep functions small and focused
- Add comments to explain complex sections of code
- Limit line length to 80 characters when possible

Example:

```c
int picolCommandPuts(struct picolInterp *i, int argc, char **argv, void *privdata) {
    if (argc != 2) {
        picolSetResult(i, "Wrong number of arguments for puts");
        return PICOL_ERR;
    }
    printf("%s\n", argv[1]);
    picolSetResult(i, "");
    return PICOL_OK;
}
```

### Tcl Code

- Use 4 spaces for indentation
- Use braces for command blocks
- Add comments to explain complex sections of code

Example:

```tcl
proc factorial {n} {
    # Base case
    if {$n <= 1} {
        return 1
    }
    
    # Recursive case
    return [expr {$n * [factorial [expr {$n - 1}]]}]
}
```

## Pull Request Guidelines

1. **Keep PRs focused**: Each PR should address a single concern
2. **Include tests**: All new features or bug fixes should include tests
3. **Update documentation**: Update any relevant documentation
4. **Describe your changes**: Provide a clear description of what your PR does

## Reporting Bugs

When reporting bugs, please include:

1. Steps to reproduce the issue
2. Expected behavior
3. Actual behavior
4. Your operating system and compiler version
5. Any error messages or stack traces

## Feature Requests

Feature requests are welcome! Please provide:

1. A clear description of the feature
2. Why you think it would be valuable
3. Any implementation ideas you have

## Documentation

Improvements to documentation are always welcome. This includes:

1. Fixing typos or clarifying existing documentation
2. Adding examples or tutorials
3. Adding documentation for undocumented features

## License

By contributing to Picol, you agree that your contributions will be licensed under the project's license.

## Questions?

If you have any questions or need help, feel free to open an issue or contact the maintainers directly.

Thank you for contributing to Picol!
