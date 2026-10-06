#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define NUM_ITEMS 5

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[]) {

	// Allocating space for 5 items, 2 of them used from the example
	Item *item_list = malloc(NUM_ITEMS * sizeof(Item));

	add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
	add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
	add_item(item_list, 2.95, "12345", "produce", "banana", 2);
	add_item(item_list, 5.95, "23456", "meat", "chicken", 3);
	add_item(item_list, 4.95, "34567", "bakery", "sourdough", 4);

	// Seaching by the sky from the CMD line
	if (argc < 2) {
		printf("Enter: %s <sku>\n", argv[0]);
	}
	else {
		char *sku = argv[1];
		int ct = 0;

		while (ct < NUM_ITEMS && strcmp(item_list[ct].sku, sku) != 0) { // this one works for me
			ct++;
		}

		if (ct < NUM_ITEMS) {
			printf("\nFound item:\n");
			print_items(&item_list[ct], 1);
		}
		else {
			printf("\nItem not found. Here's the available SKUs and Items:\n");
			print_items(item_list, NUM_ITEMS);

		}
	}
	printf("###############\n");
	printf("average price of items = $%f\n", average_price(item_list, NUM_ITEMS));

	return 0;
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
	item_list[index].price = price;

	item_list[index].sku = malloc(strlen(sku) + 1); // +1 to mark when the string will end
	strcpy(item_list[index].sku, sku);

	item_list[index].category = malloc(strlen(category) + 1); // same reason
	strcpy(item_list[index].category, category);
	
	item_list[index].name = malloc(strlen(name) + 1); // same reason
	strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
	for (int i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

double average_price(Item *item_list, int size) {
	double total = 0.0;
	for (int i = 0; i < size; i++) {
		total += item_list[i].price;
	}

	if (size > 0) {
		return total / size;
	}

	else {
		return 0.0;
	} // return size > 0 ? total / size : 0.0; also works here and is only one line but meh
}

void print_items(Item *item_list, int size) {
	for (int i = 0; i < size; i++) {
		printf("###############\n");
		printf("item name = %s\n", item_list[i].name);
		printf("item sku = %s\n", item_list[i].name);
		printf("item category = %s\n", item_list[i].category);
		printf("item price = $%f\n", item_list[i].price);
	}
}
