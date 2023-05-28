#include "main.h"

/**
 * print_pointer - a function that prints the value of a pointer
 * @types: list
 * @buffer: array
 * @width: width
 * @flags: calculate
 * @precision: precision
 * @size: size
 * Return: number of characters printed
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_adrrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[nim_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - a function that prints ascii code
 * @types: list
 * @buffer: array
 * @width: width
 * @precision: precision
 * @flags: calculate
 * @size: size
 * Return: number of characters
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			buffer[j + offset] = str[j];
		else
			offset += append_hexa_code(str[j], buffer, j + offset);
		j++;
	}
	buffer[j + offset] = '\0';
	return (write(1, buffer, j + offset));
}

/**
 * print_reverse - a function that prints strin in reverse
 * @types: list
 * @buffer: array
 * @size: size
 * @flags: calculate
 * @width: width
 * @precision: precision
 * Return: numbers of characters
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(NULL)";
	}
	for (j = 0; str[j]; j++)
		;
	for (j = j - 1; j >= 0; j--)
	{
		char z = str[j];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - a function that prints string in rot13
 * @types: type
 * @buffer: array
 * @flags: calculate
 * @width: width
 * @precision: precision
 * @size: size
 * Return: numbers of character printed
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int r, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (r = 0; str[r]; r++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[r])
			{
				y = out[m];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			y = str[r];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
