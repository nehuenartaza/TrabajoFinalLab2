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

///Archivo de Usuarios
datosUsuario guardaIndicadores(datosUsuario); // guarda los datos del usuario
#endif // ARCHIVOS_H_INCLUDED
