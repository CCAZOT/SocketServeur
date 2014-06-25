#include "ServeurSocket.h"


CServeurSocket::CServeurSocket(void)
{
}


CServeurSocket::~CServeurSocket(void)
{
}

SOCKET CServeurSocket::CreerSocketS()
{
	Socket = socket(AF_INET, SOCK_STREAM, 0);	
	return(Socket);
}

int CServeurSocket::ConfigSocketS(int Port)
{
	sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
    sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
    sin.sin_port = htons(Port);               /* Listage du port */
	recsize = sizeof(sin);
    sock_err = bind(Socket, (SOCKADDR*)&sin, recsize);

	return(sock_err);
}

int CServeurSocket::Listage(int TailleMax )
{
	 sock_err = listen(Socket, TailleMax);
	 return(sock_err);
}

SOCKET CServeurSocket::AccepterClient(void)
{
	crecsize = sizeof(sin);
	CSocket = accept(Socket, (SOCKADDR*)&csin, &crecsize);
	printf("Un client se connecte avec la socket %d de %s:%d\n", CSocket, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
	return(Socket);
}

bool CServeurSocket::recv_SocketDelivrance(void)
{
	return false;
}


bool CServeurSocket::recv_SocketConnexion(void)
{
	return false;
}
