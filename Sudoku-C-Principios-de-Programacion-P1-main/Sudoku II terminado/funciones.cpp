//Integrantes: Bruno Roldos, 50496372. Matias Alfaro 56631512.
#include<iostream>
#include<stdlib.h>
#include "estructuras.h"
#include "prototipos.h"
#include<stdio_ext.h> 
#define N 15
#define X 5
#define usuarios_cant 50
bool RegionValida2(int regionF, int regionC,int candidatoF,int candidatoC,int k,int s[9][9]);
bool RegionValida(int regionF, int regionC,int s[9][9]);
int Celda_Region(int celda);
bool es_candidato2 (int s [9][9], int num, int fila, int columna);
void Candidato_Exclusivo (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand);
bool Candidato_Unico (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand);

void nivel(int &dificultad){
	switch(dificultad){
	case 1:
		dificultad=81-70; // Dificultad Muy Facil
		break;
	case 2:
		dificultad=81-60; // Dificultad Facil
		break;
	case 3:
		dificultad=81-50; // Dificultad Normal
		break;
	case 4:
		dificultad=81-35; // Dificultad Dificil
		break;
	case 5:
		dificultad=81-30; // Dificultad Muy Dificil
		break;
	case 6:
		dificultad=81-25; // Dificultad Extremo
		break;
	}
}

// Imprime el Menu principal del programa
void Menu(){
	printf("\033[1;40m");
	printf("\n\t\t\t\t\tMenu \n\n");
	printf("\033[1;0m");
	printf("\t\t\t\t1. Registro de usuario \n");
	printf("\t\t\t\t2. Lista de usuarios\n");
	printf("\t\t\t\t3. Inicie Sesion \n");
	printf("\t\t\t\t4. Jugar \n");
	printf("\t\t\t\t5. Ver informacion de usuario \n");
	printf("\t\t\t\t6. Ver Ranking \n");
	printf("\t\t\t\t7. Salir \n");
}

// Imprime el Menu de selector de dificultad
void subMenu(){
	system("clear");
	printf("\033[1;40m");
	printf("\n\n\n\t\t\t\t\tSelector de Dificultad \n\n");
	printf("\033[1;0m");
	printf("\t\t\t\t1. Muy Facil \n");
	printf("\t\t\t\t2. Facil \n");
	printf("\t\t\t\t3. Normal \n");
	printf("\t\t\t\t4. Dificil \n");
	printf("\t\t\t\t5. Muy dificil \n");
	printf("\t\t\t\t6. Extremo \n");
}
	
// Guarda la opcion del Menu
int opcion(){
	int i;
	scanf("%d",&i);
	__fpurge(stdin);
	return i;
}	
	
// Muestra que usuario ha iniciado sesion
void MostrarSesion(Usuario_inf usuario[usuarios_cant],int Jugador){
	int z=0;
	printf("\033[1;30m");
	printf("\033[7;32m");
	printf("\t\t\t\tSe ha iniciado sesion con ");
	for(z=0;z<usuario[Jugador].Nick.largo;z++){
		printf("%c",usuario[Jugador].Nick.letra[z]);
	}
	printf("\033[1;0m");
	printf("\033[7;0m");
}
	
// Ingresa el nombre del usuario
void IngresaNombre_Nick(Usuario_inf usuario[usuarios_cant], int j,int &usuarioCant){
	int i,e;
	i=0;
	char Registro[N];
	bool esta=false;
	do{
		while(i<N&&(Registro[i]=getchar())!='\n'){
			i++;
		}
		esta=EstaRegistrado(Registro,usuario,i,usuarioCant);
		if(esta){
			printf("Este nick ya esta registrado, elija otro \n");
			__fpurge(stdin);
			i=0;
		}	
	}while(esta);
	for(e=0;e<i;e++){
		usuario[j].Nick.letra[e]=Registro[e];
	}
	usuario[j].Nick.largo=i;
	i=0;
	__fpurge(stdin);
	while(i<N&&(usuario[j].Nombre.letra[i]=getchar())!='\n'){
		i++;
	}
	usuario[j].Nombre.largo=i;
	if(usuario[j].Nombre.largo!=0){
		usuarioCant++;
	}
	InicializaPuntaje(usuario,j);
	__fpurge(stdin);
}	
	
