#include "main.h"
/**
 * handle_write_char - Output a string
 * @c: char types.
 * @buffer: Buffer array for handling the output
 * @flags:  Calculation of  active flags.
 * @width: get width.
 * @precision: Specification of precision
 * @size: Size specifier
 *
 * Return: Number of chars that have outputted
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNSUED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[j++] = c;
	buffer[j] = '\0';
	
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = padd;
		
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j  - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Handle the printing of a number
 * @is_negative: Flag indicating if the number is negative
 * @ind: char types.
 *
 * Return: Number of chars that have been  outputted.
 */
int write_flags(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int lentgh = BuFF_SIZE - ind - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	
	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}
/**
 * write_num - Handle the  writing of a  number to a bufffer
 * @ind: Starting index of the number in the buffer
 * @buffer: Buffer for writing
 * @length: Lentgh of the number
 * @padd: Pading character
 * @extra_c: Extra character to include
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int j, padd_start = 1;
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		 buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_Minus) && padd == '0')

		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], j - padd_start)
					write(1, &buffer[ind], lentgh - (1 - padd_start)
		}
	}
	if (extra_c)
		 buffer[--ind] = extra_c;
	return (write(1, &buffer[ind, lentgh));
}

/**
 * write_unsgnd - Handle the writing of  an unsigned number
 * @is_negative: Shows if the num is negative or not
 * @ind: Starting index of the number in the buffer
 * @buffer: Array of chars
 *
 * Return: Number of the chars outputted.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int lentgh = BUFF_SIZE - ind - 1, j=0;
	char padd = ' ';

	UNUSED(is_negative);















