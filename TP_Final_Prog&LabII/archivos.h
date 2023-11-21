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
stCarta buscaCartaPorIdEnArchi(int idAbuscar); //Buscca y retorna datos de carta pedidos apartir de un id //////////////////////////// Falta testear

///Archivo de Usuarios
int buscaUltimoIDEnArchiUsuarios();
void cargaArchiUsuarios(datosUsuario);
datosUsuario iniciarSesion(int*); // pide nombre de usuario y contraseņa, busca si existe alguno con dichos datos y retorna los datos asociados a dicho usuario si lo encuentra. Modifica variable int "login" por puntero.
datosUsuario cerrarSesion(int*);  // vacia los datos de variable usuario y los retorna. Modifica la variable login por puntero
datosUsuario buscaUsuarioPorIdEnArchi(int idAbuscar); //Buscca y retorna datos de usuario pedidos apartir de un id //////////////////////////// Falta testear
void muestraUsuariosEnArchi();
void muestraColeccionIntercambioUsuarioEnArchi(int idDeUsuarioAMostrar);
void hacerIntercambio(stUsuario * usuarioActual);
datosUsuario guardaIndicadores(datosUsuario); // guarda los datos del usuario
datosUsuario buscaUsuarioPorIdEnArchi(int idAbuscar); //Buscca y retorna datos de usuario pedidos apartir de un id //////////////////////////// Falta testear

#endif // ARCHIVOS_H_INCLUDED