// Muestra el nick, nombre y puntaje del usuario
void MostrarNombre_Nick(Usuario_inf usuario[usuarios_cant], int j){
	int z,i;
	i=0;
	printf("\n\n\t\t\t\tUsuario: ");
	for(z=0;z<usuario[j].Nick.largo;z++){
		printf("%c",usuario[j].Nick.letra[z]);
		
	}
	printf("\n\t\t\t\t");
	printf("Nombre: ");
	for(i=0;i<usuario[j].Nombre.largo;i++){
		printf("%c",usuario[j].Nombre.letra[i]);
	}
	printf("\n\t\t\t\t");
	printf("Puntaje: %d",usuario[j].puntos);
	printf("\n");
}

// Muestra el nick y nombre  del usuario
void MostrarNombre_Nick2(Usuario_inf usuario[usuarios_cant], int j){
	int z,i;
	i=0;
	printf("\n");
	printf("\t\t\t\tUsuario: ");
	for(z=0;z<usuario[j].Nick.largo;z++){
		printf("%c",usuario[j].Nick.letra[z]);
	}
	printf("\n");
	printf("\t\t\t\tNombre: ");
	for(i=0;i<usuario[j].Nombre.largo;i++){
		printf("%c",usuario[j].Nombre.letra[i]);
	}
	printf("\n\n");
}

// Ingresa el nick del usuario
void Ingresa_Nick(Usuario_inf usuario[usuarios_cant], int j,int &usuarioCant){
	int i;
	i=0;
	while(i<N&&(usuario[j].Nick.letra[i]=getchar())!='\n'){
		i++;
	}
	usuario[j].Nick.largo=i;
	__fpurge(stdin);
}	

// Funcion que verifica si el nick que fue ingresado esta registrado o si no 
bool EstaRegistrado(char Registrado[N],Usuario_inf usuario[usuarios_cant],int largo, int usuarioCant){
	int verifica=0;
	int letra=0;
	int contador=0;
	while(verifica<=usuarioCant&&contador!=usuario[verifica].Nick.largo){
		for(letra=0;letra<=usuario[verifica].Nick.largo;letra++){
			if(usuario[verifica].Nick.largo!=largo){
				letra=0;
				break;
			}
			if(usuario[verifica].Nick.letra[letra]==Registrado[letra]){
				contador++;
				if(contador==usuario[verifica].Nick.largo){
					return true;
				}
			}
			else{
				letra=0;
				contador=0;
				break;
			}
		}
		verifica++;
	}
	return false;
}

// Devuelve true si el usuario ingresado esta registrado y guarda la ubicacion en la variable Jugador
bool IngresaNick2(char Registrado[N],Usuario_inf usuario[usuarios_cant],int largo, int usuarioCant,int &Jugador){
	int verifica=0;
	int letra=0;
	int contador=0;
	while(verifica<=usuarioCant&&contador!=usuario[verifica].Nick.largo){
		for(letra=0;letra<=usuario[verifica].Nick.largo;letra++){
			if(usuario[verifica].Nick.largo!=largo){
				letra=0;
				break;
			}
			if(usuario[verifica].Nick.letra[letra]==Registrado[letra]){
				contador++;
				if(contador==usuario[verifica].Nick.largo){
					Jugador=verifica;
					return true;
				}
			}
			else{
				letra=0;
				contador=0;
				break;
			}
		}
		verifica++;
	}
	return false;
}
	
