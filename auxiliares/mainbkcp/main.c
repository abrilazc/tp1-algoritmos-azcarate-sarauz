#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"
#include "fisica.h"


int main() {

    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    /*
    figura_t **nave=figuras[2];

    float pos_nave[2]={0,0};
    float velocidad[2] ={0,0};
    float aceleracion[2]={0,-5*G}; //BORRAR
    */

    figura_t *fig_generica=cargar_nombre(figuras[2],"NAVE");
    printf("%s\n",nombre_fig(fig_generica));
    size_t j=0;
    for(size_t i=0;i<8;i++){
    j+=cantidad_figuras[i];
    printf("Cantidad tipo %zd: %zd\n",i,cantidad_figuras[i]);
    }

    printf("%zd\n",j);

    
    destruir_figuras(figuras,cantidad_figuras);


    return 0;
}

