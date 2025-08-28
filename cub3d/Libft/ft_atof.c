/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:04:40 by gansari           #+#    #+#             */
/*   Updated: 2025/03/04 15:04:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_and_parse_sign(t_atof_data *data, const char **str)
{
	data->result = 0.0;
	data->fraction = 0.0;
	data->sign = 1.0;
	data->power = 1.0;
	data->decimal_found = 0;
	data->exponent = 0.0;
	data->exponent_sign = 1.0;
	data->exponent_factor = 1.0;
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			data->sign = -1.0;
		(*str)++;
	}
}

static void	ft_parse_integer_and_fraction(t_atof_data *data, const char **str)
{
	while (**str >= '0' && **str <= '9')
	{
		data->result = data->result * 10.0 + (**str - '0');
		(*str)++;
	}
	if (**str == '.')
	{
		data->decimal_found = 1;
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			data->fraction = data->fraction * 10.0 + (**str - '0');
			data->power *= 10.0;
			(*str)++;
		}
	}
}

static void	ft_parse_exponent(t_atof_data *data, const char **str)
{
	if (**str == 'e' || **str == 'E')
	{
		(*str)++;
		if (**str == '-' || **str == '+')
		{
			if (**str == '-')
				data->exponent_sign = -1.0;
			(*str)++;
		}
		while (**str >= '0' && **str <= '9')
		{
			data->exponent = data->exponent * 10.0 + (**str - '0');
			(*str)++;
		}
	}
}

static double	ft_finalize_result(t_atof_data *data)
{
	int		i;
	double	result;

	result = data->result;
	if (data->decimal_found)
		result += data->fraction / data->power;
	if (data->exponent > 0)
	{
		data->exponent_factor = 1.0;
		i = 0;
		while (i++ < (int)data->exponent)
			data->exponent_factor *= 10.0;
		if (data->exponent_sign > 0)
			result *= data->exponent_factor;
		else
			result /= data->exponent_factor;
	}
	return (result * data->sign);
}

double	ft_atof(const char *str)
{
	t_atof_data	data;

	ft_init_and_parse_sign(&data, &str);
	ft_parse_integer_and_fraction(&data, &str);
	ft_parse_exponent(&data, &str);
	return (ft_finalize_result(&data));
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     const char *test_cases[] = {
//         "123.456",
//         "-42.75",
//         "   +3.14159",
//         "0.0",
//         "42",
//         "-0",
//         "1.23e4",
//         "9.876e-2",
//         "  -5.678E+3  ",
//         "invalid123.45",
//         ".5",
//         "1.",
//         "-.123"
//     };

//     int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

//     printf("Testing ft_atof function against standard atof:\n");
//     printf("--------------------------------------------\n");

//     for (int i = 0; i < num_tests; i++)
//     {
//         double ft_result = ft_atof(test_cases[i]);
//         double std_result = atof(test_cases[i]);

//         printf("String: \"%s\"\n", test_cases[i]);
//         printf("ft_atof: %f\n", ft_result);
//         printf("atof:    %f\n", std_result);
//         printf("Difference: %f\n", ft_result - std_result);
//         printf("--------------------------------------------\n");
//     }

//     return 0;
// }
