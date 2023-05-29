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
	UNUSED(size);

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
	int lentgh = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && ! (flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		lentgh, padd, extra_ch));
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
	int lentgh, char padd, char extra_c)
{
	int j, padd_start = 1;
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		 buffer[ind] = padd = ' ';
	if (prec > 0 && prec < lentgh)
		padd = ' ';
	while (prec > lentgh)
		buffer[--ind] = '0', lentgh++;
	if (extra_c != 0)
		lentgh++;
	if (width > lentgh)
	{
		for (j = 1; j < width - lentgh + 1; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], lentgh) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[ind], lentgh));
		}
		else if (!(flags & F_MINUS) && padd == '0')

		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], j - padd_start))
					write(1, &buffer[ind], lentgh - (1 - padd_start));
		}
	}
	if (extra_c)
		 buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], lentgh));
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
	int lentgh = BUFF_SIZE - ind - 1, j = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0') 
		return (0);
	if (precision > lentgh && precision < lentgh)
		padd = ' ';

	while (precision > lentgh)
	{
		buffer[--ind] = '0';
		lentgh++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > lentgh)
	{
		for (j = 0; j < width - lentgh; j++)
			  buffer[j] = padd;
		buffer[j] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], lentgh) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[ind], lentgh));
		}
	}

	return (write(1, &buffer[ind], lentgh));
}
/**
 * write_pointer - Output  a memory address to the buffer
 * @buffer: Buffer for writing
 * @ind:  Starting index of the adress in the buffer
 * @length: Length of adress
 * @width: Width specifier for formatting
 * @flags: Flags specifier for formatting
 * @padd: The padding
 * @extra_c:  Extra character
 * @padd_start: Index at which padding should start
 *
 * Return: Number of chars printed.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int j;
	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			 buffer[--ind] = 'x';
			 buffer[--ind] = '0';
			 if (extra_c)
				 buffer[--ind] = extra_c;
			 return ((write(1, &buffer[ind], length) + write(1, &buffer[3], j - 3)));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			 buffer[--ind] = 'x';
                         buffer[--ind] = '0';
			 if (extra_c)
                               buffer[--ind] = extra_c;
			 return ((write(1, &buffer[3], j - 3) + write(1, &buffer[ind], length)));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = 'x';
                        	buffer[2] = '0';
			return (write(1, &buffer[padd_start], j - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
		}
			 buffer[--ind] = 'x';
                	 buffer[--ind] = '0';
                 	if (extra_c)
                       		buffer[--ind] = extra_c;
		 return ((write(1, &buffer[ind], BUFF_SIZE - ind - 1)));
}


































