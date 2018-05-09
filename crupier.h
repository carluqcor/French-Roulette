#ifndef CRUPIER_H_
#define CRUPIER_H_

#include <string>
#include "persona.h"

class Crupier: public Persona{	//It inherited from public Persona

private:
std::string Codigo_;

public:
inline Crupier(std::string DNI, std::string Codigo, std::string nombre="", std::string apellidos="", std::string direccion="", std::string localidad="", std::string provincia="", std::string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){Codigo_=Codigo;}	//Constructor can be here at inline function

	inline void setCodigo(std::string Codigo){Codigo_=Codigo;}	//This function will save public Code into private Code 
	inline std::string getCodigo() const {return Codigo_;}		//THis fuction will return private Code
};
#endif
