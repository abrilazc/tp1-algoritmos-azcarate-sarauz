#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"
#include "fisica.h"
#include "nave.h"
#include "pantalla.h"


int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Gravitar");

    //int dormir = 0;

    // BEGIN código del alumno
    // Mi nave:
    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    
    nave_t *nave=nave_crear(figuras[2]);

    //float velocidad[2]={0,0};
    float posicion[2] ={VENTANA_ANCHO/2,VENTANA_ALTO/2};
    nave_posicion_set(nave, posicion);
    
    
    //bool held_down=false;
    // Queremos que todo se dibuje escalado por f:
    //float f = 1;
    // END código del alumno
    pantalla_inicio(nave, figuras,NULL, window, renderer, event);
    //unsigned int ticks = SDL_GetTicks();
    /*while(1) {
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
            // BEGIN código del alumno
            registrar_teclas(nave, event, &held_down);
           

            if (event.type == SDL_KEYDOWN) {
                // Se apretó una tecla
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        // Prendemos el chorro:
                        chorro_set(nave);
                        break;
                    case SDLK_DOWN:
                        //prendemos el escudo
                        if(!held_down){
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
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        // Apagamos el chorro:
                        chorro_clear(nave);
                        break;
                    case SDLK_DOWN:
                        held_down=false;
                        break;
                }
            }
            // END código del alumno
            continue;
        }
        clear_renderer(renderer);
        //SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        //SDL_RenderClear(renderer);
        //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
        
        // BEGIN código del alumno
        // Dibujamos la nave escalada por f en el centro de la pantalla:
        frame++;
        computar_posicion(nave, NULL);
        nave_velocidad_get(nave, velocidad);
        nave_posicion_get(nave, posicion);
        printf("\nframe: %zd posicion: (%.2f,%.2f) velocidad: (%.2f,%.2f)  ",frame,posicion[0],posicion[1],velocidad[0],velocidad[1]);
        render_nave(nave, renderer, figuras, f);
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
    }*/
    
    // BEGIN código del alumno
    nave_destruir(nave);
    destruir_figuras(figuras, cantidad_figuras);
    // END código del alumno

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

