/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:33:11 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 21:36:59 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef enum	e_bool
{
	FALSE,
	TRUE,
	MAYBE
}				t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_buffer
{
	char		buffer[BUFFER_SIZE];
	ssize_t		readlen;
	ssize_t		buffinc;
}				t_buffer;
t_bool 			ft_malloc_char(int size, char **ptr);
t_bool 			ft_malloc_int(int size, int **ptr);
t_bool 			ft_malloc_float(int size, float **ptr);
t_bool 			ft_malloc_double(int size, double **ptr);
t_bool 			ft_malloc_t_bool(int size, t_bool **ptr);
t_bool 			ft_free_char(char **ptr);
t_bool 			ft_free_int(int **ptr);
t_bool 			ft_free_float(float **ptr);
t_bool 			ft_free_double(double **ptr);
t_bool 			ft_free_t_bool(t_bool **ptr);
double			ft_atof(const char *str);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
t_bool			ft_error(const char *msg, const char *msg2);
t_bool			ft_freerror(const char *msg, const char *msg2);
t_bool			ft_memerror(const char *forfree);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
void			ft_itoa_init(int n, int *clclen, \
					int *strlen, int *posinega);
char			*ft_itoa(int n);
int				ft_isprint(int c);
int				ft_issigned(int c);
int				ft_isspace(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				s1_index0_not_exist(char **str);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
t_bool			ft_gnl_status(int error, char *line, int fd,
				const char *file);
int				ft_gnl_return_value(t_buffer *buff);
int				ft_gnl_line_maker \
				(t_buffer *buff, ssize_t *linelen, char **line);
int				get_next_line(int fd, char **line);

#endif 