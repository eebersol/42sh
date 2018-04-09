/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_channel_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 04:10:04 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:23:54 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char		*heredoc_backspace_check(char *ret)
{
	if (ret && ft_strlen(ret) > 0)
	{
		ret[ft_strlen(ret) - 1] = '\0';
		tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
	}
	return (ret);
}

char		*heredoc_enter_check(char *ret, t_list **list)
{
	ft_putchar('\n');
	return (add_to_list(list, ret, 1));
}

char		*heredoc_show_check(char *b, char *ret)
{
	if (b[0] != '\n' && ft_isprint(b[0]))
	{
		ft_putchar(b[0]);
		ret = ft_freejoin(ret, b);
	}
	return (ret);
}
