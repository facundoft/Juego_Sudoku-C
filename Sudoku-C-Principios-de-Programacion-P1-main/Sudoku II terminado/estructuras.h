#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

/* Constante que define la cantidad maxima de letras
que puden ser ingresadas en el arreglo letra*/
#define N 15

/* Constante que define la cantidad maxima
de usuarios que puedes ser registrados*/
#define usuarios_cant 50

/* Estructura de tipo palabra que guarda las
letras en un arreglo y el largo de la palabra 
en una variable entera*/
typedef struct {
	char letra[N];
	int largo;
}palabra;

/* Estructura de tipo Usuario_inf que guarda
toda la informacion del usuario registrado*/
typedef struct {
	palabra Nombre;
	palabra Nick;
	int cantidad;
	int puntos;
}Usuario_inf;

#endif
