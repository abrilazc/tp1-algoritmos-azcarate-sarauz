#include "pantalla.h"
#include <string.h>

#define POS_BASE {388, 218}
#define POS_P1 {663, 473}
#define POS_P2 {671, 145}
#define POS_P3 {110, 79}
#define POS_P4 {204, 455}
#define POS_P5 {111,307}
#define POS_ESTRELLA {457, 364}

//pantallas

void pos_planetas(size_t n, float posicion[2]){
    float planetas[7][2]={
        POS_BASE,
        POS_P1,
        POS_P2,
        POS_P3,
        POS_P4,
        POS_P5,        
        POS_ESTRELLA
    };
    posicion[0]=planetas[n][0];
    posicion[1]=planetas[n][1];
}

static bool colisiones_inicio(nave_t *nave,nivel_t **niveles, float planeta_pos[7][2], planeta_nombre *planeta_actual);
void cargar_pantalla_inicio(nave_t *nave, planeta_nombre planeta_actual,bool spawn){
    float pos[2];
    if(spawn){
        pos_planetas(0,pos);
        vidas_reiniciar(nave);

    }
        
    else {
        if(planeta_actual==4)
        pos_planetas(3,pos);
    else if(planeta_actual==2)
        pos_planetas(5,pos);
    else
        pos_planetas(planeta_actual+1,pos);
    pos[0]+=2*RADIONAVE;
    }
    
    float v[2]={0,0};
    nave_posicion_set(nave, pos);
    nave_velocidad_set(nave,v);
}

