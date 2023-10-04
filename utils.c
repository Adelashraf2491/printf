#include "main.h"

/**
 * is_printable - it Evaluates if a char is being able to print or not
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - it Append ASCII in hexadecimal code for buffering
 * @buffer: is an Array of chars.
 * @i: Index in which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - IT Verifies if a char is a digit or not
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - it Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: the Casted value of num
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LNG)
		return (num);
	else if (size == S_SHRT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - it Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: the Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LNG)
		return (num);
	else if (size == S_SHRT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
