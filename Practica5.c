#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista vinculada
struct ListNode {
    int val;
    struct ListNode *next;
};

// Función para crear un nuevo nodo
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Función para fusionar dos listas vinculadas ordenadas
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Función para fusionar k listas vinculadas ordenadas
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];
    
    int mid = listsSize / 2;
    struct ListNode* left = mergeKLists(lists, mid);
    struct ListNode* right = mergeKLists(lists + mid, listsSize - mid);
    
    return mergeTwoLists(left, right);
}

// Función para imprimir la lista vinculada
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Función principal para probar el programa
int main() {
    // Ejemplo de entrada: [[1,4,5],[1,3,4],[2,6]]
    struct ListNode* lists[3];
    
    // Lista 1: 1->4->5
    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);
    
    // Lista 2: 1->3->4
    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);
    
    // Lista 3: 2->6
    lists[2] = createNode(2);
    lists[2]->next = createNode(6);
    
    // Fusionar todas las listas
    struct ListNode* result = mergeKLists(lists, 3);
    
    // Imprimir la lista fusionada
    printList(result);
    
    return 0;
}
