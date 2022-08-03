#include "figura.h"
#include "game.h"

int main(){
    figura_t ***figuras=inicio();
    if(figuras==NULL)
        return 1;

    figura_t *planeta=figuras[3][2];
    printf("%s\n", nombre_fig(planeta));
    figura_t *nave=figuras[2][0];
    polilinea_t **polilinea_nave;
    polilinea_nave=polilinea_fig(nave);
    size_t cp=polilinea_cantidad_puntos(polilinea_nave[0]);
    float dibujo_nave[cp][2];
    for(size_t i=0; i<cp;i++){
        polilinea_obtener_punto(polilinea_nave[0],i,&dibujo_nave[i][0],&dibujo_nave[i][1]);
    }
    printf("%.0f,%.0f\n",dibujo_nave[0][0],dibujo_nave[0][1]);
    return 0;
}