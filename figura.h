#ifndef _FIGURA_H_
#define _FIGURA_H_

#include "polilinea.h"
#include "fisica.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#define LONG_NOM 20
#define INF_MASK 0x01
#define TIPO_MASK 0x07
#define CANTIDAD_PUNTOS_MASK 0x3ff
#define MASK_G 0x2
#define MASK_B 0x1

#define LON_NOM

//si la funciones de setteo o creacion fallan se mata todo

//tipos de dato
//cada figura tiene toda la informacion necesaria recogida del archivo
struct figura;
typedef struct figura figura_t;

//tabla de busqueda (tipo)
typedef enum{
    ICONO,
    NIVEL,
    SPRITE,
    PLANETA,
    BASE,
    COMBUSTIBLE,
    TORRETA,
    REACTOR,
}figura_tipo_t;

const char* figura_tipo_a_cadena(figura_tipo_t figura);

//seteo
bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);
polilinea_t *leer_polilinea(FILE *f);
void figura_trasladar(figura_t *figura, double traslacion[2]);
void figura_rotar(figura_t *figura, double angulo);

//creacion
figura_t *figura_crear(FILE *f);
figura_t **crear_figuras(FILE *f,size_t *i);

//getter
char *nombre_fig(const figura_t *figura); //hacerlo con tabla de busqueda
bool infinito_fig(const figura_t *figura);
figura_tipo_t tipo_fig(const figura_t *figura);
size_t cantidad_poli_fig(const figura_t *figura);
polilinea_t **polilinea_fig(const figura_t *figura);

//manipulacion de datos
figura_t *cargar_nombre(figura_t **bloque,char *nombre_figura);
figura_t **cargar_tipo(figura_t **bloque,figura_tipo_t tipo);
//bool dibujar_polilineas(figura_t **bloque,char *nombre, size_t cantidad,float escalado,float posicion[2]);

//destrucción- liberacion de la memoria
void figura_destruir(figura_t *figura);
void destruir_bloque(figura_t **bloque,size_t i);

#endif 