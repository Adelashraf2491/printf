#include "main.h"

/**
 * get_flags - it Calculates al the  active flags
 * @format: a Formatted string to print all the arguments
 * @i: take a parameter.
 * Return: The Flags:
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, crr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (crr_i = *i + 1; format[crr_i] != '\0'; crr_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[crr_i] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = crr_i - 1;

	return (flags);
}
