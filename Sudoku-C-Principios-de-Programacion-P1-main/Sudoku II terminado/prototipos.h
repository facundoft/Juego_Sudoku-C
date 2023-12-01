#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "estructuras.h"

bool RegionValida2(int regionF, int regionC,int candidatoF,int candidatoC,int k,int s[9][9]);


bool RegionValida(int regionF, int regionC,int s[9][9]);


int Celda_Region(int celda);
// Recibe una fila o columna y devuelve la primera fila o columna de su region

bool es_candidato2 (int s [9][9], int num, int fila, int columna);
/* Devuelve true si 'num' es candidato para la celda del Sudoku 's' dada por 'fila' y 'columna', o
false en caso contrario. La celda viene cargada con el dato a evaluar*/

void Candidato_Exclusivo (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand);
/* Dada la fila y la columna, encuentra los candidatos para esa celda vacía y los registra en el
arreglo 'candidatos'. A modo de ejemplo si el conjunto de candidatos es {1,3,4,9} --> 'candidatos'
= [true,false,true,true,false,false,false,false,true]*/

bool Candidato_Unico (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand);


void inicializar_sudoku (int s [9][9]);
// Inicializa el Sudoku \u2018s\u2019 llenando todas las celdas con el valor 0.

void imprimir_sudoku (int s [9][9]);
// Imprime el Sudoku en pantalla con un formato matricial mostrando la separación entre regiones.

void generar_sudoku_valido (int s [9][9]);
/*Genera aleatoriamente un nuevo Sudoku \u2018s\u2019 con la cantidad de elementos \u2018cant_elem\u2019. Si
\u2018cant_elem\u2019 = 81 entonces se genera un sudoku resuelto. Debe variar las generaciones cada vez
que se lo invoque. En las celdas que no se genera un elemento debe figurar el 0.*/

void Candidato_Exclusivo (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand);
/* Dada la fila y la columna, encuentra los candidatos para esa celda vacía y los registra en el
arreglo 'candidatos\u2019. A modo de ejemplo si el conjunto de candidatos es {1,3,4,9} --> \u2018candidatos\u2019
= [true,false,true,true,false,false,false,false,true]*/

bool es_candidato (int s [9][9], int num, int fila, int columna);
/* Devuelve true si \u2018num\u2019 es candidato para la celda del Sudoku \u2018s\u2019 dada por \u2018fila\u2019 y \u2018columna\u2019, o
false en caso contrario. La celda debe ser vacía.*/

bool sudoku_valido (int s [9][9]);
/*Devuelve true si el tablero \u2018s\u2019 cumple con los requisitos de un Sudoku válido (unicidad en filas,columnas y regiones), o false en 
caso contrario. El tablero puede estar incompleto, en ese caso las celdas vacías se representan con 0.*/

bool sudoku_resuelto (int s [9][9]);
// Devuelve true si el tablero está completamente resuelto, o false en caso contrario

void Menu();
// Imprime el Menu principal de programa

void subMenu();
// Imprime el Menu de selector de dificultad

int opcion();
// Guarda la opcion del Menu

void IngresaNombre_Nick(Usuario_inf usuario[usuarios_cant], int j,int &usuarioCant);
// Ingresa el nombre del ususario

palabra IngresaNick(palabra &usuario, int j);
// Ingresa el nick del usuario

void MostrarNombre_Nick(Usuario_inf usuario[usuarios_cant], int j);
// Muestra el nombre del usuario

palabra IngresaNombre(palabra &usuario);
// Ingresa el nombre del usuario

void MostrarNombre(Usuario_inf usuario);
// Muestra el nick del usuario

void InicializaNick(Usuario_inf usuario[usuarios_cant],int j);
// Funcion que inicializa el nick del usuario en 0

void InicializaNombre(Usuario_inf usuario[usuarios_cant],int j);
// Funcion que inicializa el nombre del usuario en 0 

void InicializaPuntaje(Usuario_inf usuario[usuarios_cant],int j);
// Funcion que inicializa el puntaje del usuario en 0

void nivel(int &dificultad);
// Guarda la dificultad que elijio el usuario

bool IngresaNick2(char Registrado[N],Usuario_inf usuario[usuarios_cant],int largo, int usuarioCant,int &Jugador);
// Ingresa el nick

bool IniciaSesion(Usuario_inf usuario[usuarios_cant], int usuarioCant,int &Jugador,bool SesionInciada);
// Funcion que inicia sesion si el nick ingresado no fue registrado por otro usuario

void sudoku_noresuelto (int s [9][9], int cant_elem);
// Imprime un Sudoku 's' no resuelto

void Jugar(Usuario_inf usuario[usuarios_cant], int Jugador);
// Funcionamiento del Juego

void Ranking(Usuario_inf usuario[usuarios_cant], int usuarioCant, int Jugador);
// Muestra el Ranking segun los puntos

bool EstaRegistrado(char Registrado[N],Usuario_inf usuario[usuarios_cant],int largo, int usuarioCant);
// Funcion que verifica si el nick que fue ingresado esta registrado o si no

void ListarUsuario(Usuario_inf usuario[usuarios_cant], int usuarioCant);
// Imprime la lista de usuarios

void MostrarNombre_Nick2(Usuario_inf usuario[usuarios_cant], int j);
// Muestra el nick y nombre del usuario en Lista de Usuarios

void MostrarSesion(Usuario_inf usuario[usuarios_cant],int Jugador);
// Muestra que usuario ha ingresado sesion

#endif
