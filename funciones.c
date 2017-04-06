#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * \brief suma las dos variables nroOne and nroTwo
 * \param nroOne corresponde al operador A
 * \param nroTwo corresponde al operador B
 * \return result que es la suma de A+B
 *
 */
float sum(float nroOne,float nroTwo)
{
      float result;
      result= nroOne + nroTwo;

    return result;
}//end of sum

/**
 * \brief resta las dos variables nroOne menos nroTwo
 * \param nroOne corresponde al operador A
 * \param nroTwo corresponde al operador B
 * \return result que es el resultado de A-B
 *
 */
float subtract(float nroOne,float nroTwo)
{
   float result;
   result = nroOne - nroTwo;

   return result;
}//end of subtract

/**
 * \brief multiplica nroOne y nroTwo
 * \param nroOne corresponde al operador A
 * \param nroTwo corresponde al operador B
 * \return result de  A x B
 *
 */
float multiply(float nroOne,float nroTwo)
{
   float result;
   result = nroOne * nroTwo;

   return result;
}//end of multiply

/**
 * \brief divide nroOne por nroTwo
 * \param nroOne corresponde al operador A
 * \param nroTwo corresponde al operador B
 * \return result de  A/B
 *
 */
float divide(float nroOne,float nroTwo)
{
   float result;
   result= nroOne / nroTwo;

   return result;

}//end of divide

/**
 * \brief toma el valor de operador A y se lo trabaja por recursividad
 * \param nroOne corresponde al operador A
 * \return result el factorial del valor ingresado como A
 *
 */
int factorial(int nroOne)
{
	if(nroOne == 1 || nroOne == 0)
   {
      return 1;
	}
	else
	{
      return nroOne*factorial(nroOne-1);
   }
}//end of factorial

/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \return option variable para realizar la/s opcion/es de la calculadora
 *
 */
int menu()
{
   int option = 0;

   puts(" ====================================");
   printf("| 1- Ingresar 1er operando (A = X)   |\n");
   printf("| 2- Ingresar 2do operando (B = Y)   |\n");
   printf("| 3- Calcular la suma (A+B)          |\n");
   printf("| 4- Calcular la resta (A-B)         |\n");
   printf("| 5- Calcular la division (A/B)      |\n");
   printf("| 6- Calcular la multiplicacion (A*B)|\n");
   printf("| 7- Calcular el factorial (A!)      |\n");
   printf("| 8- Calcular todas las operacione   |\n");
   printf("| 9- Salir                           |\n");
   puts(" ====================================\n");

   option = getValidInt("Ingrese una de las opciones disponibles\n","DATO INCORRECTO\n", 0, 10);

   return option;

}//end function menu

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
 * \param input Array donde se cargará el texto ingresado
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
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }

}//end of getValidInt


/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \param nroOne es el operador A
 * \param nroTwo es el operador B
 * \return auxOne variable para cargar en el operador A
 *
 */
int menuA(char nroOne, char nroTwo)
{
   int option = 1;
   float auxOne;
   char auxInput[250];

   puts(" ====================================");
   printf("| 1- Ingresar 1er operando (A = %c)   |\n", nroOne);
   printf("| 2- Ingresar 2do operando (B = %c)   |\n", nroTwo);
   printf("| 3- Calcular la suma (A+B)          |\n");
   printf("| 4- Calcular la resta (A-B)         |\n");
   printf("| 5- Calcular la division (A/B)      |\n");
   printf("| 6- Calcular la multiplicacion (A*B)|\n");
   printf("| 7- Calcular el factorial (A!)      |\n");
   printf("| 8- Calcular todas las operacione   |\n");
   printf("| 9- Salir                           |\n");
   puts(" ====================================\n");

   while(option == 1)
   {
      if(!getStringNumbersFloat("INGRESE OPERADOR A: ",auxInput))
      {
         printf("ERROR, INGRESE VALOR NUMERIOCO:\n");
      }
      else option++;
   }

   auxOne = atof(auxInput);
   puts("\n");
   system("pause");
   system("cls");

   return auxOne;

}//end function menuA

/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \param nroOne es el operador A
 * \param nroTwo es el operador B
 * \return auxTwo variable para cargar en el operador B
 *
 */
