#include "figura.h"

int main(){

    FILE *f = fopen("/figuras.bin", "rb");
    if(f == NULL) {
        fprintf(stderr, "No pudo abrirse el archivo\n");
        return 1;
    }
    
    size_t cant_figuras=0;
    figura_t **memoria=crear_figuras(f, &cant_figuras);
    fclose(f);

    figura_t **figuras_icono=cargar_tipo(memoria,ICONO);
    figura_t **figuras_nivel=cargar_tipo(memoria,NIVEL);
    figura_t **figuras_sprite=cargar_tipo(memoria,SPRITE);
    figura_t **figura_planeta=cargar_tipo(memoria,PLANETA);
    figura_t **figura_base=cargar_tipo(memoria,BASE);
    figura_t **figura_combustible=cargar_tipo(memoria,COMBUSTIBLE);
    figura_t **figura_torreta=cargar_tipo(memoria,TORRETA);
    figura_t **figura_reactor=cargar_tipo(memoria,REACTOR);

    figura_t **figuras[8]={
        figuras_icono,
        figuras_nivel,
        figuras_sprite,
        figura_planeta,
        figura_base,
        figura_combustible,
        figura_torreta,
        figura_reactor
    };

    figura_t *planeta=figuras[3][2];
    printf("%s\n", nombre_fig(planeta));
    return 0;
}