#include "Socket.h"
#include <iostream>
using namespace std;


Socket::Socket(void)
{
	int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);			//La macro MAKEWORD transforme les deux entiers (d'un octet)
																//qui lui sont passés en paramètres en un seul entier (de 2 octets)
																//qu'elle retourne. Elle retourne la valeur 0 si tout s'est bien passé.
}

Socket::~Socket(void)
{
	WSACleanup();
	shutdown(CSocket, 2);										//Cette fonction va simplement libérer les ressources
																//allouées par la fonction WSAStartup()

    closesocket(CSocket);

    closesocket(Socket);

}

void Socket::FermerConnexion(SOCKET Socket)
{
	closesocket(Socket);
}

int Socket::Reception(char *bufferR,int TailleBuf )
{
	memset(bufferR,0,TailleBuf);
	sock_err = recv(CSocket, bufferR, TailleBuf, 0);			//Dernier parametre : flags = 0.
	return(sock_err);

}

int Socket::Envoie(char *bufferE, int TailleBuf, int flag)
{
	sock_err = send(Socket, bufferE, TailleBuf, flag);
	return(sock_err);
}


SOCKADDR_IN Socket::GetSin(void)
{
	return (sin);
}


SOCKET Socket::GetSocket(void)
{
	return (Socket);
}
