/* Sae BUT1*/

#include <stdio.h>

void print_js(char *str, int j) // print une chaine de caractère en couleur soit bleu soit rouge
{
    if (j == 1) {
        printf("\033[0;34m"); // Bleu
        printf("str");
    } else {
        printf("\033[0;31m"); // Rouge
        printf("str");
    }
}

void affiche_mat(char **mat) // affiche la matrice 
{
    for (int i = 0; mat[i] != NULL; i++) {
        for (int j = 0; mat[i][j] != '\0'; j++) {
            if (mat[i][j] < 0)
                print_js(mat[i][j], 2);
            else
                print_js(mat[i][j], 1);
            if (mat[i][j + 1] != '\0')
                printf(" ");
        }
        printf("\n");
    }
}

char **tour_js(char **mat, int id_j) // déroulé du tour
{
    int l, c, elt;
    int emp_invalid = 1;

    while (emp_invalid == 1) {
        printf("Joueur %d, saisissez l'emplacement, la ligne puis la colone", id_j);
        scanf("%d %d", &l, &c);                                                             // saisi de l'emplacement de la case
        if (mat[l][c] == NULL) {                                                            // verification validité de l'emplacement
            printf("L'emplacement %d %d n'existe pas dans le tableau", l, c);
            emp_invalid = 1;
        } else if (mat[l][c] != 0) {
            printf("L'emplacement %d %d est déjà occupé", l, c);
            emp_invalid = 1;
        } else
            emp_invalid = 0;
    }
    printf("Saisissez le jeton à placer");                                                  // saisi du numéro du jeton
    scanf("%d", &elt);
    if (id_j == 1)                                                                          // ajout du jeton dans la matrice
        mat[l][c] = elt * -1;
    else
        mat[l][c] = elt;
    return mat;
}

char **jeu(char **mat, int l, int c) // boucle de partie
{
    int nb_jet;
    int nb_tour, id_j = 0;

    while (nb_tour <= ((nb_jet * 2) + 1)) {
        mat = tour_js(mat, id_j % 2); // lance un tour de la partie
        nb_tour += 1;
        id_j += 1;
        affiche_mat(mat); // affichage de la matrice
    }
    who_win(mat, l, c); // lance la fcontion pour connaitre le vainqueur
    return mat;
}

void find_vide(char **mat, int *posl, int *posc, int l, int c) // trouve l'elt vide dans la matrice
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] = 0) {
                *posl = i;
                *posc = j;
            }
        }
    }
}

void som(char **mat, int posl, int posc, int l, int c, int *som1, int *som2) // fait la somme des elt autour de l'elt vide
{
    for (int i = posl - 1; i != posl + 1; i++) {
        if (i >= 0 && i <= l) {
            for (int j = posc - 1; j != posc + 1; j++) {
                if (j >= 0 && j <= c) {
                    if (mat[i][j] < 0)
                        *som2 += mat[i][j];
                    else
                        *som1 += mat[i][j];
                }
            }
        }
    }
}

int who_win(char **mat, int l, int c) // détermine le vainqueur
{
    int posl, posc, som1, som2 = 0;
    char *winner;

    find_vide(mat, &posl, &posc, l, c);
    som(mat, posl, posc, l, c, &som1, &som2);
    winner = (som1 > som2 ? "rouge":"bleu");
    printf("La somme bleue est égale à %d\nLa somme rouge est égale à %d\nLe gagnant est le joueur %s\n", som1, som2, winner);
}

char **init_mat(int l, int c) // initialise la matrice
{
    char **mat = malloc(sizeof(char *) * l + 1);
    int i, j = 0;

    for (; i < l; i++) {
        mat[i] = malloc(sizeof(char) * c + 1);
        for (j = 0; j < c; j++)
            mat[i][j] = 0;
        mat[i][j] = '\0';
    }
    mat[i] = NULL;
    return mat;
}

int main(int argc, char **argv) // main
{
    int l, c, bcl;
    char rep;
    char **mat;

    printf("Saisissez le nombre de ligne puis le nombre de colones");
    scanf("%d %d", &l, &c);
    mat = init_mat(l, c);
    while (bcl == 1) { // boucle de jeu
        mat = jeu(mat, l, c);
        printf("Voulez-vous faire une autre partie ?");
        scanf("%c", &rep);
        bcl = (rep == 'o' || rep == 'O' ? 1:0); // verifie si on veut faire une autre partie
    }
}
