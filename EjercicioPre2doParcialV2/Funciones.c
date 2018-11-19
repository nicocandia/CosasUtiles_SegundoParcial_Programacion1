#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define false 0
#define true 1
#define DATO_INVALIDO -1

static int verificarMail(char *arreglo);

static int isLetras(char*pBuffer);

static int getString(char* pBuffer, int limite);

static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;
}


 int getFloat(float* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArreglosoloFlotantes(bufferString)==0)
    {
        *pBuffer = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}


int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos)

{
    int retorno=-1;
    float buffer;
    if( pFloat != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getFloat(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pFloat = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

void mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);
    }
}

int calcularMaximoArray(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

void initArray(int* pArray, int limite, int valor)
{
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
}
}

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor)
{
    int flagnoTerminedeOrdenar=1;
    int aux;
    int i;

    while(flagnoTerminedeOrdenar==1)
    {
        flagnoTerminedeOrdenar=0;
        for(i=0;i<limite-1;i++)
        {
            if((flagMayorMenor==1 && pArray[i]>pArray[i+1]) || (flagMayorMenor==0 && pArray[i]<pArray[i+1]))
            {
                aux=pArray[i];
                pArray[i]=pArray[i+1];
                pArray[i+1]=aux;
                flagnoTerminedeOrdenar=1;
            }
        }
    }
}
int verificarArreglosoloFlotantes(char* pBuffer)
{
    int retorno;
    int i=0;
    char auxiliar=pBuffer[i];
    int contadorPunto=0;
    while(auxiliar!='\0')
        {
            if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z'))
                {
                    retorno=-1;
                    break;
                }
            if(auxiliar=='.')
                {
                    contadorPunto++;
                }
            if(contadorPunto==1)
                {
                    retorno=0;
                }
            else
                {
                    retorno=-1;
                }
                i++;
                auxiliar=pBuffer[i];
        }

    return retorno;
}
int verificarArregloSoloLetras(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if((auxiliar!=' ')&&(auxiliar<'a' || auxiliar>'z') && (auxiliar<'A' || auxiliar>'Z' ))
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int verificarArregloAlfanumerica(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= 0)
    {

     if(!((auxiliar>=48 && auxiliar<=57) || (auxiliar>=65 && auxiliar<=90)||(auxiliar>=97 && auxiliar<=122)))
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int verificarNumeroTelefono(char *pArreglo)
{
    int i=0;
    int retorno;
    int contadorDigito=0;
    int contarGuion=0;;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(!((auxiliar>=48 && auxiliar<=57)|| auxiliar==45))
            {
                retorno=-1;
                break;
            }
        else{contadorDigito++;}
        if(auxiliar=='-')
            {
                contarGuion++;
            }
            i++;
            auxiliar=pArreglo[i];
    }

     if(contarGuion==1 && pArreglo[4]=='-' && contadorDigito==9)
            {
                retorno=0;
            }
    else {retorno =-1;}
    return retorno;
}
int verificarArregloSoloNumeros(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z') || auxiliar=='.')
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

 int getInt(int* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArregloSoloNumeros(bufferString)==0)
    {
        *pBuffer = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}
int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int buffer;
    if( pInt != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getInt(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pInt = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

void insertion(int data[],int len)
{
    int i,j;
    int temp;
    for(i=1;i<len;i++)
    {
        temp=data[i];
        j=i-1;
        while(j>=0 && temp<data[j])
        {
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=temp;
    }
}

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0)
            {
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;


    }

int utn_getMail(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarMail(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

static int verificarMail(char *arreglo)
{
    int i=0;
    int retorno;
    char bufferAuxiliar=arreglo[i];
    int contadorPuntos=0;
    int contadorArrobas=0;

    while(bufferAuxiliar!='\0')
        {
            if(bufferAuxiliar=='@')
                {
                    contadorArrobas++;
                }
            if(bufferAuxiliar=='.')
                {
                    contadorPuntos++;
                }
                i++;
                bufferAuxiliar=arreglo[i];
        }
        if(contadorArrobas==1 && contadorPuntos>=1)
            {
                retorno=0;
            }
            else{retorno=-1;}

 return retorno;
}
int verificarCuitoCuil(char*arreglo)
{
    int retorno;
    int i=0;
    int contadorGuion=0;
    char auxiliar=arreglo[i];
    while(auxiliar!='\0')
        {
            if(!((auxiliar>='0' && auxiliar<='9')|| auxiliar=='-'))
                {
                    retorno=-1;
                    break;
                }
                 if(auxiliar=='-')
                    {
                        contadorGuion++;
                    }
                i++;
                auxiliar=arreglo[i];
            }
    if(contadorGuion==2 && arreglo[0]>='0' && arreglo[1]>=0 && arreglo[2]=='-' && arreglo[12]>=0 && arreglo[11]=='-')
        {
            retorno=0;
        }
    return retorno;
}

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarCuitoCuil(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

int utn_getPassword(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){

    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarArregloAlfanumerica(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

int utn_getNumeroTelefono(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){

    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarNumeroTelefono(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

int utn_getNumerocelular(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){

    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarNumeroCelular(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

int verificarNumeroCelular(char *pArreglo)
{
    int i=0;
    int retorno;
    int contadorDigitos=0;
    int contarGuion=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(!((auxiliar>=48 && auxiliar<=57)|| auxiliar==45))
            {
                retorno=-1;
                break;
            }
        else{contadorDigitos++;}

        if(auxiliar=='-' )
            {
                contarGuion++;
            }
            i++;
            auxiliar=pArreglo[i];
    }

     if(contarGuion==1 && pArreglo[2]=='-' && contadorDigitos==11)
            {
                retorno=0;
            }
    else {retorno =-1;}
    return retorno;
}
