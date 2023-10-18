#include "header_file.h"

/**
 * prepend_node - Adds a node to the start of the list.
 * @head: Address of the pointer to the head node.
 * @str: Str field of the node.
 * @num: Node index used by history.
 *
 * Return: The size of the list.
 */
list_t *prepend_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	fill_memory((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = string_dpl(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * append_node - Adds a node to the end of the list.
 * @head: Address of the pointer to the head node.
 * @str: Str field of the node.
 * @num: Node index used by history.
 *
 * Return: The size of the list.
 */
list_t *append_node(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	fill_memory((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = string_dpl(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * output_string_list - Prints only the str element of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: The size of the list.
 */
size_t output_string_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		string_puts(h->str ? h->str : "(nil)");
		string_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * remove_node_at_index - Deletes a node at the given index.
 * @head: Address of the pointer to the first node.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, 0 on failure.
 */
int remove_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * clear_list - Frees all nodes of a list.
 * @head_ptr: Address of the pointer to the head node.
 *
 * Return: Void.
 */
void clear_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}