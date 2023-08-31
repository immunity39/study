#include <stdio.h>

void bookshelf(void);
void magazine(void);

int main(void) {
  printf("BookStore\n");
  magazine();

  return 0;
}

void magazine(void) {
  char title[50];
  int price;

  printf("Magazine\n");
}

void bookshelf(void) { printf("Bookshelf\n"); }