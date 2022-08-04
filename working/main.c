#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"


int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Gravitar");

    int dormir = 0;

    // BEGIN código del alumno
    // Mi nave:
    size_t cantidad_figuras=0;
    figura_t ***figuras=inicio(&cantidad_figuras);
    if(figuras==NULL)
        return 1;

    
    figura_t **nave=figuras[2];
    /*
    figura_t *planeta=figuras[3][2];
    printf("%s\n", nombre_fig(planeta));
    
    polilinea_t **polilinea_nave;
    polilinea_nave=polilinea_fig(figura_nave);
    size_t cp=polilinea_cantidad_puntos(polilinea_nave[0]);
    float nave[cp][2];
    for(size_t i=0; i<cp;i++){
        polilinea_obtener_punto(polilinea_nave[0],i,&nave[i][0],&nave[i][1]);
    }
    */
    //size_t nave_tam = 9;
    float pos_nave[2]={100,0};
    //double direccion=0;
    //size_t nivel= 0;
    // El chorro de la nave:
    //const float chorro[][2] = {{-4, 2}, {-8, 0}, {-4, -2}};
    //size_t chorro_tam = 3;

    bool chorro_prendido = false;

    // Queremos que todo se dibuje escalado por f:
    float f = 10;
    // END código del alumno

    unsigned int ticks = SDL_GetTicks();
    while(1) {
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
            // BEGIN código del alumno
            if (event.type == SDL_KEYDOWN) {
                // Se apretó una tecla
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        // Prendemos el chorro:
                        chorro_prendido = true;
                        break;
                    case SDLK_DOWN:
                        //
                    case SDLK_RIGHT:
                        //rotar horario
                        //nave_rotar_horario(nave, direccion); //TEST
                    case SDLK_LEFT:
                        //rotar antihorario
                        //nave_rotar_antihorario(nave, direccion);
                        break;
                }
            }
            else if (event.type == SDL_KEYUP) {
                // Se soltó una tecla
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        // Apagamos el chorro:
                        chorro_prendido = false;
                        break;
                }
            }
            // END código del alumno
            continue;
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
        
        // BEGIN código del alumno
        // Dibujamos la nave escalada por f en el centro de la pantalla:
        

        if(dibujar_figura(renderer, nave, "NAVE",pos_nave,f)==false) printf("fail");
        if(chorro_prendido) {
            // Dibujamos el chorro escalado por f en el centro de la pantalla:
            if(dibujar_figura(renderer, nave, "NAVE+CHORRO",pos_nave,f)==false) printf("fail");
        }

        // END código del alumno

        SDL_RenderPresent(renderer);
        ticks = SDL_GetTicks() - ticks;
        if(dormir) {
            SDL_Delay(dormir);
            dormir = 0;
        }
        else if(ticks < 1000 / JUEGO_FPS)
            SDL_Delay(1000 / JUEGO_FPS - ticks);
        ticks = SDL_GetTicks();
    }

    // BEGIN código del alumno
    // No tengo nada que destruir.
    // END código del alumno

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(nave);
    destruir_bloque(figuras, cantidad_figuras);
    SDL_Quit();
    return 0;
}

