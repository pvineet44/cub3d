/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:09:29 by vparekh           #+#    #+#             */
/*   Updated: 2020/01/19 13:09:31 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_params {
	int	width;
	int	size;
	int	flags[3];
}					t_params;

int					ft_printf(const char *format, ...);
int					isflag(const char c);
unsigned int		putstr(char *s, t_params params);
void				get_flags(char **ptr, int flags[2]);
int					get_width(char **ptr);
int					get_size(char **ptr);
int					min(int a, int b);
int					max(int a, int b);
unsigned int		putchar_(char c, t_params params);
unsigned int		putnbr(long int n, t_params params);
unsigned int		putunbr(long int n, t_params params);
unsigned int		puthex(long int n, t_params params, int caps);
long int			abs_(long int n);
char				*ft_itoa_hex(unsigned long int n, int caps);
unsigned int		putptr(void *ptr, t_params params);
void				replace_stars(char **format, ...);
void				replace_first_star(char **src, int n);
int					is_type(const char c);
int					count_stars(char *str);
int					handle_format(char **ptr, va_list args);
int					handle_format_star(char **ptr, int arg, va_list args);
int					handle_format_star2(char **ptr, int arg1, int arg2,
		va_list args);
int					process(char type, t_params params, va_list args);
void				ft_putcharn_fd(char c, int n);
void				fill_hex(int *fill_s, int *fill_z, int s, t_params args);
#endif
