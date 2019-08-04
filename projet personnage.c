#include<stdio.h>

/*placement des élements dans le tableau en utilisant "for" pour les 0 et les 2 et 3
et création des autres éléments dans chaque case. */
void init_carte(int tab[][20]) {
	int i;
	int j;
	
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
				tab[i][j] = 0;
			if( (i <= 10) && (j == 2)){
				tab[i][j] = 2;
			}
			if( (i == 12) && (j <= 15 )){
				tab[i][j] = 3;
			}
		}
	}
	tab[19][19] = 4;
	tab[1][1] = 7;
	tab[3][1] = 7;
	tab[1][8] = 7;
	tab[8][1] = 7;
	tab[7][3] = 7;
	tab[5][4] = 7;
	tab[13][13] = 7;
	tab[13][12] = 7;
	tab[16][16] = 7;
	tab[3][3] = 7;
	tab[11][6] = 7;
	tab[1][1] = 7;
	tab[14][16] = 7;
	tab[17][17] = 7;
	tab[9][9] = 6;
	tab[7][16] = 5;
	tab[17][13] = 5;
	tab[11][11] = 5;
	tab[7][3] = 5;
	tab[6][5] = 5;
	tab[4][5] = 5;
	tab[19][9] = 5;
	tab[8][12] = 5;
	tab[12][17] = 5;
	tab[4][16] = 5;
	tab[8][8] = 1;
	tab[6][6] = 1;
	tab[18][19] = 8;
}

/*On affiche les éléments qu'on a introduit dans notre tab[][20] à l'aide d'une procédure et on initialise notre X sur la carte à l'aide d'un printf. */

void affiche_carte(int tab[][20], int tabA[2]){
	int i ;
	int j ;
	for(i = 0; i < 20 ; i++ ){
		for(j = 0; j < 20; j++){
			if(i == tabA[0] && j == tabA[1]) {
				printf("X ");
			} else {
				printf("%d ", tab[i][j]);
			}
		}
		printf("\n");
	}
}

/*On crée notre l'élément qui permets de stocker chacun des évènements qui va se produire pendant le jeu. */
void deplace_personnage(int tab[][20], int tabB[1], int tabA[2]){
	int i = 0;
	int j = 0;
	int move = 1;
	int score = 0;
	int vie = 12;
	int clee =0;
	int tresor =0;

	while(move==1){
		affiche_carte(tab, tabA);
		printf("Vous avez %d trésor !\n", tresor);
		printf("Vous avez %d clée !\n", clee);
		printf("Vous avez %d points de vie.\n",vie);
		printf("Votre score est : %d.\n",score);	
		printf("Ou voulez-vous vous déplacer(haut:8 bas:2 gauche:4 droite:6 et quitter:0 ) ?\n");
		
/* Notre tabB[0] fait office ici de flèche directionnelle pour se déplacer et le déplacement est fait qu'à certaine condition ! */
		scanf("%d",&tabB[0]);
		switch(tabB[0]){
			case 8: i = tabA[0]-1; j = tabA[1]; break;
			case 2:	i = tabA[0]+1; j = tabA[1]; break;
			case 6: i = tabA[0]; j = tabA[1]+1; break;
			case 4: i = tabA[0]; j = tabA[1]-1; break;
			case 0: printf("Vous avez quitté !\n"); move=0; break;
			default: printf("Commande non répertorié !\n"); break;
		}
		if(i<0 || i>19 || j<0 || j>19) {
			printf("Tu es sorti du tableau !\n");
		} else if(tab[i][j] == 2 || tab[i][j] == 3) {
			printf("Tu t'es cogné !\n");
		} else { 
			tabA[0]= i;
			tabA[1]= j;
			if(tab[tabA[0]][tabA[1]] == 5 ) {
				tab[tabA[0]][tabA[1]] = 0;
				score = score +1;
				if(score == 10) {
					printf("Votre score est : %d.\n",score);
					printf("Vous avez gagné, bravo !\n");
					move=0;
				}
			}
			else if(tab[tabA[0]][tabA[1]] == 4) {
				tab[tabA[0]][tabA[1]] = 0;
				clee= clee +1;
				printf("Vous avez acquis une clé(s) !\n");
			}
			else if(tab[tabA[0]][tabA[1]] == 7 ) {
				tab[tabA[0]][tabA[1]] = 0;
				vie = vie-1;
				if(vie == 0){
					printf("Vous avez %d points de vie.\n",vie);
					printf("Vous avez succombé..\n");
					move=0;
				}
			}
			else if(clee==1 && tab[tabA[0]][tabA[1]] == 6) {
					tab[tabA[0]][tabA[1]] = 0;
					tresor = tresor+1;
					printf("vous avez acquis un trésor !!!\n");
			}
			else if(tab[tabA[0]][tabA[1]] == 8) {
					tab[tabA[0]][tabA[1]] == 0;
					vie = vie -12;
					printf("Vous avez %d points de vie.\n",vie);
					printf("Vous avez succombé..\n");
					move=0;
			}
		}	
	}
}


int main() {
	int tab[20][20];
	int tabA[2];
	int tabB[1];
	tabA[0] = 0;
	tabA[1] = 0;
	init_carte(tab);
	deplace_personnage(tab, tabB, tabA);
	return 0;
}
	
