#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "persona.h"
#include "crupier.h"
#include "jugador.h"
#include "ruleta.h"

using namespace std;
Ruleta::Ruleta(Crupier crupier):crupier_(crupier)	//Constructor
{
	srand(time(NULL));
	bola_=-1;
	banca_=1000000;
	tiradas_=0;
}
/*
It will return false or true, depends if bola is between 0-36
*/
bool Ruleta::setBola(int bola)
{
	if(bola<0 || bola>36)
		return false;
	else
		bola_=bola;
		tiradas_++;
		return true;
}
/*
It will return false or true, depends if banca is above 0
*/
bool Ruleta::setBanca(int banca)
{
	if(banca<0)
		return false;
	else
		banca_=banca;
		return true;
}

/*
Proc: It will verify if DNI file from such player is created.
If its not created, it will create and return true, if it exits it will return true and if dniJugador
and introduced if isnt the same, it will return false
Modify: Jugador list
*/
bool Ruleta::addJugador(Jugador jugador) //It receives a player from jugador.h as a parameter
{
	for(list<Jugador>::iterator it=jugadores_.begin(); it != jugadores_.end(); it++){ //Verify that Player isnt in the list(It creates Jugadores) list with iterator it as a 'name' and it will iterate while it is different than list funcion .end, it sum it++)
		if(it->getDNI()==jugador.getDNI())
			return false;
  }
	//If it isn't exists the Player, it will added with push_back
	jugadores_.push_back(jugador);
	string name=(jugador.getDNI() + ".txt");
	ifstream DNI;
	DNI.open(name.c_str());	//It opens in write mode
	//Si usamos un string, luego habrá que usar .c_str()

	if(DNI)
		return true; //File exists
	else
	{
		ofstream DNIj; //It creates file
		DNIj.open(name.c_str());	//It doesnt exist
		DNIj.close();
	}
return true;
}
/*
It will erase the list from the beginning and it will go over the list with the iterator it, when the introduced dni is the same, it will delete with .erase(it)
*/
int Ruleta::deleteJugador(string DNIj)
{
	list<Jugador>::iterator it;
	if(jugadores_.empty())	//Verify if list is empty
		return -1;
	for(it=jugadores_.begin(); it != jugadores_.end(); it++)
	{
		if(it->getDNI()==DNIj)	//If Dni of it is equals than DNIj
		{
			jugadores_.erase(it);	//It will erase the element linked with it and DNIj
			return 1;	//Player erased
		}
	}
	return -2;	//Player already doesnt exit
}

int Ruleta::deleteJugador(Jugador jugador)
{
	return(deleteJugador(jugador.getDNI()));
}

/*
It will create a file named jugadores.txt and it will push from the back all the elements that a player and a croupier have.
*/
void Ruleta::escribeJugadores()
{
	list<Jugador>::iterator it;
	ofstream ent;
	ent.open("jugadores.txt");
	for(it=jugadores_.begin(); it!=jugadores_.end(); it++)
	ent<<it->getDNI()<<","<< it->getCodigo()<<","<< it->getNombre()<<","<< it->getApellidos()<<","<< it->getDireccion()<<","<< it->getLocalidad()<<","<< it->getProvincia()<<","<< it->getPais()<<","<< it->getDinero()<<endl;
	/*It will be displayed like this
	DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero	(Spanish)
	ID,code,name,surnames,adress,locality,province,country,money			(English)*/
	ent.close();//It will close ent file
}
/*
It will read all the elements from the file jugadores.txt and it will push from the back to the list
*/
void Ruleta::leeJugadores()
{
	ifstream jug;
	string DNI, nombre, codigo, apellidos, direccion, localidad, provincia, pais, dinero;
	Jugador jugador("", "", "", "", "", "", "", "");
	jugadores_.clear();
	jug.open("jugadores.txt");
	while(getline(jug, DNI, ','))
	{
		jugador.setDNI(DNI);

		getline(jug, codigo, ',');
		jugador.setCodigo(codigo);

		getline(jug, nombre, ',');
		jugador.setNombre(nombre);

		getline(jug, codigo, ',');
		jugador.setApellidos(apellidos);

		getline(jug, apellidos, ',');
		jugador.setDireccion(direccion);

		getline(jug, direccion, ',');
		jugador.setLocalidad(localidad);

		getline(jug, localidad, ',');
		jugador.setProvincia(provincia);

		getline(jug, provincia, ',');
		jugador.setPais(pais);

		getline(jug, dinero, '\n');
		jugador.setDinero(atoi(dinero.c_str()));

	    jugadores_.push_back(jugador);	//It will push to the back of the list
	}
	jug.close();
}
/*
It will spin the roulette and throw the ball
*/
void Ruleta::giraRuleta()
{
	bola_=rand()%37;	//Random number from 0 to 36
	tiradas_++;
}

