/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:04:15 by abellakr          #+#    #+#             */
/*   Updated: 2023/05/01 18:01:20 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ircserv.head.hpp"




// constractor parametrized of my simple server
Server::Server(int PORT, std::string PASSWORD) : PORT(PORT) , PASSWORD(PASSWORD)
{
   
   // step 1 : creat socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        throw std::runtime_error("cannot create socket");
   // before calling bind we need to fill the sockaddr_in
   memset((char *)&ServAddr, 0 , sizeof(ServAddr));
   ServAddr.sin_family = AF_INET;
   ServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
   ServAddr.sin_port = htons(this->PORT);
   // step 2 : associate a socket with a specific network address and port number
    if(bind(sockfd, (struct sockaddr *)&ServAddr, sizeof(ServAddr)) < 0)
        throw std::runtime_error("bind failed");
    // step 3 : wait for the incoming connection (listen)
    if(listen(sockfd, 1) < 0)
        throw std::runtime_error("listen failed");


    while(true)
    {
        std::cout << "----waiting for the connection----" << std::endl;
        int addrlen = sizeof(ServAddr);
        // step 4 : accept the incoming connection 
        int newsockfd = accept(sockfd, (struct sockaddr *)&ServAddr, (socklen_t *)&addrlen);
        if(newsockfd < 0)
            throw std::runtime_error("accept failed"); 
        // step 5 : connection phase : send and receive | read and write
        char buffer[256];
        bzero(buffer, 256);
        int valread = recv(newsockfd,  &buffer, sizeof(buffer), 0);
        if(valread < 0)
            throw std::runtime_error("recv failed"); 
        std::cout << buffer << std::endl;
        int valwrite = send(newsockfd, "done.\n", 6, 0);
        if(valwrite < 0)
            throw std::runtime_error("send failed"); 
        close(newsockfd);
    }
    
}

Server::~Server()
{
    
}