int menuB(float nroOne, char nroTwo)
{
   int option = 1;
   float auxTwo;
   char auxInput[250];

   puts(" ====================================");
   printf("| 1- Ingresar 1er operando (A = %.2f)\n", nroOne);
   printf("| 2- Ingresar 2do operando (B = %c)   |\n", nroTwo);
   printf("| 3- Calcular la suma (A+B)          |\n");
   printf("| 4- Calcular la resta (A-B)         |\n");
   printf("| 5- Calcular la division (A/B)      |\n");
   printf("| 6- Calcular la multiplicacion (A*B)|\n");
   printf("| 7- Calcular el factorial (A!)      |\n");
   printf("| 8- Calcular todas las operacione   |\n");
   printf("| 9- Salir                           |\n");
   puts(" ====================================\n");

   while(option == 1)
   {
      if(!getStringNumbersFloat("INGRESE OPERADOR B: ",auxInput))
      {
         printf("ERROR, INGRESE VALOR NUMERIOCO:\n");
      }
      else option++;
   }

   auxTwo = atof(auxInput);
   puts("\n");

   system("pause");
   system("cls");

   return auxTwo;

}//end function menuB

/**
 * \brief Verifica si el valor recibido es aceptado como flotante negativo o positivo
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int isNumberFloat(char str[]){

   int i=0;
   int qtyDots = 0;
   int qtyHyphen = 0;

   if (str[0] == '-')
      qtyHyphen++;

   if (qtyHyphen == 1)
   {
      while(str[i+1] != '\0')
      {

         if (str[i+1] == '.' && qtyDots == 0)
         {
            qtyDots++;
            i++;
            continue;
         }
         if (str[i+1] < '0' || str[i+1] > '9')

         return 0;
         i++;
      }
   }
   else
   {
      while(str[i] != '\0')
      {
         if (str[i] == '.' && qtyDots == 0)
         {
            qtyDots++;
            i++;
            continue;
         }
         if (str[i] < '0' || str[i] > '9')
            return 0;
         i++;
      }
   }

   return 1;

}//end of isNumberFloat

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param menssage Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números y un dot. O un 0 si tira error
*/
int getStringNumbersFloat(char message[],char input[]){

    char aux[250];
    getString(message,aux);
    if(isNumberFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}//end of getStringNumbersFloat

/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \return option variable para realizar la/s opcion/es de la calculadora
 *
 */
int menuA_B(float nroOne, float nroTwo)
{
   int option = 0;

   puts(" ====================================");
   printf("| 1- Ingresar 1er operando (A = %.2f)\n",nroOne);
   printf("| 2- Ingresar 2do operando (B = %.2f)\n",nroTwo);
   printf("| 3- Calcular la suma (A+B)          |\n");
   printf("| 4- Calcular la resta (A-B)         |\n");
   printf("| 5- Calcular la division (A/B)      |\n");
   printf("| 6- Calcular la multiplicacion (A*B)|\n");
   printf("| 7- Calcular el factorial (A!)      |\n");
   printf("| 8- Calcular todas las operacione   |\n");
   printf("| 9- Salir                           |\n");
   puts(" ====================================\n");

   option = getValidInt("Ingrese una de las opciones disponibles\n","DATO INCORRECTO\n", 0, 10);

   return option;

}//end function menuA_B

/**
 * \brief Imprime menú de opciones y toma el dato ingresado por usuario
 * \param nroOne el valor que contiene el Nro A
 * \param nroTwo el char en referencia al valor pendiente de ingreso en B
 * \return option variable para realizar la/s opcion/es de la calculadora
 *
 */
int menuTwoA_B(float nroOne, char nroTwo)
{
   int option = 0;

   puts(" ====================================");
   printf("| 1- Ingresar 1er operando (A = %.2f)\n",nroOne);
   printf("| 2- Ingresar 2do operando (B = %c)   |\n",nroTwo);
   printf("| 3- Calcular la suma (A+B)          |\n");
   printf("| 4- Calcular la resta (A-B)         |\n");
   printf("| 5- Calcular la division (A/B)      |\n");
   printf("| 6- Calcular la multiplicacion (A*B)|\n");
   printf("| 7- Calcular el factorial (A!)      |\n");
   printf("| 8- Calcular todas las operacione   |\n");
   printf("| 9- Salir                           |\n");
   puts(" ====================================\n");

   option = getValidInt("Ingrese una de las opciones disponibles\n","DATO INCORRECTO\n", 0, 10);

   return option;

}//end function menuTwoA_B
