
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
                //disparar
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

void calcular_centro_inf(const float escala,const float posicion_nave_x, float *centro){
    if((posicion_nave_x - *centro) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x - VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
    else if((*centro - posicion_nave_x) * escala > VENTANA_ANCHO / 2 * MARGEN_ANCHO)
        *centro = posicion_nave_x + VENTANA_ANCHO / 2 * MARGEN_ANCHO / escala;
}

void calcular_escala(figura_t **figuras, planeta_nombre *planeta_actual,float *escala, float *centro){
    float max[2];
    float min[2];
    extremos_figura(figuras[*planeta_actual],max,min);
    float planeta_alto=max[1]-min[1];
    float planeta_ancho=max[0]-min[0];
    *escala = VENTANA_ALTO * 1.0 / planeta_alto;
    if((VENTANA_ANCHO * 1.0 / (planeta_ancho + min[0])) < *escala)
        *escala = VENTANA_ANCHO * 1.0 / (planeta_ancho + min[0]);
    *centro = (planeta_ancho + min[0]) / 2;
    printf("centro:%.2f ancho:%.2f alto:%.2f \n" ,*centro, planeta_ancho,planeta_alto);
}


