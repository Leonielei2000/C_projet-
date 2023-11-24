#include <stdio.h>
#include <MLV/MLV_all.h>
#define NB_COL 22
#define NB_LIG 28
#define GAPG_D 60//mettre au centre
#define GAPH_B 40//mettre au centre
#define FENETRE_H 440
#define FENETRE_W 560
/*define chaque type de cellule en enum*/
enum CellType {
    EMPTY, // case vide 
    PATH,  // case chemin
    NEST,  // case nid de monstre
    CAMP   // case camp a proteger
};

enum CellType grid[NB_COL][NB_LIG];
/*afficher la grille*/
void afficher_grille(void){
    int i,j;
g
    for(i=0;i < NB_COL;i++){
        MLV_draw_line( 0, FENETRE_H/NB_COL * i, FENETRE_W, FENETRE_H/NB_COL * i, MLV_COLOR_BLACK );
        for(j=0;j < NB_LIG;j++){
            MLV_draw_line( FENETRE_W/NB_LIG * j , 0, FENETRE_W/NB_LIG * j, FENETRE_H, MLV_COLOR_BLACK );
            switch(grid[i][j]){
                case EMPTY:
                /*case gris +1 cest pour le gris effacer pas le grille*/
                MLV_draw_filled_rectangle( FENETRE_W/NB_LIG * j + 1,FENETRE_H/NB_COL * i + 1, FENETRE_W/NB_LIG , FENETRE_H/NB_COL, MLV_COLOR_GRAY );
                    break;
                case PATH:
		/*case blanc*/
		MLV_draw_filled_rectangle( FENETRE_W/NB_LIG * j + 1,FENETRE_H/NB_COL * i + 1, FENETRE_W/NB_LIG , FENETRE_H/NB_COL, MLV_COLOR_WHITE );
                    break;
                case NEST:
                MLV_draw_filled_rectangle( FENETRE_W/NB_LIG * j + 1,FENETRE_H/NB_COL * i + 1, FENETRE_W/NB_LIG , FENETRE_H/NB_COL, MLV_COLOR_RED );
                /*case rouge*/
                    break;
                case CAMP:
                MLV_draw_filled_rectangle( FENETRE_W/NB_LIG * j + 1,FENETRE_H/NB_COL * i + 1, FENETRE_W/NB_LIG , FENETRE_H/NB_COL, MLV_COLOR_GREEN );
                /*case vert*/
                    break;
            }
        }
        
    }
}
int main(){
    MLV_create_window( "jeu", "jeu", 600, 500 );
 
	grid[3][6]=NEST;
	grid[20][16]=CAMP;
        //
        // Attend 10 secondes avant la fin du programme.
        //
	afficher_grille();
    MLV_actualise_window();
        MLV_wait_seconds( 100 );
        //
        // Fermer la fenêtre
        //
        MLV_free_window();
        return 0;
}
