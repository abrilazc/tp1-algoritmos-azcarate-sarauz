#ifndef _NIVEL_H_
#define _NIVEL_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "figura.h"


struct vector;
struct objeto;
struct reactor;
struct nivel;

typedef struct vector vector_t;
typedef struct objeto objeto_t;
typedef struct reactor reactor_t;
typedef struct nivel nivel_t;

//Crear
//niveles
nivel_t *crear_nivel(char *nombre);
nivel_t **crear_niveles(char *nombre);

const size_t cantidad_combustible(planeta_nombre nombre);

typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

#endif 