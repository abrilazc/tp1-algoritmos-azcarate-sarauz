#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"
#include "fisica.h"


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

    
    figura_t **nave=figuras[2];

    float pos_nave[2]={0,0};
    float velocidad[2] ={0,0};
    float aceleracion[]={0,-5*G}; //BORRAR
    bool chorro_prendido = false;
    size_t frame=0;
    // Queremos que todo se dibuje escalado por f:
    float f = 10;
    // END código del alumno

    unsigned int ticks = SDL_GetTicks();
    while(1) {
        frame++;
        printf("\nframe: %zd posicion: (%.2f,%.2f) velocidad: (%.2f,%.2f)  ",frame,pos_nave[0],pos_nave[1],velocidad[0],velocidad[1]);
        computar_velocidad(velocidad,aceleracion);
        trasladar(pos_nave,velocidad);
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
    free(nave);
    //destruir_bloque(figuras, cantidad_figuras);
    // END código del alumno

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

