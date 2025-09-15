/*
 * File: main.c
 * Author: Ragib Asif
 * Email: ragibasif@tuta.io
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define EXAMPLE_HOST "www.example.com"
#define PORT         "2222"
#define BACKLOG      10

int main( int argc, char **argv ) {
    struct addrinfo hints, *res, *p;
    int             status;
    char            ipstr[INET6_ADDRSTRLEN];

    memset( &hints, 0, sizeof hints );
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ( ( status = getaddrinfo( EXAMPLE_HOST, "http", &hints, &res ) ) != 0 ) {
        fprintf( stderr, "gai error: %s\n", gai_strerror( status ) );
        return 2;
    }
    printf( "IP addresses for %s:\n\n", EXAMPLE_HOST );

    for ( p = res; p != NULL; p = p->ai_next ) {
        void *addr;
        char *ipver;

        struct sockaddr_in  *ipv4;
        struct sockaddr_in6 *ipv6;

        if ( p->ai_family == AF_INET ) {
            ipv4  = (struct sockaddr_in *)p->ai_addr;
            addr  = &( ipv4->sin_addr );
            ipver = "IPv4";
        } else {
            ipv6  = (struct sockaddr_in6 *)p->ai_addr;
            addr  = &( ipv6->sin6_addr );
            ipver = "IPv6";
        }

        inet_ntop( p->ai_family, addr, ipstr, sizeof ipstr );
        printf( " %s: %s\n", ipver, ipstr );
    }
    status = socket( res->ai_family, res->ai_socktype, res->ai_protocol );

    freeaddrinfo( res );

    return 0;
}
