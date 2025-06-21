//cadenas de caracteres.c
/// Actividad recomendada
/// Objetivo: comprender las herramientas b�sicas para poder trabajar con cadenas de caracteres en el Lenguaje C.
/// 1- Analizar el c�digo del archivo cadenas de caracteres.c. Compilar y ejecutar
/// el programa para observar las maneras correctas de asignar valores a las cadenas de caracteres.
///
/// 2- Estudiar y verificar el funcionamiento de la funci�n STRCMP() inclu�da en la librer�a string.h.
///
/// 3- Desarrollar un programa que permita identificar si un apellido ingresado por teclado,
/// se encontrar� antes o despu�s del apellido "Lopez" en una lista de contactos ordenados alfab�ticamente.
#include<stdio.h>
#include<string.h> //incluye librer�a para el manejo de cadenas de caracteres (string)

int main(){
    //Declara cadena de caracteres
    char nombre[50]="JUAN";//En la declaraci�n, es posible asignarle un valor con el "=" y valor a guardar entre "".
    char apellido[50];
    int i;

    //Verificaci�n de funcionamiento
    printf("En nombre[50] se almaceno: %s\n\n", nombre); //Muestra el contenido de nombre[50]

    printf("\n\tNombre tiene almacenado una palabra que inicia con: %c\n\n", nombre[0]);
    //Asignaci�n de un string
    apellido[0]="GONZALEZ";//Manera INCORRECTA de asignaci�n
    printf("Opcion incorrecta: %s    <-- asignando con el =\n\n",apellido);

    //La siguiente asignaci�n no es posible que sea compilada. Verificar quitando las //
    //apellido="GONZALEZ";

    strcpy(apellido,"PEREZ");//Manera CORRECTA, empleando la funci�n String Copy.
    printf("Opcion correcta: %s     <-- usando strcpy\n\n",apellido);//se utiliza la funci�n STRCPY de la biblioteca <string.h> para asignar apellido

    printf("\n\nMensaje impreso con un repetir para:\n\t");
    for (i=0; i < strlen(apellido);i++){
        printf("%c", apellido[i]);
    }

    //Ingreso nuevos valores por teclado
    printf("\n\nIngrese su Nombre: ");
    scanf(" %s",nombre); //Observar el formato de lectura tipo String, que se indica con %s

    printf("Ingrese su Apellido: ");
	scanf(" %s",apellido);

    printf("Nueva carga: %s %s\n",nombre,apellido);//Muestra los nuevos valores ingresados
    printf("Largo de NOMBRE: %d\n",strlen(nombre)); //strlen indica longitud de nombre

    fflush(stdin);//Vac�a el buffer del Teclado.

	printf("Ingrese OTRO Nombre y Apellido, en un solo rengl�n,\n separado por un espacio: ");
	scanf(" %s %s",nombre,apellido);
	//scanf(" %s",apellido);
	printf("\nUsted ingreso: %s %s\n",nombre,apellido);//Muestra los nuevos valores ingresados
	printf("\n\nNotar que el 'espacio' marca el fin de la primera cadena de caracteres, \ny lo ingresado luego del mismo se almacena en el siguiente arreglo \nde caracteres.\n\n");

	if(strcmp(nombre,apellido)==0){
            printf("El nombre es igual al apellido\n\n");}
        else{
            printf("El nombre NO es igual al apellido\n\n");
    }

    return 0;
}
/*Estudiar y verificar el funcionamiento de la funci�n STRCMP()
inclu�da en la librer�a string.h

Desarrollar un programa que permita identificar si un apellido
ingresado por teclado, se encontrar� antes o despu�s del apellido
"Lopez" en una lista de contactos ordenados alfab�ticamente.*/
