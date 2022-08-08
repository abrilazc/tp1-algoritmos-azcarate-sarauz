#include <stddef.h>
#include <stdio.h>
#include "caracteres.h"




int main(void){
    size_t i=sizeof(*polilinea_caracter('a'))/(2*sizeof(float));
    printf("%zd",i);
    return 1;
}

//float **puntero=polilinea_caracter('a');

//polilinea_t *polilinea=polilinea_crear();