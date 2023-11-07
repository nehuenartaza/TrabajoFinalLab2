#ifndef STCLASE_H_INCLUDED
#define STCLASE_H_INCLUDED

#include "stPokemon.h"
#include "stEnergia.h"
#include "stEntrenador.h"

typedef struct {
    stPokemon datosPokemon;
    stEnergia datosEnergia;
    stEntrenador datosEntrenador;
} stClase;

//Carga de cada caso
stClase cargaClasePokemon(stClase);
stClase cargaClaseEnergia(stClase);
stClase cargaClaseEntrenador(stClase);

stClase cargaClaseUsuario(stClase);  //Carga Preguntando que caso
void muestraClase(stClase);   //Muestra la clase
int validaOpcionCargaClaseUsuario(int);    //Valida Opcion

#endif // STCLASE_H_INCLUDED
