#include "shell.h"

/**
 * _strcpy - copies string from src to dest
 * @src: source of the string
 * @dest: destination of the string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr;

	if (src == NULL || dest == NULL)
	{
		return (NULL);
	}
	ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
/**
 * _strlen - returns length of a string
 * @str: string given
 *
 * Return: length
 */
int _strlen(char *str)
{
	int c = 0;

	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}
/**
 * wrd_cnt - returns number of words separated by delim from s
 * @s: the string
 * @delim: separator character
 *
 * Return: number of words
 */
int wrd_cnt(char *s, char delim)
{
	int j = 0, wc = 0;

	while (s[j] != '\0')
	{
		if (s[j] == delim && s[j + 1] != '\0')
		{
			wc++;
		}
		j++;
	}
	wc++;
	return (wc);
}

/**
 * split - splits string into words
 * @str: string
 * @delim: delimitor
 *
 * Return: array of words
 */

char **split(char *str, char delim)
{
	int w, wcc, wc, j = 0;
	char *s = str;
	char *t, **c;

	w = 0;
	t = s;
	wc = wrd_cnt(str, delim);
	c = malloc(sizeof(char *) * wc);
	while (s[j] != '\0')
	{
		if (s[j] == delim && s[j + 1] != '\0')
		{
			s[j] = '\0';
			wcc = _strlen(t);
			c[w] = malloc(sizeof(char) * wcc + 1);
			_strcpy(c[w], t);
			t = &s[j + 1];
			w++;
		}
		j++;
	}
	wcc = _strlen(t);
	c[w] = malloc(sizeof(char *) * wcc);
	_strcpy(c[w], t);
	c[++w] = NULL;
	return (c);
}

/**
 * _strcat - concatinates strings
 * @dst: destination
 * @src: source
 *
 * Return: dest
 */

char *_strcat(char *dst, char *src)
{
	char *d = dst;

	if (src == NULL || dst == NULL)
	{
		return (NULL);
	}
	while (*dst != '\0')
	{
		dst++;
	}
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	return (d);
}
