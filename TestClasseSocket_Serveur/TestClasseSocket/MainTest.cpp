#include "Socket.h"
#include "ClientSocket.h"
#include "ServeurSocket.h"
#include <iostream>
using namespace std;

void main(void)
{

	CServeurSocket Ss1;


	/*******************************************************************************************
	* PARTIE SERVEUR SOCKET
	********************************************************************************************/
	SOCKET Socket;
	int port = 3306;
	int sock_err;
	char buffer[32] = "";

	Socket = Ss1.CreerSocketS();

	if(Socket != INVALID_SOCKET)
	{
		cout << "La socket "<< Socket << " est maintenant ouverte en mode TCP/IP\n";
		sock_err = Ss1.ConfigSocketS(port);

		 if(sock_err != SOCKET_ERROR)
		 {
			sock_err = Ss1.Listage(5);
			cout << "Utilisation du port " << port << endl;
			if(sock_err != SOCKET_ERROR)
			{
				cout << "Patientez pendant que le client se connecte sur le port "<< port << endl;
				Ss1.AccepterClient();
				cout << "Un client se connecte sur la socket " << Socket <<endl;

				//sock_err = Socket1.Reception(buffer, 32);

				/*if(sock_err != SOCKET_ERROR)
				{
					cout << "Recu : " << buffer;
				}
				else
				{
					cout << "Probleme de reception du message" << endl;
				}*/

				do {
					sock_err = Ss1.Reception(buffer, 32);
					if ( sock_err > 0 )
						cout << "Recu : " << buffer << endl;
					else if ( sock_err == 0 )
						printf("Connection closed\n");
					else
						printf("recv failed: %d\n", WSAGetLastError());
				} while( sock_err > 0 );


			}
		 }
	}
}
