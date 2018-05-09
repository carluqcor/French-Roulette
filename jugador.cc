#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <stdlib.h> 
#include "jugador.h"
#include "persona.h"

using namespace std;

/*
Proc Set new bets to the players list, writing in a file their bets
Require true
Modify This fuction modify list Apuesta. tipo, valor and cantidad char value. File with bets value. 
*/
void Jugador:: setApuestas(){
	apuestas_.clear(); //Clear apuestas_ list
	string DNI=(getDNI()+".txt");
	ifstream entrada(DNI.c_str());	//It will read file DNI.txt
	struct Apuesta p;
	char tipo[10], valor[10], cantidad[10];
	
	while(entrada.getline(tipo, 256, ',')){
		p.tipo = atoi(tipo);	//Convert char value to int value
		entrada.getline(valor, 256, ',');
		p.valor = valor;
		entrada.getline(cantidad, 256, '\n');
		p.cantidad = atoi(cantidad);	//Convert char value to int value
        apuestas_.push_back(p);	//It will push to the back of the list
	}
entrada.close();	//It closes entrada output file
}
