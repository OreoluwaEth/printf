#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * struct types - specifier structure for printf
 * @p: pointer to characteres specifiers
 * @func : function pointer to print fucntions
 */
typedef struct types
{
	char p;
	int (*func)(va_list);
} print_f;

int _putchar(char c);
int _printf(const char *format, ...);
int printc(va_list l);
int print_string(va_list s);
int (*cmp_func(const char a))(va_list);
int print_n(va_list n);
void write_buffer(char buffer[], int *buflen);
void initialize_buffer(char buffer[]);
char *binConverter(unsigned int n);
char *octConverter(unsigned int n);
char *hexConverter(char type, unsigned int n);
char *binConverter(unsigned int n);
int print_o();
int print_hex();
int print_heX();
int print_b();
int print_S();

#endif 
