#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#define ARCHI_CARTAS "cartas.dat"
#define ARCHI_USUARIOS "usuarios.dat"

#include "stUsuario.h"

///Archivos de Cartas
void cargaArchiCartas(stCarta cartaAGuardar);
void muestraArchiCartas();
int buscaUltimoIDEnArchi();
arbolDeListasCartas * cargaCartasArchiToArbolDL(arbolDeListasCartas * arbolACargar);

void cargaArchiUsuarios(datosUsuario);
datosUsuario iniciarSesion(int*); // pide nombre de usuario y contrase�a, busca si existe alguno con dichos datos y retorna los datos asociados a dicho usuario si lo encuentra. Modifica variable int "login" por puntero.
datosUsuario cerrarSesion(int*);  // vacia los datos de variable usuario y los retorna. Modifica la variable login por puntero

///Archivo de Usuarios
datosUsuario guardaIndicadores(datosUsuario); // guarda los datos del usuario
#endif // ARCHIVOS_H_INCLUDED
