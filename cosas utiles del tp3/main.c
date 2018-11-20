#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados=ll_newLinkedList();
    printf("\n<<<<<BIENVENIDO>>>>>\n");
    do{
        if(!utn_getInt(&option,"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n\nopcion???\n","\nerror opcion invalida\n",1,10,3))
        {
            switch(option)
            {
                case 1:
                    if(!controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("\nSe cargaron los datos de los empleados correctamente\n");
                    }
                    else{printf("\nno se cargaron los datos de los empleados correctamente\n");}
                break;

                case 2:
                    if(!controller_loadFromBinary("data.csv",listaEmpleados))
                    {
                        printf("\nSe cargaron los datos de los empleados correctamente\n");
                    }
                    else{printf("\nno se cargaron los datos de los empleados correctamente\n");}

                    break;

                case 3:
                    if(!controller_addEmployee(listaEmpleados))
                        {
                            printf("\nse dio de alta el empleado\n");
                        }
                        else
                            {printf("\nno se pudo dar de alta el empleado\n");}
                        break;

                case 4:
                    if(!controller_editEmployee(listaEmpleados))
                        {
                            printf("\nse modificaron los datos del empleado\n");
                        }
                        else
                            {printf("\nel id no existe o no se pudieron modificar los datos\n");};
                    break;

                case 5:
                    if(!controller_removeEmployee(listaEmpleados))
                        {
                            printf("\nSe dio de baja el empleado\n");
                        }
                        else{printf("\nel id no existe o no se pudo dar de baja el empleado\n");}
                    break;

                case 6:
                    if(!controller_ListEmployee(listaEmpleados))
                        {
                            printf("\nlista empleados\n");
                        }
                        else{printf("\nno hay ningun empleado cargado\n");}
                    break;

                case 7:
                    controller_sortEmployee(listaEmpleados);
                    break;

                case 8:
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                        {
                            printf("\nse guardaron los datos\n");
                        }
                        else{printf("\nno se guardaron los datos\n");}
                    break;
                case 9:
                    if(!controller_saveAsBinary("data.csv",listaEmpleados))
                    {
                        printf("\nse guardaron los datos\n");
                    }
                    else{printf("\nno se guardaron los datos\n");}
                    break;
            }
        }
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
