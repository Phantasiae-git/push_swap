/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:07:35 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/24 22:28:45 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define UP "0123456789ABCDEF"
# define LOW "0123456789abcdef"

int		ft_printf(const char *s, ...);
int		puthexa(unsigned int n, int flag);
int		putpointer(unsigned long int n, int flag, int flag2);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_itoa_unsigned(unsigned int n);

#endif