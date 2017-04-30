#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int status;//Activa 1 o inactiva 0.

}EPersona;

//(1)========================================================================================
int isNumber(char a[]);//OK
void getString(char message[],char input[]);//OK
int getStringNumbers(char message[],char input[]);//OK
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);//OK
void getValidString(char requestMessage[],char errorMessage[], char input[]);//OK
void clean_stdin(void);//OK
int isOnlyletters(char str[]);//OK
int getStringLetters(char message[],char input[]);//OK

//===========================================================

int menu();//OK
void setStatus(EPersona list[], int arrayLenght);//OK
void setPerson(EPersona list[],int freePlaceIndex,char nameAux[], int ageAux, int DNIAux);//OK
int foundFreePlace(EPersona list[], int arrayLenght);//OK
int FoundByDni(EPersona list[], int arrayLenght, int dni);//OK
void loadPerson(EPersona list[]);//OK
int foundUsedPlace(EPersona list[], int arrayLenght);//OK
void deletePerson(EPersona list[], int length);//OK
void listPerson(EPersona list[], int length);//OK
void graphicOfAges(EPersona list[], int length);//OK

#endif // FUNCIONES_H_INCLUDED
