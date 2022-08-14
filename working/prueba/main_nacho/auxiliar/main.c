#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"
#include "figura.h"
#include "game.h"
//#include "fisica.h"


int main() {

    size_t cantidad_figuras[8]={0,0,0,0,0,0,0,0};
    figura_t ***figuras=inicio(cantidad_figuras);
    if(figuras==NULL)
        return 1;

    figura_t *fig_generica=cargar_nombre(figuras[2],"NAVE");
    printf("%s\n",nombre_fig(fig_generica));
    size_t j=0;
    for(size_t i=0;i<8;i++){
    j+=cantidad_figuras[i];
    printf("Cantidad tipo %zd: %zd\n",i,cantidad_figuras[i]);
    }

    printf("%zd\n",j);
    for(size_t i=1;i<6;i++){
        char planeta_p[9]="PLANETA";
        char ii=i+48;
        strcat(planeta_p,&ii);
        printf("%s\n",planeta_p);
    }
    
    return 0;
}

