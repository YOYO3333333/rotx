#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int my_atoi(const char *str)
{
    int c = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == 32)
            continue;
        if (str[i] == 43)
        {
            if ((48 <= str[i + 1]) && (str[i + 1] <= 57))
            {
                c = str[i + 1] - '0';
                for (int j = i + 2; str[j] != 0; j++)
                {
                    if ((48 <= str[j]) && (str[j] <= 57))
                    {
                        c = (c * 10) + (str[j] - '0');
                    }
                    else
                        return 0;
                }
                return c;
            }
            return 0;
        }
        if (str[i] == 45)
        {
            if ((48 <= str[i + 1]) && (str[i + 1] <= 57))
            {
                c = str[i + 1] - '0';
                for (int j = i + 2; str[j] != 0; j++)
                {
                    if ((48 <= str[j]) && (str[j] <= 57))
                    {
                        c = (c * 10) + (str[j] - '0');
                    }
                    else
                        return 0;
                }
                return -c;
            }
            return 0;
        }
        if ((48 <= str[i]) && (str[i] <= 57))
        {
            c = str[i] - '0';
            for (int j = i + 1; str[j] != 0; j++)
            {
                if ((48 <= str[j]) && (str[j] <= 57))
                {
                    c = (c * 10) + (str[j] - '0');
                }
                else
                {
                    return 0;
                }
            }
            return c;
        }
        else
            return 0;
    }
    return 0;
}
void rot_x(char *s, int x)
{
    if (s == NULL)
        return;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (('A' <= s[i]) && (s[i] <= 'Z'))
        {
            if (x < 0)
                x = 26 + (x % 26);
            s[i] = s[i] + x - 'A';
