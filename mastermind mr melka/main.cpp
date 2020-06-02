#include <stdio.h>
#include <stdlib.h>


// typedef char Formule[5]

#define COLORS "BRNVJOG"

bool caracValide(char c)
{
    for (int i=0; i<7; ++i)
    {
        if (c == COLORS[i])
            return true;
    }
    return false;
}

char saisieCouleur()
{
    char c;
    do
    {
        scanf("%c", &c);
    }
    while (!caracValide(c));
    return c;
}

int calculBP(char vec1[5], char vec2[5])
{
    int count = 0;
    for (int i=0; i<5; ++i)
    {
        if (vec1[i] == vec2[i])
        {
            count++;
            vec1[i] = 'X';
            vec2[i] = 'Y';
        }
    }
    return count;
}

int calculMP(char vec1[5], char vec2[5])
{
    int count = 0;
    for (int i=0; i<5; ++i)
    {
        for (int j=0; j<5; ++j)
        {
            if (vec1[i] == vec2[j])
            {
                count++;
                vec1[i] = 'X';
                vec2[j] = 'Y';
            }
        }
    }
    return count;
}

int main()
{
    char varOriginale[5], varCopie[5], varEssai[5];
    int BP, MP;
    int nbEssais = 0;

    // saisie 1er joueur
    printf("1er Joueur: ");
    for (int i=0; i<5; ++i)
    {
        varOriginale[i] = saisieCouleur();
    }

    // efface l'ecran (system("clear") sous LINUX)
    system("cls");

    printf("2eme Joueur:   BP   MP\n");

    // boucle principale
    BP = 0;
    while (BP < 5)
    {
        nbEssais++;

        // saisie 2e joueur
        printf("essai %d  ", nbEssais);
        for (int i=0; i<5; ++i)
        {
            varCopie[i] = varOriginale[i];  // copie de varOriginale
            varEssai[i] = saisieCouleur();
        }

        // calcul du nombre de couleur bien placees
        BP = calculBP(varCopie, varEssai);
        // calcul du nombre de couleur mal placees
        MP = calculMP(varCopie, varEssai);

        printf("                %d     %d\n", BP, MP);
    }

    // affichage resultat
    printf("La formule a ete touvee en %d essais:", nbEssais);
    if (nbEssais <= 5)
        printf("Bravo !\n");
    else if (nbEssais <= 10)
        printf("Correct\n");
    else
        printf("Decevant\n");

    return 0;
}
