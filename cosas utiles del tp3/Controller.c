#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Funciones.h"

static int buscarEmployeebyId(LinkedList*array,int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    if(pArchivo!=NULL &&!parser_EmployeeFromText(pArchivo,pArrayListEmployee))
    {
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");
    if(pArchivo!=NULL && !parser_EmployeeFromBinary(pArchivo,pArrayListEmployee))
    {
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee*pEmployeeauxiliar;
    pEmployeeauxiliar=NULL;
    pEmployeeauxiliar=Employee_new();

    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;

    if(!utn_getLetras(nombreAuxiliar,128,3,"\ningrese nombre empleado\n","\nerror solo letras\n")
        &&!utn_getInt(&horasAuxiliar,"\ningrese horas trabajadas\n","\nerror\n",0,999999999,3)
        &&!utn_getInt(&sueldoAuxiliar,"\ningrese sueldo \n","\nerror\n",0,999999999,3)
        && pEmployeeauxiliar!=NULL
        && !Employee_setNombre(pEmployeeauxiliar,nombreAuxiliar)
        && !Employee_setHorasTrabajadas(pEmployeeauxiliar,horasAuxiliar)
        && !Employee_setSueldo(pEmployeeauxiliar,sueldoAuxiliar)
        && !Employee_setId(pEmployeeauxiliar,-1))
        {
            ll_add(pArrayListEmployee,(Employee*)pEmployeeauxiliar);
            retorno=0;
        }
    else
    {
        Employee_delete(pEmployeeauxiliar);
        pEmployeeauxiliar=NULL;
        retorno=-1;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int indice;
    int opcion;
    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;
    Employee*pEmployeeAuxiliar;

    if(!utn_getInt(&id,"\ningrese id del empleado para modificar los datos\n","\nerror\n",0,999999999,3))
    {
        indice=buscarEmployeebyId(pArrayListEmployee,id);
        if(indice>=0 && !utn_getInt(&opcion,"\ningrese:\n1 para modificar nombre\n2 para modificar horas trabajadas\n3 para modificar sueldo\n","\nerror opcion invalida\n",1,3,3))
        {
            pEmployeeAuxiliar=(Employee*)ll_get(pArrayListEmployee,indice);
            switch(opcion)
            {
                case 1:
                if(!utn_getLetras(nombreAuxiliar,128,3,"\ningrese nuevo nombre\n","\nerror solo letras\n")
                    && !Employee_setNombre(pEmployeeAuxiliar,nombreAuxiliar))
                {
                    retorno=0;
                }
                break;

                case 2:
                if(!utn_getInt(&horasAuxiliar,"\ningrese cantidad de horas\n","\nerror\n",0,999999999,3)
                   &&!Employee_setHorasTrabajadas(pEmployeeAuxiliar,horasAuxiliar))
                {
                    retorno=0;
                }
                break;

                case 3:
                if(!utn_getInt(&sueldoAuxiliar,"\ningrese nuevo sueldo\n","\nerror\n",0,999999999,3)
                   &&!Employee_setHorasTrabajadas(pEmployeeAuxiliar,sueldoAuxiliar))
                {
                    retorno=0;
                }
                break;
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int indice;
    if(!utn_getInt(&id,"\ningrese id del empleado\n","\nerror\n",0,999999999,3))
        {
            indice=buscarEmployeebyId(pArrayListEmployee,id);
            if(indice>=0)
                {
                    ll_remove(pArrayListEmployee,indice);
                    retorno=0;
                }
        }

    return retorno;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayListEmployee);
    int idAuxiliar;
    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;
    Employee*pEmployeeAuxiliar;

    if(pArrayListEmployee!=NULL)
        {
            for(i=0;i<len;i++)
                {
                    pEmployeeAuxiliar=(Employee*)ll_get(pArrayListEmployee,i);
                    if(pEmployeeAuxiliar!=NULL)
                        {
                            Employee_getId(pEmployeeAuxiliar,&idAuxiliar);
                            Employee_getNombre(pEmployeeAuxiliar,nombreAuxiliar);
                            Employee_getHorasTrabajadas(pEmployeeAuxiliar,&horasAuxiliar);
                            Employee_getSueldo(pEmployeeAuxiliar,&sueldoAuxiliar);

                            printf("\n%d -- %s -- %d -- %d\n",idAuxiliar,nombreAuxiliar,horasAuxiliar,sueldoAuxiliar);
                            retorno=0;
                        }
                }
        }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    ll_sort(pArrayListEmployee,employee_Compare,1);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayListEmployee);
    FILE*pArchivo;
    pArchivo=fopen(path,"w");
    Employee*pEmployeeAuxiliar;
    int idAuxiliar;
    char nombreAuxiliar[128];
    int horasAuxiliar;
    int sueldoAuxiliar;

    if(pArchivo!=NULL)
        {
            fprintf(pArchivo,"%s","\nLISTA EMPLEADOS\n");
          for(i=0;i<len;i++)
            {
                pEmployeeAuxiliar=(Employee*)ll_get(pArrayListEmployee,i);
                Employee_getId(pEmployeeAuxiliar,&idAuxiliar);
                Employee_getNombre(pEmployeeAuxiliar,nombreAuxiliar);
                Employee_getHorasTrabajadas(pEmployeeAuxiliar,&horasAuxiliar);
                Employee_getSueldo(pEmployeeAuxiliar,&sueldoAuxiliar);

                fprintf(pArchivo,"\n%d,%s,%d,%d\n",idAuxiliar,nombreAuxiliar,horasAuxiliar,sueldoAuxiliar);
                retorno=0;
            }
        }
        fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE*parchivo=fopen(path,"wb");
    Employee*pEmpleado;
    int len=ll_len(pArrayListEmployee);
    int i;
    if(parchivo!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,parchivo);
            retorno=0;
        }
    }
    fclose(parchivo);
    return retorno;
}

/** \brief busca empleado por numero id
 *
 * \param id int
 * \param pArray LinkedList*
 * \return int
 */
static int buscarEmployeebyId(LinkedList*array,int id)
{
    int indice=-1;
    int len=ll_len(array);
    int i;
    Employee*pEmployeeAuxiliar;
    int idEmployee;

    if(array!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmployeeAuxiliar=(Employee*)ll_get(array,i);
            Employee_getId(pEmployeeAuxiliar,&idEmployee);
            if(idEmployee==id)
                {
                    indice=i;
                    break;
                }
        }
    }
    return indice;
}
