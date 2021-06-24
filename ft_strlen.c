#include "libftprintf.h"

ssize_t  ft_strlen(const char *str)
{
        ssize_t  a;

        a = 0;
        while (str[a] != '\0')
                a++;
        return (a);
}