#include "figura.h"

#include <stdint.h>

//tipos de dato
struct figura{
    char nombre[LONG_NOM];
    figura_tipo_t figura;
    bool infinito;
    size_t cantidad_polilineas;
    polilinea_t **polilineas;
};

typedef struct figura figura_t;

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    static const char* tipo[]={
    [ICONO]="Icono",
    [NIVEL]="Nivel",
    [SPRITE]="Sprite",
    [PLANETA]="Planeta",
    [BASE]="Base",
    [COMBUSTIBLE]="Combustible",
    [TORRETA]="Torreta",
    [REACTOR]="Reactor"};
    return tipo[figura];
}

//creacion y destruccion
bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){

    if (!f) return false;

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
    color_t color=color_crear(encabezado>>15,(encabezado>>13)&MASK_G,(encabezado>>13)&MASK_B);  

    polilinea_t *polilinea=polilinea_crear_vacia(n,color);
    if(polilinea==NULL) return NULL;

    float posicion[2];
    for(size_t i=0;i<n;i++){
        
         if(fread(&posicion,sizeof(float),2,f)!=2){
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
figura_t *figura_crear(FILE *f){
    figura_t *figura=malloc(sizeof(figura_t));
    if(figura==NULL) return NULL;
    
    if(leer_encabezado_figura(f,figura->nombre,&figura->figura,&figura->infinito,&figura->cantidad_polilineas)==0) return NULL;

    size_t cantidad_polilineas=figura->cantidad_polilineas;

    polilinea_t **conjunto_polilineas=malloc(sizeof(polilinea_t*)*cantidad_polilineas);
    size_t i=0;
    //polilinea_t *polilinea=leer_polilinea(f);
    //figura->polilinea[i]=polilinea;
    while(i<cantidad_polilineas){
        conjunto_polilineas[i]=leer_polilinea(f);
        i++;
    }
    figura->polilineas=conjunto_polilineas;

    return figura;
}

void figura_destruir(figura_t *figura){
    size_t j=0;
    size_t i=figura->cantidad_polilineas;
    printf("destruyendo polilineas");
    while(j<i){
        polilinea_destruir(figura->polilineas[i]);
        printf("destruidas %zd figuras\n",j);
        j++;
    }
    
    free(figura);
}

//getters
char *nombre_fig(const figura_t *figura){
    return (char *)figura->nombre;
}
bool infinito_fig(const figura_t *figura){
    return figura->infinito;
}
char *tipo_fig(const figura_t *figura){
    return (char *)figura_tipo_a_cadena(figura->figura);
}
size_t cantidad_poli_fig(const figura_t *figura){
    return figura->cantidad_polilineas;
}
polilinea_t **polilinea_fig(const figura_t *figura){
    return figura->polilineas;
}
figura_t *cargar(const figura_t **bloque,char *nombre_figura,size_t cantidad){
    size_t i=0;
    figura_t *figura=(figura_t *)bloque[i];
    while(i<cantidad){       
        if(strcmp(figura->nombre,nombre_figura)==0)
            return figura;
        i++;
        figura=(figura_t *)bloque[i];
    }
    return NULL;
}


//gestion de bloques
figura_t **crear_figuras(FILE *f,size_t *i){
    figura_t **bloque_figuras=malloc(sizeof(figura_t*));
    if(!bloque_figuras) return NULL;
    figura_t *figura0=figura_crear(f);

    bloque_figuras[0]=figura0;
    while((*i)<5){
        (*i)++;
        figura_t **aux=realloc(bloque_figuras,sizeof(figura_t)*((*i)+1));
        if(!aux){
            free(aux);
            return NULL;
        }
        bloque_figuras=aux;
        bloque_figuras[*i]=figura_crear(f);
    }
    return bloque_figuras;
}

void destruir_bloque(figura_t **bloque,size_t i){
    size_t j=0;
    printf("destruyendo figuras");
    while(j<i){
        figura_destruir(bloque[j]);
        printf("destruidas %zd figuras\n",j);
        j++;
    }
    free(bloque);
}