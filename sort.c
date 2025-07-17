#include <stdio.h>
#include <string.h>

#define MAX_NAMES 20
#define MAX_NAME_LENGTH 50


int ascending_compare(const char *a, const char *b) { return strcmp(a, b) > 0; }

// Bubble sort function using function pointer
void bubble_sort(char names[][MAX_NAME_LENGTH], int n, int asc) {
  char temp[MAX_NAME_LENGTH];

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (ascending_compare(names[j], names[j + 1]) == asc) {
        // Swap names[j] and names[j + 1]
        strcpy(temp, names[j]);
        strcpy(names[j], names[j + 1]);
        strcpy(names[j + 1], temp);
      }
    }
  }
}

// Function to print all names
void print_names(char names[][MAX_NAME_LENGTH], int n) {
  printf("\nSorted names:\n\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %s\n", i + 1, names[i]);
  }
}

int main() {
  int num_names = 20;

  char names[20][MAX_NAME_LENGTH] = {
      "Uwimana Jean Baptiste", "Mukamana Marie Claire",
      "Nzeyimana Paul",        "Uwamahoro Grace",
      "Hakizimana Emmanuel",   "Nyirahabimana Josephine",
      "Bizimana Claude",       "Uwimana Immaculee",
      "Nshimiyimana Eric",     "Mukantabana Solange",
      "Bizumuremyi Albert",    "Nyiramana Vestine",
      "Habimana Samuel",       "Uwizeyimana Chantal",
      "Niyonsenga David",      "Mukamuganga Beatrice",
      "Bizimungu Francis",     "Nyiranzeyimana Agnes",
      "Hakizamungu Robert",    "Uwamahoro Lillian"};

  char order[10];

  printf("Original list of names:\n\n");
  for (int i = 0; i < num_names; i++) {
    printf("%d. %s\n", i + 1, names[i]);
  }

  printf("\nEnter sorting order (asc for ascending, desc for descending): \n");
  scanf("%s", order);

  if (strcmp(order, "asc") == 0) {
    printf("\nSorting in ascending order...\n");
    bubble_sort(names, num_names, 1);
  } else {
    printf("\nSorting in descending order...\n");
    bubble_sort(names, num_names, 0);
  }

  print_names(names, num_names);

  return 0;
}
