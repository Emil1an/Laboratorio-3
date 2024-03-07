// Nombres de integrantes: Daniel Martinez Macedo, Emiliano Saucedo Tavitas, Roberto Carlos Benitez Rizzo, Adriana de Jesús Jerónimo Alarcón
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *Lchild;
    struct Nodo *Rchild;
};

struct Nodo *nuevoNodo(int dato) {
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->Lchild = nodo->Rchild = NULL;
    return nodo;
}

void insertar(struct Nodo *raiz, int dato) {

    if (dato < raiz->dato) {

        if (raiz->Lchild == NULL) {
            raiz->Lchild = nuevoNodo(dato);
        } else {
            insertar(raiz->Lchild, dato);
        }

    } else if (dato > raiz->dato) {

        if (raiz->Rchild == NULL) {
            raiz->Rchild = nuevoNodo(dato);
        } else {
            insertar(raiz->Rchild, dato);
        }

    }

}

 

struct Nodo *buscarNodo(struct Nodo *raiz, int valor) {

    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }

    if (valor < raiz->dato) {
        return buscarNodo(raiz->Lchild, valor);
    } 
    else {
        return buscarNodo(raiz->Rchild, valor);
    }

}

 

int encontrarMinimo(struct Nodo *raiz) {

    struct Nodo *temp = raiz;

    while (temp->Lchild != NULL) {
        temp = temp->Lchild;
    }
    return temp->dato;
}

 

int encontrarMaximo(struct Nodo *raiz) {

    struct Nodo *temp = raiz;

    while (temp->Rchild != NULL) {
        temp = temp->Rchild;
    }
    return temp->dato;
}

 

struct Nodo *eliminarNodo(struct Nodo *raiz, int valor) {

    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->dato) {
        raiz->Lchild = eliminarNodo(raiz->Lchild, valor);
    } else if (valor > raiz->dato) {
        raiz->Rchild = eliminarNodo(raiz->Rchild, valor);
    } else {

        if (raiz->Lchild == NULL) {
            struct Nodo *temp = raiz->Rchild;
            free(raiz);
            return temp;

        } else if (raiz->Rchild == NULL) {
            struct Nodo *temp = raiz->Lchild;
            free(raiz);
            return temp;
        }

        struct Nodo *temp = raiz->Rchild;

        while (temp->Lchild != NULL) {
            temp = temp->Lchild;
        }
        raiz->dato = temp->dato;
        raiz->Rchild = eliminarNodo(raiz->Rchild, temp->dato);
    }
    return raiz;

}

void elimArbol(struct Nodo *raiz) {

  if (raiz != NULL) {
      elimArbol(raiz->Lchild);
      elimArbol(raiz->Rchild);
      free(raiz);
  }

}


void preOrden(struct Nodo *raiz) {

    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preOrden(raiz->Lchild);
        preOrden(raiz->Rchild);
    }

}

 

void inOrden(struct Nodo *raiz) {

    if (raiz != NULL) {
        inOrden(raiz->Lchild);
        printf("%d ", raiz->dato);
        inOrden(raiz->Rchild);

    }

}

 

void postOrden(struct Nodo *raiz) {

    if (raiz != NULL) {
        postOrden(raiz->Lchild);
        postOrden(raiz->Rchild);
        printf("%d ", raiz->dato);
    }

}

 

int altura(struct Nodo *raiz) {

    if (raiz == NULL)
    {
        printf("No se puede calcular la altura\n");
    }

    else
    {
        int Laltura = altura(raiz->Lchild);
        int Raltura = altura(raiz->Rchild);

        if (Laltura >= Raltura)
        {
           return Laltura +1;
        }

        else
        {
            return Raltura +1;
        }

    }

}

int main() {

    int Rinic, Nueraiz, op, valor;
    struct Nodo *raiz = NULL;

    printf("\nIngresar inicio del arbol: ");
    scanf("%d", &Rinic);
    raiz = nuevoNodo(Rinic);
    int height;

 

    do {
        printf("\n------- Menu -------");
        printf("\n1. Insertar un nodo");
        printf("\n2. Eliminar un nodo");
        printf("\n3. Buscar un valor/nodo");
        printf("\n4. Encontrar el valor mas pequeño");
        printf("\n5. Encontrar el valor mas grande");
        printf("\n6. Determinar la altura del árbol");
        printf("\n7. Imprimir el arbol en Pre-orden");
        printf("\n8. Imprimir el arbol en In-orden");
        printf("\n9. Imprimir el arbol en Post-orden");
        printf("\n10. Eliminar todo el árbol");
        printf("\n0. Salir\n");
        scanf("%d", &op);

  switch (op) {

    case 1:
        printf("\nIngresar valor: ");
        scanf("%d", &Nueraiz);
        insertar(raiz, Nueraiz);
        break;

    case 2:
        printf("\nIngresar valor a eliminar: ");
        scanf("%d", &Nueraiz);
        raiz = eliminarNodo(raiz, Nueraiz);
        break;

    case 3:
        printf("\nIngresar valor de busqueda: ");
        scanf("%d", &valor);
        if (buscarNodo(raiz, valor) != NULL) {
            printf("%d esta en el arbol.\n", valor);
        } else 
        {
            printf("%d no esta en el arbol.\n", valor);
        }
        break;

    case 4:
        printf("El valor minimo en el arbol es: %d\n", encontrarMinimo(raiz));
        break;
    
    case 5:
        printf("El valor maximo en el arbol es: %d\n", encontrarMaximo(raiz));
        break;

    case 6:
        height = altura(raiz);
        printf("La altura del árbol es: %d \n", height);
        break;

    case 7:
        printf("Recorrido Pre-orden: ");
        preOrden(raiz);
        printf("\n");
        break;

    case 8:
        printf("Recorrido In-orden: ");
        inOrden(raiz);
        printf("\n");
        break;

    case 9:
        printf("Recorrido Post-orden: ");
        postOrden(raiz);
        printf("\n");
        break;

    case 10:
        elimArbol(raiz);
        raiz = NULL;
        printf("Árbol eliminado\n");
        printf("Ingrese una nueva raiz\n");
        scanf("%d", &Rinic);
        raiz = nuevoNodo(Rinic);
        break;

    case 0:
        printf("Saliendo del programa.\n");
        break;

    

    default:
        printf("Opcion no valida.\n");
    }

  } while (op != 0);
    return 0;
}
