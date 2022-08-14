//main para ver el manejo de datos de polilineas
//#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "figura.h"


int main(int argc, char *argv[]) {
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
    
    if(dibujar_figura(nave,"NAVE")==false) printf("fail");

    free(nave);
    destruir_bloque(memoria,cantidad_figuras);

    return 0;
}
