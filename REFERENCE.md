# Minilibft - Syntax Reference

## Introduction
If something doesn't quite make sense to you, then hover over the text and the tip might help.

## Contents
**[Functions](#functions "Navigate to Functions")**
- **[`ft_strlen`](#ft_strlen "Goto ft_strlen")**

### Functions
#### `int ft_isalnum(int c)`
`Returns:` [*`boolean truth for if the character when printed gives any alphanumeric value`*](# "if the character is either an ascii letter or number")

#### `int ft_isalpha(int c)`
`Returns:` [*`boolean truth for if the character when printed gives any alphabetical value`*](# "if the character is an ascii letter")

#### `int ft_isdigit(int c)`
`Returns:` [*`boolean truth for if the character when printed gives any numeric value`*](# "if the character is a digit")

#### `int ft_isprint(int c)`
`Returns:` [*`boolean truth for if the character when printed lonesomely affects the screen in any way`*](# "if the character prints to the screen when passed")

#### `int ft_isspace(int c)`
`Returns:` [*`boolean truth for if the character when printed gives any whitespace `*](# "")

#### `int ft_ascii(int c)`
`Returns:` [*`boolean truth for if the character is within the ascii boundary`*](# "if the value passed in is less than 127")

#### `size_t ft_strlen(char *str)`
`Returns:` [*`Amount of characters found before a null at the pointer.`*](# "Size of null terminated string")

#### `int ft_atoi(const char *str)`
`Returns:` [*`The integer value of the numbers in place value in the null terminated string `*](# "Evaluates number in string")

#### `void *ft_memchr(const void *s, int c, size_t n)`
`Returns:` [*`The pointer of the first occurence of the character c in range of n`*](# "Buffer starting at where c occurs first")

#### `int ft_memcmp(const void *b1, const void *b2, size_t n)`
`Returns:` [*`The difference of both buffers at the position of first difference in range of n`*](# "Character difference of both buffers if any")

#### `void *ft_memcpy(void *dst, const void *src, size_t n)`
`Returns:` [*`The pointer of "dst" after replacing the values from "src" up to 'n' positions`*](# "Copies n bytes from src to dst")

#### `void *ft_memset(void *dst, int c, size_t n)`
`Returns:` [*`The pointer of "dst" after 'n' bytes have been replaced by the value 'c'`*](# "Replaces n bytes with c")

#### `void	ft_bzero(void *dst, unsigned long n)`
`Returns:` [*`The pointer of "dst" after 'n' bytes have been replaced with NULL`*](# "Sets buffer to value 0 for n bytes")

#### `void *ft_calloc(size_t count, size_t size)`
`Returns:` [*`A Pointer that has been allocated memory of width "count" with each feild having length of "size" with all memory positions evaluating to 0`*](# "Allocates and Clears memory of size [count * size]")

#### `char *ft_strchr(const char *s, int c)`
`Returns:` [*`The String of the first occurence of the character c`*](# "String starting at where c occurs first")

#### `char *ft_strdup(const char *s1)`
`Returns:` [*`A String Duplicate of the string passed in`*](# "Allocates and Copies s1 and returns the new string")

#### `size_t ft_strlcat(char *dst, const char *src, size_t size)`
`Returns:` [*`The String at "dst" after "src" has been concatenated up to "size"`*](# "Puts src at the end of dst and truncates up to size")

#### `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`
`Returns:` [*`The String at "dst" after the characters up to "dstsize" have been replaced with the characters in "src"`*](# "Replaces dstsize amount of characters in dst with src ")

#### `int ft_strncmp(const char *s1, const char *s2, size_t n)`
`Returns:` [*`The difference of both character pointers at the position of the first difference in range n`*](# "")

#### `char *ft_strnstr(const char *haystack, const char *needle, size_t len)`

char	*ft_strrchr(const char *s, int c)

int	ft_tolower(int c)

int	ft_toupper(int c)

char	*ft_substr(char const *s, unsigned int start, size_t len)

char	*ft_strjoin(char const *s1, char const *s2)

char	*ft_strtrim(char const *s1, char const *set)

char	**ft_split(char const *s, char c)

char	*ft_itoa(int n)

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

void	ft_striteri(char *s, void (*f)(unsigned int, char*))

void	ft_putchar_fd(char c, int fd)

void	ft_putstr_fd(char *s, int fd)

void	ft_putendl_fd(char *s, int fd)

void	ft_putnbr_fd(int n, int fd)

int	ft_printf(const char *string, ...)
## Index

