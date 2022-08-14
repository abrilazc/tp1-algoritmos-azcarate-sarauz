

//Creacion niveles
nivel_t *crear_nivel(figura_t **figura,planeta_t nombre){
    nivel_t *nivel_nuevo=malloc(sizeof(nivel_t));
    if(nivel_t==NULL) return NULL;

    nivel->figura=cargar_nombre(figura,nombre_asignado(nombre));//alguna funcion de figura_t por nombre;
    nivel->infinito=infinito_fig(figura);
    nivel->combustible=lista_combustible(nombre);
    nivel->torreta=lista_torreta(nombre);
    nivel->ractor=disponer_reactor(nombre);

    return nivel_nuevo;
}
nivel_t **crear_niveles(figura_t **figura){
    size_t cantidad_niveles=contar_tipo("NIVEL");
    nivel_t **conjunto_niveles=malloc(sizeof(nivel_t*)*cantidad_niveles);
    if(conjunto_niveles==NULL) return NULL;

    for(size_t i=0,i<cantidad_niveles,i++){
        figura_t *figura=conjunto_niveles[i];
        conjunto_nivel[i]=crear_nivel(figura);//ke
    }
    return conjunto_niveles;
}

