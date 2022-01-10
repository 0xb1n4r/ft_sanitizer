/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitizer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:13:59 by hsabir            #+#    #+#             */
/*   Updated: 2022/01/10 18:23:52 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SANITIZER_H
# define FT_SANITIZER_H

// Undefine malloc associated functions
// so we don't have any conflict with their
// original macros later on
# undef malloc
# undef calloc
# undef ft_calloc
# undef free

# include "../libs/libft/incs/libft.h"

typedef struct	s_mem
{
	void			*ptr;	// Adresses of allocated memories
	size_t			block;	// Blocksize of leaked memories
	size_t			line;	// The line where leak occured
	char			*filename;	// The filename where leak occured
	struct s_mem	*next;	// Hmm obvious this one.
}	t_mem;

#endif
