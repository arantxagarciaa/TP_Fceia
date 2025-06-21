#include <stdio.h>
#include <stdlib.h>
void CARGA(){ //carga el  mensaje, lo guarda y lo cierra
    FILE *archi;

    archi: fopen("MensajeEncriptado", "r");
      // Leer el archivo línea por línea
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }

    // Cerrar el archivo
    fclose(archivo);

}
void DESENCRIPTAR(){
    int contra;
    CARGA();
    printf("ingrese constraseña");
        scanf("%i", contra);
    if (contra == 3){
        printf("ingrese por teclado una cadena de caracteres");

    }
}
void ENCRIPTAR(){
    int clave;
    printf("ingrese clave de encriptacion");

}
void VALIDA(int *opc){

  while( *opc < 0 || *opc > 5){
   printf("error\n");
   printf("ingrese nuevamente una opcion de menu\n");
    scanf("%i", opc);
  }
}
void menu(int *opc){
    printf("MENU\n");
    printf("1: Desencriptar\n");
    printf("2: Encriptar\n");
    printf("3: Mostrar ocurrencia en el mensaje encriptado\n");
    printf("4: Mostrar orden en el mensaje desencriptado\n");
    printf("5: Salir\n");
        scanf("%i", opc);
    VALIDA(opc);
    printf("%i es el numero de opc\n", *opc);
}
int main(void) {
  int opc;

  menu(&opc);

  switch(opc){
    case 1:
      DESENCRIPTAR();
    case 2:
        ENCRIPTAR();
    case 3:
        ;
    case 4:
        ;
    case 5:
        ;
  };

  return 0;
}
