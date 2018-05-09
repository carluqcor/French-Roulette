#include <iostream>
#include <string>
#include "persona.h"

//Constructor declaration
Persona:: Persona(std::string DNI, std::string nombre, std::string apellidos, std::string direccion, std::string localidad, std::string provincia, std::string pais){
	DNI_=DNI;
	nombre_=nombre;
	apellidos_=apellidos; 
	direccion_=direccion; 
	localidad_=localidad; 
	provincia_=provincia;
	pais_=pais;
}

//Fuction to link Surnames with name
std::string Persona:: getApellidosyNombre()
{
	std::string cad1,cad2,cad3;
	cad1=nombre_;
	cad2=apellidos_;
	cad3=cad2+", "+cad1;	//Linking
	return cad3;		//Return linked cad
}
