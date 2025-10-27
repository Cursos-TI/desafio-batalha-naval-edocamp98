#include <stdio.h>

// declaração da matriz-tabuleiro
int main() {
    int tabuleiro[10][10] = {
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

    // impressão da matriz-tabuleiro INICIAL
    printf("   A B C D E F G H I J\n");
    printf(" +--------------------\n");
    int coluna = 0;
    for (int i = 0; i < 10; i++) {
        printf("%d| ", coluna); 
        for (int j = 0; j < 10; j++) {
            //Navio H(A0,B0,C0)
            if (j < 3 && i == 0) {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);
                continue;
            }
            //Navio V(J0,J1,J2)
            if (j == 9 && i < 6 && i > 2) {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);
                continue;
            }
            //Navio D-1 (F5, G6, H7)
            if (j == i && i > 4 && i < 8) {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);                
                continue;
            }
            //Navio D-2 (A9, B8, C7)
            if ((j + i) == 9 && i > 6) {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);                
                continue;
            }
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        coluna++;
    }

    int poder;
    printf("\nInsira um poder para atacar:\n");
    printf("[ 1 ] Cone\n");
    printf("[ 2 ] Octaedro\n");
    printf("[ 3 ] Cruz\n");
    scanf("%d", &poder);
    
    switch(poder) {
        case 1: {
            int cone[3][5] = {
                {0,0,1,0,0},
                {0,1,1,1,0},
                {1,1,1,1,1}
            };
            
            printf("Onde deseja atacar? (insira as coordenadas na matriz)\n");
            printf("Posição na linha (0-9): ");
            int linha_ataque;
            scanf("%d", &linha_ataque);
            printf("Posição na coluna (0-9): ");
            int coluna_ataque;
            scanf("%d", &coluna_ataque);
            
            // INSERIR o cone na posição desejada
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    int pos_linha = linha_ataque + i;
                    int pos_coluna = coluna_ataque + j;
                    
                    // Verificar se está dentro dos limites do tabuleiro
                    if (pos_linha >= 0 && pos_linha < 10 && pos_coluna >= 0 && pos_coluna < 10) {
                        tabuleiro[pos_linha][pos_coluna] = cone[i][j];
                    }
                }
            }
            break;
        }
        
        case 2: {
            int octaedro[3][5] = {
                {0,0,1,0,0},
                {0,1,1,1,0},
                {0,0,1,0,0}
            };
            
            printf("Onde deseja atacar? (insira as coordenadas na matriz)\n");
            printf("Posição na linha (0-9): ");
            int linha_ataque;
            scanf("%d", &linha_ataque);
            printf("Posição na coluna (0-9): ");
            int coluna_ataque;
            scanf("%d", &coluna_ataque);
            
            // INSERIR o octaedro na posição desejada
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    int pos_linha = linha_ataque + i;
                    int pos_coluna = coluna_ataque + j;
                    
                    // Verificar se está dentro dos limites do tabuleiro
                    if (pos_linha >= 0 && pos_linha < 10 && pos_coluna >= 0 && pos_coluna < 10) {
                        tabuleiro[pos_linha][pos_coluna] = octaedro[i][j];
                    }
                }
            }
            break;
        }
        
        case 3: {
            int cruz[3][5] = {
                {0,0,1,0,0},
                {1,1,1,1,1},
                {0,0,1,0,0}
            };
            
            printf("Onde deseja atacar? (insira as coordenadas na matriz)\n");
            printf("Posição na linha (0-9): ");
            int linha_ataque;
            scanf("%d", &linha_ataque);
            printf("Posição na coluna (0-9): ");
            int coluna_ataque;
            scanf("%d", &coluna_ataque);
            
            // INSERIR a cruz na posição desejada
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    int pos_linha = linha_ataque + i;
                    int pos_coluna = coluna_ataque + j;
                    
                    // Verificar se está dentro dos limites do tabuleiro
                    if (pos_linha >= 0 && pos_linha < 10 && pos_coluna >= 0 && pos_coluna < 10) {
                        tabuleiro[pos_linha][pos_coluna] = cruz[i][j];
                    }
                }
            }
            break;
        }
    }
    
    // IMPRESSÃO do tabuleiro ATUALIZADO
    printf("\nTabuleiro após o ataque:\n");
    printf("   A B C D E F G H I J\n");
    printf(" +--------------------\n");
    coluna = 0;
    for (int i = 0; i < 10; i++) {
        printf("%d| ", coluna); 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        coluna++;
    }

    return 0;
}