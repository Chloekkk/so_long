/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:18:35 by nkim              #+#    #+#             */
/*   Updated: 2022/07/15 19:44:05 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "utils_bonus.h"
#include <stdlib.h>

static void	init_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map.cols;
	y = game->map.rows;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * x, TILE_SIZE * y,
			"KIRBY");
}

void	init_props(t_game *game)
{
	game->move_status = NONE;
	game->is_running = FALSE;
	game->is_stop = FALSE;
	game->status = NOTSTARTED;
	game->offset = 0;
	game->collect.collections = NULL;
	game->enemy.enemies = NULL;
	game->step = 0;
}

static void	init_sprites(t_game *game)
{
	t_player	*player;

	player = &game->player;
	ft_make_iterable_sprites(game, &player->r_sprites, "rkirby", 10);
	ft_make_iterable_sprites(game, &player->l_sprites, "lkirby", 10);
	ft_make_iterable_sprites(game, &player->r_run_sprites, "run_kirby", 8);
	ft_make_iterable_sprites(game, &player->l_run_sprites, "run_lkirby", 8);
	ft_make_iterable_sprites(game, &player->r_stop_sprites, "stop_kirby", 10);
	ft_make_iterable_sprites(game, &player->l_stop_sprites, "stop_lkirby", 10);
	ft_make_iterable_sprites(game, &player->fire_sprites, "fire_kirby", 8);
	ft_make_iterable_sprites(game, &game->collect.sprites, "star", 6);
	ft_make_iterable_sprites(game, &game->enemy.sprites, "fire", 4);
}

static void	init_imgs(t_game *game)
{
	t_tiles	*tiles;

	tiles = &game->tiles;
	tiles->wall = ft_make_xpm_img(game, "wall.xpm");
	tiles->ground = ft_make_xpm_img(game, "ground.xpm");
	tiles->step = ft_make_xpm_img(game, "step.xpm");
	tiles->exit = ft_make_xpm_img(game, "exit.xpm");
	tiles->open_exit = ft_make_xpm_img(game, "open_exit.xpm");
	game->player.r_inital = game->player.r_sprites;
	game->player.l_inital = game->player.l_sprites;
	game->player.sprites = game->player.r_sprites;
	game->player.initial = game->player.r_sprites;
	game->screen.start = ft_make_xpm_screen(game, "start_screen.xpm");
	game->screen.fail = ft_make_xpm_screen(game, "fail_screen.xpm");
	game->screen.success = ft_make_xpm_screen(game, "success_screen.xpm");
}

void	init_game(t_game *game)
{
	init_window(game);
	init_props(game);
	init_sprites(game);
	init_imgs(game);
}
