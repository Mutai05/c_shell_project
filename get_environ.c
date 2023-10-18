#include "header_file.h"

/**
 * copy_environ_strings - Returns a copy of the environment as an array of strings.
 * @info: Structure containing potential arguments. Used to maintain a
 *        constant function prototype.
 * Return: Always 0
 */
char **copy_environ_strings(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * remove_env_variable - Removes an environment variable.
 * @info: Structure containing potential arguments. Used to maintain a
 *        constant function prototype.
 * @var: The string representing the environment variable to remove.
 * Return: 1 on successful removal, 0 if the variable was not found.
 */
int remove_env_variable(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = remove_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * add_env_variable - Initializes a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments. Used to maintain a
 *        constant function prototype.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 * Return: Always 0
 */
int add_env_variable(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	append_node(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}