#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#define ARCHI_CARTAS "cartas.dat"
#define ARCHI_USUARIOS "usuarios.dat"

#include "stUsuario.h"

///Archivos de Cartas
//Carga
void cargaArchiCartas(stCarta cartaAGuardar);
arbolDeListasCartas * cargaCartasArchiToArbolDL(arbolDeListasCartas * arbolACargar);
//Muestra
void muestraArchiCartas(); //Muestra Base de datos completa
void muestraArchiCartasPorNombre(char[]); //Muestra Base de datos por nombre recibido por parametro
void muestraArchiCartasPorRareza(char[]); //Muestra Base de datos Por rarezas Recibidas por parametro
void muestraArchiCartasPorExpansion(char[]); //Muestra Base de datos Por Expansion
void muestraArchiCartasPorSubExpansion(char[]); //Muestra Base de datos Por SubExpansion
void muestraArchiCartasPorClase(char[]);
void muestraArchiCartasPokemon();
void muestraArchiCartasEnergia();
void muestraArchiCartasEntrenador();
//Busqueda
int buscaUltimoIDEnArchi();
stCarta buscaCartaPorIdEnArchi(int idAbuscar); //Buscca y retorna datos de carta pedidos apartir de un id //////////////////////////// Falta testear

///Archivo de Usuarios
//Carga Del Usuario
void cargaArchiUsuarios(datosUsuario);
datosUsuario iniciarSesion(int*); // pide nombre de usuario y contraseña, busca si existe alguno con dichos datos y retorna los datos asociados a dicho usuario si lo encuentra. Modifica variable int "login" por puntero.
datosUsuario cerrarSesion(int*);  // vacia los datos de variable usuario y los retorna. Modifica la variable login por puntero
//Carga Datos Del Usuario
stListaD * cargaColeccionPorParametro(datosUsuario datosUsuarioACargar);
stMazo * cargaMazoPorParametro(datosUsuario datosUsuarioACargar); //////////////////////// JULI
void cargaBuzonPorParametro(datosUsuario datosUsuarioACargar , stBuzon * buzonACargar);
//Muestra Datos Usuario
void muestraUsuariosEnArchi();
void muestraColeccionIntercambioUsuarioEnArchi(int idDeUsuarioAMostrar);
//Busqueda
int buscaUltimoIDEnArchiUsuarios();
datosUsuario buscaUsuarioPorIdEnArchi(int idAbuscar); //Buscca y retorna datos de usuario pedidos apartir de un id //////////////////////////// Falta testear
//Manejo Del Sistema
void hacerIntercambio(stUsuario * usuarioActual);
//Guardado De Datos
void guardaDatosNuevos(datosUsuario usuarioACambiar); // guarda los datos del usuario

#endif // ARCHIVOS_H_INCLUDED
