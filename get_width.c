#include "main.h"

/**
 * get_width - it Calculates the width of printing
 * @format: a Formatted string to print all the arguments
 * @i: List of arguments will be printed
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int crr_i;
	int width = 0;

	for (crr_i = *i + 1; format[crr_i] != '\0'; crr_i++)
	{
		if (is_digit(format[crr_i]))
		{
			width *= 10;
			width += format[crr_i] - '0';
		}
		else if (format[crr_i] == '*')
		{
			crr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crr_i - 1;

	return (width);
}
