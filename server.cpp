#include <iostream>
#include <winsock2.h>
#include <cstring>
using namespace std;
int main(){
     WSADATA wsa;
    WSAStartup(MAKEWORD(2,2),&wsa);
int ServerSocket = socket(AF_INET,SOCK_STREAM,0);  
// cout<<"starting\n"; 
sockaddr_in serverAddress;
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(12345);
serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
// cout<<"binding\n";
bind(ServerSocket ,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
// cout<<"listening\n";
listen(ServerSocket,5);
while(true){
int ClientSocket = accept(ServerSocket,nullptr,nullptr);
cout<<"connected\n"; 
char buffer[1024] = {0};
string msg;
while(true){
    getline(cin,msg);
    memset(buffer,0,sizeof(buffer));
    recv(ClientSocket,buffer,sizeof(buffer),0);
    send(ClientSocket,msg.c_str(), msg.length(), 0);
cout<<buffer<<endl;
if(strcmp(buffer,"stop")==0) break;
}
break;
                          }
closesocket(ServerSocket);
return 0;

}
