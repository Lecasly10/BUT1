#include <stdio.h>

int main() {
    float ht;

    printf("Donne le rpix ht batard\n");
    scanf("%f", &ht);
    ht *= 1.20;
    printf("Le prix TTC est pour cet article est de : %.2f\n", ht);
    return 0;
}