#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * \brief Verifica si el valor recibido es numérico POS x POS de ARRAY
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int isNumber(char str[])
{

   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;

}//end of isNumber

/**
 * \brief Imprime un mensaje para el usuario solicitando txt
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getString(char message[],char input[])
{
    printf("%s",message);
    scanf ("%s", input);
}//end of getString

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará los chars ingresados
 * \return 1 si el texto contiene solo números
 */
int getStringNumbers(char message[],char input[])
{
   char aux[250];
   getString(message,aux);
   if(isNumber(aux))
   {
      strcpy(input,aux);
      return 1;
   }

   return 0;

}//end of getStringNumbers

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errortMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit el menor valor que no tolera la funcion
 * \param hiLimit  el mayor valor que no tolera la función
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[250];
    int auxInt;
    while(1)
    {
        if (!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor/igual %d\n",lowLimit,hiLimit);
            continue;
        }

        return auxInt;
    }

}//end of getValidInt

/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \return option variable para realizar la/s opciones del menú
 *
 */
int menu()
{
   int option = 0;

   puts(" ==================ABM====================");
   printf("| 1- AGREGAR PERSONA                      |\n");
   printf("| 2- BORRAR PERSONA                       |\n");
   printf("| 3- IMPRIMIR LISTADO ORDENADO POR NOMBRE |\n");
   printf("| 4- IMPRIMIR GRAFICO DE EDADES           |\n");
   printf("| 5- SALIR                                |\n");
   puts(" =========================================\n");

   option = getValidInt("Ingresar una de las opciones del programa\n","DATO INCORRECTO\n", 0, 5);

   return option;

}//end function menu

/**
 * \brief Busca el primer lugar no utilizado en el array.
 * \param lista Es el array en el cual buscar.
 * \param arrayLenght Indica la longitud del array
 * \return Si no hay lugares libres (-1) y si los hay la posición del mismo (i)
 */
int foundFreePlace(EPersona list[], int arrayLenght)
{
    int i;
    for(i=0; i < arrayLenght; i++)
    {
       if(list[i].status == 0)
       {
           return i;
       }
    }
    return -1;

}//end of foundFreePlace

/**
 * \brief Busca la primer ocurrencia de un producto mediante su DNI
 * \param lista Es el array en el cual buscar.
 * \param arrayLenght Indica la longitud del array.
 * \param dni Es el valor que se busca.
 * \return Si no hay ocurrencia (-1) y si la hay la posición de la misma (i)
 */
int FoundByDni(EPersona list[], int arrayLenght, int dni)
{
    int i;
    for(i=0; i < arrayLenght; i++)
    {
       if(list[i].dni == dni && list[i].status == 1)
       {
           return i;
       }
    }
    return -1;
}//end of FoundByDni

/**
 * \brief Inicializa el status en un array de lista
 * \param lista Es el array en el cuál buscar.
 * \param arrayLenght Indica la longitud del array.
 * \return -
 */
 void setStatus(EPersona list[], int arrayLength)
{
    int i;
    for(i=0; i < arrayLength; i++)
    {
        list[i].status = 0;
    }
}//end setStatus

/**
 * \brief Verifica si el valor recibido contiene solo letras POS x POS del ARRAY
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 (cero) si no lo es
 *
 */
int isOnlyletters(char str[])
{

   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}//end of isOnlyletters

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetters(char message[],char input[])
{

    char aux[256];
    getString(message,aux);
    if(isOnlyletters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}//end of getStringLetters

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}//end of clean_stdin

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetters(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        clean_stdin();
        break;
    }

}//end of getValidString

/**
 * \brief Carga los valores de EPersona
 * \param list Es el array de persona
 * \param freePlaceIndex Indica la posicion a setear
 * \param nameAux nombre de la Persona
 * \param ageAux Edad de la persona
 * \param DNIAux Documento de indentidad de la persona
 * \return -
 *
 */
void setPerson(EPersona list[],int freePlaceIndex,char nameAux[], int ageAux, int DNIAux)
{
    strcpy(list[freePlaceIndex].nombre,nameAux);
    list[freePlaceIndex].edad = ageAux;
    list[freePlaceIndex].dni = DNIAux;
    list[freePlaceIndex].status = 1;
}

/**
 * \brief Solicita los datos a usuario y lo carga validando los mismos
 * \param list Es el struct array de persona
 * \return -
 *
 */
