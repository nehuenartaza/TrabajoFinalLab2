#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#define ARCHI_CARTAS "cartas.dat"
#define ARCHI_USUARIOS "usuarios.dat"
#include "stUsuario.h"
#include "stCarta.h"



///Archivos de Cartas
void cargaArchiCartas(stCarta cartaAGuardar);
void muestraArchiCartas();
int buscaUltimoIDEnArchi();

#endif // ARCHIVOS_H_INCLUDED
