#include "main.h"

/**
 * print_unsigned - Function to print an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array for print handling
 * @flags:  Active flaags calculating
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
	int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
	}

/**
 * print_octal - Prints an unsigned number using octal notation
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags:  Active flags calculating
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of printed characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[j--] = '0';
	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Function to Print an unsigned number in hexadecimal notation
 * @types: the arguments list
 * @buffer: Buffer array for print handling
 * @flags:  Active flags calculating
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Function to Print an unsigned number in upper  hexadecimal notation
 * @types: the arguments list
 * @buffer: Buffer array for print handling
 * @flags:  Active flags calculating
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], 	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Function to Print an hexadecimal number in upper or lower
 * @types: the arguments list
 * @buffer: Buffer array for print handling
 * @flags:  Active flags calculating
 * @flags_ch: Active flags calculating
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @map_to: array
 * @flag_ch: calculates
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

