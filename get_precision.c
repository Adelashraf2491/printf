#include "main.h"

/**
 * get_precision - it Calculates the precision for printing
 * @format: a Formatted string to print all the arguments
 * @i: List of arguments will be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int crr_i = *i + 1;
	int precision = -1;

	if (format[crr_i] != '.')
		return (precision);

	precision = 0;

	for (crr_i += 1; format[crr_i] != '\0'; crr_i++)
	{
		if (is_digit(format[crr_i]))
		{
			precision *= 10;
			precision += format[crr_i] - '0';
		}
		else if (format[crr_i] == '*')
		{
			crr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crr_i - 1;

	return (precision);
}
