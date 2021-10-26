#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu();
void facile();
void moyenne();
void difficile();
void jeu(int *, int);

int main()
{
    menu();

    return (0);
}

void menu()
{
    char *choix = malloc(1 * sizeof(char));

    printf("\t ---MASTERMIND--- \n");
    printf("but du jeu : \n ");
    printf("retrouver la suite exacte de chiffre\n la lettre B indique que le chiffre est present mais pas au bon endroit, la lettre A indique qu'il est au bon endroit\n");
    printf("choisir la dificulte :\n 1 : facile (f) \n 2 : moyen (m) \n 3 : difficile (d) \n 4 : quitter (q)\n");
    fgets(choix, 2, stdin);

    if (*choix == 'f')
    {
        facile();
    }
    else if (*choix == 'm')
    {
        moyenne();
    }
    else if (*choix == 'd')
    {
        difficile();
    }
    else if (*choix == 'q')
    {
        printf("vous avez choisi de quitter le jeu.");
    }
    free(choix);
}

void facile()
{

    srand(time(NULL));

    int *nb = malloc(4 * sizeof(int));

    printf("difficulte facile :\n");
    printf("combinaison de 4 chiffres allant de 1 a 4, chaque chiffre n'est present qu'une fois.\n");
    printf("(ex : 1324, 3241, 4132, ...)\n");

    nb[0] = rand() % 4 + 1;
    nb[1] = rand() % 4 + 1;
    while (nb[1] == nb[0])
    {
        nb[1] = rand() % 4 + 1;
    }
    nb[2] = rand() % 4 + 1;
    while (nb[2] == nb[0] || nb[2] == nb[1])
    {
        nb[2] = rand() % 4 + 1;
    }
    nb[3] = rand() % 4 + 1;
    while (nb[3] == nb[0] || nb[3] == nb[1] || nb[3] == nb[2])
    {
        nb[3] = rand() % 4 + 1;
    }

    jeu(nb, 4);

    free(nb);
}

void moyenne()
{

    srand(time(NULL));

    int *nb = malloc(6 * sizeof(int));

    printf("difficulte moyenne :\n");
    printf("combinaison de 6 chiffres allant de 0 a 6, un chiffre peut etre present plusieurs fois.\n");
    printf("(ex : 016532, 640201, ...)\n");

    nb[0] = rand() % 6;
    nb[1] = rand() % 6;
    while (nb[1] == nb[0] && nb[1] != 0)
    {
        nb[1] = rand() % 6;
    }
    nb[2] = rand() % 6;
    while ((nb[2] == nb[0] && nb[2] != 0) || (nb[2] == nb[1] && nb[2] != 0))
    {
        nb[2] = rand() % 6;
    }
    nb[3] = rand() % 6;
    while ((nb[3] == nb[0] && nb[3] != 0) || (nb[3] == nb[1] && nb[3] != 0) || (nb[3] == nb[2] && nb[3] != 0))
    {
        nb[3] = rand() % 6;
    }
    nb[4] = rand() % 6;
    while ((nb[4] == nb[0] && nb[4] != 0) || (nb[4] == nb[1] && nb[4] != 0) || (nb[4] == nb[2] && nb[4] != 0) || (nb[4] == nb[3] && nb[4] != 0))
    {
        nb[4] = rand() % 6;
    }
    nb[5] = rand() % 6;
    while ((nb[5] == nb[0] && nb[5] != 0) || (nb[5] == nb[1] && nb[5] != 0) || (nb[5] == nb[2] && nb[5] != 0) || (nb[5] == nb[3] && nb[5] != 0) || (nb[5] == nb[4] && nb[5] != 0))
    {
        nb[5] = rand() % 6;
    }

    jeu(nb, 6);

    free(nb);
}

void difficile()
{
    srand(time(NULL));

    int *nb = malloc(8 * sizeof(int));

    printf("difficulte difficile :\n");
    printf("combinaison de 8 chiffres allant de 0 a 8, un chiffre peut etre present plusieurs fois.\n");
    printf("(ex : 86220165, 07513570, ...)\n");

    nb[0] = rand() % 8;
    nb[1] = rand() % 8;
    nb[2] = rand() % 8;
    nb[3] = rand() % 8;
    nb[4] = rand() % 8;
    nb[5] = rand() % 8;
    nb[6] = rand() % 8;
    nb[7] = rand() % 8;

    jeu(nb, 8);

    free(nb);
}

void jeu(int *nb, int compteur)
{

    char *aide = malloc(compteur * sizeof(char));
    int *tabChoix = malloc(compteur * sizeof(int));
    int choix = 0, j = 0, essaie = 0;

    printf("choisir un chiffre entre 1 et %d\n", compteur);

    for (int i = 0; i < compteur; i++)
    {
        printf("%d", nb[i]);
    }
    printf("\n");

    do
    {
        for (int i = 0; i < compteur; i++)
        {
            aide[i] = ' ';
        }
        aide[compteur] = '\0';

        j = 0;

        for (int i = 0; i < compteur; i++)
        {

            scanf("%d", &choix);

            tabChoix[i] = choix;
            if (tabChoix[i] == nb[i] && i != compteur)
            {
                j++;
                aide[i] = 'A';
            }

            for (int a = 0; a < compteur; a++)
            {
                if(tabChoix[i] == nb[a] && a != i && aide[i] != 'A')
                    aide[i] = 'B';
            }
        }

        printf("%s\n", aide);

        if (j != compteur)
            printf("vous n'avez pas trouver la bonne combinaison retenter votre chance !!\n");

        essaie++;

    } while (j < compteur);

    printf("bravo vous avez reussi en %d essaie\n", essaie);

    free(aide);
    free(tabChoix);
}