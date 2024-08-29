#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 3
#define COLUMNS 3
#define NUMBER_OF_VERIFY 2
#define SIZE_BOARD 10

char game[ROWS][COLUMNS];
char playerOne[50], playerTwo[50];

void initializeMatrix();
int isValidy(char letter);
int isValidyCoordinate(int x, int y);
int positionIsVoid(int x, int y);

int winLines();
int winColumns();
int winDiagonalMain();
int winDiagonalSecondary();

void printMatrix();
void play();

int main(){
    
    int op;

    puts("Player one enter a name: ");
    fgets(playerOne,50,stdin);
    playerOne[strcspn(playerOne, "\n")] = '\0';

    puts("Player second enter a name: ");
    fgets(playerTwo,50,stdin);
    playerTwo[strcspn(playerTwo, "\n")] = '\0';

    printf("\n\n");

    do{
        initializeMatrix();
        play();
        printf("New game? (1 -> Yes || 0 -> No): ");
        scanf("%d",&op);
    }while(op);


    return 0;
}

void initializeMatrix(){
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            game[i][j] = 'V';
        }
    }
}

int isValidy(char letter){

    return (letter == 'x' || letter == '0') ?  1 : 0;

}

int isValidyCoordinate(int x, int y){

    return (x >= 0 && x < ROWS && y >= 0 && y < COLUMNS) ? 1 : 0;

}
int positionIsVoid(int x, int y){

    return (game[x][y] != 'x' && game[x][y] != '0') ? 1 : 0;

}

int winLines(){

    int equals = 1;

    for(int i = 0; i < ROWS; i++){

         equals = 1;

        for(int j = 0; j < ROWS - 1; j++){

            if(isValidy(game[i][j]) &&
                game[i][j] == game[i][j+1])
                {

                    equals++;
            }
        }
        
        if(equals == ROWS){
            return 1;
        }

    }

    return 0;
}

int winColumns(){

    int equals = 1;

    for(int i = 0; i < ROWS; i++){

        for(int j = 0; j < COLUMNS - 1; j++){

            if(isValidy(game[j][i]) && game[j][i] == game[j+1][i]){
                equals++;
            }

            if(equals == COLUMNS){
                return 1;
            }

            equals = 1;
        }
    }

    return 0;

}

int winDiagonalMain(){

    int equals = 1;

    for(int i = 0; i < ROWS - 1; i++){

        if(isValidy(game[i][i]) && game[i][i] == game[i+1][i+1]){
            equals++;
        }        
    } 

    return (equals == ROWS) ? 1 : 0;


}

int winDiagonalSecondary(){

    int equals = 1;

    for(int i = 0; i < ROWS - 1; i++){
        
        if(isValidy(game[i][COLUMNS - i - 1]) && game[i][COLUMNS - i - 1] == game[i+1][COLUMNS - i - 2]){
            equals++;
        }

    }

     return (equals == ROWS) ? 1 : 0;

}

void printMatrix(){

    printf("   0   1    2\n");

    for(int i = 0; i < ROWS; i++){

        printf("%d ",i);

        for(int j = 0; j < COLUMNS; j++){

            if(isValidy(game[i][j])){

                if(j < 2){
                    printf(" %c| ", game[i][j]);
                }

                else{
                    printf(" %c ",game[i][j]);
                }

            }
            else{

                if(j < 2){
                    printf(" | ");
                }

                else{
                    printf("  ");
                }

            }
        }
        printf("\n-------------\n");
    }

}

void play(){

    int x = 0, y = 0, validy = 0, order = 1, win = 0, plays = 0;

    do{
            do{
                    printMatrix();
                    printf("Enter a x and y to play in board: ");
                    scanf(" %d %d",&x,&y);
                    getchar();

                    validy = isValidyCoordinate(x,y);

                    if(validy){
                        validy += positionIsVoid(x,y);
                    }

                }while(validy != NUMBER_OF_VERIFY);


                if(order == 1){
                     game[x][y] = 'x';
                }
                else{
                     game[x][y] = '0';
                }

                plays++;
                order++;

                if(order == 3){
                    order = 1;
                }


                win = winLines() || winColumns() || winDiagonalMain() || winDiagonalSecondary();

    }while(!win && plays < SIZE_BOARD);

    if(win){

        if(order - 1 == 1){
            printf("Congratulations. %s win my boy\n",playerOne);
        }

        else{
            printf("Congratulations. %s win my boy\n", playerTwo);
        }

    }
    else{
        printf("\nDefeat my boys\n");
    }
     
}

