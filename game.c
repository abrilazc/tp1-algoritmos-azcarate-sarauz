
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "game.h"
#include "nave.h"
#include "figura.h"


typedef enum{
    INICIO,
    NIVEL1NE,
    NIVEL1SE,
    NIVEL1R,
    NIVEL1NW,
    NIVEL1SW,
}niveles_t;

void inicio(figura_t **figuras_tipo_lista, size_t n_fig[8]){
    FILE *f = fopen("/figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return 1;
    }

    figura_t ***figuras=malloc(8*sizeof(figura_t ***));
    if(figuras==NULL){
        fclose(f);
        return NULL;
    }
    figura_t **figuras_tipo=malloc(sizeof(figura_t **)*8);
    if(figuras_tipo==NULL){
        free(figuras);
        fclose(f);
        return NULL;
    }

    figura_t *auxiliar=NULL;

    for(int i=0; i<8; i++){
        figuras_tipo[i]=malloc(sizeof(figura_t *));
        if(figuras_tipo[i]==NULL){
            for(size_t n=0;n<=i;i++){
                free(figuras_tipo[n]);
            }
            free(figuras);
            fclose(f);
            return NULL;
        }
        n_fig[i]=0;
    }

    while((auxiliar=figura_crear(f))!=NULL){
        figura_tipo_t auxiliar_tipo=tipo_fig(auxiliar);
        figuras_tipo[tipo_fig(auxiliar)][n_fig[tipo_fig(auxiliar)]]=auxiliar; 
    }
    size_t cantidad_figuras=0;
    /*
    figura_t **memoria=crear_figuras(f,&cantidad_figuras);

    if(memoria==NULL){
        printf("problema de memoria (NULL)");
        fclose(f);
        //destruir_bloque(memoria,cantidad_figuras);
        return 1;
    }
    printf("\nson %zd figuras\n",cantidad_figuras);

    figura_t *fig_generica=cargar_nombre(memoria,"NAVE");
    printf("%s\n",nombre_fig(fig_generica));

/*  figura_t **planetas=cargar_tipo(memoria,"Planeta");
    figura_t *planeta_generico=cargar_nombre(planetas,"PLANETA4");
    figura_t *planeta1=planetas[1];
    printf("%s",nombre_fig(planeta_generico));
*/
//    destruir_bloque(memoria,cantidad_figuras);

    fclose(f);
}

void render_figura(float pos[2]){
    
    
}