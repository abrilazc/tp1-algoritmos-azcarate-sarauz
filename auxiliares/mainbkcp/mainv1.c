//main para ver el manejo de datos de polilineas
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "figura.h"
#include "config.h"

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Gravitar");

    int dormir = 0;

    if(argc != 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse \"%s\"\n", argv[1]);
        return 1;
    }

    size_t cantidad_figuras=0;
    figura_t **memoria=crear_figuras(f,&cantidad_figuras);

    if(memoria==NULL){
        printf("problema de memoria (NULL)");
        fclose(f);
        //destruir_bloque(memoria,cantidad_figuras);
        return 1;
    }
    fclose(f);
    printf("\nson %zd figuras\n",cantidad_figuras);

    figura_t *fig_generica=cargar_nombre(memoria,"NAVE");
    printf("%s\n",nombre_fig(fig_generica));

    figura_t **nave=cargar_tipo(memoria,SPRITE);//no rediomiensiono la memoria aca
    printf("exito\n");
    float pos[2]={1,0};
    float escala=10;
    if(dibujar_figura(renderer, nave, "NAVE",pos,escala)==false) printf("fail");

    free(nave);
    destruir_bloque(memoria,cantidad_figuras);

    return 0;
}
