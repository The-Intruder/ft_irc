/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Misc.functions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <hssain.aitkadir@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:42:31 by haitkadi          #+#    #+#             */
/*   Updated: 2023/06/05 15:42:32 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ircserv.head.hpp"

/* -------------------------------------------------------------------------- */

void    stringTrim(std::string &str, const char *to_trim){
    str.erase(0, str.find_first_not_of(to_trim));
    str.erase(str.find_last_not_of(to_trim)+1);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */
void    writeMessageToClient(int fd, std::string message)
{
    int valwrite = write(fd, message.c_str() ,message.length());
    if(valwrite < 0)
        throw std::runtime_error("write failed");
}


/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void Server::removeChannel(std::string chName){
    std::map<std::string, IRCChannel>::iterator channelIt = \
    this->ChannelsMap.find(chName);
    if(channelIt != this->ChannelsMap.end() && channelIt->second.empty()){
        this->ChannelsMap.erase(channelIt);
    }
}
/* -------------------------------------------------------------------------- */