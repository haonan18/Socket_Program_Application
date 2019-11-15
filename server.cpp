#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <time.h>



// This is a data structure that holds important information on a session.
struct session {
    char client_id[32]; // Assume the client ID is less than 32 characters.
    struct sockaddr_in client_addr; // IP address and port of the client
                                    // for receiving messages from the 
                                    // server.
    time_t last_time; // The last time when the server receives a message
                      // from this client.
    int token;        // The token of this session.
    int state;        // The state of this session, 0 is "OFFLINE", etc.

    // TODO: You may need to add more information such as the subscription
    // list, etc.
};

// TODO: You may need to add more structures to hold global information
// such as all registered clients, the list of all posted messages, etc.

int main() {

    int ret;
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char recv_buffer[1024];
    int recv_len;
    socklen_t len;

    // You may need to use a std::map to hold all the sessions to find a 
    // session given a token. I just use an array just for demonstration.
    struct session session_array[16];

    // This current_session is a variable temporarily hold the session upon
    // an event.
    struct session *current_session;
    int token;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("socket() error: %s.\n", strerror(errno));
        return -1;
    }

    // The servaddr is the address and port number that the server will 
    // keep receiving from.
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(32000);

    bind(sockfd, 
         (struct sockaddr *) &serv_addr, 
         sizeof(serv_addr));

    while (1) {

        // Note that the program will still block on recvfrom()
        // You may call select() only on this socket file descriptor with
        // a timeout, or set a timeout using the socket options.

        len = sizeof(cli_addr);
        recv_len = recvfrom(sockfd, // socket file descriptor
                 recv_buffer,       // receive buffer
                 sizeof(recv_buffer),  // number of bytes to be received
                 0,
                 (struct sockaddr *) &cli_addr,  // client address
                 &len);             // length of client address structure

        if (recv_len <= 0) {
            printf("recvfrom() error: %s.\n", strerror(errno));
            return -1;
        }




        // Now we know there is an event from the network
        // TODO: Figure out which event and process it according to the
        // current state of the session referred.


        int token = extract_token_from_the_received_binary_msg(...)
        struct session *current_session = find_the_session_by_token(...)
        int event = parse_the_event_from_the_datagram(...)

        // Record the last time that this session is active.
        current_session->last_time = time();

        if (event == EVENT_LOGIN) {
            if (current_session->state == STATE_OFFLINE) {

                // TODO: parse the payload the received message and
                // authenticate the client.
            } else if (current_session->state == ...) {

                // TODO: handles errors if the event happens in some state
                // that is not expected.

            }

        } else if (event == ...) {

            // TODO: process other events

        }

        time_t current_time = time();

        // Now you may check the time of all clients. 
        // For each session, if the current time has passed 5 minutes plus 
        // the last time of the session, the session expires.
        // TODO: check session liveliness


    } // This is the end of the while loop

    return 0;
} // This is the end of main()