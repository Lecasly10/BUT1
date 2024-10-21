#include <stdio.h>

int main() {
    char op;
    int x, i, tmp;
    
    printf("Donne le opé batard et ensuite le nb x et ensuite i\n");
    scanf("%c %d %d", &op, &x, &i);
    tmp = x;
    switch (op) {
        case '*': 
                x *= i;
                break;
        case '-':
                x-= i;
                break;
        case '+': 
                x += i;
                break;
        case '/': 
                x/= i;
                break;
        default : 
            printf("Tu me donnes de la merde fdp\n");
            return -1;
    }
    printf("Le résultat de %d %c %d = %d\n", tmp, op, i, x);
    return 0;
}