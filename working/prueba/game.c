
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
/*
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
void clear_renderer(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
}
*/