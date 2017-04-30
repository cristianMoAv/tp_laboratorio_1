/**==================================================================================
 Name    	 : Trabajo práctio N°2
 Author  	 : Cristian Morales
 year    	 : 2017
 Description :

Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo
Ejemplo:

*
*      *
*      *      *
*      *      *
*      *      *
*      *      *
<18  19-35    >35
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
19 y 35, y 5 personas con edades mayores a 35.


 ====================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX_PEOPLE 20

int main()
{
    char seguir = 's';
    int optionMenu = 0;
    EPersona list[MAX_PEOPLE];
    int flag = 0;

   setStatus(list,MAX_PEOPLE);

//==============DATOS DE CARGA PARA TESTING=====================
setPerson(list,0,"Fabian", 5, 41007002);
setPerson(list,1,"Cristian", 33, 92898883);
setPerson(list,2,"Arsenio", 66, 20837527);
setPerson(list,3,"Luis", 21, 38233556);
setPerson(list,4,"Pablo", 16, 40253656);
setPerson(list,5,"Natalia", 13, 42151777);
setPerson(list,6,"Sabrina", 30, 32821715);
setPerson(list,7,"Leandro", 25, 38131025);
setPerson(list,8,"Soledad", 35, 31253321);
setPerson(list,9,"Lucas", 12, 42221656);
setPerson(list,10,"Micaela", 6, 43565721);
setPerson(list,11,"Florencia", 25, 38001323);
setPerson(list,12,"Antonio", 55, 22437519);
setPerson(list,13,"Lorenzo", 70, 20001002);
setPerson(list,14,"Milena", 23, 37999999);
setPerson(list,15,"Hugo", 40, 99999998);
setPerson(list,16,"Belen", 30, 32833211);
setPerson(list,17,"Marcos", 47, 30321012);
setPerson(list,18,"Carlos", 52, 92896543);

//==============================================================
    while(seguir=='s')
    {
         optionMenu = menu();

        switch(optionMenu)
        {
            case 1://Upload

               loadPerson(list);
                break;

            case 2://Delete

               flag = foundUsedPlace(list,MAX_PEOPLE);
               if(flag == 0)
               {
                  puts("FAVOR DE INGRESAR DATOS DE PERSONAS PARA PODER BORRAR");
                  system("pause");
                  system("cls");
                  break;
               }
               else

                  deletePerson(list, MAX_PEOPLE);

                break;

            case 3://List by Name

               flag = foundUsedPlace(list,MAX_PEOPLE);
               if(flag == 0)
               {
                  puts("FAVOR DE INGRESAR DATOS DE PERSONAS PARA LISTAR");
                  system("pause");
                  system("cls");
                  break;
               }
               else
                  listPerson(list, MAX_PEOPLE);

                break;

            case 4://Graphic by age

               flag = foundUsedPlace(list,MAX_PEOPLE);
               if(flag == 0)
               {
                  puts("FAVOR DE INGRESAR DATOS DE PERSONAS PARA LISTAR");
                  system("pause");
                  system("cls");
                  break;
               }
               else
                  graphicOfAges(list, MAX_PEOPLE);

                break;

            case 5:
                seguir = 'n';
                puts("GRACIAS POR PARTICIPAR!!");
                break;
        }
    }

   return 0;

}//end of main
