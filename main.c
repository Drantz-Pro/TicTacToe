#include<stdio.h>


const int R=3;
const int C=3;

void init(char t[R][C]);
int options();

void printTable(char table[R][C]);
int scanOption();
void updateTable(char table[R][C], int position, int turn);
int winner(char table[R][C]);
int repeatPosition(int arr[9],int pos);

void play(char table[R][C]);

int main(){

    char table [R][C];
    init(table);
    printf("\e[1;1H\e[2J");    
    while (1)
    {
        
        if (options() == 1)
        {
            play(table);
        }else{
            printf("\n\nBye...\n\n");
            break;
        }
        

    }

    return 0;
}


void init(char t[R][C]){

    for(int i=0; i < R ; i++){
        for(int j=0; j < C ; j++){
            t[i][j]= ' ';
        }
    }

}

int options(){

    int opcion=0;

    while (1)
    {
    
        printf("---- Ingrese numero de la opcion elegida ----\n\n");
        printf("\n1_ \t Jugar");
        printf("\n2_ \t Salir");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

        if (opcion < 3 && opcion > 0){
            break;
        }else{
            
            printf("\e[1;1H\e[2J");
            printf("\n\nBad input...\n\n");
            
        }
    }
    return opcion;
}

void printTable(char table[R][C]){

    printf("\n\n");

    for(int i=0; i < R ; i++){
        for (int j = 0; j < C; j++){
            
            printf(" %c ", table[i][j]);
            
            if (j<2){

                printf("|");

            }
            
        }

        if(i < 2){

            printf("\n------------\n");

        }
    }
    printf("\n\n");

}

int scanOption(){

    int position = 0;

    printf("\n\n");

    int adder = 0;
    for(int i=0; i < R ; i++){
        
        for (int j = 0; j < C; j++){
            
            printf(" %d ", 1+j+adder);
            
            if (j<2){

                printf("|");

            }
            
        }

        if(i < 2){

            printf("\n------------\n");

        }

        adder += 3;
    }
    printf("\n\n");

    printf("Choose with number: ");
    scanf("%d", &position);

    return position;

}


void updateTable(char table[R][C],int position , int turn){

  if(position > 6){
    position = position - 6;
    if (turn % 2 == 0)
    {
        table[2][position-1] = 'X';
    }else{
        table[2][position-1] = 'O';
    }

  } else{
    if (position > 3)
    {
        position = position - 3;
        if (turn % 2 == 0)
        {
            table[1][position-1] = 'X';
        }else{
            table[1][position-1] = 'O';
        }

    }else{

        if (turn % 2 == 0)
        {
            table[0][position-1] = 'X';
        }else{
            table[0][position-1] = 'O';
        }

    }
    
  } 

}

int winner(char table[R][C]){
    int win = 0;

    printf("0");
    for (int i = 0; i < C; i++){
        if (table[0][i] == table[1][i] && table[2][i] == table[1][i] && (table[0][i] =='X' || table[0][i] =='O'))
        {
            win = 1;
        }
    }

    for (int i = 0; i < R; i++)
    {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && (table[i][0] =='X' || table[i][0] =='O'))
        {
            win = 1;
        }
    }

    if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && (table[0][0] =='X' || table[0][0] =='O'))
    {
        win = 1;
    }

    if (table[0][2] == table[1][1] && table[1][1] == table[2][0]&& (table[0][2] =='X' || table[0][2] =='O'))
    {
        win = 1;
    }
    
    return win;
}

int repeatPosition(int arr[9],int pos){
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == 0)
        {
            break;
        }
        
        if (arr[i]== pos)
        {
            res = 1;
            break;
        }
        
    }
    
    return res;
}

void play(char table[R][C]){
 
    int turn = 0;
    int option = 0;
    int arr[9]={0,0,0,0,0,0,0,0,0};
    while (turn != 9)
    {
        printf("\e[1;1H\e[2J");
        printTable(table);
        option = scanOption();  
        if (option < 10 && option > 0 ) {
            if (repeatPosition(arr,option))
            {
                continue;
            }else{
                arr[turn] = option;
            }
            
            turn+=1;
            updateTable(table,option,turn);
            if (winner(table) == 1)
            {
                printf("\e[1;1H\e[2J");
                printf("\n\nCongratulations\n\n");
                break;
            }
        }else{
            continue;
        }

        printf("\e[1;1H\e[2J");

    }

    init(table);      
}