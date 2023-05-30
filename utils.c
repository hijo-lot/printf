#include "main.h"

/**
 * is_printable - Checks if a char is printable
 * @c: The character to be examined.
 *
 * Return: 1 if the character is considred as  printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - Concatenate hexadecimal
 * representation of ascci code to buffer
 * @buffer: Character array of appending.
 * @j: Starting index for  appending.
 * @ascii_code: ASSCI CODE to be added
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Check if the a chararacter is a digit
 * @c: arg
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a function that casts a number
 * @num: Numbe that will be casted
 * @size: Size
 *
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Converts a number to the specified size
 * @size: size
 * @num: number
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)

{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

