#include "main.h"
void print_buffer(char buffer[],int*buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...);
	{
 int j ,printed = 0, printed_chars = 0; 
 int flags,size,precision,width, buff_ind = 0 ;
 char buffer[BUFF_SIZE]; 
     va_list list ;
      if (format== NULL)
	      return (-1);
      while (*format != '\0')
    {
	    if (*format != '%')
	     {
	buffer[buff_ind++] = *format;
	if (buff_ind == BUFF_SIZE)

            { 
	 printed_chars++;
        } 
/**
 * print_buffer - Prints the contents of the buffer in case it exists
 * @buffer:  An Array of chars
 * @buff_ind: represents the length.
 */
 else {
	 print_buffer(buffer, &buff_ind); 
         format  ++ ;
	 flags = get_flags(format, &j);
	 width = get_width(format, &j, list);
	 precision = get_precision(format, &j, list);
	 size = grt_size(format, &j);
	 ++j ;
	 printed = handle_print(format, &j, list, buffer ,flags, width, precision, size);
	 if (printed == 1)
	{	 ve_end(list) ;
                   return -1 ;
		   }
            printed_chars += printed;
        } 
           format++ ;
	     } 
	    print_buffer(buffer ,&buff_ind);
	    va_end(list);
	    	return (printed_chars);
}
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