// Devuelve true si el nick ingresado esta registrado(Inicia sesion)
bool IniciaSesion(Usuario_inf usuario[usuarios_cant], int usuarioCant,int &Jugador,bool SesionInciada){
	int i=0;
	char registrarse;
	char Registro[N];
	bool esta=false;
	do{
		while(i<N&&(Registro[i]=getchar())!='\n'){
			i++;
		}
		esta=IngresaNick2(Registro,usuario,i,usuarioCant,Jugador);
		if(!(esta)){
			printf("\n\nerror: Este nick no esta registrado \n");
			printf("Presione enter para regresar al menu . . .");
			__fpurge(stdin);
			scanf("%c",&registrarse);
			__fpurge(stdin);
			if(registrarse=='\n'){
				system("clear");
				Menu();
				return false;
			}
		}	
	}while(!(esta));
	return true;
}
	
		
// Imprime el Ranking segun los puntos de forma descendente
void Ranking(Usuario_inf usuario[usuarios_cant], int usuarioCant, int Jugador){
	int j;
	char finalizar;
	system("clear");
	printf("\033[1;40m");
	printf("\n\n\n\t\t\t\t\tRanking\n\n");
	printf("\033[1;0m");
	
	int k,z,pos,nropos;
	Usuario_inf aux[1];
	Usuario_inf ordena[usuarioCant];
	for(k=0;k<usuarioCant;k++){
		ordena[k]=usuario[k];
	}
	for(k=0;k<usuarioCant-1;k++){
		pos=k;
		nropos=ordena[k].puntos;//0
		for(z=k+1;z<usuarioCant;z++){
			if (ordena[z].puntos>nropos){
				nropos=ordena[z].puntos;//5
				pos=z;//1
			}
		}
		//Intercambio
		aux[0] = ordena[pos];
		ordena[pos]=ordena[k];
		ordena[k]=aux[0];
	}
	for(j=0;j<usuarioCant;j++){
		MostrarNombre_Nick(ordena,j);
		
	}
	printf("\n\n\t\t\tPresione enter para regresar al menu . . .");
	scanf("%c",&finalizar);
	__fpurge(stdin);
}	
	
	// Muestra la lista de usuarios
void ListarUsuario(Usuario_inf usuario[usuarios_cant], int usuarioCant){
	int j;
	char finalizar;
	printf("\033[1;40m");
	printf("\n\n\n\t\t\t\t\tLista de usuarios\n\n");
	printf("\033[1;0m");
	for(j=0;j<usuarioCant;j++){
		MostrarNombre_Nick2(usuario,j);
		if(j==3){
			break;
		}
	}
	printf("\n\n\t\t\tPresione enter para regresar al menu . . .");
	scanf("%c",&finalizar);
}	

// Funcion que inicializa el nick del usuario en largo 0
void InicializaNick(Usuario_inf usuario[usuarios_cant],int j){
	usuario[j].Nick.largo=0;
}
	
// Funcion que inicializa el nombre del usuario en 0
void InicializaNombre(Usuario_inf usuario[usuarios_cant],int j){
	usuario[j].cantidad=0;
}

// Funcion que inicializa el puntaje en 0
void InicializaPuntaje(Usuario_inf usuario[usuarios_cant],int j){
	usuario[j].puntos=0;
}	
	
