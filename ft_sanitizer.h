/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:13:59 by hsabir            #+#    #+#             */
/*   Updated: 2022/02/19 19:45:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SANITIZER_H
# define FT_SANITIZER_H

//#include <libft.a>
#include "libs/libft/incs/libft.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct s_info t_info;

typedef struct	s_info
{
	int 			len;
	void			*ptr;	// Adresses of allocated memories
	size_t 			line;	// The line where leak occured
	char			*filename;	// The filename where leak occured
	struct s_info	*next;	// Hmm obvious this one.
}	t_info;


#endif //FT_SANITIZER_H
