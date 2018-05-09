#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>
using namespace std;
class Persona{

private:
	string DNI_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;


public:
	Persona(string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""); //Constructor
	//Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais); //Construc
	inline void setDNI(string DNI){DNI_=DNI;}	//This function will save public DNI into private DNI
	inline string getDNI() const {return DNI_;}	//This fuction will return Private DNI

	inline void setNombre(string nombre){nombre_=nombre;}	//This function will save public Name into private Name
	inline string getNombre() const {return nombre_;}		//This fuction will return Private Name

	inline void setApellidos(string apellidos){apellidos_=apellidos;}   //This function will save public Surnames into private Surnames
	inline string getApellidos() const {return apellidos_;}				 //This fuction will return Private Surnames

	inline void setDireccion(string direccion){direccion_=direccion;}	//This function will save public Adress into private Adress
	inline string getDireccion() const {return direccion_;}				//This fuction will return Private Adress

	inline void setLocalidad(string localidad){localidad_=localidad;}	//This function will save public Locatity into private Locatity
	inline string getLocalidad() const {return localidad_;}				//This fuction will return Private Locality

	inline void setProvincia(string provincia){provincia_=provincia;}	//This function will save public Province into private Province
	inline string getProvincia(){return provincia_;}				//This fuction will return Private Province

	inline void setPais(string pais){pais_=pais;}	//This function will save public Country into private Country
	inline string getPais(){return pais_;}	//This fuction will return Private Country

	string getApellidosyNombre();	//This fuction will link Surnames and Name with a ','
};
#endif
