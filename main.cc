#include <iostream>
#include "persona.h"
#include "crupier.h"
#include "jugador.h"
#include "ruleta.h"
#include <string>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <unistd.h>
using namespace std;


//Compilación g++  persona.cc jugador.cc crupier.cc ruleta.cc main.cc -o ruleta



int main(){

	//Seleccionador del menu
	int opcion=0;

	//Declaraciones de las variables
	int jugadoresTotal=0, tipo, banca, dineroJ,  cantidad, sumaDineroTotal=0, tiradasTotales=0, bancaTotal=0, s, r, y, x, i, dinero=0, controlador=0, nApuestas=0;
	string DNI,nombre,codigoCrupier,codigoJugador,apellidos,direccion,localidad,provincia,pais, string, valor, apellido2;

	


	//Declaracion de una Apuesta
	Apuesta bet;

	//Apertura de ficheros en modo escritura
	ofstream bets;
	ofstream dni;

	//Declaraciones de los objetos
	Persona p(DNI, nombre, apellidos, direccion, localidad, provincia, pais);
	Crupier c(DNI, codigoCrupier, nombre, apellidos, direccion, localidad, provincia, pais);
	Jugador j(DNI, codigoJugador, nombre, apellidos, direccion, localidad, provincia, pais);
	Ruleta u(c);

	//Declaraciones de iteradores
	list<Jugador>newList;
	list<Jugador>::iterator it;
	list<Apuesta>::iterator ot;

	system("clear");
	
	cout<<"Con cuanto dinero empezará la banca... ";
	cin>>banca;
	u.setBanca(banca);


	do{
		getchar();
		cout<<"\nPulse para continuar...";
		getchar();
		system("clear");
		cout<<"----------------------------------------------\n";
		cout<<"Elija una opción de la Ruleta:\n";
		cout<<"1. Cargar la Ruleta con el registro\n";
		cout<<"2. Guardar en el Registro los jugadores\n";
		cout<<"3. Ver el estado de la Ruleta \n";
		cout<<"4. Jugar para ver los premios de cada jugador\n";
		cout<<"5. Imprimir los Jugadores y su Dinero\n";
		cout<<"6. Eliminar a un jugador de la mesa\n";
		cout<<"7. Añadir a un jugador a la mesa\n";
		cout<<"8. Añadir apuestas a un jugador de la mesa\n";
		cout<<"9. Salir del programa \n";
		cout<<"----------------------------------------------\n";

		cout<<"\n\nOpcion elegida: ";
		cin >> opcion;

		switch (opcion){
			case 1:
				cout<<"\n--------------------------------------------\n";
				cout<<"Ha elegido cargar los jugadores del fichero";
				u.leeJugadores();
				cout<<"\n--------------------------------------------\n";
				break;

			case 2:
				cout<<"\n-------------------------------------------------";
				cout<<"\nHa elegido guardar los jugadores en el fichero\n";
				u.escribeJugadores();
				cout<<"-------------------------------------------------\n";
				break;

			case 3:
				cout<<"\n----------------------------------------------------------";
				cout<<"\nHa elegido ver el estado de la ruleta, dinero y jugadores\n";
				u.getEstadoRuleta(jugadoresTotal, sumaDineroTotal, tiradasTotales, bancaTotal);
				cout<<"La ruleta tiene "<<jugadoresTotal<<" jugadores.\nEl dinero en la mesa actualmente es "<<sumaDineroTotal<<" €.\nLa bola se ha tirado " <<tiradasTotales<< " veces.\nEl dinero de la banca actualmente es "<<bancaTotal<<" €.\n";
				cout<<"----------------------------------------------------------\n";
				break;

			case 4:
				cout<<"\n---------------------------------------------------------------------------";
				cout<<"\nHa elegido jugar, ver los premios de cada jugador y el balance de la banca\n";
				u.giraRuleta();
				s=u.getBola();
				cout<<"La bola resultante ha sido: "<<s<<"\n";
				u.getPremios();
				newList=u.getJugadores();
				for(it=newList.begin(); it!=newList.end(); it++){
					if(u.getBets()<0)
						cout<<"El jugador con DNI "<<it->getDNI()<<" ha perdido "<<u.getBets()<<" €, saldo restante: "<<it->getDinero()<<" €\n\n";
					if(u.getBets()>0)
						cout<<"El jugador con DNI "<<it->getDNI()<<" ha ganado "<<u.getBets()<<" €, saldo restante: "<<it->getDinero()<<" €\n\n";
					if(it->getDinero()<0){
						cout<<"El jugador con DNI "<<it->getDNI()<<" tiene: "<<it->getDinero()<<" €, el jugador será eliminado de la ruleta\n\n";
						u.deleteJugador(it->getDNI());
						cout<<"Borrando jugador...\n\n";
						sleep(1);
						cout<<"Jugador Eliminado\n\n";
					}
				}
				y=u.getBanca();
				cout<<"La banca tiene "<<y<<" €\n";
				cout<<"---------------------------------------------------------------------------\n";
				break;
				
			case 5:
				cout<<"---------------------------------------------------------------------------\n";
				cout<<"\nHa elegido jugar ver a todos los jugadores\n";
				newList=u.getJugadores();
				for(it=newList.begin(); it!=newList.end(); it++)
					cout<<"El jugador con DNI "<<it->getDNI()<<" con codigo "<<it->getCodigo()<<" y el saldo restante es: "<<it->getDinero()<<" €\n\n";
				cout<<"---------------------------------------------------------------------------\n";
				break;


			case 6:
				cout<<"\n-------------------------------------------------";
				cout<<"\nHa elegido eliminar un jugador de la mesa \n";
				cout<<"Introduzca el dni del jugador que desea eliminar...\n";
				cin>>string;
		
				cout<<"Eliminado Jugador...\n";
				sleep(1);
				cout<<"Jugador Eliminado\n";
				cout<<"-------------------------------------------------\n";
				break;

			case 7:
				cout<<"\n--------------------------------------------\n";
				cout<<"\nHa elegido añadir un jugador a la mesa \n";
				cout<<"Introduzca su DNI...\n";
				cin>>string;
				j.setDNI(string);

				cout<<"\nIntroduzca su codigo...\n";
				cin>>string;
				j.setCodigo(string);

				cout<<"\nIntroduzca su nombre...\n";
				cin>>string;
				j.setNombre(string);
				
				cout<<"\nIntroduzca su primer Apellido...\n";
				cin>>string;
				
				cout<<"\nIntroduzca su segundo Apellido...\n";
				cin>>apellido2;
				apellidos=string+" "+apellido2;
				j.setApellidos(apellidos);

				cout<<"\nIntroduzca su Direción...\n";
				cin>>string;
				j.setDireccion(string);

				cout<<"\nIntroduzca su Localidad...\n";
				cin>>string;
				j.setLocalidad(string);

				cout<<"\nIntroduzca su Provincia...\n";
				cin>>string;
				j.setProvincia(string);

				cout<<"\nIntroduzca su Pais...\n";
				cin>>string;
				j.setPais(string);

				cout<<"\nIntroduzca el dinero de inicio...\n";
				cin>>dinero;
				j.setDinero(dinero);

				u.addJugador(j);

				cout<<"---------------------------------------------\n";
				break;

	 		case 8:
	 			cout<<"\n------------------------------------------------";
				cout<<"\nIntroduzca cuantas apuestas desea realizar...\n";
				cin>>s;
				cout<<"Introduzca el DNI del jugador para apostar\n";
				cin>>DNI;
				i=0;
				cout<<"Tipo de apuesta 1: Numero de la Bola\n";
				cout<<"Tipo de apuesta 2: Color \n";
				cout<<"Tipo de apuesta 3: Paridad(Par e Impar)\n";
				cout<<"Tipo de apuesta 4: Nivel(1-18(Bajo) y 19-36(Alto))\n";

				bets.open((DNI+".txt").c_str());
				do{
					cout<<"\nApuesta numero "<<i;

					cout<<"\nIntroduzca su tipo de apuesta-> ";
					cin>>bet.tipo;  

					cout<<"\nIntroduzca su valor de apuesta-> ";
					cin>>bet.valor;
						
					cout<<"\nIntroduzca su cantidad de apuesta-> ";
					cin>>bet.cantidad;

					bets<<bet.tipo<<","<<bet.valor<<","<<bet.cantidad<<"\n";
					j.setApuestas();

					i++;
					nApuestas++;
				}while(nApuestas<s);
				bets.close();
				cout<<"\n------------------------------------------------\n";
				break;

			

			case 9:  
				cout<<"\n------------------------";
				cout<<"\nAbandonando ruleta... \n";
				controlador=1;
				cout<<"------------------------\n";
				break;

		 	default:
		 		cout<<"\n-------------------------------------------";
				cout<<"\nElección incorrecta, abandonando ruleta... \n";
				controlador=1;
				cout<<"-------------------------------------------\n";
				break;
				
		}
	}while(controlador!=1);
	return 0;
}
