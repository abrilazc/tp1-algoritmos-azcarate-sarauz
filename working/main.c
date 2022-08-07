#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"
#include "fisica.h"
#include "nave.h"
#include "pantalla.h"
#include "nivel.h"

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
    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    bool pantalla_inicio_ingreso=true;
    bool nivel_inicio=true;
    //planeta_nombre planeta_actual=1;
    nave_t *nave=nave_crear(figuras[2]);

    float velocidad[2]={0,0};
    float posicion[2] ={VENTANA_ANCHO/2,VENTANA_ALTO/2};
    nave_posicion_set(nave, posicion);
    bool held_down=false;
    size_t frame=0;
    // Queremos que todo se dibuje escalado por f:
    //float f = 1;
    // END código del alumno

    unsigned int ticks = SDL_GetTicks();
    while(1) {
        frame++;
        
        printf("\nframe: %zd posicion: (%.2f,%.2f) velocidad: (%.2f,%.2f)  ",frame,posicion[0],posicion[1],velocidad[0],velocidad[1]);
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
            // BEGIN código del alumno

           

            registrar_teclas(nave, event, &held_down);
            // END código del alumno
            continue;
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
        
        // BEGIN código del alumno
        // Dibujamos la nave escalada por f en el centro de la pantalla:
        if(nivel_inicio){
            if(pantalla_inicio_ingreso){
                cargar_pantalla_inicio(nave);
                pantalla_inicio_ingreso=false;
            }
            pantalla_inicio_mostrar(nave, figuras, renderer);
            }
        //pantalla_inicio(nave, figuras, renderer);
        nave_velocidad_get(nave, velocidad);
        nave_posicion_get(nave, posicion);
        
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
    nave_destruir(nave);
    destruir_figuras(figuras, cantidad_figuras);
    // END código del alumno

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

