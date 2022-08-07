

//pantallas
void pantalla_inicio(nave_t *nave,figura_t ***figura,nivel_t **niveles){
    
    float planetas[7][2]={
        (388, 218),//base
        (663, 473),//p1
        (671, 145),//p2
        (110, 79),//p3
        (204, 455),//p4
        (111, 307),//p5
        (457, 364)//estrella
    };
    
    set_posicion_nave(nave,planetas[0]);

    figura_t **figura_base=figura[4];
    figura_t **figura_planeta=figura[3];
    figura_t **figura_nave=figura[2];
        
    float centro_grav[2]=planetas[6];
    bool aceleracion=FALSE;
    
    
    while(1){
                   
        //SDL:
        //chequear botones;
        //fondo negro;

        //dibujar texto;

        estado_nave(nave);
        dibujar_planetas(planetas);
        iteracion_nave_inicio(nave,planetas);
    }
}
void cargar_nivel(nave_t *nave,nivel_t *nivel,figura_t ***figuras){//quizas saco ***figuras

    float centro_grav[2]=NULL;
    float escala=1;
    bool inf=get_tipo_infinito(nivel);

    
    //iteraciones 
    
    while(1){
       
        size_t cantidad_combustible=get_combustible(nivel);
        size_t cantidad_torretas=get_torretas(nivel);
        bool reactor_nivel=get_reactor(nivel);
        size_t cantidad_balas=get_balas(lista_balas);

        //SDL:
            //chequear botones;
            //fondo negro;
 
        estado_nave(nave);

        if(inf){
            centro_grav[2]={0,-ALTO}
            escala=obtener_escala();
            acomodar_camara();
            polilinea_extendida();//dibuja la pollinea en 3 posiciones consecutivas
            iteracion_nave_nivel_inf(nave,nivel);
        }else{
            escala=obtener_escala();
            iteracion_nave_nivel_no_inf(nave,nivel);
        }

        //dibujar texto

        if(cantidad_combustible!=0) iteracion_combustible(); 
        if(cantidad_torretas!=0) iteracion_torretas();
        if(reactor_nivel) iteracion_nivel();
        if(cantidad_balas!=0) iteracion_balas();
    }
}

//fisicas nave
void estado_nave(nave_t *nave, float pos_g[2]){
    //revisa direccion
    //revisa velocidad
    computar_velocidad(nave,pos_g);
    //revisa posicion
    //revisa combustible
    //chequear puntos
    //chequear vidas
}

//iteraciones inicio
void dibujar_planetas(float planeta[7][2]){
    
    dibujar_figura(renderer,figura_base,"BASE",planetas[0],1);

    for(size_t i=1;i<6;i++){
        char planeta_p[9]="PLANETA";
        char ii=i+48;
        strcat(planeta_p,&ii);
        dibujar_figura(renderer,figura_planeta,planeta_p,planetas[i],1);
    }

    dibujar_figura(renderer,figura_planeta,"ESTRELLA",planetas[7],1);
}
void iteracion_nave_inicio(nave_t *nave,float planeta[7][2]l){
    iteraciones_colisiones_inicio(nave,planeta);
    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteraciones_colisiones_inicio(nave_t nave, float planeta[7][2]){
    
    if(0<posicion[0]<VENTANA_ANCHO || 0<posicion[1]<VENTANA_ALTO){
        rebotar(nave);
    }
    float radio=6;

    if(colision(posicion,planeta[6],radio)){
        perder_vida(nave);
        set_posicion(nave,planeta[0]);
    }

    for(size_t i=1,i<6,i++){
        if(colision(posicion,planeta[i],radio)){
            nombre_nivel nombre=i-1;
            nivel_t *nivel=llamar_nivel(nombre);
            cargar_nivel(nave,nivel,figuras);
            return;// NULL;
        }
    }
}

//iteraciones niveles
void iteracion_nave_nivel_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteracion_nave_nivel_no_inf(nave_t nave,nivel_t nivel){

    //revisa choque limites
    //revisa choque polilinea

    dibujar_figura(renderer,figura_nave,"NAVE",posicion,1);
}
void iteracion_combustible(figura_t ***figuras,nivel_t nivel){
    figura_t **combustible=figuras[];
    float posicion_combustible[cantidad_combustible][2]=get_posicion_combustible(nivel);
    for(size_t i=0;i<cantidad_combustible,i++){
        dibujar_figura(renderer,combustible,"COMBUSTIBLE",posicion_combustible[i]);
    }    //falta colision (nave,tanque) 
}
void iteracion_torretas(figura_t ***figuras,nivel_t nivel){
    figura_t **torretas=figuras[];//posiciones(lista_torretas)
    float posicion_torretas[cantidad_torretas][2]=get_posicion_torretas(nivel);
    for(size_t i=0;i<cantidad_torretas;i++){
        if(interseccion(nave_pos,alcance_torretas[i])){//interseccion=colision
            //si puede hacer una bala:
            //dibujar_torreta_disparando;
            crear_nodo_bala(lista_bala);
            cantidad_balas++;
            //dibujar
        }else{
            dibujar_figura(renderer,torretas,"TORRETAS",posicion_torretas[i]);
        }
    }
}
void iteracion_nivel(figura_t ***figuras,nivel_t nivel){
    figura_t **reactor=figuras[];
    float posicion_reactor[2]=get_posicion_reactor(nivel);
    dibujar_figura(renderer,reactor,"REACTOR",posicion_reactor);
}
void iteracion_balas(figura_t ***figuras,nivel_t nivel){
    float balas_pos[cantidad_balas][2]=posiciones(lista_balas);
    //dibujar
    for(size_t j=0;j<cantidad_balas;j++){
        if(interseccion(nave_pos,balas_pos[i])){
            //pierde_vida;
            cantidad_torretas=cantidad(lista_torretas);
            torretas_pos=posiciones(lista_torretas);
            //dibujar
        }
    }

    if(cantidad_torretas!=0){
        for(size_t i=0;i<cantidad_torretas;i++){
            for(size_t j=0;j<cantidad_balas;j++){
                if(interseccion(torretas_pos[j],balas_pos[i])){
                    quitar_nodo(lista_torretas,torretas_pos[j]);
                    cantidad_torretas=cantidad(lista_torretas);
                    torretas_pos=posiciones(lista_torretas);
                    //dibujar
                }
            }
        }
    }

    for(size_t j=0;j<cantidad_balas;j++){
        size_t vida_bala=lista_balas->nodo_actual->vida;
        if(vida_bala>5){
            quitar_nodo//bala?
        }else{
            lista_balas->nodo_actualvida++;
        }
    }  
}