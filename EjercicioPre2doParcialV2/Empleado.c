#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if( this==NULL ||
    Empleado_setId(this,id)||
    Empleado_setHorasTrabajadas(this,horasTrabajadas)||
    Empleado_setSueldo(this,sueldo)||
    Empleado_setNombre(this,nombre))
    {
        Empleado_delete(this);
        this=NULL;
    }
    return this;
}

int Empleado_setId(Empleado* this,char*id)
{
    int retorno=-1;
    static int proximoId=-1;
    int idAux;

    if(!verificarArregloSoloNumeros(id))
    {
        idAux=atoi(id);
    }

    if(this!=NULL && idAux==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(idAux>proximoId)
    {
        proximoId=idAux;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas)
{
    int retorno=-1;
    int auxHorasTrabajadas;
    if(this!=NULL && !verificarArregloSoloNumeros(horasTrabajadas))
    {
        auxHorasTrabajadas=atoi(horasTrabajadas);
        this->horasTrabajadas=auxHorasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

void em_calcularSueldo(void* p)
{
    int horasBuffer;
    Empleado_getHorasTrabajadas(p,&horasBuffer);
    Empleado_setSueldo(p,horasBuffer*2);
}

