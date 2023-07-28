#include "main.h"
#include <stdio.h>

/**
 * print_character - takes the format
 * to print character
 * @list: character to print
 */

void print_character(va_list *list)
{
	_putchar(va_arg(*list, int));
}
/**
 * print_string - takes the format to
 * print a string
 * @list: string to print
 */
void print_string(va_list *list)
{
	char *s = va_arg(*list, char *);

	s = s == NULL ? "(null)" : s;
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * print_percent - takes the format to
 * print percent
 * @list: character to print
 */

void print_percent(va_list *list __attribute__ ((unused)))
{
	_putchar(37);
	_putchar(37);
}

/**
 * _printf - prints a format
 * @format: the format to print
 * Return: returns integer
 */
int _printf(const char *format, ...)
{
	int i = 0, j;
	va_list list;

	opr to_p[] = {
		{'c', print_character},
		{'%', print_percent},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			for (j = 0; j < 3; j++)
			{
				if (format[i + 1] == to_p[j].type)
				{
					to_p[j].print(&list);
					i++;
					break;
				}
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (0);
}
