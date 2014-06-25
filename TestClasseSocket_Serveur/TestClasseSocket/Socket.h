#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>


typedef int socklen_t;					 //sert à stocker la taille d'une structure de
										 //type sockaddr_inclass CPharmaSocket
class Socket{
public:
	Socket(void);
	~Socket(void);
protected:
	WSADATA WSAData;				//sert à initialiser la bibliothèque WinSock.
	/* Socket et contexte d'adressage du serveur ou du Client */
	SOCKADDR_IN sin;
	SOCKET Socket;
	SOCKET CSocket;
	SOCKADDR_IN csin;
	socklen_t crecsize;
	socklen_t recsize;
	int erreur;
	int sock_err;		//Attribut utiliser comme valeur de retour. Permet de tester le bon fonctionement de la socket
	int PORT;			//Attribut permettant de saisir le port sur lequelle le serveur ecoutera
public:
	void FermerConnexion(SOCKET Socket);				//Permet de Fermer les socket
	int Reception(char *bufferR,int TailleBuf);			//Methode permettant de recevoir les informations envoyés par le serveur.
	int Envoie(char *bufferE, int TailleBuf, int flag);	//Methode permettant d'envoyer l
	SOCKADDR_IN GetSin(void);
	SOCKET GetSocket(void);
};

