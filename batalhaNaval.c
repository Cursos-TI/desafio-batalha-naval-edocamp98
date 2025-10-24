#include <stdio.h>

//Recursivas



// declaração da matriz-tabuleiro

int main() {
    int tabuleiro[10][10]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
        
    };

// impressão da matriz-tabuleiro
    printf("   A B C D E F G H I J\n");
    printf(" +--------------------\n");
    int coluna = 0;
    for (int i = 0; i < 10; i++){ //Loop externo - COLUNAS
        printf("%d| ", coluna); 
        for (int j = 0; j <10; j++){ //Loop interno - LINHAS
            //Navio H(A0,B0,C0)
            if (j < 3 && i == 0){
                printf("3 ");
                continue;
            }
            //Navio V(J0,J1,J2)
            if (j == 9 && i < 6 && i > 2){
                printf("3 ");
                continue;
            }
            //Navio D-1 (F5, G6, H7)
            if (j == i && i > 4 && i <8){
                printf("3 ");
                continue;
            }
            //Navio D-2 (A9, B8, C7)
            if ((j + i) == 9 && i > 6){
                printf("3 ");
                continue;
                
            }
            printf("%d ", tabuleiro[i][j]);
        }
        
        printf("\n");
        coluna++;
    };
    int poder;
    printf("Insira um poder para atacar:\n");
    printf("[ 1 ] Cone\n");
    printf("[ 2 ] Octaedro\n");
    printf("[ 3 ] Cruz\n");
    scanf("%d", &poder);

    switch(poder)
    {
        case 1:
            cone();
            break;
 /*       case 2:
            octa();
            break;
        case 3:
            cruz();
            break;
        }


    
    */

    return 0;
}}
