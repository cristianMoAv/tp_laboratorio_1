#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menu();//OK
int menuA(char nroOne, char nroTwo);//OK
int menuB(float nroOne, char nroTwo);//OK
int menuA_B(float nroOne, float nroTwo);//OK
int menuTwoA_B(float numberA,char x);//OK

float sum(float nroOne, float norTwo);//OK
float subtract(float nroOne, float norTwo);//OK
float multiply(float nroOne, float norTwo);//OK
float divide(float nroOne, float norTwo);//OK
int factorial(int nroOne);//OK

/*===========================================*/
void getString(char message[],char input[]);//OK
int isNumber(char a[]);//OK
int getStringNumbers(char message[],char input[]);//OK
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);//OK
int isNumberFloat(char str[]);//
int getStringNumbersFloat(char message[],char input[]);//OK

#endif
