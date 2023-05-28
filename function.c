#include "main.h"

/**
 * print_char - a function that prints char.
 * @types: list
 * @buffer: array
 * @flags: calculate
 * @size: size
 * @width: width
 * @precision: precision
 * Return: number of characters
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - a function that prints a string
 * @types: list
 * @buffer: array
 * @flags: calculate
 * @size: size
 * @width: width
 * @precision: precision
 * Return: number of characters
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "		";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
