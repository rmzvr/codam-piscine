/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:15:00 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 14:50:06 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "values.h"

t_dict_e	*create_dict(int argc, char **argv);
char		*create_final_string(void);
void		create_thousands(char *str, int count);
int			handle_one_digit_case(char *str, char *f_str, t_dict_e *dict);
int			handle_three_digit_case(char *str, char *f_str, t_dict_e *dict);
int			handle_two_digit_case(char *str, char *f_str, t_dict_e *dict);
void		parse_buffer(char *buffer, t_dict_e *dict);
void		parse_dict(char *file, t_dict_e *dict);
void		parse_line(char *buffer, int *i, t_dict_e *dict, int row);
int			process_one_digit(char *str, char *f_str, t_dict_e *dict);
int			process_three_digits(char *str, char *f_str, t_dict_e *dict);
int			process_two_digits(char *str, char *f_str, t_dict_e *dict);
long		read_file_to_buffer(char *file, char *buffer);
void		trim_dict(t_dict_e *dict);
int			validate_input(int argc, char **argv);
int			write_dictionary(char *nbr, char *c_str, t_dict_e *dict);
int			write_hundred_str(char *str, char *f_str, t_dict_e *dict);
int			write_number(char *str, char *f_str, t_dict_e *dict);
int			write_one_str(char *str, int one_i, char *f_str, t_dict_e *dict);
int			write_ten_str(char *str, int one_i, char *f_str, t_dict_e *dict);
int			write_thousands_str(int strlen, int m, char *f_str, t_dict_e *dict);

#endif
