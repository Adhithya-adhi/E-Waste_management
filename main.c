#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "ewaste.txt"

struct Item {
    int id;
    char name[30];
    float weight;
    char category[20];
    char disposal[40];
    struct Item* next;
};

int pickupQueue[20];
int front = 0, rear = 0;
struct Item* head = NULL;

void enqueue(int id) {
    if (rear < 20) {
        pickupQueue[rear++] = id;
        printf("Item %d added to pickup queue.\n", id);
    } else {
        printf("Queue is full!\n");
    }
}

void dequeue() {
    if (front == rear) {
        printf("No pending pickup requests.\n");
    } else {
        printf("Processed pickup for Item ID: %d\n", pickupQueue[front++]);
    }
}

void addItem(int id, char name[], float weight) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->weight = weight;

    if (strstr(name, "Battery") || strstr(name, "battery")) {
        strcpy(newItem->category, "Hazardous");
        strcpy(newItem->disposal, "Chemical Neutralization");
    } else if (strstr(name, "PCB") || strstr(name, "Board")) {
        strcpy(newItem->category, "E-Board");
        strcpy(newItem->disposal, "Metal Smelting");
    } else {
        strcpy(newItem->category, "General");
        strcpy(newItem->disposal, "Shredding & Recycling");
    }

    newItem->next = head;
    head = newItem;

    FILE* fp = fopen(FILE_NAME, "a");
    if (fp != NULL) {
        fprintf(fp, "%d,%s,%.2f,%s,%s\n", newItem->id, newItem->name, newItem->weight, newItem->category, newItem->disposal);
        fclose(fp);
    }

    printf("Item registered successfully! Category: %s | Disposal: %s\n", newItem->category, newItem->disposal);
}

void displayItems() {
    struct Item* temp = head;
    if (temp == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n--- Registered E-Waste Items ---\n");
    printf("%-6s %-15s %-10s %-15s %-25s\n", "ID", "Name", "Weight", "Category", "Disposal Method");
    while (temp != NULL) {
        printf("%-6d %-15s %-10.2f %-15s %-25s\n", temp->id, temp->name, temp->weight, temp->category, temp->disposal);
        temp = temp->next;
    }
}

void loadFromFile() {
    FILE* fp = fopen(FILE_NAME, "r");
    if (fp == NULL) return;

    struct Item temp;
    // Reading with comma delimiters to handle multi-word categories and disposal methods safely
    while (fscanf(fp, "%d,%29[^,],%f,%19[^,],%39[^\n]\n", &temp.id, temp.name, &temp.weight, temp.category, temp.disposal) == 5) {
        struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
        *newItem = temp;
        newItem->next = head;
        head = newItem;
    }
    fclose(fp);
}

int main() {
    loadFromFile();
    int choice, id;
    float weight;
    char name[30];

    while (1) {
        printf("\n--- E-WASTE MANAGEMENT ---\n");
        printf("1. Register Item\n");
        printf("2. View All Items\n");
        printf("3. Request Pickup\n");
        printf("4. Process Pickup\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter ID, Name (no spaces), and Weight (kg): ");
                scanf("%d %s %f", &id, name, &weight);
                addItem(id, name, weight);
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printf("Enter Item ID to queue for pickup: ");
                scanf("%d", &id);
                enqueue(id);
                break;
            case 4:
                dequeue();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}
