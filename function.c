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
