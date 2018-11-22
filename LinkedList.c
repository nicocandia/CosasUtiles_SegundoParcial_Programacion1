#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int indiceNodoActual=0;
    int len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
    {
        pNode=this->pFirstNode;
        while(indiceNodoActual<len)
        {
            if(indiceNodoActual==nodeIndex)
            {
                break;
            }
            if(pNode!=NULL)
            {
                pNode=pNode->pNextNode;
                indiceNodoActual++;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* nuevoNodo=(Node*)malloc(sizeof(Node));
    nuevoNodo->pElement=pElement;
    Node* nodoAuxiliar=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len && nuevoNodo!=NULL)
    {
        if(nodeIndex==0)
        {
            nuevoNodo->pNextNode=this->pFirstNode;
            this->pFirstNode=nuevoNodo;
            this->size++;
            returnAux=0;
        }
        else
        {
            nodoAuxiliar=test_getNode(this,nodeIndex-1);
            nuevoNodo->pNextNode=nodoAuxiliar->pNextNode;
            nodoAuxiliar->pNextNode=nuevoNodo;
            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if( this!=NULL)
    {
        test_addNode(this,len,pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node*nodo;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        nodo=test_getNode(this,index);
        returnAux=nodo->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node*nodo;

    if(this!=NULL && index>=0 && index<len)
    {
        nodo=test_getNode(this,index);
        if(nodo!=NULL)
        {
            nodo->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node*nodoAeliminar;
    Node*nodoAnterior;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        nodoAeliminar=test_getNode(this,index);
        if(index==0)
        {
            this->pFirstNode=nodoAeliminar->pNextNode;
            free(nodoAeliminar);
            this->size--;
            returnAux=0;
        }
        else
        {
            nodoAnterior=test_getNode(this,index-1);
            nodoAnterior->pNextNode=nodoAeliminar->pNextNode;
            free(nodoAeliminar);
            this->size--;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int indice=0;
    int len=ll_len(this);
    if(this!=NULL)
    {
        for(indice=0; indice<len; indice++)
        {
            ll_remove(this,indice);
        }
        this->pFirstNode=NULL;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node*nodo;
    int len=ll_len(this);
    if(this!=NULL)
    {
        for(i=0; i<len; i++)
        {
            nodo=getNode(this,i);
            if(nodo!=NULL && nodo->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
        if (len==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
        test_addNode(this,index,pElement);
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index <=len)
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i=0;
    void*pElement;
    int len=ll_len(this2);
    int contadorElementos=0;

    if(this!=NULL && this2!=NULL)
    {
        for(i=0; i<len; i++)
        {
            pElement=ll_get(this2,i);
            if(ll_contains(this,pElement)==1)
            {
                contadorElementos++;
            }
        }
        if(contadorElementos==len)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = ll_newLinkedList();
    void*pElement;
    int len=ll_len(this);
    int i;

    if(this!=NULL && from>=0 && from<len && to>from && to<=len)
    {
        for(i=0; i<len; i++)
        {
            if(i>=from && i<to)
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }

    }
    else
    {
        cloneArray=NULL;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);

    if(this!=NULL)
    {
        cloneArray=ll_subList(this,0,len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int flagOrdenar = 1;
    int i;
    void*pElementAuxiliar;
    void*pElementI;
    void*pElementImasUno;
    int len=ll_len(this);
    if(this!=NULL && pFunc!=NULL && (order == 0 || order == 1))
    {
        while(flagOrdenar==1)
        {
            flagOrdenar=0;
            for(i=0; i<len-1; i++)
            {
                pElementI=ll_get(this,i);
                pElementImasUno=ll_get(this,i+1);
                if((order==1 && pFunc(pElementI,pElementImasUno)>0) || (order==0 && pFunc(pElementI,pElementImasUno)<0))
                {
                    pElementAuxiliar=pElementI;
                    ll_set(this,i,pElementImasUno);
                    ll_set(this,i+1,pElementAuxiliar);
                    flagOrdenar=1;
                    returnAux=0;
                }
            }

        }

    }

    return returnAux;

}

LinkedList* ll_filter(LinkedList*this,int (*pFunc)(void*))
{
    int i;
    LinkedList*newList=NULL;
    int len=ll_len(this);
    void*pElement;

    if(this!=NULL && pFunc!=NULL && len>0)
    {
        newList=ll_newLinkedList();
        for(i=0;i<len;i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement)>0)
            {
                ll_add(newList,pElement);
            }
        }
    }
    return newList;
}

Node* ll_startIterator(LinkedList* this)
{
    Node*retorno=NULL;
    if(this != NULL)
    {
        this->nodeIterator=this->pFirstNode;
        retorno=this->nodeIterator;
    }
    return retorno;
}

Node* ll_getNextIterator(LinkedList* this)
{
    Node* retorno=NULL;
    if(this->nodeIterator != NULL)
    {
        this->nodeIterator=(this->nodeIterator)->pNextNode;
        retorno=this->nodeIterator;
    }
    return retorno;
}

int ll_map (LinkedList* this,void (*pFunc)(void*))
{
    int retorno=-1;
    Node* nodo;
    if(this != NULL && pFunc != NULL)
    {
        nodo = ll_startIterator(this);
        while(nodo!=NULL)
        {
            pFunc(nodo->pElement);
            nodo=ll_getNextIterator(this);
            retorno=0;
        }
    }
    return retorno;
}

LinkedList* ll_filterVersion2(LinkedList*this,int (*pFunc)(void*,int entero),int numero)
{
    int i;
    LinkedList*newList=NULL;
    int len=ll_len(this);
    void*pElement;

    if(this!=NULL && pFunc!=NULL && len>0)
    {
        newList=ll_newLinkedList();
        for(i=0;i<len;i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement,numero)>0)
            {
                ll_add(newList,pElement);
            }
        }
    }
    return newList;
}
