/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:01:40 by danielga          #+#    #+#             */
/*   Updated: 2023/02/08 16:51:20 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//To run write and variadics.

# include <unistd.h>
# include <stdarg.h>

/**
 * @brief The basic function to start writing what is needed. From it, 
 * will derive the rest of the functions depending on the parameter set.
 * 
 * @param str The string sent.
 * @param ... Any arguments required.
 * 
 * @return The number of characters printed.
**/
int		ft_printf(char const *str, ...);

/**
 * @brief Prints a character. Used for %c, %% parameters.
 * 
 * @param str The character to print.
 * 
 * @return The number of characters printed.
**/
int		ft_printchar(int c);

/**
 * @brief Will print a complete string. Used for %s and %p parameters. 
 * 
 * @param str The string sent.
 * 
 * @return The number of characters printed.
**/
int		ft_printstr(char *str);

/**
 * @brief Will print an integer or number. Used for %d and %i parameters.
 * 
 * @param n The integer sent.
 * 
 * @return The number of items printed.
**/
int		ft_printnbr(int n);

/**
 * @brief Prints a hexadecimal number. Used in %p and %x-X parameters. 
 * 
 * @param p The item to print.
 * @param hex The hexadecimal base.
 * 
 * @return The number of characters printed.
**/
int		ft_printhex(unsigned long p, char *hex);

/**
 * @brief Prints an unsigned number or integer. Used in the %u parameter.  
 * 
 * @param n the number or integer to print.
 * 
 * @return The number of characters printed.
**/
int		ft_print_unsig_nbr(unsigned int n);

#endif