#ifndef _BALA_H_
#define _BALA_H_

#include <stdlib.h>
#include "lista.h"
#include "config.h"
#include "fisica.h"


#define MAX_BAL_ENEM 10
#define MAX_BAL_PROP 10
#define MAX_BAL_TIEM 5
#define MAX_BAL_VELO 24

//Las balas son elementos de tiempo limitado y velocidad constante
//Se guardan en listas (jugador y enemigo) de manera secuencial
//Sus interacciones son por proximidad con otros objetos en el plano
struct bala;
typedef struct bala bala_t;

//mediante disparo se genera en la lista una bala con posicion y direccion
//propias del lguar de disparo
//la cantidad de balas es limitada por MAX_BAL ENEM y PROP
bala_t *crear_bala(float posicion[2],float direccion);
bool disparo(lista_t *lista,float posicion[2],float direccion);

//estas funciones manejan la durabilidad de la bala
bool destruir_disparos(lista_t *lista);
float obtener_tiempo(bala_t *bala);
void restar_tiempo(bala_t *bala,float tiempo);

//Devuelve la posicion de la bala por posicion
void posicion_bala(bala_t *bala,float posicion[2]);

//En cada DT esta funcion cambia la posicion de todas las balas de la lista
void trayectoria_disparo(lista_t *lista);

//Una vez que ya no son necesarias las balas se eliminan como listas de balas
void vaciar_bala(lista_t *lista);
void destruir_bala(bala_t *bala);
void liquidar_municion(void *bala);

#endif