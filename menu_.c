#include <stdlib.h>
#include <stdio.h>
void CARGA(){  //carga el  mensaje, lo guarda y lo cierra
    FILE *archi;

    char letra;
    int pos, i; //i es la cantidad de caracteres

    archi=fopen("MensajeEncriptado.txt", "r");

    if(archi==NULL){
        printf("no existe el archivo");
    }

    while(!(feof(archi))){
    fscanf(archi, "%c", &letra);
    fscanf(archi, "%d", &pos);
    printf("Caracter: %c | Posicion: %d\n ", letra, pos);
    i+=1;
    }
    printf("la cantidad de posiciones es %d\n", i);
    fclose(archi);
}
int main(void) {

  CARGA();
  return 0;
}
