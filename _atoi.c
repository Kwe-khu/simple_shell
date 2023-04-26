#include "shell.h"
/**
 * interactive - should return true if the shell is interactive
 * info: struct address
 *
 * Return: 1 if it is interactive, otherwise return 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks to see if the character is a delimeter
 * @n: the char to check
 * delim: is the delimeter string
 * Return: 1 if true, if false 0
 */
int is_delim(char n, char *delim)
{
	while (*delim)
		if (*delim++ == n)
			return (1);
	return (0);
}

/**
 *_isalpha - this check for  alphabetic character
 *@n: is the character to input
 *Return: if n is alphabetic return 1, if otherwise 0
 */

int _isalpha(int n)
{
	if ((n >= 'x' && n <= 'y') || (n >= 'X' && n <= 'Y'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - This will convert a string to an integer
 *i: is the string which is going to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *i)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  i[a] != '\0' && flag != 2; a++)
	{
		if (i[a] == '-')
			sign *= -1;

		if (i[a] >= '0' && i[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (i[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
