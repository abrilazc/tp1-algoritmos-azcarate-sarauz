
#include "game.h"

figura_t ***inicio(size_t cant_figuras[MAX_TIPOS]){

    FILE *f = fopen("figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return NULL;
    }
    size_t i=0;
    figura_t **memoria=crear_figuras(f, &i);
    fclose(f);


    figura_t ***figuras=malloc(sizeof(figura_t**)*8);

    for(figura_tipo_t i=ICONO;i<MAX_TIPOS;i++){
    figuras[i]=cargar_tipo(memoria,i,&cant_figuras[i]);
    }

    free(memoria);
    return figuras;
}

void registrar_teclas(nave_t *nave, SDL_Event event, bool *held_down){
    if (event.type == SDL_KEYDOWN) {
    // Se apretó una tecla
        switch(event.key.keysym.sym) {
            case SDLK_UP:
                // Prendemos el chorro:
                chorro_set(nave);
                break;
            case SDLK_DOWN:
                //prendemos el escudo
                if(!*held_down){
                    if(escudo_get(nave))
                        escudo_clear(nave);
                    else
                        escudo_set(nave);
                }
                    
                break;
            case SDLK_RIGHT:
                //rotar horario
                nave_rotar_horario(nave);
                break;
            case SDLK_LEFT:
                //rotar antihorario
                nave_rotar_antihorario(nave);
                break;
            case SDLK_SPACE:
                set_disparar(nave);
                break;
        }
    }
    else if (event.type == SDL_KEYUP) {
        // Se soltó una tecla
        switch(event.key.keysym.sym){
            case SDLK_UP:
                // Apagamos el chorro:
                chorro_clear(nave);
                break;
            case SDLK_DOWN:
                *held_down=false;
                break;
        }
    }
}
void render_nave(nave_t *nave, SDL_Renderer *renderer, figura_t ***figuras, size_t f){
    float posicion[2];
    nave_posicion_get(nave, posicion);
    if(dibujar_figura(renderer, figuras[2], "NAVE",posicion,f)==false) printf("fail");
        if(chorro_get(nave)) {
            if(dibujar_figura(renderer, figuras[2], "NAVE+CHORRO",posicion,f)==false) printf("fail");
        }
        if(escudo_get(nave))
            if(dibujar_figura(renderer, figuras[2], "ESCUDO2",posicion,f)==false) printf("fail");
}

void calcular_escala_inf(float posicion_nave_y, float *escala){
    if(posicion_nave_y > VENTANA_ALTO * MARGEN_ALTURA)
        *escala = VENTANA_ALTO * MARGEN_ALTURA / posicion_nave_y;
    if(*escala < ESCALA_MINIMA)
        *escala = ESCALA_MINIMA;

}
/*
bool camara_inf(nave_t *nave, bool *inicio){
    float pos[2];
    float v[2];
    float camara=posicion_camara_get(nave);
    nave_posicion_get(nave, pos);
    nave_velocidad_get(nave, v);
    
    if(pos[0]>=(camara+((VENTANA_ANCHO / 2) * MARGEN_ANCHO)))
        camara+=(v[0]*DT);
    }
    
    nave_velocidad_set(nave, v);
    return false;
}
*/
void render_nave_inf(nave_t *nave, SDL_Renderer *renderer, figura_t ***figuras, size_t f){
    float posicion[2];
    nave_posicion_get(nave, posicion);
    if(dibujar_figura(renderer, figuras[2], "NAVE",posicion,f)==false) printf("fail");
        if(chorro_get(nave)) {
            if(dibujar_figura(renderer, figuras[2], "NAVE+CHORRO",posicion,f)==false) printf("fail");
        }
        if(escudo_get(nave))
            if(dibujar_figura(renderer, figuras[2], "ESCUDO2",posicion,f)==false) printf("fail");
}


void calcular_centro_inf(float escala,float posicion_nave_x, float *centro){
    if((posicion_nave_x - *centro) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x - VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
    else if((*centro - posicion_nave_x) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x + VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
}

void min_max(figura_t **figuras, planeta_nombre planeta_actual,float min[2],float max[2]){
    polilinea_t *pol_planeta=(polilinea_fig(figuras[planeta_actual]))[0];
    size_t n=polilinea_cantidad_puntos(pol_planeta);
    float x,y;

    polilinea_obtener_punto(pol_planeta,0,&min[0],&min[1]);
    max[0]=min[0];
    max[1]=min[1];

    for(size_t i=1;i<n;i++){
        polilinea_obtener_punto(pol_planeta,i,&x,&y);

        if(x<min[0]){
            min[0]=x;
        }
        else if(x>max[0]){
            max[0]=x;
        }
        if(y<min[1]){
            min[1]=y;
        }
        else if(y>max[1]){
            max[1]=y;
        }
        else
            continue;
    }
}
void calcular_escala(figura_t **figuras, planeta_nombre planeta_actual,float *escala, float *centro){
polilinea_t *pol_planeta=(polilinea_fig(figuras[planeta_actual]))[0];
    size_t n=polilinea_cantidad_puntos(pol_planeta);

    float x,y;
    float planeta_x_min, planeta_x_max;
    float planeta_y_min, planeta_y_max;
    polilinea_obtener_punto(pol_planeta,0,&planeta_x_min,&planeta_y_min);
    planeta_x_max=planeta_x_min;
    planeta_y_max=planeta_y_min;
    for(size_t i=1;i<n;i++){
        polilinea_obtener_punto(pol_planeta,i,&x,&y);
        
        if(x<planeta_x_min){
            planeta_x_min=x;
        }
        else if(x>planeta_x_max){
            planeta_x_max=x;
        }
        if(y<planeta_y_min){
            planeta_y_min=y;
        }
        else if(y>planeta_y_max){
            planeta_y_max=y;
        }
        else
            continue;
    }
    float planeta_alto=planeta_y_max-planeta_y_min;
    float planeta_ancho=planeta_x_max-planeta_x_min;
    *escala = VENTANA_ALTO * 1.0 / planeta_alto;
    if((VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min)) < *escala)
        *escala = VENTANA_ANCHO * 1.0 / (planeta_ancho + planeta_x_min);
    *centro = (planeta_ancho + planeta_x_min) / 2;
    printf("centro:%.2f ancho:%.2f alto:%.2f \n" ,*centro, planeta_ancho,planeta_alto);
}

//void game_over(nave_t *nave,nivel_t **niveles, figura_t ***figuras);

