/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:50:07 by nkim              #+#    #+#             */
/*   Updated: 2022/01/29 23:29:23 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_animate_player(t_game *game)
{
	int	step;

	step = 4;
	if (game->move_status == RIGHT)
		handle_location(game, step, 0);
	else if (game->move_status == LEFT)
		handle_location(game, -step, 0);
	else if (game->move_status == TOP)
		handle_location(game, 0, -step);
	else if (game->move_status == BOTTOM)
		handle_location(game, 0, step);
	game->offset += step;
	if (game->offset > MAX_OFFSET)
		game->offset = 0;
	ft_put_img(game, game->player.sprites->img,
		game->player.x, game->player.y);
	game->player.sprites = game->player.sprites->next;
}

void	draw_animate_collect(t_game *game)
{
	t_component	*collections;

	collections = game->collect.collections;
	while (collections)
	{
		ft_put_img(game, game->tiles.ground,
			collections->x, collections->y);
		ft_put_img(game, game->collect.sprites->img,
			collections->x, collections->y);
		collections = collections->next;
	}
	game->collect.sprites = game->collect.sprites->next;
}
