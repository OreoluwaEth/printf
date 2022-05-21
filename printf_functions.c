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
 * print_unsig - print unsigned numbers
 * @n: number to print
 * Return: @count, number or chars printed.
 */
int print_unsig(unsigned int n)
{
	int count = 0;
	unsigned int num_copy = n;

	if (n == 0)
		count = 1;
	while (num_copy != 0)
	{
		num_copy = num_copy / 10;
		count++;
	}
	if (n >= 10)
		print_unsig(n / 10);
	_putchar (n % 10 + '0');
	return (count);
}

/**
 * print_hexaup - Print number in hexadecimal with upper numbers
 *@n: unsigned int
 * Return: numer times print
 */
int print_hexaup(unsigned int n)
{
	int i, j, remainder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		remainder = 0;
		remainder = n % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = remainder + '0';
		}
		else
		{
			hexadecimal[i] = remainder + '7';
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexadecimal[j]);

	free(hexadecimal);
	return (count);
}

/**
 * print_hexalow - convert unsigned int in hexadecimal
 *@n: unsigned int
 * Return: numer times print
 */
int print_hexalow(unsigned int n)
{
	int i, j, remainder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		remainder = 0;
		remainder = n % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = remainder + '0';
		}
		else
		{
			hexadecimal[i] = remainder + 'W';
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexadecimal[j]);
	free(hexadecimal);
	return (count);
}
