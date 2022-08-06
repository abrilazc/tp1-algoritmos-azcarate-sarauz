#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct vector{
    float x,y,z;
    int cantidad;
};
struct objeto{
    float *posicion[2];
    float *direccion;
};

typedef struct vector vector_t;
typedef struct objeto objeto_t;

typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

vector_t *posicion_combustible(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][4]={
    [NIVEL1NE]={{.x=1064,.y=13,.z=0},{.x=1685,.y=113,.z=0}},
    [NIVEL1SE]={{.x=482,.y=94,.z=0},{.x=1751,.y=247,.z=0}},
    [NIVEL1R]={{0,0,0}},
    [NIVEL1NW]={{.x=188,.y=429,.z=9},{667,600,0},{1054,404,0},{574,344,0}},
    [NIVEL1SW]={{.x=820,.y=46,.z=0},{1196,68,0},{1602,46,0}}
    };
    *cantidad=sizeof(vectores[nombre])/sizeof(vector_t);
    //printf("%zd",sizeof(vectores[nombre]));
    return vectores[nombre];
}
vector_t *posicion_torreta(planeta_nombre nombre, int *cantidad){
    static vector_t vectores[][3]={
    [NIVEL1NE]={{.x=1,.y=2,.z=3}},
    [NIVEL1SE]={{.x=4,.y=5,.z=6},{.x=10,.y=11,.z=12},{.x=7,.y=8,.z=9}},
    [NIVEL1R]={{815,309,0}},
    [NIVEL1NW]={{.x=7,.y=8,.z=9}},
    [NIVEL1SW]={{.x=10,.y=11,.z=12}}
    };
    *cantidad=sizeof(vectores[nombre])/sizeof(vector_t);
    return vectores[nombre];
}

objeto_t *crear_combustible(planeta_nombre nombre){
    int cantidad=0;
    vector_t *referencia=posicion_combustible(nombre,&cantidad);
    
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
    
    printf("%d combustibles\n",cantidad);
    return objeto;
}
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

void destruir_cosa(objeto_t *objeto){
    free(objeto->posicion[0]);
    free(objeto->posicion[1]);
    free(objeto->direccion);
    free(objeto);
}


int main(void){

    lista_t *l_combustible=lista_crear();
    lista_t *l_torreta=lista_crear();
    objeto_t *combustible=NULL;
    objeto_t *torreta=NULL;

    for(planeta_nombre planeta=0;planeta<5;planeta++){
        combustible=crear_combustible(planeta);
        torreta=crear_torreta(planeta);

        lista_agregar_al_principio(l_combustible,combustible);
        lista_agregar_al_principio(l_torreta,torreta);
    }

    

    //liberar memoria
    //lista_destruir(l_combustible, destruir_cosa(combustible));
    //lista_destruir(l_torreta, destruir_cosa(torreta));


    //objeto_t *objeto=crear_objeto(NIVEL1SE);
    //printf("%f %f\n",objeto->posicion[0][0],objeto->posicion[0][1]);
    return 1;
}