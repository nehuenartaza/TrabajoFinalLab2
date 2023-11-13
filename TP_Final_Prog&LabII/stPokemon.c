#include "stPokemon.h"

stPokemon cargaPokemon(int puntosAtaque_F, char tipo_F[], char ataqueNro1_F[], char ataqueNro2_F[]) //Carga Pokemon
{
    stPokemon pokemonACargar;

    pokemonACargar.puntosAtaque = puntosAtaque_F;
    strcpy(pokemonACargar.tipo, tipo_F);
    strcpy(pokemonACargar.ataqueNro1, ataqueNro1_F);
    strcpy(pokemonACargar.ataqueNro2, ataqueNro2_F);
    return pokemonACargar;
}

void muestraPokemon(stPokemon pokemonAMostrar)  //Muestra Pokemon
{
    printf("\n Hit Points(HP): %d", pokemonAMostrar.puntosAtaque);
    printf("\n Tipo..........: %s", pokemonAMostrar.tipo);
    printf("\n Ataque Nro 1..: %s", pokemonAMostrar.ataqueNro1);
    printf("\n Ataque Nro 2..: %s", pokemonAMostrar.ataqueNro2);
}

