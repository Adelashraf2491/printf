#include "main.h"

/**
 * handle_print - it Prints an argument according to its type
 * @frmt: Formatted string in which to print the arguments.
 * @list: List of arguments will be printed.
 * @ind: is an index.
 * @buffer: is a Buffer array to handle print.
 * @flags: it Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *frmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknw_len = 0, printed_chars = -1;
	frmt_t frmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; frmt_types[i].frmt != '\0'; i++)
		if (frmt[*ind] == frmt_types[i].frmt)
			return (frmt_types[i].fun(list, buffer, flags, width, precision, size));

	if (frmt_types[i].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknw_len += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknw_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknw_len += write(1, &frmt[*ind], 1);
		return (unknw_len);
	}
	return (printed_chars);
}
