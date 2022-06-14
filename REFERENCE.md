# Minilibft - Syntax Reference
### Categories
[Character Manipulation](#character-manipulation "Navigate to Character based functions")  
[Memory Manipulation](#memory-manipulation "Navigate to Memory based functions")  
[String Manipulation](#string-manipulation "Navigate to String based functions")  
[Putting to FileDescriptors](#putting-to-filedescriptors "Navigate to typed printing functions")
[Linked Lists](#linked-lists "Navigate to Linked list Manipulative functions")
[Special Functions](#special-functions "Navigate to Special Functions")
___
### Character Manipulation
```c
int ft_isalnum(int c)
```
`Returns:` Boolean truth for if the character when printed gives any alphanumeric value.
&nbsp;
```c
int ft_isalpha(int c)
```
`Returns:` Boolean truth for if the character when printed gives any alphabetical value.
&nbsp;
```c
int ft_isdigit(int c)
```
`Returns:` Boolean truth for if the character when printed gives any numeric value.
&nbsp;
```c
int ft_isprint(int c)
```
`Returns:` Boolean truth for if the character when printed lonesomely affects the screen in any way.
&nbsp;
```c
int ft_isspace(int c)
```
`Returns:` Boolean truth for if the character when printed gives any whitespace.
&nbsp;
```c
int ft_ascii(int c)
```
`Returns:` Boolean truth for if the character is within the ascii boundary.
&nbsp;
```c
int ft_tolower(int c)
```
`Returns:` The String with all alphabetical characters replaced with their lowercase counterpart.
&nbsp;
```c
int ft_toupper(int c)
```
`Returns:` The String with all alphabetical characters replaced with their uppercase counterpart.
&nbsp;
```c
size_t ft_strlen(char *str)
```
`Returns:` Amount of characters found before a null at the pointer.
&nbsp;
```c
int ft_atoi(const char *str)
```
`Returns:` The integer value of the numbers in place value in the null terminated string.
___
### Memory Manipulation
```c
void *ft_memchr(const void *s, int c, size_t n)
```
`Returns:` The pointer of the first occurence of the byte `c` in range of `n`.
&nbsp;
```c
int ft_memcmp(const void *b1, const void *b2, size_t n)
```
`Returns:` The difference of both buffers at the position of first difference in range of `n`.
&nbsp;
```c
void *ft_memcpy(void *dst, const void *src, size_t n)
```
`Returns:` The pointer of `dst` after replacing the values from `src` up to `n` positions.
&nbsp;
```c
void *ft_memset(void *dst, int c, size_t n)
```
`Returns:` The pointer of `dst` after `n` bytes have been replaced by the value `c`.
&nbsp;
```c
void	ft_bzero(void *dst, unsigned long n)
```
`Returns:` The pointer of `dst` after `n` bytes have been replaced with 0.
&nbsp;
```c
void *ft_calloc(size_t count, size_t size)
```
`Returns:` A Pointer that has been allocated memory of width `count` with each feild having length of `size` with all memory positions evaluating to 0.
___
### String Manipulation
```c
char *ft_strchr(const char *s, int c)
```
`Returns:` The String of the first occurence of the character `c`.
&nbsp;
```c
char *ft_strrchr(const char *s, int c)
```
`Returns:` The String of the last occurance of the character `c`.
&nbsp;
```c
char *ft_strdup(const char *s1)
```
`Returns:` A String Duplicate of the string passed in.
&nbsp;
```c
size_t ft_strlcat(char *dst, const char *src, size_t size)
```
`Returns:` The String at `dst` after `src` has been concatenated up to `size`.
&nbsp;
```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
```
`Returns:` The String at `dst` after the characters up to `dstsize` have been replaced with the characters in `src`.
&nbsp;
```c
int ft_strncmp(const char *s1, const char *s2, size_t n)
```
`Returns:` The difference of both character pointers at the position of the first difference in range `n`.
&nbsp;
```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
```
`Returns:` A String of the occurance `needle` in `haystack` in range of `n`.
&nbsp;
```c
char *ft_substr(char const *s, unsigned int start, size_t len)
```
`Returns:` A String that is a substr of `*s` starting at position `start` and has the length of `len`.
&nbsp;
```c
char *ft_strjoin(char const *s1, char const *s2)
```
`Returns:` A String that contains `s1` and `s2` combined.
&nbsp;
```c
char *ft_strtrim(char const *s1, char const *set)
```
`Returns:` A String that has all the characters in `*set` removed.
&nbsp;
```c
char **ft_split(char const *s, char c)
```
`Returns:` An Array of String of the sections in `*s` seperated by `c`.
&nbsp;
```c
char *ft_itoa(int n)
```
`Returns:` A String of ascii characters to represent the number passed in.
&nbsp;
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
```
`Returns:` The String after each characer is ran through the function that prototypes as such `char f(int index, char c);`.
&nbsp;
```c
void ft_striteri(char *s, void (*f)(unsigned int, char*))
```
`Returns:` Replaces each character in String with characters after each character is ran through the function that prototypes as such `char f(int index, char c);`.
___
### Putting to FileDescriptors
```c
void ft_putchar_fd(char c, int fd)
```
`Returns:` Puts a character to the file descriptor.
&nbsp;
```c
void ft_putstr_fd(char *s, int fd)
```
`Returns:` Puts a string to the file descriptor.
&nbsp;
```c
void ft_putendl_fd(char *s, int fd)
```
`Returns:` Puts a newline character to file descriptor.
&nbsp;
```c
void ft_putnbr_fd(int n, int fd)
```
`Returns:` Puts an integer to file descriptor.
___
### Linked Lists
```c
t_list *ft_lstnew(void *content)
```
`Returns:` A new list item containing content.
&nbsp;
```c
void ft_lstadd_front(t_list** lst, t_list *item)
```
`Returns:` Adds a list item to the top/front of a list pointer.
&nbsp;
```c
int ft_lstsize(t_list *lst)
```
`Returns:` The size of a list from top/front to bottom/back.
&nbsp;
```c
t_list *ft_lstlast(t_list *lst)
```
`Returns:` The last item in a list.
&nbsp;
```c
void ft_lstadd_back(t_list **lst, t_list *item)
```
`Returns:` Adds a list item to the bottom/back of a list pointer.
&nbsp;
```c
void ft_lstdelone(t_list *lst, void (*del)(void*))
```
`Returns:` Runs `void del(void*)` on content and frees the list item.
&nbsp;
```c
void ft_lstclear(t_list **lst, void (*del)(void*))
```
`Returns:` Runs `ft_lstdelone()` on each item in a list pointer.
&nbsp;
```c
void ft_lstiter(t_list *lst, void *(*f)(void *))
```
`Returns:` Replaces each items content with the result of running the content through the function pointer.
&nbsp;
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```
`Returns:` A new whole new list of the previous after running each items content through the function pointer.
___
### Special Functions
```c
int ft_printf(const char *string, ...)
```
`Returns:` The number of characters printed after running.