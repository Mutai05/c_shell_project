#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT                                                               \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}

/**
 * struct built_in - contains a built_in string and related function
 * @type: the built_in command flag
 * @func: the function
 */
typedef struct built_in
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

void print_prompt(void);

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void show_error_msg(char *);
int _write_char_to_stderr(char);
int _write_to_fd(char c, int fd);
int _write_string_to_fd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int write_char(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int string_to_int(char *);
void print_error(info_t *, char *);
int print_dec(int, int);
char *converts_number(long int, int, int);
void erase_comments(char *);

int _shellexit(info_t *);
int _changedir(info_t *);
int _seehelp(info_t *);

int _allhistory(info_t *);
int _myalias(info_t *);

ssize_t get_line_input(info_t *);
int get_input_line(info_t *, char **, size_t *);
void blockCtrlC(int);

void clear_info(info_t *);
void initialize_info(info_t *, char **);
void free_info(info_t *, int);

char *_environment_variable(info_t *, const char *);
int _listenv(info_t *);
int _setenvironment(info_t *);
int _unsetenvironment(info_t *);
int initialize_env(info_t *);

char **copy_environ_strings(info_t *);
int remove_env_variable(info_t *, char *);
int add_env_variable(info_t *, char *, char *);

char *see_file_history(info_t *info);
int save_history_to_file(info_t *info);
int load_history_from_file(info_t *info);
int add_history_entry(info_t *info, char *buf, int linecount);
int update_history_line_numbers(info_t *info);

list_t *prepend_node(list_t **, const char *, int);
list_t *append_node(list_t **, const char *, int);
size_t output_string_list(const list_t *);
int remove_node_at_index(list_t **, unsigned int);
void clear_list(list_t **);

size_t count_nodes(const list_t *);
char **list_to_strings(list_t *);
size_t show_list(const list_t *);
list_t *find_node_with_prefix(list_t *, char *, char);
ssize_t retrieve_node_index(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
