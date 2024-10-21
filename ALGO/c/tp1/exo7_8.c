#include <stdio.h>

int bisextil(int a) {
    if (((a % 4) == 0 && (a % 100) != 0) || (a % 400) == 0)
        return 0;
    return 1;
}

int nbjmois(int m, int a) {
    switch (m) {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                                            return 31;
        case 4 : case 6 : case 9 : case 11 :
                        return 31;
        case 2 :
            if (bisextil(a) == 0)
                return 29;
            return 28;
        default : return -1;
    }
}

int verif_date(int a, int m, int j) {
    if (j > nbjmois(m, a))
        return 0;
    return 1;
}

void jour_l(int a, int m, int j) {
    if (m == 12 && j == 31) {
        a += 1;
        m = 1;
        j = 1;
    } else if (j == nbjmois(m, a)) {
        m += 1;
        j = 1;
    } else
        j += 1;
    printf("La date du lendemain est : %d/%d/%d\n", j, m, a);
}

int main() {
    int a, m, j;

    printf("Donne dans l'ordre suivant année, mois, jour\n");
    scanf("%d %d %d", &a, &m, &j);
    if (verif_date(a, m, j) == 0) {
        printf("Tu me donne de la merde fdp\n");
        return -1;
    } else
        jour_l(a, m, j);
    return 0;
}