/*
Bet for ball number
*/
void Ruleta::apuestaSencilla(int &dinero, Apuesta p)
{
	if(bola_==atoi(p.valor.c_str()))	//If bola value is equal to struct valor value
	{
		dinero = dinero + (p.cantidad)*35;
		banca_ = banca_ -(p.cantidad)*35;
	
	}else
	{
		dinero = dinero - (p.cantidad);
		banca_ = banca_ + (p.cantidad);
	
	}
}

/*
Bet for colour number
*/
void Ruleta::apuestaRojoyNegro(int &dinero, Apuesta p)
{
	if((bola_!=0 && p.valor==color(bola_)))	//If bola is different than 0 and colour bola value is equal to struct valor value
	{
		dinero = dinero + (p.cantidad);
		banca_ = banca_ - (p.cantidad);
		

	}else{
		dinero = dinero - (p.cantidad);
		banca_ = banca_ + (p.cantidad);
		;

	}
}

/*
Bet for number
*/
void Ruleta::apuestaImparypar(int &dinero, Apuesta p){
	if((bola_!=0 && p.valor==paridad(bola_))){	//If bola is different than 0 and paridad bola value is equal to struct valor value
		dinero = dinero + (p.cantidad);
		banca_ = banca_ - (p.cantidad);
	

	}else{
		dinero = dinero - (p.cantidad);
		banca_ = banca_ + (p.cantidad);
		

	}
}

string Ruleta::paridad(int bola){
	if(bola%2==0)
		return "par";
	else
		return "impar";
}

void Ruleta::apuestaAltoyBajo(int &dinero, Apuesta p){
	if(bola_!=0 && p.valor==nivel(bola_)){	//If bola is different than 0 and nivel bola value is equal to struct valor value
		dinero = dinero + (p.cantidad);
		banca_ = banca_ - (p.cantidad);
		

	}else{
		dinero = dinero - (p.cantidad);
		banca_ = banca_ + (p.cantidad);
	}
}

string Ruleta::nivel(int bola){
if(bola>0 && bola<19)
	return "bajo";
else
	return "alto";
}

string Ruleta::color(int bola){
	switch(bola){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 12:
		case 14:
		case 16:
		case 18:
		case 19:
		case 21:
		case 23:
		case 25:
		case 27:
		case 30:
		case 32:
		case 34:
		case 36:
			return "rojo";
		default:
			return "negro";
	}
}

/*
This fuction will save bets and sum with the currently money of the player to resave the money of them
*/
void Ruleta::getPremios(){
	list<Apuesta>apuestaslist;
	list<Jugador>::iterator it;
	list<Apuesta>::iterator ot;
	for(it=jugadores_.begin(); it != jugadores_.end(); it++){
		int dinero=0;
		it->setApuestas();
		apuestaslist=it->getApuestas();
		dinero=it->getDinero();
		for(ot=apuestaslist.begin(); ot != apuestaslist.end(); ot++){
			switch (ot->tipo){
				case 1:
					apuestaSencilla(dinero, (*ot));
					break;

				case 2:
					apuestaRojoyNegro(dinero, (*ot));
					break;

				case 3:
					apuestaImparypar(dinero, (*ot));
					break;

				case 4:
					apuestaAltoyBajo(dinero, (*ot));
					break;
			}
		it->setDinero(dinero);
		escribeJugadores();
		}
	}
}

/*This fuction it will return bets value without sum the money of the player*/
int Ruleta::getBets(){
	list<Apuesta>apuestaslist;
	list<Jugador>::iterator it;
	list<Apuesta>::iterator ot;
	int dinero;
	for(it=jugadores_.begin(); it != jugadores_.end(); it++){
		dinero=0;
		it->setApuestas();
		apuestaslist=it->getApuestas();
		for(ot=apuestaslist.begin(); ot != apuestaslist.end(); ot++){
			switch (ot->tipo){
				case 1:
					apuestaSencilla(dinero, (*ot));
					break;

				case 2:
					apuestaRojoyNegro(dinero, (*ot));
					break;

				case 3:
					apuestaImparypar(dinero, (*ot));
					break;

				case 4:
					apuestaAltoyBajo(dinero, (*ot));
					break;
			}	
		}
	}
	return dinero;
}

/*
It will return money valye of all players
*/
int Ruleta::dineroJug(int dinero){
	list<Jugador>::iterator it;
	for(it=jugadores_.begin(); it != jugadores_.end(); it++){
		dinero=it->getDinero();
	}
	return dinero;
}

void Ruleta::getEstadoRuleta(int &jugadoresTotal, int &sumaDinero, int &tiradasTotales, int &bancaTotal){
	list<Jugador>::iterator it;
	sumaDinero=0;
	for(it=jugadores_.begin(); it != jugadores_.end(); it++)
		sumaDinero=sumaDinero+it->getDinero();

	sumaDinero=sumaDinero+getBanca();

	jugadoresTotal=jugadores_.size();

	tiradasTotales=getTiradas();

	bancaTotal=getBanca();
}
