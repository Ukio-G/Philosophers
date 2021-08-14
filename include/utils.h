/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:59:43 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 15:42:00 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *source, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	ft_ternary_char(int predict, char true_v, char false_v);
char	*ft_ternary_str(int predict, char *true_v, char *false_v);
float	ft_ternary_float(int predict, float true_v, float false_v);
long long	ft_ternary_ll(int predict, long long true_v, long long false_v);
int	ft_ternary_int(int predict, int true_v, int false_v);


#endif
