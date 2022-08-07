#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct vector{
    float x,y,z;
    //int cantidad;
};
struct objeto{
    float posicion[2];
    float direccion;
};

typedef struct vector vector_t;
typedef struct objeto objeto_t;

typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

const size_t cantidad_combustible(planeta_nombre nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=2,
    [NIVEL1R]=0,
    [NIVEL1NW]=4,
    [NIVEL1SW]=3
    };
    return cantidad[nombre];
}
/*
const size_t cantidad_torretas(planeta_nombre nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=4,
    [NIVEL1R]=0,
    [NIVEL1NW]=8,
    [NIVEL1SW]=6;
    }
    return cantidad[nombre];
}
const bool cantidad_reactores(planeta_nombre nombre){
    static const bool cantidad[]={
    [NIVEL1NE]=0,
    [NIVEL1SE]=0,
    [NIVEL1R]=1,
    [NIVEL1NW]=0,
    [NIVEL1SW]=0;
    }
    return cantidad[nombre];
}
*/

vector_t *posicion_combustible(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][4]={
    [NIVEL1NE]={{.x=1064,.y=13,.z=0},{.x=1685,.y=113,.z=0}},
    [NIVEL1SE]={{.x=482,.y=94,.z=0},{.x=1751,.y=247,.z=0}},
    [NIVEL1R]={{0,0,0}},
    [NIVEL1NW]={{.x=188,.y=429,.z=9},{667,600,0},{1054,404,0},{574,344,0}},
    [NIVEL1SW]={{.x=820,.y=46,.z=0},{1196,68,0},{1602,46,0}}
    };
    //*cantidad=sizeof(vectores[nombre])/sizeof(vector_t);
    *cantidad=cantidad_combustible(nombre);

    return vectores[nombre];
}
/*vector_t *posicion_torreta(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][8]={
    [NIVEL1NE]={{.x=1,.y=2,.z=3}},
    [NIVEL1SE]={{.x=4,.y=5,.z=6},{.x=10,.y=11,.z=12},{.x=7,.y=8,.z=9}},
    [NIVEL1R]={{815,309,0}},
    [NIVEL1NW]={{.x=7,.y=8,.z=9}},
    [NIVEL1SW]={{.x=10,.y=11,.z=12}}
    };
    *cantidad=sizeof(vectores[nombre])/sizeof(vector_t);
    //cantidad=cantidad_torretas(nombre);
    return vectores[nombre];
}
*/
objeto_t *crear_combustible(vector_t *referencia, size_t fila){
    
    objeto_t *objeto=malloc(sizeof(objeto_t));
    if(objeto==NULL) return NULL;

    float posicion[2];
    float direccion;

    posicion[0]=(referencia[fila]).x;
    posicion[1]=(referencia[fila]).y;
    direccion=(referencia[fila]).z;
   

    objeto->posicion[0]=posicion[0];
    objeto->posicion[1]=posicion[1];
    objeto->direccion=direccion;
    
    //printf("%d combustibles\n",cantidad);
    return objeto;
}/*
objeto_t *crear_torreta(planeta_nombre nombre){
    int cantidad=0;
    vector_t *referencia=posicion_torreta(nombre,&cantidad);
    
    objeto_t *objeto=malloc(sizeof(objeto_t));
    if(objeto==NULL) return NULL;
    
    float *posicion_x=malloc(sizeof(float)*cantidad);
    float *posicion_y=malloc(sizeof(float)*cantidad);
    float *direccion=malloc(sizeof(float)*cantidad);

    posicion_x=&(referencia->x);
    posicion_y=&(referencia->y);
    direccion=&(referencia->z);

    objeto->posicion[0]=posicion_x;
    objeto->posicion[1]=posicion_y;
    objeto->direccion=direccion;
    
    printf("%d torretas\n",cantidad);
    return objeto;
}
*/

void objeto_a_posicion(objeto_t *objeto,float *posicion){
    posicion[0]=objeto->posicion[0];
    posicion[1]=objeto->posicion[1];
}

void objeto_a_direccion(objeto_t *objeto,float *direccion){
    *direccion=objeto->direccion;
}

/*
void destruir_cosa(objeto_t *objeto){
    printf("1");
    free(objeto->posicion[0]);
    printf("2");
    free(objeto->posicion[1]);
    printf("3");
    free(objeto->direccion);
    printf("4");
    free(objeto);
}
void destruir_bien(void *objeto){
    printf("0\n");
    destruir_cosa(objeto);
}
*/
/*
float *get_ref(vector_t *vector){
    float f[3];
    float *vec[3]=vector[0];
    f[0]=referencia->x;
    f[1]=referencia->y;
    f[2]=referencia->z;
    return *f;
}*/

int main(void){

    lista_t *l_combustible=lista_crear();
    //lista_t *l_torreta=lista_crear();
    objeto_t *combustible=NULL;
    //objeto_t *torreta=NULL;

    int cantidad=0;
    size_t fila=0;
    float posicion[2]={0,0};
    float direccion=0;

    vector_t *referencia=posicion_combustible(NIVEL1NE,&cantidad);
    
    printf("%d\n",cantidad);
  
    while(fila<cantidad){
        combustible=crear_combustible(referencia,fila);
        lista_insertar_primero(l_combustible,combustible);
        objeto_a_posicion(combustible,posicion);
        objeto_a_direccion(combustible,&direccion);
        printf("%f %f %f\n",posicion[0],posicion[1],direccion);
        fila++;
    }

    printf("anda\n");
    objeto_t *caca=NULL;
    lista_iter_t *li_combustible=lista_iter_crear(l_combustible);
    caca=lista_iter_ver_actual(li_combustible);
    objeto_a_posicion(caca,posicion);
    objeto_a_direccion(caca,&direccion);
    printf("pos 0 %f %f %f\n",posicion[0],posicion[1],direccion);

    if(lista_iter_avanzar(li_combustible)==false) printf("NULL");
    caca=lista_iter_ver_actual(li_combustible);
    objeto_a_posicion(caca,posicion);
    objeto_a_direccion(caca,&direccion);
    printf("pos 1 %f %f %f\n",posicion[0],posicion[1],direccion);

    if(lista_iter_avanzar(li_combustible)==false) printf("NULL");
    caca=lista_iter_ver_actual(li_combustible);
    objeto_a_posicion(caca,posicion);
    objeto_a_direccion(caca,&direccion);
    printf("%f %f %f\n",posicion[0],posicion[1],direccion);
/*    printf("anda");
    objeto_t *caca=NULL;
     printf("anda");

    while(lista_iter_avanzar(li_combustible)){
        printf("anda");
        caca=lista_iter_ver_actual(li_combustible);
        objeto_a_posicion(caca,posicion);
        objeto_a_direccion(caca,&direccion);
    }
*/
    printf("%zd\n",fila);
/*
    fila=0;
    referencia=posicion_torreta(nombre,&cantidad);
    while(fila<cantidad){
        torreta=crear_torreta(referencia,fila);
        lista_insertar_primero(l_torreta,torreta);
    }
*/
/*
    //liberar memoria
    printf("-1\n");
    lista_destruir(l_combustible, destruir_bien);
    lista_destruir(l_torreta, destruir_bien);
*/
    //printf("%f %f %f\n",fila_v[0],fila_v[1],fila_v[2]);
    //objeto_t *objeto=crear_objeto(NIVEL1SE);
    //printf("%f %f\n",objeto->posicion[0][0],objeto->posicion[0][1]);
    return 1;
}
