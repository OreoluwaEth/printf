#include "main.h"
/**
 * _putchar - Entry function. Write characteres
 * @c: variable va_list
 *
 * Return: Writed character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printc - Entry function. Print character
 * @list: variable va_list
 *
 * Return: 1 (nbyte)
 */
int printc(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);

}
/**
 * print_string - Entry point. Print string
 * @s: variable va_list
 *
 * Return: k (nbytes) 6 (NULL)
 */
int print_string(va_list s)
{
	char *str;
	int k;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (k = 0; str[k] != '\0'; k++)
		{
			_putchar(str[k]);
		}
	}
	return (k);
}
/**
 * print_n - Entry point. Print number
 * @n: Variable va_list
 *
 * Return: count (nbytes)
 */
int print_n(va_list n)
{

	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(n, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}

/**
 * _print_bin - is a function that converts unsigned integer into binary
 * @args: accepts incoming unsigned int arguements
 * Return: the number of character printed
 */

int _print_bin(va_list args)
{
	int n = va_arg(args, int);
	unsigned int length = 0, power = 1, k, digit, count = 0, number;

	if (n != 0)
	{
		number = n;
		while (number != 0)
		{
			number /= 2;
			length++;
		}
		for (k = 1; k <= length - 1; k++)
			power *= 2;
		for (k = 1; k <= length; k++)
		{
			digit = n / power;
			_putchar(digit + '0');
			count++;
			n -= digit * power;
			power /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 *_printstring - function that print a string
 *@s: pointer to value of each simbol of string
 *Return: counter.
 */
int _printstring(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		i++;
	}
	return (i);
}
