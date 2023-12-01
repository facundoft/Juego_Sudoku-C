#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "prototipos.h"
#include "estructuras.h"
#define N 15
#define usuarios_cant 50

/* Colores

reset               0
bold\bright         1
underline           4 
inverse             7
bold\bright off     21
underline off       24
inverse off         27

forgeground   background
black        30            40
red          31            41
green        32            42
yellow       33            43
blue         34            44
magenta      35            45
cyan         36            46
white        37            47

*/

using namespace std;

int main (int argc, char *argv[]) {
	char finalizar;
	int j,eleccion;
	int usuarioCant=0;
	int Jugador=0;
	bool SesionInciada=false;
	Usuario_inf usuario[usuarios_cant];
	srand(time(NULL));
	//comprobacion de funcionamiento
	//printf("El sudoku esta resuelto o no: %d \n",sudoku_resuelto (matriz));
	//printf("El sudoku es valido o no: %d \n",sudoku_valido (matriz));
		
		j=0;
		InicializaNick(usuario,j);
		InicializaNombre(usuario,j);
		InicializaPuntaje(usuario,j);
		
		printf("\n\n");
		Menu();
		do{
			eleccion=opcion();
			switch(eleccion){
			case 1:
				j=usuarioCant;
				if(SesionInciada){
					system("clear");
					MostrarSesion(usuario,Jugador);
					printf("\033[1;40m");
					printf("\n\n\n\t\t\t\t\tRegistro\n\n");
					printf("\033[1;0m");
					printf("\t\t\t\tCree su nick y presione enter\n");
					printf("\t\t\t\tIngrese su nombre y presione enter\n\n");
					IngresaNombre_Nick(usuario,j,usuarioCant);
					system("clear");
					MostrarSesion(usuario,Jugador);
					printf("\n\n");
					Menu();
				}
				else{
					system("clear");
					printf("\033[1;40m");
					printf("\n\n\n\t\t\t\t\tRegistro\n\n");
					printf("\033[1;0m");
					printf("\t\t\t\tCree su nick y presione enter\n");
					printf("\t\t\t\tIngrese su nombre y presione enter\n\n");
					IngresaNombre_Nick(usuario,j,usuarioCant);
					system("clear");
					printf("\n\n");
					Menu();
				}
				break;
			case 2:
				if(usuarioCant==0){
					system("clear");
					printf("\n\n");
					Menu();
					printf("\n\n\t\t\terror: No hay jugadores registrados aun, presione 1 \n\t\t\t	y luego enter para registrarse \n");
				}
				else{
					system("clear");
					if(SesionInciada){
						MostrarSesion(usuario,Jugador);
					}
					ListarUsuario(usuario,usuarioCant);
					system("clear");
					if(SesionInciada){
						MostrarSesion(usuario,Jugador);
					}
					printf("\n\n");
					Menu();
				}
				break;
			case 3:
				system("clear");
				printf("\n\n");
				Menu();
				if(usuarioCant==0){
					printf("\n\n\t\t\terror: No hay jugadores registrados aun, presione 1 \n\t\t\t	y luego enter para registrarse \n");
				}
				else{
					system("clear");
					printf("\033[1;40m");
					printf("\n\n\n\t\t\t\t\tIniciar Sesion\n\n");
					printf("\033[1;0m");
					printf("\t\t\t\tIngrese su nick: ");
					SesionInciada=IniciaSesion(usuario,usuarioCant,Jugador,SesionInciada);
					if(SesionInciada){
						system("clear");
						MostrarSesion(usuario,Jugador);
						printf("\n\n");
						Menu();
					}
				}
				break;
			case 4:
				if(SesionInciada){
					MostrarSesion(usuario,Jugador);
					subMenu();
					Jugar(usuario,Jugador);
					
				}
				else{
					system("clear");
					printf("\n\n");
					Menu();
					printf("\n\n\t\t\terror: Inicie sesion para jugar, presione 3 \n\t\t\t	y luego enter para iniciar sesion \n");
				}
				break;
			case 5:
				if(SesionInciada){
					system("clear");
					MostrarSesion(usuario,Jugador);
					printf("\n\n");
					Menu();
					if(usuario[Jugador].Nick.largo!=0){
						system("clear");
						MostrarSesion(usuario,Jugador);
						printf("\033[1;40m");
						printf("\n\n\n\t\t\t\tInformacion de Usuario\n\n");
						printf("\033[1;0m");
						MostrarNombre_Nick(usuario,Jugador);
						printf("\n\n\t\t\tPresione enter para regresar al menu . . .");
						scanf("%c",&finalizar);
						system("clear");
						MostrarSesion(usuario,Jugador);
						printf("\n\n");
						Menu();
					}
					else{
						printf("\n\n\t\t\tPrimero debe iniciar sesion, presione 3 \n\t\t\t	y luego enter para iniciar sesion \n");
					}
					
				}
				else{
					system("clear");
					printf("\n\n");
					Menu();
					printf("\n\n\t\t\terror: Inicia sesion para ver su informacion, presione 3 \n\t\t\t	y luego enter para iniciar sesion \n");
				}
				break;
			case 6:
				if(usuarioCant==0){
					system("clear");
					printf("\n\n");
					Menu();
					printf("\n\n\t\t\terror: No hay jugadores registrados aun, presione 1 \n\t\t\t	y luego enter para registrarse \n");
				}
				else{
					if(SesionInciada){
					MostrarSesion(usuario,Jugador);
					}
					Ranking(usuario,usuarioCant,Jugador);
					system("clear");
					if(SesionInciada){
						MostrarSesion(usuario,Jugador);
					}
					printf("\n\n");
					Menu();
				}
				break;
			case 7:
				system("clear");
				printf("Gracias por jugar SUDOKU");
				break;
			}
		}while(eleccion!=7);
	return 0;
}

