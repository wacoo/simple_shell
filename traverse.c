#include "shell.h"

/**
 * _getenv - get the values of the envronment variables given
 * @name: environment variable
 *
 * Return: the value of the variable
 */
char *_getenv(const char *name)
{
        int i = 0, cnt;
        extern char **environ;
        char **sp, *c;

        while (environ[i] != NULL)
        {
                cnt = _strlen(environ[i]);
                c = malloc(sizeof(char) * cnt);
                _strcpy(c, environ[i]);
                sp = split(c, '=');
                if(_strcmp(sp[0], name) == 0)
                {
                        /*printf("%s\n", sp[0]);*/
                        return (environ[i]);
                }
                i++;
        }
	return (NULL);
}
/**
 * print_path -  prints directories in PATH
 */
void print_path(void)
{
        char *en, **sp1, **sp2;
        int c = 0;

        en = _getenv("PATH");
        sp1 = split(en, '=');
        sp2 = split(sp1[1], ':');
        while (sp2[c] != NULL)
        {
                printf("%s\n", sp2[c]);
                c++;
        }

}
void add_new_node_end(dirs **head, char *fpath)
{
	dirs *new, *ln;
	int len;

	new = malloc(sizeof(dirs));
	if (new == NULL)
	{
		return;
	}
	len = _strlen(fpath);
	new->fpath = malloc(sizeof(char) * len + 1);
	_strcpy(new->fpath, fpath);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		ln = *head;
		while (ln->next != NULL)
		{
			ln = ln->next;
		}
		ln->next = new;
	}
}
char **create_path_list(void)
{
	extern char **environ;
	char *en, **sp1, **sp2;
	int c = 0;

	en = _getenv("PATH");
	sp1 = split(en, '=');
	sp2 = split(sp1[1], ':');
	while (sp2[c] != NULL)
	{
		/*printf("%s\n", sp2[c]);*/
		c++;
	}
	return (sp2);
}
