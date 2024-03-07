// Nombres de integrantes: Daniel Martinez Macedo, Emiliano Saucedo Tavitas, Roberto Carlos Benitez Rizzo, Adriana de Jesús Jerónimo Alarcón
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo de la lista enlazada
struct Node {
    int data;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para insertar un nodo al inicio de la lista
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Nodo insertado al inicio.\n");
}

// Función para insertar un nodo al final de la lista
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Nodo insertado al final.\n");
}

// Función para insertar un nodo en una posición intermedia de la lista
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Posición inválida.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posición fuera de rango.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Nodo insertado en la posición %d.\n", position);
    }
}

// Función para eliminar el nodo al inicio de la lista
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Nodo eliminado del inicio.\n");
}

// Función para eliminar el nodo al final de la lista
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Nodo eliminado del final.\n");
        return;
    }
    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = NULL;
    printf("Nodo eliminado del final.\n");
}

// Función para eliminar el nodo en una posición intermedia de la lista
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    if (position < 1) {
        printf("Posición inválida.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posición fuera de rango.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Nodo eliminado en la posición %d.\n", position);
    }
}

// Función para imprimir los elementos de la lista
void printList(struct Node* head) {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Elementos de la lista:\n");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenú:\n");
        printf("1. Insertar un nodo al inicio\n");
        printf("2. Insertar un nodo al final\n");
        printf("3. Insertar un nodo intermedio\n");
        printf("4. Eliminar un nodo al inicio\n");
        printf("5. Eliminar un nodo al final\n");
        printf("6. Eliminar un nodo intermedio\n");
        printf("7. Imprimir los elementos de la lista\n");
        printf("0. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor del nodo a insertar al inicio: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Ingrese el valor del nodo a insertar al final: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Ingrese el valor del nodo a insertar: ");
                scanf("%d", &data);
                printf("Ingrese la posición del nodo intermedio: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Ingrese la posición del nodo intermedio a eliminar: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente de nuevo.\n");
        }
    } while (choice != 0);

    return 0;
}