// Funcionamiento del Juego
void Jugar(Usuario_inf usuario[usuarios_cant], int Jugador){
	int i,j,fila,columna,numero,dificultad,dificultad2,puntosnivel,errores;
	char finalizar;
	int SudokuResuelto[9][9];	
	int SudokuNoResuelto[9][9];
	int SudokuJuego[9][9];
	dificultad=opcion();
	puntosnivel=dificultad;
	nivel(dificultad);
	dificultad2=dificultad;
	errores=81;
	inicializar_sudoku (SudokuResuelto);
	inicializar_sudoku (SudokuNoResuelto);
	generar_sudoku_valido (SudokuResuelto);
	system("clear");
	for(fila=0;fila<9;fila++){
		for(columna=0;columna<9;columna++){
			SudokuNoResuelto[fila][columna]=SudokuResuelto[fila][columna];
		}
	}
	sudoku_noresuelto (SudokuNoResuelto,dificultad);
	for(fila=0;fila<9;fila++){
		for(columna=0;columna<9;columna++){
			SudokuJuego[fila][columna]=SudokuNoResuelto[fila][columna];
		}
	}
	do{
		MostrarSesion(usuario,Jugador);
		imprimir_sudoku (SudokuNoResuelto);
		printf("\n\n\t\tIngrese la fila y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\tPresione r y enter para rendirse\n\n\t\ts[");
		do{
			do{
				i=getchar();
				if(i==(int)'r'){
					system("clear");
					MostrarSesion(usuario,Jugador);
					printf("\n\n\t\tUsted ha elegido rendirse, la solucion del sudoku era:");
					imprimir_sudoku (SudokuResuelto);
					__fpurge(stdin);
					printf("\n\n\t\tPresione enter para regresar al menu . . .");
					scanf("%c",&finalizar);
					system("clear");
					MostrarSesion(usuario,Jugador);
					printf("\n\n");
					Menu();
					return;
				}
				else{
					if(!(i>47&&i<57)){
						__fpurge(stdin);
						system("clear");
						MostrarSesion(usuario,Jugador);
						imprimir_sudoku (SudokuNoResuelto);
						printf("\n\n\t\tIngrese la fila y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\tPresione r y enter para rendirse ¡La fila debe ser entre 0 y 8!\n\n\t\ts[");
						
					}
				}
			} while(!(i>47&&i<57));
			
			system("clear");
			MostrarSesion(usuario,Jugador);
			imprimir_sudoku (SudokuNoResuelto);
			printf("\n\n\t\tIngrese la columa y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada\n\n");
			printf("\t\ts[%d][",i-48);
			__fpurge(stdin);
			
			do{
				j=getchar();
				if(!(j>47&&j<57)){
					system("clear");
					MostrarSesion(usuario,Jugador);
					imprimir_sudoku (SudokuNoResuelto);
					printf("\n\n\t\tIngrese la columa y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\t¡La columa debe ser entre 0 y 8!\n\n");
					printf("\t\ts[%d][",i-48);
					__fpurge(stdin);
				}
			} while(!(j>47&&j<57));
			
			system("clear");
			MostrarSesion(usuario,Jugador);
			imprimir_sudoku (SudokuNoResuelto);
			printf("\n\n\t\tIngrese el numero que desea colocar en la celda del 1 al 9.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\n");
			printf("\t\ts[%d][%d]=",i-48,j-48);
			__fpurge(stdin);
			
			do{
				numero=getchar();
				if(!(numero>48&&i<58)){
					system("clear");
					MostrarSesion(usuario,Jugador);
					imprimir_sudoku (SudokuNoResuelto);
					printf("\n\n\t\tIngrese el numero que desea colocar en la celda del 1 al 9.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\t¡El numero debe estar entre el 1 y el 9!\n\n");
					printf("\t\ts[%d][%d]=",i-48,j-48);
					__fpurge(stdin);
				}
			} while(!(numero>48&&i<58));
			
			system("clear");
			MostrarSesion(usuario,Jugador);
			imprimir_sudoku (SudokuNoResuelto);
			printf("\n\n\t\tIngrese la fila y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\tPresione r y enter para rendirse\n\n");
			printf("\t\ts[%d][%d]=%d",i-48,j-48,numero-48);
			__fpurge(stdin);
			
			if(SudokuJuego[i-48][j-48]==0){
				if(SudokuNoResuelto[i-48][j-48]!=0){
					dificultad++;//si se va a cambiar una celda ya ingresada no es necesario restarla
				}
				SudokuNoResuelto[i-48][j-48]=0;
			}
			if(SudokuNoResuelto[i-48][j-48]==0){
				SudokuNoResuelto[i-48][j-48]=numero-48;
				dificultad=dificultad-1;
				system("clear");
				MostrarSesion(usuario,Jugador);
				imprimir_sudoku (SudokuNoResuelto);
				if(dificultad!=0){
				printf("\n\n\t\tIngrese la fila y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\tPresione r y enter para rendirse\n\n\t\ts[");
				}
			}
			else{
				system("clear");
				MostrarSesion(usuario,Jugador);
				imprimir_sudoku (SudokuNoResuelto);
				printf("\n\n\t\tIngrese la fila y presione enter, debe ser entre 0 y 8.\n\t\tSi ingresa un numero mayor a 9 solo se tendra en\n\t\tcuenta la primera cifra ingresada.\n\t\tPresione r y enter para rendirse\n");
				printf("\t\t¡Elija una celda vacia!\n\n\t\ts[");
			}
		}while(dificultad!=0);
		for(fila=0;fila<9;fila++){
			for(columna=0;columna<9;columna++){
				if(SudokuNoResuelto[fila][columna]!=SudokuResuelto[fila][columna]){
					printf("\n\n\t\tHa fallado, vuelva a intentarlo: \n\t\t");
					__fpurge(stdin);
					printf("Presione enter para volver a jugar . . .");
					scanf("%c",&finalizar);
					system("clear");
					for(fila=0;fila<9;fila++){
						for(columna=0;columna<9;columna++){
							SudokuNoResuelto[fila][columna]=SudokuJuego[fila][columna];
						}
					}
					errores=81;
					dificultad=dificultad2;
					break;
					break;
				}
				else{
					if(SudokuNoResuelto[fila][columna]==SudokuResuelto[fila][columna]){
						errores=errores-1;
						if(errores==0){
							__fpurge(stdin);
							system("clear");
							MostrarSesion(usuario,Jugador);
							imprimir_sudoku (SudokuNoResuelto);
							printf("\n\n\t\tLo ha resuelto correctamente, felicidades \n");
							usuario[Jugador].puntos=usuario[Jugador].puntos+puntosnivel*X;
						}
					}
				}
			}
		}
	}while(errores!=0);
	__fpurge(stdin);
	printf("\t\tPresione enter para regresar al menu . . .");
	scanf("%c",&finalizar);
	__fpurge(stdin);
	system("clear");
	MostrarSesion(usuario,Jugador);
	printf("\n\n");
	Menu();
}
	
