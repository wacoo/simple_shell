#include "shell.h"

/**
 * _strcmp - compares two strings
 * @x: string 1
 * @y: string 2
 *
 * Return: if both string are the same, returns 0. Else another number
 */

int _strcmp(const char *x, const char *y)
{
	while (*x)
	{
		if (*x != *y) {
			break;
		}

		x++;
		y++;
	}

	return *(const unsigned char*)x - *(const unsigned char*)y;
}

char *remove_space(char *str, char flag)
{
	int i = 0, k = 0, x = 0;
	static int s = 0;
	while (str[k] != '\0')
        {
        	k++;
	}
	if (s == 0)
	{
		s = k;
	}
	while (str[i] != '\0')
	{
		if (flag == 's')
		{
			if (str[i] == ' ' && i == 0)
			{
				x = 1;
			}
			if (x > 0)
			{
				str[i] = str[i + 1];
			}
			if (str[s - 1] != '\0')
			{
				str[s - 1] = '\0';
			}

                }
		else if (flag == 'm')
		{	
			if (str[i] == ' ' && i != 0)
			{
				x++;
			}
			if (x > 1)
			{
				str[i - 1] = str[i];
				str[i] = '\0';
			}
			
			if (str[s - 1] != '\0')
                        {
                                str[s - 1] = '\0';
                        }
		}
		i++;
	}
	x = 0;	
	if (flag == 'e')
	{
		while (str[k] != '\0')
		{
			k++;
		}
		if (str[k - 1] != '\0')
		{	
			str[k - 1] = '\0';
		}
	}
	return (str);
}

/**
 * parse - removes unneccessary space from string
 * @str: string given
 * Return: pointer to list of cleaned strings
 */
char *parse(char *str)
{
	static int flag = 0, x, t = 0;
	int counter = 0;
	int i = 0, k = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[k] != '\0')
	{
		k++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && i != 0 && k - 1 != i)
		{
			t++;
			str = remove_space(str, 'm');
			if (t > 1)
			{
				counter++;
				t = 0;
			}
		}
		else if (str[i] == ' ' && i == 0)
		{
			str = remove_space(str, 's');
			counter++;	
		}
		else if (str[k - 1] == ' ')
		{
			str = remove_space(str, 'e');
			counter++;
		}
		i++;
	}
	if (flag == 0)
	{
		x = k;
	}
	str[x - 1] = '\0';	
	if(counter == 0)
	{
		flag = 0;
		return (str);
	}
	else
	{
		flag = 1;
		parse(str);
	}
	return (str);
}
