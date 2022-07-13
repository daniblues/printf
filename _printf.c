#include "main.h"

/**
 * _printf - Outputs the formatted string
 * @format: input constant
 * Return: size of bufer (success) or -1 if fail
 */
int _printf(const char *format, ...)
{
if (format != NULL)
{
va_list argu;
int i;
char *buf;
char *temp_str;
va_start(argu, format);
buf = malloc(1024 * sizeof(char));
if (buf == NULL)
{
return (-1);
}
while (format && format[i] != 00)
{
i = _strncat(buf, format, i);
if (format[i] == 37)
{
i++;
temp_str = fntn(format[i], argu);
_strcat(buf, temp_str);
}
if (format[i] != 00)
i++;
}
i = _strlen(buf);
write(1, buf, i);
va_end(argu);
free(buf);
return (i);
}
return (-1);
}