// Llena el Sudoku 's' con cant_elem cantidad de 0 de forma aleatoria
void sudoku_noresuelto (int s [9][9], int cant_elem){
	int i,j,cuentacasillas;
	cuentacasillas=1;
	while(cuentacasillas<=cant_elem){
		do{
			i=rand()%9;
			j=rand()%9;//Se elige una celda para llenar al azar
		}while(s[i][j]==0);
		s[i][j]=0;
		cuentacasillas=cuentacasillas+1;
	}//repite el proceso hasta que se llene un numero cant_elem de celdas
}	
	
	
void inicializar_sudoku (int s [9][9]){
// Inicializa el Sudoku 's' llenando todas las celdas con el valor 0.
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			s[i][j]=0;
		}
	}
}

// Imprime el Sudoku 's' en pantalla 
void imprimir_sudoku (int s [9][9]){
	// Imprime el Sudoku en pantalla con un formato matricial mostrando la separación entre regiones.
	int i,j;
	printf("\n\n\n");
	printf("\t\t\t::===========::===========::===========::");
	for(i=0;i<9;i++){
		if(i!=0){
			if(i%3==0){
				printf("\t\t\t::===========::===========::===========::");// Se imprime para separar las filas entre regiones y en el inicio y final de la matriz para que las regiones queden bien delimitadas
			}else{
				printf("\t\t\t||___|___|___||___|___|___||___|___|___||");// Se imprime para separar las filas dentro de las regiones 
			}
		}
		printf("\n");
		if(i % 1 == 0){
			printf("\t\t\t");
		}
		for(j=0;j<9;j++){
			if(j%3==0){
				printf("|");// Se imprime un | adicional antes del inicio de cada region para separar las columnas entre regiones
			}
			printf("| %d ",s[i][j]);
			if(j==8){
				printf("||");// Se imprime un || al llegar a la ultima columna par que la region quede totalmente delimitada
			}
		}
		printf("\n");
	}
	printf("\t\t\t::===========::===========::===========::");
	printf("\n");
}
		
	
// Funcion que genera un Sudoku 's' valido
void generar_sudoku_valido (int s [9][9]){
	int i,j,k,cuenta_cand,Exclusivo;
	inicializar_sudoku (s);
	bool candidato[9];
	for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				for(k=0;k<9;k++){//se inicializa el arreglo con true en sus casillas
					candidato[k]=true;
				}
				cuenta_cand=9;
					do{
						Exclusivo=rand()%10;
					}while(Exclusivo==0);
					Candidato_Exclusivo(s,i,j,candidato,cuenta_cand);
					while(candidato[Exclusivo-1]==false){
						Exclusivo=rand()%10;
						//printf("loop \n");
						if(cuenta_cand<=0){
							inicializar_sudoku (s);
							cuenta_cand=9;
							
							i=0;
							j=0;
							break;
						}
					}
					if(Exclusivo!=0){
						s[i][j]=Exclusivo;
						
					}
				}
	}

}
	

