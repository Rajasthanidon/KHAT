#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <string.h>
using namespace std;
int main(){
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);
int ClientSocket = socket(AF_INET,SOCK_STREAM,0);
sockaddr_in serverAddress;
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(12345);
serverAddress.sin_addr.s_addr = INADDR_ANY;
cout<<"connecting";
connect(ClientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
cout<<"connected";
// string msg;
const char* msg = "Hello";
// char buffer[1024]={0};
             
// while(true){
    cout<<endl;
    // getline(cin,msg);
    send(ClientSocket, msg,strlen(msg), 0);
    // recv(ClientSocket,buffer,sizeof(buffer),0);
    // cout<<buffer;
    // if(msg=="stop") break;
// }

closesocket(ClientSocket);
return 0;
}