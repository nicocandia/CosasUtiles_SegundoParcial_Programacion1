#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE*pFile;
    int retorno=0;
    char buffer[2000];
    pFile=fopen(fileName,"r");
    char*token1;
    char*token2;
    char*token3;
    fgets(buffer,2000,pFile);
    Empleado*empleado;

    if(pFile!=NULL && listaEmpleados!=NULL)
    {
        do
        {
            fscanf(pFile,"%[^\n]\n",buffer);
            token1=strtok(buffer,",");
            token2=strtok(NULL,",");
            token3=strtok(NULL,"\n");

            empleado=Empleado_newConParametros(token1,token2,token3,0);

            if(empleado!=NULL)
            {
                ll_add(listaEmpleados,empleado);
                retorno=1;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);

    return retorno; // OK
}

