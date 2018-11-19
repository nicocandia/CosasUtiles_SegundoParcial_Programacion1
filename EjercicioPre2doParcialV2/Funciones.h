#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);

void mostrarArray(int* pArray, int limite);

int calcularMaximoArray(int* pArray, int limite, int* pMaximo);

void initArray(int* pArray, int limite, int valor);

void ordenarArreglo(int *pArray,int limite,int flagMayorMenor);

int verificarArregloSoloLetras(char *pArreglo);

int verificarArregloAlfanumerica(char *pArreglo);

int verificarNumeroTelefono(char *pArreglo);

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);

void insertion(int data[],int len);

int verificarArreglosoloFlotantes(char* pBuffer);

int getFloat(float* pBuffer);

int verificarNumeroCelular(char *pArreglo);

int utn_getNumerocelular(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int verificarArregloSoloNumeros(char *pArreglo);

int getInt(int* pBuffer);

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int utn_getMail(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int verificarCuitoCuil(char*arreglo);

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int utn_getPassword(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int utn_getNumeroTelefono(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

#endif // FUNCIONES_H_INCLUDED
