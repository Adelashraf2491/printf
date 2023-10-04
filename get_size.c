#include "main.h"

/**
 * get_size - it Calculates the size to cast the argument
 * @format: a Formatted string to print all the arguments
 * @i: List of arguments will be printed
 *
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int crr_i = *i + 1;
	int size = 0;

	if (format[crr_i] == 'l')
		size = S_LNG;
	else if (format[crr_i] == 'h')
		size = S_SHRT;

	if (size == 0)
		*i = crr_i - 1;
	else
		*i = crr_i;

	return (size);
}