void Candidato_Exclusivo (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand){
/* Dada la fila y la columna, encuentra los candidatos para esa celda vacía y los registra en el
arreglo 'candidatos'. A modo de ejemplo si el conjunto de candidatos es {1,3,4,9} --> 'candidatos'
	= [true,false,true,true,false,false,false,false,true]*/
	int k,i,j,aux_i,aux_j;
	if(s[fila][columna]==0){
		for(j=0;j<9;j++){
			if(columna!=j){
				if(s[fila][j]!=0){
					candidatos[s[fila][j]-1]=false;//En caso de que un numero ya se encuentre en la fila o columna de la celda que se quiere averiguar los candidatos, se llena con false en el arreglo
				}
			}
		}
	//se resta -1 al numero que encuentra porque el arreglo candidatos se llena del 0 al 8 y los numeros posibles van del 1 al 9, 
	//de manera de que si ej 1 no es candidato para esta celda porque ya esta en la misma fila o columna, en el arreglo candidatos[0] se carga con false
		for(i=0;i<9;i++){
			if(fila!=i){
				if(s[i][columna]!=0){
					candidatos[s[i][columna]-1]=false;//En caso de que un numero ya se encuentre en la fila o columna de la celda que se quiere averiguar los candidatos, se llena con false en el arreglo
				}
			}
		}
		aux_i=Celda_Region(fila);
		aux_j=Celda_Region(columna);
		for(k=1;k<9;k++){
			if(RegionValida2(aux_i,aux_j,columna,fila,k,s)==false){
				candidatos[k-1]=false;
			}
		}
	}
	for(k=0;k<9;k++){
		if(candidatos[k]==false){
			cuenta_cand=cuenta_cand-1;
		}
	}
}

bool Candidato_Unico (int s [9][9], int fila, int columna, bool candidatos[9],int &cuenta_cand){
	int i,j,k;
	int Cant_cand[9][9];
	inicializar_sudoku (Cant_cand);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			Candidato_Exclusivo(s,i,j,candidatos,cuenta_cand);
			Cant_cand[i][j]=cuenta_cand;
			if(cuenta_cand==0){
				return false;
			}
			cuenta_cand=9;
			for(k=0;k<9;k++){//se inicializa el arreglo con true en sus casillas
				candidatos[k]=true;
			}
		}
	}
	return true;
}

