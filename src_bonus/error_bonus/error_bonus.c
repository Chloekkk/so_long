/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:50:10 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:00:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

void	throw_error(char *message)
{
	ft_putstr_fd("\033[31mError\n\033[0m", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}
