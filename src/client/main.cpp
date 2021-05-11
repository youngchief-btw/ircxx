#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

// The following are Linux & MacOS ONLY Terminal color codes.
// To-Do: Work on getting colors done in Windows (see here: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c)
#ifdef __unix__
#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define BOLDRED "\033[1m\033[31m" /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m" /* Bold White */
#define UNDERLINE "\033[4m" /* Underline */
#define UNDERLINE_OFF "\033[0m" /* Turn off underlining */
#endif

using namespace std;

string receiveInput(string prefix) {
    string input;
    cin >> input;
    if (prefix == "") {
        return input;
    } else {
        return prefix + " " + input;
    }
}

string colorize(string color, string str) {
    return color + str + RESET;
}

int main(int argc, char *argv[]) {
    cout << colorize(CYAN, "ircpp CLI Client.\nDo /help for commands!\n");

    while(1) {
        // This loops forever until stopped
        string input = receiveInput("");
        if (input == "/help") {
            cout << colorize(CYAN, "Commands:\n  /help\n  /connect\n");
        } else if (input == "/connect") {
            cout << colorize(CYAN, "Server Hostname: ");
            string srvhn = receiveInput("");
            cout << colorize(CYAN, "Server Port: ");
            int srvport;
            cin >> srvport;
            // Start connecting.
            cout << colorize(CYAN, "Username: ");
            string usrname = receiveInput("");
            cout << colorize(CYAN, "Nickname: ");
            string nickname = receiveInput("");
            cout << colorize(CYAN, "Hostname: ");
            string hostname = receiveInput("");
            
            // Resolve hostname to IP  
            server = gethostbyname(srvhn.c_str()); 
   
            if (server == NULL) {
                printf("ERROR, No such host!\n");
                // exit(0);
            }
        } else // if (input.split()) {

        // } else
        if (input == "/exit") {
            // exit(0);
        } else {
            cout << colorize(RED, "Unknown command! Try again!\n");
        }
    }

    return 0;
}