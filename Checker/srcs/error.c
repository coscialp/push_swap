/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:01:20 by coscialp          #+#    #+#             */
/*   Updated: 2021/03/05 09:26:39 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	log_error(int error)
{
	if (error == DUNUM)
		ft_dprintf(2, "Error:\tNo duplicates numbers!\n");
	else if (error == NONUM)
		ft_dprintf(2, "Error:\tOnly numbers are accepted!\n");
	exit(1);
}
