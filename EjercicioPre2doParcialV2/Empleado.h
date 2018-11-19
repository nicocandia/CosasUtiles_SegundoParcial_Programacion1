#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
int id;
int horasTrabajadas;
int sueldo;
char nombre[128];
}Empleado;

void em_calcularSueldo(void* p);

Empleado* Empleado_new();
void Empleado_delete();
Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas,int sueldo);

int Empleado_setId(Empleado* this,char*id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

#endif // EMPLEADO_H_INCLUDED