void cargar_nivel(nave_t *nave, nivel_t **niveles, planeta_nombre planeta_actual){
    float posicion[2]={VENTANA_ANCHO/2,VENTANA_ALTO*0.9};
    float velocidad[2]={0,0};
    nave_posicion_set(nave, posicion);
    nave_velocidad_set(nave, velocidad);
    cargar_datos_nivel(niveles, planeta_actual);
}
void planeta_finito(nave_t* nave, SDL_Renderer *renderer, figura_t ***figuras, planeta_nombre *planeta_actual, float *f, float *centro, bool *inicio){
    calcular_escala(figuras[1],*planeta_actual,f, centro);
    if(colision_rebote_ni(nave, inicio))
        {
            cargar_pantalla_inicio(nave,*planeta_actual,false);
        }
    float position[2]={( - *centro + VENTANA_ANCHO / 2 / (*f))*(*f),0.0};
    render_nave(nave, renderer, figuras,1);
    printf("func_render_ni\n");
    if(*planeta_actual==NIVEL1R){
        printf("NIVEL1R");
        dibujar_figura(renderer,figuras[1], "NIVEL1R",position,*f);
    }
    if(*planeta_actual==NIVEL1NW){
        printf("NIVEL1NW");
        dibujar_figura(renderer,figuras[1], "NIVEL1NW",position,*f);
    }
}
bool dibujar_planeta_infinito(SDL_Renderer *renderer,figura_t **figuras,char *nombre, float posicion[2], float escala, float x_max, float x_min){
    figura_t *figura=cargar_nombre(figuras,nombre);
    polilinea_t **polilineas=polilinea_fig(figura);
    size_t cant_poli=cantidad_poli_fig(figura);
    
    for(size_t i=0;i<cant_poli;i++){
        polilinea_t *polilinea_original=polilineas[i];
        polilinea_t *prepolilinea=polilinea_clonar(polilinea_original);
        polilinea_t *postpolilinea=polilinea_clonar(polilinea_original);
        
        float pos_min[2]={posicion[0]+x_min,posicion[1]};
        float pos_max[2]={posicion[0]+x_max,posicion[1]};
        
        if(dibujar_polilinea(renderer, polilinea_original, posicion, escala)==false) return false;
        if(dibujar_polilinea(renderer, prepolilinea, pos_max, escala)==false) return false;
        if(dibujar_polilinea(renderer, postpolilinea, pos_min, escala)==false) return false;
    }
    return true;
}
void planeta_infinito(nave_t* nave, SDL_Renderer *renderer, figura_t ***figuras, planeta_nombre *planeta_actual, float *f, float *centro, bool *inicio){
    float posicion_nave[2];
    
    polilinea_t *planeta_pol=polilinea_fig(figuras[1][*planeta_actual])[0];
    nave_posicion_get(nave, posicion_nave);
    *f = 1;
    if(posicion_nave[1] > VENTANA_ALTO * MARGEN_ALTURA)
        *f = VENTANA_ALTO * MARGEN_ALTURA / posicion_nave[1];
    if(*f < ESCALA_MINIMA)
        *f= ESCALA_MINIMA;

    if((posicion_nave[0] - *centro) * (*f)> VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave[0] - VENTANA_ANCHO / 2 * MARGEN_ANCHO /(*f);
    else if((*centro - posicion_nave[0]) * (*f)> VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave[0] + VENTANA_ANCHO / 2 * MARGEN_ANCHO /(*f);
    float camara[2]={0,0};
    
    
    float min[2];
    float max[2];
    min_max(figuras[1], *planeta_actual, min,max);
    
    if((((posicion_nave[0]-*centro)*(*f)))>(VENTANA_ANCHO/2* MARGEN_ANCHO)){
        *centro=(posicion_nave[0]-VENTANA_ANCHO/2*MARGEN_ANCHO/(*f));
    }
    else if(((*centro-posicion_nave[0])*(*f))>VENTANA_ANCHO/2* MARGEN_ANCHO){
        *centro=(posicion_nave[0]+VENTANA_ANCHO/2*MARGEN_ANCHO/(*f));
    }
    
    if((posicion_nave[0]>max[0])){
        posicion_nave[0]-=max[0];
        nave_posicion_set(nave,posicion_nave);
        *centro-=max[0];
    }
    else if((posicion_nave[0]<min[0])){
        posicion_nave[0]+=max[0];
        nave_posicion_set(nave,posicion_nave);
        *centro+=max[0];
    }
    float pos_aux[2]={posicion_nave[0]+(-*centro)+VENTANA_ANCHO/2,posicion_nave[1]};
    nave_posicion_set(nave,pos_aux);
    render_nave(nave,renderer, figuras,1);
    nave_posicion_set(nave, posicion_nave);
    camara[0]=(-(*centro+VENTANA_ANCHO/2/(*f)))*(*f);
    if(*planeta_actual==NIVEL1NE){
        printf("NIVEL1NE: CENTRO: %.2f ESCALA: %.2f",*centro, *f);
        //dibujar_figura(renderer,figuras[1], "NIVEL1NE",camara,*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro-max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
        camara[0]=(-(*centro+max[0]+VENTANA_ANCHO/2/(*f)))*(*f);
        dibujar_polilinea(renderer,planeta_pol,camara,*f);
    }
    if(*planeta_actual==NIVEL1SE){
        printf("NIVEL1SE: MIN=(%.2f,%.2f) MAX=(%.2f,%.2f)",min[0],min[1],max[0],max[1]);
        dibujar_figura(renderer,figuras[1], "NIVEL1SE",camara,*f);
        camara[0]=(-*centro-max[0]+VENTANA_ANCHO/2/(*f))*(*f);
        dibujar_figura(renderer,figuras[1], "NIVEL1SE",camara,*f);

    }
    if(*planeta_actual==NIVEL1SW){
        printf("NIVEL1SW: MIN=(%.2f,%.2f) MAX=(%.2f,%.2f)",min[0],min[1],max[0],max[1]);
        dibujar_figura(renderer,figuras[1], "NIVEL1SW",camara,*f);
        camara[0]=(-*centro-max[0]+VENTANA_ANCHO/2/(*f))*(*f);
        dibujar_figura(renderer,figuras[1], "NIVEL1SW",camara,*f);
    }
    if(posicion_nave[1]>=VENTANA_ALTO){
            *inicio=true;
            cargar_pantalla_inicio(nave,*planeta_actual,false);
    }
    
}

bool pantalla_inicio_mostrar(nave_t *nave,figura_t ***figuras, nivel_t **niveles, SDL_Renderer *renderer, float *f, planeta_nombre *planeta_actual){
    *f=1;
    
    float planetas[7][2]={
        POS_BASE,
        POS_P1,
        POS_P2,
        POS_P3,
        POS_P4,
        POS_P5,        
        POS_ESTRELLA
    };


    float centro_grav[2];
    centro_grav[0]=planetas[6][0];
    centro_grav[1]=planetas[6][1];
    computar_posicion(nave, centro_grav);
    colision_rebote(nave);
    render_nave(nave,renderer, figuras, *f);
    dibujar_planetas(planetas,renderer,figuras);
    texto_bis(nave, figuras, renderer);
    return !colisiones_inicio(nave,niveles,planetas,planeta_actual);
}
void pantalla_nivel(nave_t *nave, figura_t ***figuras, SDL_Renderer *renderer, bool *goto_inicio, planeta_nombre *planeta_actual, float *f, float *centro){
    float posicion[2];
    nave_posicion_get(nave, posicion);
    //calcular_escala(posicion[1],f);
    //calcular_centro(*f,posicion[0],centro);
    computar_posicion(nave, NULL);
    
    if(*planeta_actual==NIVEL1R||*planeta_actual==NIVEL1NW)
        planeta_finito(nave, renderer, figuras, planeta_actual,f, centro, goto_inicio);
    else    
        planeta_infinito(nave, renderer, figuras, planeta_actual,f, centro, goto_inicio);
    texto_bis(nave, figuras, renderer);
}

//fisicas nave
void estado_nave(nave_t *nave, float pos_g[2]){
    computar_posicion(nave, pos_g);
    combustible_usar(nave);
    //revisa direccion
    //revisa velocidad
    //revisa posicion
    //revisa combustible
    //chequear puntos
    //chequear vidas
}

//iteraciones inicio
void dibujar_planetas(float planeta[7][2], SDL_Renderer *renderer, figura_t ***figuras){
    
    dibujar_figura(renderer,figuras[4],"BASE",planeta[0],1);
    dibujar_figura(renderer,figuras[3],"ESTRELLA",planeta[6],1);
    dibujar_figura(renderer,figuras[3],"PLANETA1",planeta[1],1);
    dibujar_figura(renderer,figuras[3],"PLANETA2",planeta[2],1);
    dibujar_figura(renderer,figuras[3],"PLANETA3",planeta[3],1);
    dibujar_figura(renderer,figuras[3],"PLANETA4",planeta[4],1);
    dibujar_figura(renderer,figuras[3],"PLANETA5",planeta[5],1);
        
}

static bool colisiones_inicio(nave_t *nave,nivel_t **niveles, float planeta_pos[7][2], planeta_nombre *planeta_actual){
    float posicion[2];
    nave_posicion_get(nave, posicion);
    for(size_t i=1;i<7;i++){
        if(dist_puntos(planeta_pos[i],posicion)<RADIONAVE){
            if(i==6){
                //choque contra estrella
                break;
            }
            else if(i==3)
                *planeta_actual=4;
            else if(i==5)
                *planeta_actual=2;
            else
                *planeta_actual=i-1;
            cargar_nivel(nave,niveles, *planeta_actual);
            return true;
        }
    }
    return false;
}
/*
//iteraciones niveles
void iteracion_nave_nivel_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteracion_nave_nivel_no_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}*/

//sirve para iterar contra COMNUSTIBLE si este no es 0
//cambiar a bool
bool interseccion_lista_nave(nave_t *nave,size_t *cantidad, lista_t *lista,figura_t **figuras,char *nombre){
    lista_iter_t *lista_iter;
    lista_iter=lista_iter_crear(lista);
    
    for(size_t i=0;i<(*cantidad);i++){
        float posicion_objeto[2];
        float posicion_nave[2]; 
        float r=100;//radio de colision
        
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_objeto);
        nave_posicion_get(nave,posicion_nave);
        
        figura_t *figura=cargar_nombre(figuras,nombre);
        size_t cantidad_poli=cantidad_poli_fig(figura);
        
        polilinea_t **polilineas=polilinea_fig(figura);
        size_t numero_poli=0;
        
        polilinea_t *polilinea=get_polilinea(polilineas,numero_poli,cantidad_poli);
        size_t puntos=polilinea_cantidad_puntos(polilinea);
        
        polilinea_trasladar(polilinea, posicion_objeto);
        
        float puntos_polilinea[puntos][2];

        for(size_t g=0; g<puntos;g++){
            polilinea_obtener_punto(polilinea, g, &puntos_polilinea[g][0], &puntos_polilinea[g][1]);
        }

        if(colision(puntos_polilinea, puntos, posicion_nave, r)){//posi=posicion_nave
            if(!strcmp(nombre,"TORRETA")){
                //disparar
                lista_iter_destruir(lista_iter);
                return true;
            }
            objeto_t *dest=lista_iter_borrar(lista_iter);
            lista_iter_destruir(lista_iter);
            destruir_cosa(dest);
            (*cantidad)--;
            return true;
        }
        lista_iter_avanzar(lista_iter);
    }
    lista_iter_destruir(lista_iter);
    return false;
}
void dibujar_lista(figura_t **figuras, lista_t *lista,char *nombre,SDL_Renderer *renderer, float escala){
    size_t cantidad=lista_largo(lista);
    lista_iter_t *liter;
    float direccion;
    float posicion[2];
    float origen[2]={0,0};
    liter=lista_iter_crear(lista);
    for(size_t i=0;i<cantidad;i++){
        objeto_t *objeto=lista_iter_ver_actual(liter);
        objeto_a_direccion(objeto,&direccion);
        objeto_a_posicion(objeto,posicion);
        rotar_punto(posicion,origen,direccion);
        dibujar_figura(renderer,figuras,nombre,posicion,escala);
        lista_iter_avanzar(liter);
    }
    lista_iter_destruir(liter);
}
//si cualquier punto de la lsita  1 alcanza las poliines del 2, destruye a este ultimo.
size_t interseccion_lista_lista(lista_t *lista, lista_t *lista_2,size_t *cantidad_2){
    size_t intersecciones=0;
    
    lista_iter_t *lista_iter;
    lista_iter_t *lista_iter_2;
    
    size_t cantidad=lista_largo(lista);
    float posicion_lista[2];
    float posicion_lista_2[2]; 
    float r=100;//radio de colision
    
    for(size_t i=0;i<cantidad;i++){
        bool pasar=false;
        lista_iter=lista_iter_crear(lista);
        objeto_t *objeto=lista_iter_ver_actual(lista_iter);
        objeto_a_posicion(objeto,posicion_lista);    

        for(size_t j=0;j<(*cantidad_2) || pasar==true;j++){
            lista_iter_2=lista_iter_crear(lista_2);
            objeto_t *objeto_2=lista_iter_ver_actual(lista_iter_2);
            objeto_a_posicion(objeto_2,posicion_lista_2);
            size_t puntos=sizeof(objeto_2)/sizeof(float);

            if(colision(&posicion_lista_2, puntos, posicion_lista, r)){
                objeto_t *dest=lista_iter_borrar(lista_iter);
                (*cantidad_2)--;
                lista_iter_destruir(lista_iter_2);
                destruir_cosa(dest);
                intersecciones++;
                pasar=true;
            }else{
                lista_iter_avanzar(lista_iter_2);
            }
        }
        lista_iter_destruir(lista_iter);
    }
    return intersecciones;
}
bool interseccion_nave_polilinea(nave_t *nave,figura_t **figuras,planeta_nombre nombre){
    float posicion_nave[2]; 
    nave_posicion_get(nave,posicion_nave);
    float r=50;

    figura_t *figura=figuras[nombre];
    size_t cantidad_poli=cantidad_poli_fig(figura);
    
    polilinea_t **polilineas=polilinea_fig(figura);
    
    for(size_t i=0;i<cantidad_poli;i++){
        polilinea_t *polilinea=polilineas[i];
        size_t puntos=polilinea_cantidad_puntos(polilinea);    
        float puntos_polilinea[puntos][2];

        for(size_t g=0; g<puntos;g++){
            polilinea_obtener_punto(polilinea, g, &puntos_polilinea[g][0], &puntos_polilinea[g][1]);
        }

        if(colision(puntos_polilinea, puntos, posicion_nave, r)){//posi=posicion_nave
            return true;
        } 
    }
    return false;
}


//static void dibujar_letras(char *texto, float posicion[2]){}

polilinea_t *simbolo_vida_crear(){
    const float simbolo_pol[][2]= {{8, 0}, {-1, 6}, {-4, 4}, {-4, 2}, {-2, 0}, {-4, -2}, {-4, -4}, {-1, -6}, {8, 0}};
    polilinea_t *simbolo_vida=polilinea_crear(simbolo_pol,9,color_crear(false,true,false));
    polilinea_rotar(simbolo_vida,3.0*PI/2);
    return simbolo_vida;
}

static void renderizar_vidas(nave_t *nave, SDL_Renderer *renderer){
    
    float posicion_vidas[3][2]={{VENTANA_ANCHO*(1.0/10), VENTANA_ALTO*(9.0/10)},{VENTANA_ANCHO*(1.35/10), VENTANA_ALTO*(9.0/10)},{VENTANA_ANCHO*(1.7/10), VENTANA_ALTO*(9.0/10)}};
    polilinea_t *vida=simbolo_vida_crear();
    size_t cant_vidas=vidas_get(nave);
    for(size_t i=0;i<cant_vidas;i++){
        dibujar_polilinea(renderer, vida, posicion_vidas[i],2);
    }

    polilinea_destruir(vida);
}   



void texto_bis(nave_t *nave, figura_t ***figuras, SDL_Renderer *renderer){
    //uint8_t vidas=vidas_get(nave);
    //float pos[2]={VENTANA_ALTO*MARGEN_ALTURA, VENTANA_ANCHO-VENTANA_ANCHO*MARGEN_ANCHO};
    
    renderizar_vidas(nave, renderer);  
} 