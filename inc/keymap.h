/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/08 19:21:25 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# define MENU(key) if (key == 46){show_menu(box);}
# define P_CL_P(key) if (key == 12){box->prm->set_plus_color +=5;}
# define P_CL_M(key) if (key == 13){box->prm->set_plus_color -=5;}
# define Z_CL_P(key) if (key == 0){box->prm->set_zero_color +=5;}
# define Z_CL_M(key) if (key == 1){box->prm->set_zero_color -=5;}
# define M_CL_P(key) if (key == 6){box->prm->set_minus_color +=5;}
# define M_CL_M(key) if (key == 7){box->prm->set_minus_color -=5;}
# define RESET(key) if (key == 2){reset_to_default(&box);}
# define ROT_X_P(key) if (key == 89){box->mtrx = rot_x(&box, 1);}
# define ROT_X_M(key) if (key == 91){box->mtrx = rot_x(&box, -1);}
# define ROT_Y_P(key) if (key == 86){box->mtrx = rot_y(&box, 1);}
# define ROT_Y_M(key) if (key == 87){box->mtrx = rot_y(&box, -1);}
# define ROT_Z_P(key) if (key == 83){box->mtrx = rot_z(&box, 1);}
# define ROT_Z_M(key) if (key == 84){box->mtrx = rot_z(&box, -1);}
# define ISO_PROJ(key) if (key == 34){box->mtrx = isometric_pojection(&box);}
# define EL_PROJ(key) if (key == 31){box->mtrx = elevation_side(&box);}
# define SET_RED(key) if (key == 15){box->prm->set_zero_color = 16711680;}
# define SET_GREEN(key) if (key == 5){box->prm->set_zero_color = 65280;}
# define SET_BLUE(key) if (key == 11){box->prm->set_zero_color = 255;}
# define MOVE_RIGHT(key) if (key == 124){box->prm->init.x += 10;}
# define MOVE_LEFT(key) if (key == 123){box->prm->init.x -= 10;}
# define ESCAPE(key) if (key == 53) exit (0);

#endif
