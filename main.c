#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

//function to add an item

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;
    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    
    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
    
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
}

// Function to free all allocated memory for items

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
    free(item_list);
}

// Function to calculate the average price of items

double average_price(Item *item_list, int size) {
    double total_price = 0.0;
    for (int i = 0; i < size; i++) {
        total_price += item_list[i].price;
    }
    return total_price / size;
}

// Function to print all items

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("Item name = %s\n", item_list[i].name);
        printf("Item SKU = %s\n", item_list[i].sku);
        printf("Item category = %s\n", item_list[i].category);
        printf("Item price = %f\n", item_list[i].price);
        printf("###############\n");
    }
}


int main(int argc, char *argv[]) {
    int size = 5;
    Item *item_list = (Item *)malloc(size * sizeof(Item));
 
    // Adding items to the array
    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 2.50, "12345", "snacks", "chips", 2);
    add_item(item_list, 7.80, "45678", "meat", "chicken", 3);
    add_item(item_list, 6.75, "98765", "produce", "apples", 4);

    // Print items
    print_items(item_list, size);

    //Calculate and print average price
    double avg_price = average_price(item_list, size);
    printf("Average price of items = %f\n", avg_price);

    //Command line argument: search for SKU
    if (argc == 2) {
        char *search_sku = argv[1];
        int found = 0;
        int i = 0;
        while (i < size && strcmp(item_list[i].sku, search_sku) != 0) {
            i++;
        }
        
        if (i < size) {
            printf("Item found:\n");
            printf("Item name = %s\n", item_list[i].name);
            printf("Item SKU = %s\n", item_list[i].sku);
            printf("Item category = %s\n", item_list[i].category);
            printf("Item price = %f\n", item_list[i].price);
        } else {
            printf("Item not found.\n");
        }
    }

    // Free allocated memory
    free_items(item_list, size);

    return 0;
}

