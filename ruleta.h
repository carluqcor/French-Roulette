#ifndef RULETA_H_
#define RULETA_H_
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include "persona.h"
#include "crupier.h"
#include "jugador.h"
using namespace std;


class Ruleta{
private:
	int banca_, bola_, tiradas_;
	list <Jugador>jugadores_;
	Crupier crupier_;

public:
	Ruleta(Crupier crupier);	//Crupier's name
	inline int getBola() const {return bola_;}
	bool setBola(int bola);
	inline int getBanca() const {return banca_;}
	bool setBanca(int banca);

	inline Crupier getCrupier() const {return crupier_;}
	inline void setCrupier(Crupier crupier){crupier_=crupier;}	//This fuction receive a Crupier from Crupier.h as a parameter

	inline list<Jugador> getJugadores() const {return jugadores_;}
	bool addJugador(Jugador jugador);

	//It will overcharge the functions with differents parameter
	int deleteJugador(string DNIj);
	int deleteJugador(Jugador jugador);
	void escribeJugadores();
	void leeJugadores();
	void giraRuleta();
	void getPremios();
	void apuestaSencilla(int &dinero, Apuesta p);
	void apuestaRojoyNegro(int &dinero,  Apuesta p);
	void apuestaImparypar(int &dinero, Apuesta p);
	void apuestaAltoyBajo(int &dinero,  Apuesta p);
	string paridad(int bola);
	string nivel(int bola);
	string color(int bola);
	inline int getTiradas() const{return tiradas_;}
	int dineroTotal(int sumaDinero=0);
	void getEstadoRuleta(int &jugadoresTotal, int &sumaDinero, int &tiradasTotales, int &bancaTotal);
	int dineroJug(int dinero=0);
	int getBets();
};
#endif
