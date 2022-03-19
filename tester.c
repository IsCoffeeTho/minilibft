/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:20:18 by amenadue          #+#    #+#             */
/*   Updated: 2022/03/19 11:53:32 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlft.h"

typedef enum e_type
{
	INT,
	UINT,
	STR,
	PNTR,
	SIZE
} TYPE;

typedef struct s_val
{
	void *value;
	TYPE type;
} val;

val **values(val *v1, ...)
{
	val **newlst;
	val *decypheree;
	int i;
	va_list args;
	if (v1 == NULL)
		return (NULL);
	else
	{
		va_start(args, v1);
		while (1)
		{
			decypheree = va_arg(args, val*);
			if (&decypheree == NULL)
				break;
			else
			{
				newlst = &decypheree;
			}
		}
	}
}

val *value(TYPE type, void *value)
{
	val newval = {.type = type, .value = value};
	return (&newval);
}

typedef struct s_testdef {
	char* name;
	char* onfail;
	void* function;
	val *inputs;
	val extpectation;
} testdef;

void	runtest(testdef test)
{
	write(1, "Still testing\n", 14);
}

int	main(int c, char **v)
{
	testdef currtest = {
		.name = "test",
		.onfail = "you did it wrong",
		.function = *ft_atoi,
		.inputs = values(value(STR, "   -0012333test   "), NULL),
		.extpectation = value(INT, -12333)
	};
	runtest(currtest);
}