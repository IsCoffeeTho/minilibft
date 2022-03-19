/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:49:37 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/18 19:33:54 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLFT_H
# define MLFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

typedef struct s_lnklst
{
	void *content;
	struct s_lnklst *next;
} t_list;

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isalnum(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_long_border(const char c, int mult, long nb)
{
	long	border;

	border = 922337203685477580;
	if ((nb > border || (nb == border && (c - '0') > 7)) && mult == 1)
		return (-1);
	else if ((nb > border || (nb == border && (c - '0') > 8)) && mult == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		brd;

	num = 0;
	sign = 1;
	brd = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		brd = ft_long_border(*str, sign, num);
		if (brd < 1)
			return (brd);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	i = 0;
	str = (unsigned char *) s;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (*str == chr)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	if (n <= 0)
		return (0);
	s1_str = (unsigned char *) s1;
	s2_str = (unsigned char *) s2;
	while (*s1_str == *s2_str && n - 1 > 0)
	{
		s1_str++;
		s2_str++;
		n--;
	}
	return (*s1_str - *s2_str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *) b)[i++] = (unsigned char) c;
	return (b);
}

void	ft_bzero(void *b, unsigned long n)
{
	ft_memset(b, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	req;

	req = count * size;
	arr = malloc(req);
	if (!(arr))
		return (NULL);
	ft_memset(arr, 0, req);
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	return ((char *) ft_memchr(s, c, ft_strlen(s) + 1));
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = (char *) malloc(len);
	if (!dup)
		return (NULL);
	return ((char *) ft_memcpy(dup, s1, len));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	slen = ft_strlen(src) + 1;

	if (slen < dstsize)
		ft_memcpy(dst, src, slen);
	else if (dstsize != 0)
	{
		dstsize--;
		ft_memcpy(dst, src, dstsize);
		dst[dstsize] = '\0';
	}
	return (slen - 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *) haystack);
	while (len >= needle_len)
	{
		len--;
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	if (c == '\0')
	{
		while (*s++) ;
		a = (char *) --s;
		return (a);
	}
	while (*s)
		if (*s++ == c)
			a = (char *) s - 1;
	return (a);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ' ');
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	i;
	size_t	j;

	n = (char *) malloc(sizeof(*s) * (len + 1));
	if (!n)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			n[j++] = s[i];
		i++;
	}
	n[j] = '\0';
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*n;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	n = (char *) malloc(s1len + s2len);
	if (!n)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		n[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		n[s1len + i] = s2[i];
		i++;
	}
	n[s1len + s2len] = '\0';
	return (n);
}

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isinset(s1[end - 1], set))
		end--;
	str = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

static int	get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static int	ft_countwords(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	str2 = (char **) malloc(sizeof(*str2) * (ft_countwords(s, c) + 1));
	if (!s || !str2)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len(&s[j], c) + 1);
		if (!str2[i])
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	length;

	is_neg = (n < 0);
	str = (char *) ft_calloc(11 + is_neg, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*n;
	int		strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	n = (char *) malloc(strlen + 1);
	if (!n)
		return (NULL);
	while (s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i++ < len)
	{
		f(i - 1, &s[i - 1]);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		n += '0';
		write(fd, &n, 1);
	}
}

static char	*numberlength(unsigned long number, int *length)
{
	char	*string;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

static void	ifhex(t_print *arg_count, char character)
{
	unsigned int	number;
	int				length;
	char			*string;

	number = va_arg(arg_count->args, unsigned int);
	length = 1;
	string = numberlength(number, &length);
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}

static void	ifpointer(t_print *arg_count)
{
	int				length;
	char			*string;
	unsigned long	number;

	number = va_arg(arg_count->args, unsigned long);
	length = 1;
	string = numberlength(number, &length);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else
			string[length] = 'a' + (number % 16) - 10;
		number = number / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}

static void	ifcharacter(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}

static void	ifstring(t_print *arg_count)
{
	char	*string;
	int		length;

	string = va_arg(arg_count->args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		length = ft_strlen(string);
		ft_putstr_fd(string, 1);
		arg_count->counter += length;
	}
}

static int	numbersize(unsigned int number)
{
	int	length;

	length = 1;
	while (number > 9)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

static char	*itoa(unsigned int number)
{
	char	*string;
	int		length;

	length = numbersize(number);
	string = (char *)malloc(length + 1 * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	while (length > 0)
	{
		string[--length] = number % 10 + '0';
		number = number / 10;
	}
	return (string);
}

static void	ifint(t_print *arg_count)
{
	char	*string;
	int		result;

	result = va_arg(arg_count->args, int);
	string = ft_itoa(result);
	ft_putstr_fd(string, 1);
	arg_count->counter += ft_strlen(string);
	free(string);
}

static void	ifunsignedint(t_print *arg_count)
{
	char			*string;
	unsigned int	result;

	result = va_arg(arg_count->args, unsigned int);
	string = itoa(result);
	ft_putstr_fd(string, 1);
	arg_count->counter += ft_strlen(string);
	free(string);
}

static t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

static void	printcheck(const char character, t_print *arg_count)
{
	if (character == 'c')
		ifcharacter(arg_count);
	else if (character == 's')
		ifstring(arg_count);
	else if (character == 'p')
		ifpointer(arg_count);
	else if (character == 'i' || character == 'd')
		ifint(arg_count);
	else if (character == 'u')
		ifunsignedint(arg_count);
	else if (character == 'x' || character == 'X')
		ifhex(arg_count, character);
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
		arg_count->counter++;
	}
}

int	ft_printf(const char *string, ...)
{
	t_print	*arg_count;
	int		printcomplete;
	int		i;

	i = 0;
	arg_count = start();
	printcomplete = 0;
	va_start(arg_count->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			printcheck(string[++i], arg_count);
		else
		{
			ft_putchar_fd(string[i], 1);
			arg_count->counter++;
		}
		if (string[i] != '\0')
			i++;
	}
	printcomplete = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (printcomplete);
}

t_list *ft_lstnew(void *content)
{
	t_list list;
	list.content = content;
	list.next = NULL;
	return (&list);
}

void ft_lstadd_front(t_list** lst, t_list *new)
{
	new->next = *lst;
	*lst = &new;
}

int ft_lstsize(t_list *lst)
{
	int i;
	t_list *curr;

	if (lst == NULL)
		return (0);
	curr = lst;
	i = 1;
	while (curr->next != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

t_list *t_lstlast(t_list *lst)
{
	t_list *curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}

#endif



type mix
type s width
