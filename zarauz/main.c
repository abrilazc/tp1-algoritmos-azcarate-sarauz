#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//#include "polilinea.h"
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
        destruir_bloque(memoria,cantidad_figuras);
        return 1;
    }

    /*figura_t nave=cargar(nave);
    printf("%zd\n %s\n",cantidad_poli_fig(nave),nombre_fig(nave));*/
    size_t jk=0;
    figura_t *fig_generica=memoria[0];
    while(jk<cantidad_figuras){
        printf("%s\n",nombre_fig(fig_generica));
        jk++;
        fig_generica=memoria[jk];
    }

    printf("\nson %zd figuras\n",cantidad_figuras);

    destruir_bloque(memoria,cantidad_figuras);


/*
    figura_t *figura=figura_crear(f);
    if(figura==NULL){
        printf("da nULL");
    }else{
        printf("esto anda\n");
        //char nombre1[20];
        printf("%zd\n %s\n",cantidad_poli_fig(figura),nombre_fig(figura));
    }
    figura_destruir(figura);

    figura_t *figura1=figura_crear(f);
    if(figura1==NULL){
        printf("da nULL");
    }else{
        printf("esto anda\n");
        //char nombre1[20];
        printf("%zd\n %s\n %s\n",cantidad_poli_fig(figura1),nombre_fig(figura1),tipo_fig(figura1));
        float x,y;
        polilinea_obtener_punto(polilinea_fig(figura1),0,&x,&y);
        printf("%f\n %f\n",x,y);
        printf("%s\n",tipo_fig(figura1));
    }
    figura_destruir(figura);
*/

    fclose(f);

    return 0;
}