*This project has been created as part of the 42 curriculum by lschawer.*
# ft_printf


## Description
This project consists of recreating the standard C `printf()` function.<br>
The main objective was to learn how to handle a variable number of arguments using the `stdarg.h` library while reproducing the behavior of several standard format specifiers.


## Supported Conversions

| Specifier | Description |
|------------|-------------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Signed decimal integer |
| `%i` | Signed integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |


## Instructions
**Compilation**

The Makefile compiles with the flags `-Wall`, `-Wextra`, and `-Werror`, using `cc`.
The Makefile contains the following rules:

* make all = default rule to create `libftprintf.a`
* make clean = deletes the object files generated during compilation
* make fclean = deletes the object files AND the library (`libftprintf.a`)
* make re = performs `fclean` followed by an `all` to re-compile everything from scratch

**Using ft_printf**

To use ft_printf() in your project, include the header and link the library:
  ```
  cc main.c libftprintf.a
  ```

## Resources
To build this library I have used the following resources:
* subject.pdf: Detailed assignment requirements.
* man7.org: Linux manual pages for standard functions.
* 42-cursus.gitbook.io: Simplified descriptions and logic for non-standard functions.
* AI Assistance: Used for clarifying concepts.


## Algorithm Overview: Parsing Logic
The implementation consists of parsing a format string and dispatching conversion functions based on detected format specifiers using a variadic argument list.


## Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Value: %d\n", 42);
    return (0);
}
```