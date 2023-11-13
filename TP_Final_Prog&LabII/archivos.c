#include "archivos.h"

///Archivos de Cartas
void cargaArchiCartas(stCarta cartaAGuardar) //carga el archivo
{
    FILE * archi = fopen(ARCHI_CARTAS, "ab");
    if(archi)
    {
        fwrite(&cartaAGuardar, sizeof(stCarta), 1, archi);
        fclose(archi);
    }
    else
        printf("\n El archivo no se abrio correctamente. ");
}

void muestraArchiCartas()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi))
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

int buscaUltimoIDEnArchi()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    int ultimoID = 0;
    if(archi)
    {
        stCarta cartitaEnArchi;
        fseek(archi, -sizeof(stCarta), SEEK_END);
        fread(&cartitaEnArchi, sizeof(stCarta), 1, archi);
        ultimoID = cartitaEnArchi.id;

        fclose(archi);
    }
    return ultimoID;
}