void loadPerson(EPersona list[])
{
   int indexFreePlace = 0, MAX_PEOPLE = 20;
   int qtyLetters;
   char nameAux[51];
   int ageAux;
   int DNIAux;

      indexFreePlace = foundFreePlace(list, MAX_PEOPLE);

         if(indexFreePlace == -1)
         {
            printf("COMPLETADA LA CAPACIDAD PARA CARGAR DATOS DE PERSONAS!!\n");
         }
         else
         {
            puts("===COMIENZO CARGA PERSONAS===\n");

            getValidString("Ingrese el nombre: ","El NOMBRE SOLO PUEDE TENER LETRAS\n", nameAux);

            qtyLetters = strlen(nameAux);

            if(qtyLetters > 50)
            {
               printf("NOMBRE LARGO, MAXIMO PERMITIDO '50' CARACTERES!!\n");
            }
            else
            {
               ageAux = getValidInt("Ingresar la edad de la persona:\n","MANTENER UN RANGO COHERENTE DE EDAD\n", 0,120 );
               DNIAux = getValidInt("Ingresar el DNI de la persona:\n","DATO INCORRECTO FAVOR DE REINGRESAR\n", 0,99999999);
               setPerson(list, indexFreePlace, nameAux, ageAux, DNIAux);
            }

         }

   system("pause");
   system("cls");

}//end of loadPerson

/**
 * \brief Busca el primer lugar con status 1
 * \param lista Es el array en el cual buscar.
 * \param arrayLenght Indica la longitud del array
 * \return Si no hay lugares utilizados 0 y si los hay 1
 */
int foundUsedPlace(EPersona list[], int arrayLenght)
{
    int i;
    for(i=0; i < arrayLenght; i++)
    {
       if(list[i].status == 1)
       {
           return 1;
       }
    }
    return 0;
}//end of foundUsedPlace

/**
 * \brief Solicita al usuario el ingreso del DNI para borrar de la lista a la persona
 * \param list Es el struct array de persona
 * \param length el lago del array
 * \return -
 *
 */
void deletePerson(EPersona list[], int length)
{
   int DNIAux, index;

   puts("===BORRAR PERSONAS DE LA LISTA===\n");

   DNIAux = getValidInt("Ingresar el DNI de la persona:\n","DATO INCORRECTO FAVOR DE REINGRESAR\n", 0,99999999);

   index = FoundByDni(list, length, DNIAux);

   if(index == -1)
   {
      puts("EL DNI INGRESADO NO EXISTE EN EL SISTEMA");
   }
   else
   {
      list[index].status = 0;
      puts("Persona borrada con exito\n");
   }


   system("pause");
   system("cls");

}//end of deletePerson

/**
 * \brief Imprime el listado de las personas ordenadas por nombre
 * \param list Es el struct array de persona
 * \param length el lago del array
 * \return -
 *
 */
void listPerson(EPersona list[], int length)
{
   int i,j;
   EPersona auxList;

   puts("===LISTA DE PERSONAS===\n");

   for(i=0; i<length-1; i++)
   {
      if(list[i].status == 0)
      {
         continue;
      }
      for(j=i+1; j<length; j++)
      {
         if(list[j].status == 0)
         {
            continue;
         }
         if(stricmp(list[i].nombre, list[j].nombre) > 0)
         {
            auxList = list[i];
            list[i] = list[j];
            list[j] = auxList;
         }
      }
   }

   for(i=0; i<length; i++)
   {
      if(list[i].status == 0)
      {
         continue;
      }
      printf("NOMBRE: %12s EDAD:%4d\tDNI: %8d\n",list[i].nombre, list[i].edad, list[i].dni);

   }

   system("pause");
   system("cls");

}//end of listPerson

/**
 * \brief Imprime gráfico de barras con respecto a las edades de las personas
 * \param list Es el struct array de persona
 * \param length el largo del array
 * \return -
 *
 */
void graphicOfAges(EPersona list[], int length)
{
   int lessOr18=0, between19_35=0, upper35=0 ;
   int maxValue=0;
   int i,j;

   for(i=0; i<length; i++)
   {
      if(list[i].status == 0)
      {
         continue;
      }
      if(list[i].edad<=18)
         lessOr18++;
      if(list[i].edad>18 && list[i].edad<36)
         between19_35++;
      if(list[i].edad>35)
         upper35++;
   }

   int accumulator[] = {lessOr18,between19_35,upper35};


   for(i=0; i<3; i++)
   {
      if(accumulator[i] > maxValue)
         maxValue = accumulator[i];
   }

   for(i=maxValue; i>0; i--)
   {
      for(j=0; j<3; j++)
      {
         if(accumulator[j]>=i)
         {
            printf("     *");
         }
         else
            printf("      ");
      }
      puts("");
   }
   puts("   <18   19-35   >35\n\n");

   system("pause");
   system("cls");

}//end of graphicOfAges

