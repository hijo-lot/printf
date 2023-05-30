#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Outputted  chars.
 */
int _printf(const char *format, ...)

{
	int j, printed = 0, printed_chars = 0;
	int flags, size, precision, width, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
	{
		buffer[buff_ind++] = format[j];
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
	printed_chars++;
	}
	else
	{
	print_buffer(buffer, &buff_ind);
	flags = get_flags(format, &j);
	width = get_width(format, &j, list);
	precision = get_precision(format, &j, list);
	size = get_size(format, &j);
	++j;
	printed = handle_print(format, &j, list, buffer,
			flags, width, precision, size);
	if (printed == -1)
		return (-1);
	printed_chars += printed;
	}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
* print_buffer - a function that prints the content of the buffer
* @buffer:  An Array of characters
* @buff_ind: represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
