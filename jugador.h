#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "persona.h"

using namespace std;

struct Apuesta{
int tipo;
string valor;
int cantidad;
};

class Jugador: public Persona{	//It inherit Persona public functions

private:
string  codigo_;
int dinero_;
list<Apuesta>apuestas_;	//Apuestas list declared

public:
inline Jugador(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=1000;}
//inline Jugador(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=1000;}

	inline void setCodigo(string codigo){codigo_=codigo;}
	inline string getCodigo() const {return codigo_;}	//It will return const codigo private value

	inline void setDinero(int Dinero){dinero_=Dinero;}
	inline int getDinero(){return dinero_;}	//It will return dinero private value

	void setApuestas();
	inline list<Apuesta> getApuestas() const {return apuestas_;}	//It will return const apuestas private value
	void apuestasJ();
	void apuestaSaved(Apuesta bet);
	
};

#endif