bool es_candidato (int s [9][9], int num, int fila, int columna){
	/* Devuelve true si 'num' es candidato para la celda del Sudoku 's' dada por 'fila' y 'columna', o
	false en caso contrario. La celda debe ser vacía.*/
	int i,j;
	if(s[fila][columna]!=0){
		return false;
	}else{
		if(num>0&&num<10){
			for(j=0;j<9;j++){//verifica que en esa fila no este el numero que se quiere averiguar si es candidato
				if(j!=columna){
					if(s[fila][j]==num){
						return false;
					}
				}
			}
			for(i=0;i<9;i++){//verifica que en esa columna no este el numero que se quiere averiguar si es candidato
				if(i!=fila){
					if(s[i][columna]==num){
						return false;
					}
				}
			}
		}
		return true;
	}
}

	
bool sudoku_valido (int s [9][9]){
/*Devuelve true si el tablero 's' cumple con los requisitos de un Sudoku válido (unicidad en filas,columnas y regiones), o false en 
caso contrario. El tablero puede estar incompleto, en ese caso las celdas vacías se representan con 0.*/
	int i,j,columna, fila;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(s[i][j]!=0){
				for(columna=0;columna<9;columna++){//Si encuentra una celda no vacia recorre la fila de dicha celda para revisar si el contenido de dicha celda se repite en otra celda distinta
					if(columna!=j){
						if(s[i][columna]==s[i][j]){
							return false;
						}
					}
				}
				for(fila=0;fila<9;fila++){//Si encuentra una celda no vacia recorre la columna de dicha celda para revisar si el contenido de dicha celda se repite en otra celda distinta
					if(fila!=i){
						if(s[fila][j]==s[i][j]){
							return false;
						}
					}
				}
			}
		}
	}

	return ((RegionValida(0,0,s)&&RegionValida(0,3,s)&&RegionValida(0,6,s)&&RegionValida(3,0,s)&&RegionValida(3,3,s)&&RegionValida(3,6,s)&&RegionValida(6,0,s)&&RegionValida(6,3,s)&&RegionValida(6,6,s)));
	//En caso de no encontrar numeros repetidos en filas o columnas y terminar antes, evalua si todas las regiones son validas pasandole a la funcion RegionValida el inicio de cada region
}
	
//
bool RegionValida(int regionF, int regionC,int s[9][9]){
	int i,j,columna, fila;	
	for(i=regionF;i<3+regionF;i++){//va de la primera coordenada de la fila de la region hasta la ultima
		for(j=regionC;j<3+regionC;j++){//va de la primera coordenada de la columna de la region hasta la ultima
			if(s[i][j]!=0){//Si encuentra una celda no vacia recorre la region para revisar si el contenido de dicha celda se repite en otra celda distinta
				for(fila=regionF;fila<3+regionF;fila++){
					for(columna=regionC;columna<3+regionC;columna++){
						if(columna!=j||fila!=i){
							if(s[fila][columna]==s[i][j]){
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}		
	
//
bool RegionValida2(int regionF, int regionC,int candidatoF,int candidatoC,int k,int s[9][9]){
	int i,j;	
	for(i=regionF;i<3+regionF;i++){//va de la primera coordenada de la fila de la region hasta la ultima
		for(j=regionC;j<3+regionC;j++){//va de la primera coordenada de la columna de la region hasta la ultima
			if(i!=candidatoF||j!=candidatoC){
				if(s[i][j]==k){//Si encuentra una celda no vacia recorre la region para revisar si el contenido de dicha celda se repite en otra celda distinta
					return false;
				}
			}
		}
	}
	return true;
}				
	
//Funcion que devuelve true si el tablero esta completamente resuelto, o false en caso contrario
bool sudoku_resuelto (int s [9][9]){
// Devuelve true si el tablero está completamente resuelto, o false en caso contrario
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(s[i][j]==0){//revisa si alguna celda esta vacia y en caso de ser asi, no estaria resuelto devuelve false
				return false;
			}
		}
	}
	return true;
}
	
// Recibe una fila o columna y devuelve la primera fila o columna de su region
int Celda_Region(int celda){
	//recibe una fila o columna y devuelve la primera fila o columna de su region
	switch(celda){
	case 0:
	case 1:
	case 2:
		celda=0;
		break;
	case 3:
	case 4:
	case 5:
		celda=3;
		break;
	case 6:
	case 7:
	case 8:
		celda=6;
		break;
	}
	return celda;
}

bool es_candidato2 (int s [9][9], int num, int fila, int columna){
	/* Devuelve true si 'num' es candidato para la celda del Sudoku 's' dada por 'fila' y 'columna', o
	false en caso contrario. La celda viene cargada con el dato a evaluar*/
	int i,j;
	if(num>0&&num<10){
		for(j=0;j<9;j++){//verifica que en esa fila no este el numero que se quiere averiguar si es candidato
			if(j!=columna){
				if(s[fila][j]==num){
					return false;
				}
			}
		}
		for(i=0;i<9;i++){//verifica que en esa columna no este el numero que se quiere averiguar si es candidato
			if(i!=fila){
				if(s[i][columna]==num){
					return false;
				}
			}
		}
	}
	return true;
}
