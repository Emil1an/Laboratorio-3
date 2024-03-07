#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura del nodo
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Funcion para insertar un nodo al inicio de la lista
void insertarInicio(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Funcion para insertar un nodo al final de la lista
void insertarFinal(Node **head, int data) {
    if (*head == NULL) {
        insertarInicio(head, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    newNode->prev = (*head)->prev;
    newNode->next = *head;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
}

// Funcion para insertar un nodo en una posicion intermedia
void insertarIntermedio(Node **head, int data, int pos) {
    if (pos <= 0) {
        printf("Posicion invalida.\n");
        return;
    }

    if (*head == NULL || pos == 1) {
        insertarInicio(head, data);
        return;
    }

    Node *temp = *head;
    int count = 1;

    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == *head && count < pos - 1) {
        printf("Posicion invalida.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Funcion para eliminar el nodo al inicio de la lista
int eliminarInicio(Node **head) {
    int valorEliminado;

    if (*head == NULL) {
        printf("La lista esta vacia.\n");
        return -1;
    }

    if ((*head)->next == *head) {
        valorEliminado = (*head)->data;
        free(*head);
        *head = NULL;
    } else {
        Node *temp = *head;
        valorEliminado = temp->data;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        free(temp);
    }

    return valorEliminado;
}

// Funcion para eliminar el nodo al final de la lista
int eliminarFinal(Node **head) {
    int valorEliminado;

    if (*head == NULL) {
        printf("La lista esta vacia.\n");
        return -1;
    }

    if ((*head)->next == *head) {
        valorEliminado = (*head)->data;
        free(*head);
        *head = NULL;
    } else {
        Node *temp = (*head)->prev;
        valorEliminado = temp->data;
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
        free(temp);
    }

    return valorEliminado;
}

// Funcion para eliminar un nodo en una posicion intermedia
int eliminarIntermedio(Node **head, int pos) {
    int valorEliminado;

    if (pos <= 0) {
        printf("Posicion invalida.\n");
        return -1;
    }

    if (*head == NULL) {
        printf("La lista esta vacia.\n");
        return -1;
    }

    if (pos == 1) {
        valorEliminado = eliminarInicio(head);
        return valorEliminado;
    }

    Node *temp = *head;
    int count = 1;

    while (count < pos && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == *head && count < pos) {
        printf("Posicion invalida.\n");
        return -1;
    }

    valorEliminado = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return valorEliminado;
}

// Funcion para imprimir los elementos de la lista
void imprimirLista(Node *head) {
    if (head == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    Node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Funcion principal
int main() {
    Node *head = NULL;
    int opcion, numero, posicion, valorEliminado;

    do {
        printf("\nOpciones:\n");
        printf("1. Insertar nodo al inicio\n");
        printf("2. Insertar nodo al final\n");
        printf("3. Insertar nodo en posicion intermedia\n");
        printf("4. Eliminar nodo al inicio\n");
        printf("5. Eliminar nodo al final\n");
        printf("6. Eliminar nodo en posicion intermedia\n");
        printf("7. Imprimir elementos de la lista\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el numero a insertar: ");
                scanf("%d", &numero);
                insertarInicio(&head, numero);
                break;
            case 2:
                printf("Ingrese el numero a insertar: ");
                scanf("%d", &numero);
                insertarFinal(&head, numero);
                break;
            case 3:
                printf("Ingrese el numero a insertar: ");
                scanf("%d", &numero);
                printf("Ingrese la posicion intermedia: ");
                scanf("%d", &posicion);
                insertarIntermedio(&head, numero, posicion);
                break;
            case 4:
                valorEliminado = eliminarInicio(&head);
                if (valorEliminado != -1)
                    printf("Se elimino el nodo con el valor: %d\n", valorEliminado);
                break;
            case 5:
                valorEliminado = eliminarFinal(&head);
                if (valorEliminado != -1)
                    printf("Se elimino el nodo con el valor: %d\n", valorEliminado);
                break;
            case 6:
                printf("Ingrese la posicion del nodo a eliminar: ");
                scanf("%d", &posicion);
                valorEliminado = eliminarIntermedio(&head, posicion);
                if (valorEliminado != -1)
                    printf("Se elimino el nodo con el valor: %d\n", valorEliminado);
                break;
            case 7:
                printf("Elementos de la lista: ");
                imprimirLista(head);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 0);

    return 0;
}

