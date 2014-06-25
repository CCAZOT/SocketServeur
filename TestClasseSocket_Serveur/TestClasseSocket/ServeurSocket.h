#pragma once
#include "Socket.h"

class CServeurSocket: public CPharmaSocket
{

private:
	int PORT;			//Attribut permettant de saisir le port sur lequelle le serveur ecoutera

public:

	CServeurSocket(void);
	~CServeurSocket(void);
	SOCKET CreerSocketS(void);										//Methode permettant de creer un socket.
	int ConfigSocketS(int Port);		//Methode permettant de configurer un socket.
	int Listage(int TailleMax );				//Methode permettant de lister les ports.
	SOCKET AccepterClient(void);
	bool recv_SocketDelivrance(void);
	bool recv_SocketConnexion(void);
};

