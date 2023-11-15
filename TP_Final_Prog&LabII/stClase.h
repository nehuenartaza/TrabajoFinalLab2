#ifndef STCLASE_H_INCLUDED
#define STCLASE_H_INCLUDED

#include "constantes.h"

///stPokemon
typedef struct {
    int estado;
    int puntosAtaque;
    char tipo[DIM3];
    char ataqueNro1[DIM1];
    char ataqueNro2[DIM1];
} stPokemon;

stPokemon cargaPokemon(int, char[], char[], char[]); //Carga Pokemon
void muestraPokemon(stPokemon); //Muestra Pokemon

///stEnergia
typedef struct {
    int estado;
    char tipoEnergia[DIM3];
} stEnergia;

void muestraEnergia(stEnergia); //Muestra Energia

///stEntrenador
typedef struct {
    int estado;
    char efecto[DIM1];
} stEntrenador;

void muestraEntrenador(stEntrenador);    //Muestra Entrenador

///stClase
typedef struct
{
    stPokemon datosPokemon;
    stEnergia datosEnergia;
    stEntrenador datosEntrenador;
}stClase;

//Cargar de cada caso
stClase cargaClasePokemon(stClase);
stClase cargaClaseEnergia(stClase);
stClase cargaClaseEntrenador(stClase);

stClase cargaClaseUsuario(stClase);  //Carga Preguntando que caso
void muestraClase(stClase);   //Muestra la clase
int validaOpcionCargaClaseUsuario(int);    //Valida Opcion

#endif // STCLASE_H_INCLUDED
