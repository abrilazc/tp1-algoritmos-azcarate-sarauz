#include <stdio.h>

/*typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

const float* posicion_torretas(planeta_nombre nombre){
    const float* cantidad[]={
    [NIVEL1NE]={(0,0,0)},
    [NIVEL1SE]={(0,0,0)},
    [NIVEL1R]={(815,309,0)},
    [NIVEL1NW]={(0,0,0)},
    [NIVEL1SW]={(0,0,0)}
    };
    return cantidad[nombre];
}
*/

int main(void){

    //float prueba[3]=posicion_torretas(NIVEL1NE);
    float *prueba[3]={(0,0,0),(815,309,0)};
    printf("%f\n",prueba[0][1]);
    

    return 1;
}