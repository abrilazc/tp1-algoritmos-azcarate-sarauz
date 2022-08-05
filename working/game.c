
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "game.h"
//#include "nave.h"
#include "figura.h"



figura_t ***inicio(size_t cant_figuras[MAX_TIPOS]){

    FILE *f = fopen("figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return NULL;
    }
    size_t i=0;
    figura_t **memoria=crear_figuras(f, &i);
    fclose(f);


    figura_t ***figuras=malloc(sizeof(figura_t***)*8);

    for(figura_tipo_t i=ICONO;i<MAX_TIPOS;i++){
    figuras[i]=cargar_tipo(memoria,i);
    }
    return figuras;
}
