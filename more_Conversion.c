#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
* print_o - prints the octal conversion of a decimal number
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_o(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int numChars, i;
	unsigned int n;
	char *octal;

	n = va_arg(args, unsigned int);
	octal = octConverter(n);
	if (octal == NULL)
		octal = "(nil)";

	i = numChars = 0;
	while(octal[i] != '\0')
	{
		buffer[*bufpos] = octal[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
		{
			*bufpos = 0;
			write_buffer(buffer, buflen);
		}
		i++, numChars++;
	}
	free(octal);
	return (numChars);
}
/**
* print_hex - prints the hexadecimal conversion of a decimal number, lowercase
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_hex(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int numChars, i;
	unsigned int n;
	char *hex;

	n = va_arg(args, unsigned int);
	hex = hexConverter('x', n);
	if (hex == NULL)
		hex = "(nil)";
	i = numChars = 0;
	while(hex[i] != '\0')
	{
		buffer[*bufpos] = hex[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
		{
			*bufpos = 0;
			write_buffer(buffer, buflen);
		}
		i++, numChars++;
	}
	free(hex);
	return (numChars);
}
/**
* print_heX - prints the hexadecimal conversion of a decimal number, uppercase
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_heX(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int numChars, i;
	unsigned int n;
	char *heX;

	n = va_arg(args, unsigned int);
	heX = hexConverter('X', n);
	if (heX == NULL)
		heX = "(nil)";
	i = numChars = 0;
	while(heX[i] != '\0')
	{
		buffer[*bufpos] = heX[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
		{
			*bufpos = 0;
			write_buffer(buffer, buflen);
		}
		i++, numChars++;
	}
	free(heX);
	return (numChars);
}
/**
 * print_b - prints the binary conversion of a decimal number
 * @args: number to be printed
 * @buffer: space used for printing
 * @buflen: buffer length
 * @bufpos: current buffer index
 * Return: numbers of chars written to buffer
 **/
int print_b(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int numChars, i;
	unsigned int n;
	char *bin;

	n = va_arg(args, unsigned int);
	bin = binConverter(n);
	if (bin == NULL)
		bin = "(nil)";
	i = numChars = 0;
	while(bin[i] != '\0')
	{
		buffer[*bufpos] = bin[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
		{
			*bufpos = 0;
			write_buffer(buffer, buflen);
		}
		i++, numChars++;
	}
	free(bin);
	return (numChars);
}
/**
* print_S - prints printable chars, else their hexa value in uppercase
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_S(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int numChars, i, k, j;
	char *str, *inHex, st;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "\x00";

	i = numChars = 0;
	while (str[i] != '\0')
	{
		st = str[i];
		j = str[i];
		printf("st is %c\n", st);
		printf("j is %d\n", j);
		if (j > 0 && j < 32 || j >= 127)
		{
			buffer[*bufpos] = '\\';
			*bufpos += 1;
			*buflen += 1;
			if (*buflen == 1024)
			{
				*bufpos = 0;
				write_buffer(buffer, buflen);
			}
			buffer[*bufpos] = 'x';
                        *bufpos += 1;
                        *buflen += 1;
                        if (*buflen == 1024)
                        {
                                *bufpos = 0;
                                write_buffer(buffer, buflen);
                        }
			if (j > 0 && j <= 15)
			{
				buffer[*bufpos] = '0';
				*bufpos += 1;
				*buflen += 1;
				if (*buflen == 1024)
				{
					*bufpos = 0;
					write_buffer(buffer, buflen);
				}
				if (j > 0 && j <= 9)
					buffer[*bufpos] = str[i] + '0';
				else if (j > 9 && j <= 15)
					buffer[*bufpos] = str[i] + 55;
				*bufpos += 1;
                                *buflen += 1;
				if (*buflen == 1024)
				{
					*bufpos = 0;
					write_buffer(buffer, buflen);
				}
			}
			else if (j > 16 && j < 32 || j >= 127)
			{
				inHex = hexConverter('X', j);
				k = 0;
				while (inHex[k] != '\0')
				{
					buffer[*bufpos] = inHex[k];
					*bufpos += 1;
					*buflen += 1;
					if (*buflen == 1024)
					{
						*bufpos = 0;
						write_buffer(buffer, buflen);
					}
					k++;
				}
			}
			numChars += 4;
		}
	 	else
		{
			buffer[*bufpos] = str[i];
			*bufpos += 1;
			*buflen += 1;
			if (*buflen == 1024)
			{
				*bufpos = 0;
				write_buffer(buffer, buflen);
			}
			numChars++;
		}
		i++;
	}
	return (numChars);
}
