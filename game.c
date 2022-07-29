
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "figura.h"
#include "nave.h"

// UWU PRUEBA DE GIT UWU 
typedef enum{
    INICIO,
    NIVEL1NE,
    NIVEL1SE,
    NIVEL1R,
    NIVEL1NW,
    NIVEL1SW,
}niveles_t;

figura_t ***inicio(){

    FILE *f = fopen("/figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return 1;
    }
    figura_t *auxiliar=NULL;
    figura_t ***figuras=malloc(8*sizeof(figura_t ***));
    if(figuras==NULL){
        fclose(f);
        return NULL;
    }
    figura_t **figuras_tipo=malloc(sizeof(figura_t **));
    while((auxiliar=figura_crear(f))!=NULL){
        tipo_fig(auxiliar);
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