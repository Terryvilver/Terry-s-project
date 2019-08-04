#include <stdio.h>
#include <stdlib.h>
#define N 5

//Structure
typedef struct
{
    int tab[N][N];
    int lettre_max;
    int lettre_min;
    int permutationMAX;
    int permutation;
    int score;
    char Nom_joueur[30];

}POINTEUR;

//Prototypes des fonctions
int Texte_Menu();
void Jeu_1();
void Creation_Tableau(POINTEUR *pt1);
void Affichage_Tableau(POINTEUR *pt1);
void Identite_Joueur(POINTEUR *pt1);
void Afficher_Candy_Crush();
void Permutation(POINTEUR *pt1);
void Suppression_Lettre(POINTEUR *pt1);
void Remplir_Tableau(POINTEUR *pt1);
void Remplir_Case_Vide(POINTEUR *pt1);


//Divers
#define PI 3.141592653

/* Programme principal*/
void main()
{
    int choix=0;
    do
    {
        choix=Texte_Menu();
        switch(choix)
        {
        case(0):
            break;
        case(1):
            Jeu_1();
            break;
        default:
            printf("\nErreur sur le choix\n");
        }
    }
    while(choix!=0);
    system("pause");
}

int Texte_Menu()
{
    int i;
    char x;
    printf("\nPseudo Candy Crush");
    printf("\nPseudo Candy crush: 1");
    printf("\nFin du jeu : 0\n");
    printf("\nChoix : ");
    fflush(stdin);
    scanf("%c",&x);
    i=(int)x-48;
    return i;
}

void Jeu_1()
{
    POINTEUR p1;
    p1.score=0;
    p1.permutationMAX=5;
    p1.permutation=0;

    Identite_Joueur(&p1);
    Afficher_Candy_Crush();
    Creation_Tableau(&p1);
    Affichage_Tableau(&p1);
    Permutation(&p1);
    Affichage_Tableau(&p1);
    printf("\n\nScore:%d",p1.score);
    printf("\tPermutation:%d",p1.permutation);
    printf("\tPermutation MAX:%d",p1.permutationMAX);
    printf("\nJoueur:%s\n",p1.Nom_joueur);
}

void Creation_Tableau(POINTEUR *pt1)
{
    int i;
    int j;
    int k;
    int tmp;
    int compteur;
    pt1->lettre_max=100;
    pt1->lettre_min=97;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            label: while(1)
            {
                tmp=(rand()*((pt1->lettre_max+1)-pt1->lettre_min)/RAND_MAX+pt1->lettre_min);
                compteur=0;
                for(k=0;k<N;k++)
                {
                    if(pt1->tab[k][j]==tmp)
                    {
                        compteur++;

                        if(compteur>=2)
                        {
                            goto label;
                        }
                    }
                    else
                    {
                        compteur=0;
                    }
                }
                compteur=0;
                for(k=0;k<N;k++)
                {
                    if(pt1->tab[i][k]==tmp)
                    {
                        compteur++;

                        if(compteur>=2)
                        {
                            goto label;
                        }
                    }
                    else
                    {
                        compteur=0;
                    }
                }

                pt1->tab[i][j]=tmp;
                break;
            }
        }
    }
}

void Affichage_Tableau(POINTEUR *pt1)
{
    int i;
    int j;
    printf("\n\n");
    printf("    ");

    for(i=0;i<N;i++)  //Permet de faire les coordonnees en abscisse en chiffre
    {
        printf("%4d",i+1);
    }
    for(i=0;i<N;i++)
    {
        printf("\n\n%4d",i+1);
        for(j=0;j<N;j++)
        {
            printf("%4c",pt1->tab[i][j]);
        }
    }
    printf("\n");
}

void Identite_Joueur(POINTEUR *pt1)
{
    printf("Quel est votre nom ?");
    scanf("%s",pt1->Nom_joueur);
    printf("\n Joueur:%s\n\n",pt1->Nom_joueur);
}

void Afficher_Candy_Crush()
{
    printf("\n\t Pseudo Candy Crush\n\n");
}

