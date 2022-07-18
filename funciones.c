#include "funciones.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "polilinea.h"

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    static const char* tipo[]={[ICONO]="Icono",[NIVEL]="Nivel",[SPRITE]="Sprite",[OTRO]="Otro"};
    return tipo[figura];
}

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){

    if (!f) return false;

    //if(fread(nombre,sizeof(char),LONG_NOM,f)!=LONG_NOM) return false; cual conviene?
    if(fread(nombre,sizeof(char[LONG_NOM]),1,f)!=1) return false;

    uint8_t byte1;
    if(fread(&byte1,sizeof(uint8_t),1,f)!=1) return false;
    
    *infinito=(byte1>>6)&INF_MASK;
    *tipo=(byte1>>1)&TIPO_MASK;

    uint16_t byted2;
    if(fread(&byted2,sizeof(uint16_t),1,f)!=1) return false;
    *cantidad_polilineas=(size_t)byted2;

    return true;
}

polilinea_t *leer_polilinea(FILE *f){
    uint16_t encabezado;
    if(fread(&encabezado,sizeof(uint16_t),1,f)!=1) return NULL;

    size_t n=(encabezado&CANTIDAD_PUNTOS_MASK);
    
    polilinea_t *polilinea=polilinea_crear_vacia(n);
    if(polilinea==NULL) return NULL;

    color_t color=color_crear(encabezado>>15,(encabezado>>13)&MASK_G,(encabezado>>13)&MASK_B);
    if(!(polilinea_setear_color(polilinea,color))){
        polilinea_destruir(polilinea);
        return NULL;
    }
  
    float posicion[2];

    for(size_t i=0;i<n;i++){
        
         if(fread(&posicion,sizeof(float),2,f)!=2){//(fread(posicion,sizeof(float[2]),1,f)!=1) cual conviene?
            polilinea_destruir(polilinea);
            return NULL;
        }

        if(polilinea_setear_punto(polilinea,i,posicion[0],posicion[1])==0){
            polilinea_destruir(polilinea);
            return NULL;
        }
    }

    return polilinea;
}