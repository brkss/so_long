/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:10:32 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/07 19:16:33 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Things to check for 
 *	-> MAP only contains these characters : 0 1 E P C 
 *	-> MAP contains atleast : 1 exit, 1 collectible, and 1 starting position
 *	-> MAP must be rectangular 
 *	-> MAP must be closed/surrounded by walls
 */

int	read_map(int fd, t_data *data);