void Permutation(POINTEUR *pt1)
{
    int i,j,x,y,score,l,tmp;
    score=pt1->score;


    for(pt1->permutation=0;pt1->permutation<pt1->permutationMAX;pt1->permutation++) //ICI 5 permutation
    {
        printf("\n\nScore:%d",pt1->score);
        printf("\tPermutation:%d",pt1->permutation);
        printf("\tPermutation MAX:%d",pt1->permutationMAX);
        printf("\nJoueur:%s\n",pt1->Nom_joueur);

        score=pt1->score;
        printf("\nAssurez vous de prendre des cases adjacentes du tableau lors des permutations\n");
        printf("\nCase avant: ligne espace colonne puis Entree: ");
        scanf("%d %d",&i,&j);
        i=i-1;
        j=j-1;
        tmp=pt1->tab[i][j];
        printf("\nCase Apres: ligne espace colonne puis Entree: ");
        scanf("%d %d",&x,&y);
        x=x-1;
        y=y-1;

        if((x>=i+2)||(x<=i-2)||(y>=j+2)||(y<=j-2))
        {
            printf("TRICHEUR !\n");
        }
        else
        {
            pt1->tab[i][j]=pt1->tab[x][y];
            pt1->tab[x][y]=tmp;
            printf("\nPermutation cases: %d%d <-> %d%d\n\n",i+1,j+1,x+1,y+1);
            Suppression_Lettre(pt1);
            Suppression_Lettre(pt1);
            Suppression_Lettre(pt1);
            Suppression_Lettre(pt1);

            while(score==pt1->score)
            {
                pt1->tab[x][y]=pt1->tab[i][j];
                pt1->tab[i][j]=tmp;
                Affichage_Tableau(pt1);
                printf("\n\nScore:%d",pt1->score);
                printf("\tPermutation:%d",pt1->permutation+1);
                printf("\nJoueur:%s\n",pt1->Nom_joueur);
                printf("\nErreur sur la permutations, les cases ont ete remis a leurs position initiales !!!\n");
                printf("\nAssurez vous de prendre des cases adjacentes du tableau lors des permutations\n");
                printf("\nCase avant: ligne espace colonne puis Entree: ");
                scanf("%d %d",&i,&j);
                i=i-1;
                j=j-1;
                tmp=pt1->tab[i][j];
                printf("\nCase Apres: ligne espace colonne puis Entree: ");
                scanf("%d %d",&x,&y);
                x=x-1;
                y=y-1;
                if((x>=i+2)||(x<=i-2)||(y>=j+2)||(y<=j-2))
                {
                    pt1->permutation=pt1->permutationMAX;
                    printf("TRICHEUR !\n");
                }
                else
                {
                    pt1->tab[i][j]=pt1->tab[x][y];
                    pt1->tab[x][y]=tmp;
                    printf("\nPermutation cases: %d%d <-> %d%d\n\n",i+1,j+1,x+1,y+1);
                    Suppression_Lettre(pt1);
                    Suppression_Lettre(pt1);
                    Suppression_Lettre(pt1);
                    Suppression_Lettre(pt1);
                }
            }
        }
    }
}

void Suppression_Lettre(POINTEUR *pt1)
{
    int i,j;


    for(i=0;i<N;i++)
    {
        for(j=0;j<N-4;j++)
        {
            while((pt1->tab[i][j]==pt1->tab[i][j+1])&&(pt1->tab[i][j+1]==pt1->tab[i][j+2])&&(pt1->tab[i][j+2]==pt1->tab[i][j+3])&&(pt1->tab[i][j+3]==pt1->tab[i][j+4]))
            {

                pt1->tab[i][j]=0;
                pt1->tab[i][j+1]=0;
                pt1->tab[i][j+2]=0;
                pt1->tab[i][j+3]=0;
                pt1->tab[i][j+4]=0;
                pt1->score=pt1->score+15;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);
            }
        }
        for(j=0;j<N-3;j++)
        {
            while((pt1->tab[i][j]==pt1->tab[i][j+1])&&(pt1->tab[i][j+1]==pt1->tab[i][j+2])&&(pt1->tab[i][j+2]==pt1->tab[i][j+3]))
            {
                pt1->tab[i][j]=0;
                pt1->tab[i][j+1]=0;
                pt1->tab[i][j+2]=0;
                pt1->tab[i][j+3]=0;
                pt1->score=pt1->score+10;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);
            }
        }
        for(j=0;j<N-2;j++)
        {
            while((pt1->tab[i][j]==pt1->tab[i][j+1])&&(pt1->tab[i][j+1]==pt1->tab[i][j+2]))
            {
                pt1->tab[i][j]=0;
                pt1->tab[i][j+1]=0;
                pt1->tab[i][j+2]=0;
                pt1->score=pt1->score+5;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);
            }
        }
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<N-4;i++)
        {
            while((pt1->tab[i][j]==pt1->tab[i+1][j])&&(pt1->tab[i+1][j]==pt1->tab[i+2][j])&&(pt1->tab[i+2][j]==pt1->tab[i+3][j])&&(pt1->tab[i+3][j]==pt1->tab[i+4][j]))
            {
                pt1->tab[i][j]=0;
                pt1->tab[i+1][j]=0;
                pt1->tab[i+2][j]=0;
                pt1->tab[i+3][j]=0;
                pt1->tab[i+4][j]=0;
                pt1->score=pt1->score+15;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);

            }
        }
        for(i=0;i<N-3;i++)
        {
            while((pt1->tab[i][j]==pt1->tab[i+1][j])&&(pt1->tab[i+1][j]==pt1->tab[i+2][j])&&(pt1->tab[i+2][j]==pt1->tab[i+3][j]))
            {
                pt1->tab[i][j]=0;
                pt1->tab[i+1][j]=0;
                pt1->tab[i+2][j]=0;
                pt1->tab[i+3][j]=0;
                pt1->score=pt1->score+10;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);
            }
        }
        for(i=0;i<N-2;i++)
        {
            while((pt1->tab[i][j]==pt1->tab[i+1][j])&&(pt1->tab[i+1][j]==pt1->tab[i+2][j]))
            {
                pt1->tab[i][j]=0;
                pt1->tab[i+1][j]=0;
                pt1->tab[i+2][j]=0;
                pt1->score=pt1->score+5;
                Affichage_Tableau(pt1);
                Remplir_Case_Vide(pt1);
            }
        }
    }
}

void Remplir_Case_Vide(POINTEUR *pt1)
{
    int i,j,k;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(pt1->tab[i][j]==0)
            {
                for(k=i;k>0;k--)
                {
                    pt1->tab[k][j]=pt1->tab[k-1][j];
                }
                pt1->tab[0][j]=0;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(pt1->tab[i][j]==0)
            {
                pt1->tab[i][j]=(rand()*((pt1->lettre_max+1)-pt1->lettre_min)/RAND_MAX+pt1->lettre_min);
            }
        }
    }
    Affichage_Tableau(pt1);
}

