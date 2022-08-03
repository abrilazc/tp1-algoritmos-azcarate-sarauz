#include "figura.h"


//tipos de dato
struct figura{
    char nombre[LONG_NOM];
    figura_tipo_t tipo_figura;
    bool infinito;
    size_t cantidad_polilineas;
    polilinea_t **polilineas;
};
/*struct varias_figuras{
    figura_t **figura;
    size_t cantidad;
};*/
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

//setters
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
/*
void figura_trasladar(figura_t *figura, double traslacion[2]){
    for(size_t i=0; i<(figura->cantidad_polilineas);i++){
        polilinea_trasladar((figura->polilineas)+i, traslacion);
    }
}

void figura_rotar(figura_t *figura, double angulo){
    for(size_t i=0; i<(figura->cantidad_polilineas);i++){
        polilinea_rotar((figura->polilineas)+i, angulo);
    }
}
*/

//creacion 
figura_t *figura_crear(FILE *f){
    figura_t *figura=malloc(sizeof(figura_t));
    if(figura==NULL)return NULL;
    
    if(leer_encabezado_figura(f,figura->nombre,&figura->tipo_figura,&figura->infinito,&figura->cantidad_polilineas)==0) return NULL;

    size_t cantidad_polilineas=figura->cantidad_polilineas;

    figura->polilineas=malloc(sizeof(polilinea_t*)*cantidad_polilineas);
    
    if(figura->polilineas==NULL){
        figura_destruir(figura);
        return NULL;
    }
    
    size_t i=0;

    while(i<cantidad_polilineas){
        if((figura->polilineas[i]=leer_polilinea(f))==NULL)return NULL;
        i++;
    }

    return figura;
}
figura_t **crear_figuras(FILE *f,size_t *i){
    figura_t **bloque_figuras=malloc(sizeof(figura_t*));
    if(!bloque_figuras) return NULL;

    while((bloque_figuras[*i]=figura_crear(f))!=NULL){
        /*if((bloque_figuras[*i]=figura_crear(f))==NULL){
            destruir_bloque(bloque_figuras,(*i));
            return NULL;
        }*/
        (*i)++;
        figura_t **aux=realloc(bloque_figuras,sizeof(figura_t*)*((*i)+1));
        if(!aux){
            destruir_bloque(bloque_figuras,(*i));
            return NULL;
        }
        bloque_figuras=aux;
    }
    return bloque_figuras;
}
/*varias_figuras_t *crear_varias(FILE *f){
    figura_t **bloque_figuras=malloc(sizeof(figura_t*));
    if(!bloque_figuras) return NULL;
    size_t i=0;
    while((bloque_figuras[i]=figura_crear(f))!=NULL){
        figura_t **aux=realloc(bloque_figuras,sizeof(figura_t*)*(i+1));
        if(!aux){
            destruir_bloque(bloque_figuras,i);
            return NULL;
        }
        bloque_figuras=aux;
        i++;
    }
    varias_figuras_t *varias_figuras=malloc(sizeof(figura_t*)*i+sizeof(size_t));
    if(varias_figuras==NULL) return NULL;
    for(size_t j=0,j<i,j++){
    varias_figuras->figura[i]=bloque_figuras[i];
    }
    varias_figuras->cantidad=i;
    return varias_figuras;
}*/

//getters
char *nombre_fig(const figura_t *figura){
    return (char *)figura->nombre;
}
bool infinito_fig(const figura_t *figura){
    return figura->infinito;
}
figura_tipo_t tipo_fig(const figura_t *figura){
    return (figura_tipo_t)figura->tipo_figura;
}
size_t cantidad_poli_fig(const figura_t *figura){
    return figura->cantidad_polilineas;
}
polilinea_t **polilinea_fig(const figura_t *figura){
    return figura->polilineas;
}

//gestor de memoria
figura_t *cargar_nombre(figura_t **bloque,char *nombre_figura){
    size_t i=0;
    figura_t *figura=NULL;
    while(bloque[i]!=NULL){       
        figura=(figura_t *)bloque[i];
        if(strcmp(figura->nombre,nombre_figura)==0)
            return figura;
        i++;
    }
    return NULL;
}
figura_t **cargar_tipo(figura_t **bloque,figura_tipo_t tipo){
    size_t i=0;
    size_t j=0;
    figura_t **figura=malloc(sizeof(figura_t*));
    if(figura==NULL) return NULL;//no estoy redimensionando memoria
    while(bloque[i]!=NULL){
        figura_tipo_t tipo2=tipo_fig(bloque[i]);
        if(tipo==tipo2){
            figura[j]=bloque[i];
            j++;
            figura_t **aux=realloc(figura,sizeof(figura_t*)*(j+1));
            if(aux==NULL){
                return figura;
            }
            figura=aux;
        }
        i++;
    }
    if(j==0) return NULL;
    return figura;
}
/*bool dibujar_poli(figura_t *figura, size_t cantidad,float escalado,float posicion[2]){
    figura_t *dibujo=cargar(figura,nombre,cantidad);
    if(!dibujo) return false;
    
    size_t cant_poli=figura->cantidad_polilineas;
    
    for(size_t i=0,i<cant_poli,i++){
        polilinea_t *poli_dibu=figura->polilineas[i];
        size_t cant_punt=polilinea_cantidad_puntos(poli_dibu);
        float matriz[2][cant_punt];//revisar que esto sea legal
        for(size_t j=0,j<cant_punt,j++){
            //if(lodeabajo==0) return NULL;
            polilinea_obtener_punto(poli_dibu,j,matriz[0][i],matriz[1][i]);// asi es la firma -> float *x, float *y
        }
        //existe polilinea_setear_color(polilinea_t *polilinea, color_t color)
        //pero no le encuentro mucho sentido...
        uint8_t r, g, b;
        color_a_rgb(poli_dibu->color, &r, &g, &b); //en funciones.h habría que hacer #include "color.h"
        SDL_SetRenderDrawColor(renderer, 0xFF, r, g, b);
        //arreglar matriz[][] de las cosas de abajo
        SDL_RenderDrawLine(render,(matriz[i][0]+posicion[0])*escalado,-(matriz[i][1]+posicion[1])*escalado,(matriz[i+1][0]+posicion[0])*escalado,-(matriz[i+1][1]+posicion[1])*escalado);
    }
    return true;
}
*/

//destruir
void figura_destruir(figura_t *figura){
    size_t j=0;
    size_t i=figura->cantidad_polilineas;
    
    while(j<i){
        polilinea_destruir(figura->polilineas[j]);
        j++;
    }
    free(figura->polilineas);
    free(figura);
}
void destruir_bloque(figura_t **bloque,size_t i){
    size_t j=0;
    while(j<i){
        figura_destruir(bloque[j]);
        j++;
    }
    free(bloque);
}
//void destruir_varias(varias_figuras_t *)