#include <stdio.h>
#include <stdlib.h>
void CARGA(char *ordenado, int *cant){  //carga el  mensaje, lo guarda y lo cierra
    FILE *archi;
    // ya tengo la posicion del caracter, guardar en un arreglo en dicha posicion
    // carga devuelve el arreglo ya ordenado
    char letra;
    int pos; //cont es la cantidad de caracteres

    int cont=0;
    archi=fopen("MensajeEncriptado.txt", "r");

    if(archi==NULL){
        printf("no existe el archivo");
    }

    while(!(feof(archi))){
    cont+=1;
    fscanf(archi, " %c %d", &letra, &pos);

    ordenado[pos]= letra;
    *cant= cont;

    }

    for(int i=0; i < cont; i++){
        printf(" %d | %c\n", i, ordenado[i]);
    }

    fclose(archi);
}

void DESENCRIPTAR(char ordenado[],int num, char *resultado){
    int contra, i=0, aux=0;

    printf("ingrese constrasenia\n");
    scanf(" %d", &contra);
    printf("Mensaje desencriptado:\n");

    while(i<num){
        if((ordenado[i] - contra) < 44){
            aux = 44-(ordenado[i]- contra); // aux sirve para saber hasta donde se paso del rango
            resultado[i]= (char)(95-aux); //  resto ese valor al maximo del rango
        }
        else if ((ordenado[i] - contra) > 95){
            aux = (ordenado[i]- contra) - 95; // aux sirve para saber hasta donde se paso del rango
            resultado[i]= (char)(44+aux); //sumo ese valor al minimo del rango
            }
            else{
                resultado[i]=(ordenado[i] - contra);
                }
        printf("%c", resultado[i]);
        i++;
        }
        resultado[i] = '\0'; // cerrar cadena

    }
void desordenar(char letras[600], int posiciones[600], int n) {
   int i, j, tmpPos; char tmpChar;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1); // generación de un número aleatorio
        // Intercambiar letras
        tmpChar = letras[i];
        letras[i] = letras[j];
        letras[j] = tmpChar;
        // Intercambiar posiciones
        tmpPos = posiciones[i];
        posiciones[i] = posiciones[j];
        posiciones[j] = tmpPos;
      }
}
struct auxiliar{
    int pos[600];
    char mensaje[600];
};
void ENCRIPTAR(){
    FILE *nuevoarchi;
    struct auxiliar guardar;
    int clave, cant=0;
    char cadena[600];
    int pos[600];

    printf("ingrese clave de encriptacion\n");
    scanf("%i", &clave);

    printf("ingrese una cadena de caracteres sin espacios\n");
    scanf("%s", &cadena);

     while(cadena[cant]!= '\0'){
        pos[cant]=cant;
        cant++;
    }

    desordenar( cadena, pos, cant);

    nuevoarchi = fopen("NuevoEncriptado.txt", "w+");

    if (nuevoarchi == NULL) {
        printf("No se pudo crear el archivo.\n");
    }

    for(int j=0; j<cant;j++){
        guardar.mensaje[j] = cadena[j] + clave;
        guardar.pos[j] = pos[j];
        fprintf(nuevoarchi, "%c %d\n", guardar.mensaje[j], pos[j]);
        printf("%c  %d\n", guardar.mensaje[j], pos[j]);
    }

    fclose(nuevoarchi);
}
void VALIDA(int *opc){

  while( *opc < 0 || *opc > 5){
    printf("error\n");
    printf("ingrese nuevamente una opcion de menu\n");
    scanf("%i", opc);
  }
}
void OCURRENCIA(char ordenado[], int num){
    int  i=0, cont=0;
    char letra;

    printf("ingrese un caracter\n");
    while ((getchar()) != '\n');  // Limpia el búfer
    scanf("%c", &letra);

    while(i<num){
        if(ordenado[i]== letra){
            cont++;
        }
    i++;
    }
    printf("el caracter %c aparece %d veces\n", letra, cont);
}
void ORDENYCANT(char ordenado[], int n){
    int ocurrencias[26] = {0};      // contador de letras A-Z comenzado en 0
    char letras[26];
    int cantidades[26];

    for (int i = 0; i < 26; i++){ // Matriz de caracteres desde la 'A' a la 'Z'
        letras[i] = 'A' + i;
    }
    for (int i = 0; i < n; i++){ // Contar ocurrencias en el mensaje
        char c = ordenado[i];
        if (c >= 'A' && c <= 'Z') {
            ocurrencias[c - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {  // Copiar ocurrencias a arreglo auxiliar para ordenar
        cantidades[i] = ocurrencias[i];
    }
    for (int i = 0; i < 25; i++) {  // Ordenar por cantidad
        for (int j = i + 1; j < 26; j++) {
            if (cantidades[j] > cantidades[i]){
                int tempCant = cantidades[i]; // Intercambiar cantidades
                cantidades[i] = cantidades[j];
                cantidades[j] = tempCant;

                char tempLetra = letras[i]; // Intercambiar letras
                letras[i] = letras[j];
                letras[j] = tempLetra;
            }
        }
    }
    printf("\nLetra - Cantidad de ocurrencias (de mayor a menor):\n"); // Mostrar resultado
    for (int i = 0; i < 26; i++) {
        if (cantidades[i] >= 0) {
            printf("   %c - %d\n", letras[i], cantidades[i]);
        }
    }
}
void menu(int *opc){
    printf("\nMENU\n");
    printf("1: Desencriptar\n");
    printf("2: Encriptar\n");
    printf("3: Mostrar ocurrencia en el mensaje encriptado\n");
    printf("4: Mostrar orden en el mensaje desencriptado\n");
    printf("5: Salir\n");
        scanf("%i", opc);
    VALIDA(opc);
}

int main(void) {
  int opc, cont;
  char ordenado[600], desencriptado[600];

  CARGA(ordenado, &cont);
  menu(&opc);

    while(opc != 5){
      switch(opc){
        case 1:
          DESENCRIPTAR(ordenado, cont, desencriptado);
          menu(&opc);
          break;
        case 2:
            ENCRIPTAR();
            menu(&opc);
            break;
        case 3:
            OCURRENCIA(ordenado, cont);
            menu(&opc);
            break;
        case 4:
            ORDENYCANT(desencriptado, cont);
            menu(&opc);
            break;
        case 5:
            break;
        }
      }

  return 0;
}

