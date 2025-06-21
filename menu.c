#include <stdio.h>
#include <stdlib.h>
int VALIDA(int *opc){

  while (opc < 0 || opc > 3){
   printf("error\n");
   printf("ingrese nuevamente una opcion de menu\n");
  scanf("%i", opc);
  }
}
void menu(int *opc){
printf("MENU\n");
printf("1: pasar de H,M,S a seg\n");
printf("2: pasar de seg a H.M.S\n");
printf("3: comparar dos horas\n");
scanf("%i", opc);
//VALIDA(opc);
  printf("%i", *opc);
}
int main(void) {
  int opc;
  int *punt_opc = &opc;
  VALIDA(punt_opc);
  menu(&opc);

  return 0;
}
