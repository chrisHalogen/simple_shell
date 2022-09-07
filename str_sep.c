#include "shell.h"

/**
 * _strsep - function to tokenize a string
 * @str: the input string
 * @delims: the delimeter
 * Return: the token
 */

char *_strsep(char **str, char *delims)
{
	char *token;

	if (!(*str))
	{
		/* No more tokens */
		return (NULL);
	}

	token = *str;

	while (**str != '\0')
	{
		if (_strchr(delims, **str))
		{
			**str = '\0';
			(*str)++;
			return (token);
		}

		(*str)++;
	}

	/* There is no other token */
	*str = NULL;
	return (token);
}

/**
 * _strchr - function to find the occurence of a character in a string
 * @s: the input string
 * @c: the character to search the string for
 * Return: the pointer to the occurence or NULL
 */

char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}

	if (*s == c)
	{
		return (s);
	}
	else
	{
		return (NULL);
	}
}
