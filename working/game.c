
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "game.h"
//#include "nave.h"
#include "figura.h"

#define MAX_TIPOS 8

figura_t ***inicio(size_t *cant_figuras){

    FILE *f = fopen("figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return NULL;
    }
    
    size_t cant_figuras=0;
    figura_t **memoria=crear_figuras(f, &cant_figuras);
    fclose(f);


    figura_t ***figuras=malloc(sizeof(figura_t***)*8);

    for(figura_tipo_t i=ICONO;i<MAX_TIPOS;i++){
    figuras[i]=cargar_tipo(memoria,i);
    }
/*
    figura_t **figuras_icono=cargar_tipo(memoria,ICONO);
    figura_t **figuras_nivel=cargar_tipo(memoria,NIVEL);
    figura_t **figuras_sprite=cargar_tipo(memoria,SPRITE);
    figura_t **figura_planeta=cargar_tipo(memoria,PLANETA);
    figura_t **figura_base=cargar_tipo(memoria,BASE);
    figura_t **figura_combustible=cargar_tipo(memoria,COMBUSTIBLE);
    figura_t **figura_torreta=cargar_tipo(memoria,TORRETA);
    figura_t **figura_reactor=cargar_tipo(memoria,REACTOR);
    **figuras[0]=figuras
*/

    return figuras;
}
