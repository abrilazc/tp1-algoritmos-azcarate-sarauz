#ifndef _FIGURA_H_
#define _FIGURA_H_

#include "polilinea.h"
#include <stdbool.h>


#define LONG_NOM 20
#define INF_MASK 0x01
#define TIPO_MASK 0x07
#define CANTIDAD_PUNTOS_MASK 0x3ff
#define MASK_G 0x2
#define MASK_B 0x1

#define LON_NOM

struct figura;//la figura tiene toda la informacion necesaria recogida del archivo
typedef struct figura figura_t;

typedef enum{
    ICONO,
    NIVEL,
    SPRITE,
    PLANETA,
    BASE,
    COMBUSTIBLE,
    TORRETA,
    REACTOR
}figura_tipo_t;
    
const char* figura_tipo_a_cadena(figura_tipo_t figura);

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);
polilinea_t *leer_polilinea(FILE *f);

figura_t *figura_crear(FILE *f);
void figura_destruir(figura_t *figura);

//getter
char *nombre_fig(const figura_t *figura); //hacerlo con tabla de busqueda
bool infinito_fig(const figura_t *figura);
char *tipo_fig(const figura_t *figura);
size_t cantidad_poli_fig(const figura_t *figura);
polilinea_t **polilinea_fig(const figura_t *figura);
figura_t *cargar(const figura_t **bloque,char *nombre_figura,size_t cantidad);

//bloques
figura_t **crear_figuras(FILE *f,size_t *i);
void destruir_bloque(figura_t **bloque,size_t i);

#endif 