///Librerias
#ifndef STCLASE_H_INCLUDED
#define STCLASE_H_INCLUDED
#include "stPokemon.h"
#include "stEnergia.h"
#include "stEntrenador.h"

///Estructura
typedef struct
{
    stPokemon datosPokemon;
    stEnergia datosEnergia;
    stEntrenador datosEntrenador;
}stClase;

///Prototipado
//Revisa un string buscando salto de linea
void buscaSaltoLinea(char stringARecorrer[]);
//Cargar de cada caso
stClase cargaClasePokemon(stClase claseACargar_F);
stClase cargaClaseEnergia(stClase claseACargar_F);
stClase cargaClaseEntrenador(stClase claseACargar_F);
//Carga Preguntando que caso
stClase cargaClaseUsuario(stClase claseACargar_F);
//Muestra la clase
void muestraClase(stClase claseAMostrar);
//Valida Opcion
int validaOpcionCargaClaseUsuario(int opcion_F);

#endif // STCLASE_H_INCLUDED
