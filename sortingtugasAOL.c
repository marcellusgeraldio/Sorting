#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struktur untuk node dalam linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Fungsi untuk menambahkan node baru pada akhir linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Fungsi untuk menukar data dua node
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Bubble Sort
void bubbleSort(struct Node* head) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Jika linked list kosong
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Selection Sort
void selectionSort(struct Node* head) {
    struct Node* min;
    struct Node* ptr1 = head;
    struct Node* ptr2;

    // Jika linked list kosong
    if (head == NULL)
        return;

    while (ptr1->next != NULL) {
        min = ptr1;
        ptr2 = ptr1->next;

        while (ptr2 != NULL) {
            if (ptr2->data < min->data)
                min = ptr2;
            ptr2 = ptr2->next;
        }
        swap(min, ptr1);
        ptr1 = ptr1->next;
    }
}

// Quick Sort
struct Node* partition(struct Node* l, struct Node* h) {
    int x = h->data;
    struct Node* i = l->prev;

    for (struct Node* j = l; j != h; j = j->next) {
        if (j->data <= x) {
            i = (i == NULL) ? l : i->next;
            swap(i, j);
        }
    }
    i = (i == NULL) ? l : i->next;
    swap(i, h);
    return i;
}

void _quickSort(struct Node* l, struct Node* h) {
    if (h != NULL && l != h && l != h->next) {
        struct Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

void quickSort(struct Node* head) {
    struct Node* h = head;
    while (h->next != NULL)
        h = h->next;
    _quickSort(head, h);
}

// Fungsi untuk mencetak linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Fungsi untuk membebaskan memori dari linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    int data;
    char sort_choice;
    clock_t start, end;
    double cpu_time_used;

    do {
        printf("\nMenu:\n");
        printf("1. Masukkan data\n");
        printf("2. Pilihan Sorting\n");
        printf("3. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan jumlah data yang ingin dimasukkan: ");
                int num_data;
                scanf("%d", &num_data);
                printf("Masukkan %d data:\n", num_data);
                for (int i = 0; i < num_data; ++i) {
                    scanf("%d", &data);
                    append(&head, data);
                }
                break;
            case 2:
                printf("Pilihan Sorting:\n");
                printf("a. Bubble Sort\n");
                printf("b. Selection Sort\n");
                printf("c. Quick Sort\n");
                printf("Pilihan Anda: ");
                getchar();  // untuk membersihkan buffer
                sort_choice = getchar();

                start = clock();
                switch (sort_choice) {
                    case 'a':
                        bubbleSort(head);
                        printf("Linked list setelah Bubble Sort: \n");
                        printList(head);
                        break;
                    case 'b':
                        selectionSort(head);
                        printf("Linked list setelah Selection Sort: \n");
                        printList(head);
                        break;
                    case 'c':
                        quickSort(head);
                        printf("Linked list setelah Quick Sort: \n");
                        printList(head);
                        break;
                    default:
                        printf("Pilihan salah!\n");
                        break;
                }
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan: %f detik\n", cpu_time_used);
                break;
            case 3:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan salah!\n");
                break;
        }
        
    } while (choice != 3);

    freeList(head); // Membebaskan memori dari linked list
    return 0;
}