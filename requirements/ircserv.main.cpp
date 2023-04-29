/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:54:49 by abellakr          #+#    #+#             */
/*   Updated: 2023/04/29 15:30:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.head.hpp"


int main(int ac, char **av)
{
    try{
        if(ac != 2)
            throw std::invalid_argument("error: invalid argument");
        else
        {
            std::cout << av[1] << std::endl;
        }
        
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}