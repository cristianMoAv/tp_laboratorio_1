/*==================================================================================
 Name    	 : TP N°1
 Author  	 : Cristian Morales
 year    	 : 2017

Description : Calculadora con menú de opciones

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ===================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX_INT 12

int main()
{
   system("color 2F");//Allows me to change the color of the screen background; in this case green

   char keepOn ='s';
   int optionMain = 0, flag1=0, flag2=0, factorialResult;
   float numberA, numberB, sumResult, substResult, multiResult, divResult;

   while(keepOn == 's')
   {
      if (flag1 == 1 && flag2 == 1)
      {
         optionMain = menuA_B(numberA,numberB);//value to interact with the different options in the switch
         system("cls");//clean the pront windows
      }
      else if (flag1 == 1 && flag2 == 0)
      {
         optionMain = menuTwoA_B(numberA,'Y');
         system("cls");
      }
      else
      {
         optionMain = menu();
         system("cls");
      }

      switch(optionMain)
      {

         case 1:
            numberA = menuA('X','Y');

            flag1=1;//Ctrl for the called of option A

            break;

         case 2:

            numberB = menuB(numberA,'Y');

            flag2=1;//Ctrl for the called of option B

            break;

         case 3:

            if(flag1 == 1 && flag2 == 1)//Ctrl if the variables A and B have been loaded by the user
            {
               sumResult = sum(numberA,numberB);
               printf("SUMA DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,sumResult);
            }
            else if(flag1==1 && flag2==0)//ctrl of input in A and B
            {
               printf("SUMA INVALIDA\n INGRESAR VALOR EN \"B\"\n");
            }
            else if(flag1==0 && flag2==1)//ctrl of input in A and B
            {
               printf("SUMA INVALIDA\n INGRESAR VALOR EN \"A\"\n");
            }
            else
            {
               printf("INGRESAR VALORES EN \"A\" Y \"B\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 4:

            if(flag1 == 1 && flag2 == 1)
            {
               substResult = subtract(numberA,numberB);
               printf("RESTA DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,substResult);
            }
            else if(flag1 == 1 && flag2 == 0)
            {
               printf("RESTA INVALIDA\n INGRESAR VALOR EN \"B\"\n");
            }
            else if(flag1==0 && flag2==1)
            {
               printf("RESTA INVALIDA\n INGRESAR VALOR EN \"A\"\n");
            }
            else
            {
               printf("INGRESAR VALORES EN \"A\" Y \"B\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 5:

            if (flag1 == 1 && flag2 == 1)
            {
               if(numberB != 0)//Ctrl of the value B, because it can't be 0 (zero)
               {
                  divResult = divide(numberA,numberB);
                  printf("DIVISION DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,divResult);
               }
               else
               {
                  printf("DIVIDIR X 0(CERO) NO SE PUEDE\n");
               }
            }
            else if(flag1 == 1 && flag2 == 0)
            {
               printf("DIVISION INVALIDA\n INGRESAR VALOR EN \"B\"\n");
            }
            else if (flag1 == 0 && flag2 == 1)
            {
               printf("DIVISION INVALIDA\n INGRESAR VALOR EN \"A\"\n");
            }
            else
            {
               printf("INGRESAR VALORES EN \"A\" Y \"B\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 6:

            if (flag1 == 1 && flag2 == 1)
            {
               multiResult=multiply(numberA,numberB);
               printf("MULTIPLICION DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,multiResult);
            }
            else if(flag1==1 && flag2==0)
            {
               printf("MULTIPLICACION INVALIDA\n INGRESAR VALOR EN \"B\"\n");
            }
            else if (flag1 == 0 && flag2 == 1)
            {
               printf("MULTIPLICACION INVALIDA\n INGRESAR VALOR EN \"A\"\n");
            }
            else
            {
               printf("INGRESAR VALORES EN \"A\" Y \"B\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 7:

            if (flag1 == 1)
            {
               if (numberA < 0)
               {
                  printf("ERROR MATEMATICO\n");
                  printf("NUMEROS NEGATIVOS NO TIENEN FACTORIAL\n");
               }
               else if (numberA >= 0 && numberA < MAX_INT)
               {
                  numberA = (int)numberA;
                  factorialResult = factorial(numberA);
                  printf("FACTORIAL DE %.2f ES %d \n", numberA, factorialResult);
               }
               else if (numberA >= MAX_INT)
               {
                  printf("NUMERO \"A\" EXCEDE EL RANGO\n");
                  printf("NUMERO \"A\" PERMITIDO <= \"%d\"\n", MAX_INT);
               }
            }
            else
            {
               printf("INGRESAR VALOR EN \"A\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 8:

            if(flag1 == 1 && flag2 == 1)
            {
               sumResult = sum(numberA,numberB);
               printf("SUMA DE %.2f Y %.2f ES: %.4f\n", numberA,numberB,sumResult);

               substResult = subtract(numberA,numberB);
               printf("RESTA DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,substResult);

               multiResult=multiply(numberA,numberB);
               printf("MULTIPLICION DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,multiResult);

               if (numberA < 0)
               {
                  printf("ERROR MATEMATICO\n");
                  printf("NUMEROS NEGATIVOS NO TIENEN FACTORIAL\n");
               }
               else if (numberA >= 0 && numberA < MAX_INT)
               {
                  numberA= (int)numberA;
                  factorialResult = factorial(numberA);
                  printf("FACTORIAL DE %.2f ES %d \n", numberA, factorialResult);
               }
               else if (numberA >= MAX_INT)
               {
                  printf("NUMERO \"A\" EXCEDE EL RANGO\n");
                  printf("NUMERO \"A\" PERMITIDO <= \"%d\"\n", MAX_INT);
               }

               if(numberB != 0)
               {
                  divResult=divide(numberA,numberB);
                  printf("DIVISION DE %.2f Y %.2f ES: %.2f\n", numberA,numberB,divResult);
               }
               else
               {
                  printf("DIVIDIR X 0(CERO) NO SE PUEDE\n");
               }

            }
            else if(flag1 == 1 && flag2 == 0)
            {
               printf("INGRESAR VALOR EN \"B\"\n");
            }
            else if(flag1==0 && flag2==1)
            {
               printf("INGRESAR VALOR EN \"A\"\n");
            }
            else
            {
               printf("INGRESAR VALORES EN \"A\" Y \"B\"\n");
            }

            system("pause");
            system("cls");

            break;

         case 9:

            keepOn = 'n';

            break;

        }//end of switch

    }//end of while

   return 0;

}//end of main

