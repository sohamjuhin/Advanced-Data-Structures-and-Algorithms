#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 20

struct Pen {
    int price;
    char color[MAX_COLOR_LENGTH];
};

struct Pen* createPen(int price, const char* color) {
    struct Pen* pen = (struct Pen*)malloc(sizeof(struct Pen));
    pen->price = price;
    strncpy(pen->color, color, MAX_COLOR_LENGTH - 1);
    pen->color[MAX_COLOR_LENGTH - 1] = '\0'; // Ensure null-terminated string
    return pen;
}

int penHashCode(const struct Pen* pen) {
    int prime = 31;
    int result = 1;
    for (int i = 0; pen->color[i] != '\0'; i++) {
        result = prime * result + pen->color[i];
    }
    result = prime * result + pen->price;
    return result;
}

int penEquals(const struct Pen* pen1, const struct Pen* pen2) {
    if (pen1 == pen2) return 1;
    if (pen1 == NULL || pen2 == NULL) return 0;

    if (pen1->price != pen2->price) return 0;
    return strcmp(pen1->color, pen2->color) == 0;
}

int main() {
    struct Pen* pen1 = createPen(10, "blue");
    struct Pen* pen2 = createPen(10, "blue");

    printf("%s\n", pen1->color);
    printf("%s\n", pen2->color);

    int result = penEquals(pen1, pen2);
    printf("Equals: %d\n", result);

    free(pen1);
    free(pen2);

    return 0;
}
