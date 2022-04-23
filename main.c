#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void display(char board[8][8])
{
    int i;
    printf("\n");
    //sleep() function is used to pause the screen for a second
    sleep(2);
    //setclr() function is used to change the color of the text
    setclr(31);
    //a denotes the alert sound.It produces a sound when executed.Actually,it is an escape sequence
    printf("\a");
    for(i=0;i<8;)
    {
        printf("\n  +--+--+--+--+--+--+--+--+");
        printf("\n%d | %c| %c| %c| %c| %c| %c| %c| %c|",i + 1,board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7]);
        i++;
    }
    printf("\n  +--+--+--+--+--+--+--+--+");
    printf("\n    A  B  C  D  E  F  G  H");
}
int main()
{
    intro:;


    FILE *f; //creating a file to store the scores

    char name1[25],name2[25],nhigh[25];
    int i,j,x,y,dir,pla,highscr=0,opp,yolo=0,limit=0;
    char board[8][8],A,B,pos[2];

    printf("\n\t\t\t\t\t----------------------------------");
    printf("\n\t\t\t\t\t\tPrevious Records:");
    //open a file for reading
    f=fopen("F:\\highscore.txt","rb");
    if(f==NULL)
    {
        printf("file does not exists \n");
    }

    fprintf(f,"\n %s = %d",nhigh,highscr);
    //to close the file
    fclose(f);
    printf("\n\t\t\t\t\t-----------------------------------");


    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            board[i][j]=' ';
        }
    }
    setclr(34);//34 indicates the green color
    printf("\n\n\t\t\t\t\tWELCOME TO THE WORLD OF CHECKERS GAME!!!!\n\n\n");

    setclr(35);

    printf("\a");
    printf("\n\tEnter the name of the player-1:");
    scanf("%s",name1);
    printf("\a");
    printf("\n\tEnter the name of the player-2:");
    scanf("%s",name2);
    printf("\nThe rules are as usual...\n");
    printf("In the end,player who has his/her tokens left wins the game...\n");
    printf("\n 'x'  'o' ");// black or white
    setclr(31);
    sleep(1);
    printf("\a");
    printf("\n\nEnter player-1 symbol:");
    scanf(" %c",&A);
    printf("\a");


    printf("\nEnter the player-2 symbol:");
    scanf(" %c",&B);
    if(A==B)
    {
        printf("   LOL!!! Both the symbols are same....");
        goto intro;
    }
    printf("\a");
    printf("\nAND THE GAME STARTS NOW...");
    char tick=A;
    char TICK=B;
    board[0][0]=B;board[0][2]=B;board[0][4]=B;board[0][6]=B;
    board[1][1]=B;board[1][3]=B;board[1][5]=B;board[1][7]=B;
    board[2][0]=B;board[2][2]=B;board[2][4]=B;board[2][6]=B;
    board[5][1]=A;board[5][3]=A;board[5][5]=A;board[5][7]=A;
    board[6][0]=A;board[6][2]=A;board[6][4]=A;board[6][6]=A;
    board[7][1]=A;board[7][3]=A;board[7][5]=A;board[7][7]=A;

    start:
    display(board);

    setclr(34);
    printf("\a");
    printf("\n player-1's (%c) turn...",A);
    printf("\n Enter position:");//the position of the coin which we are going to move
    scanf("%s",pos);
    printf("\n");

    if(pos[0]== 'A')
        x=0;
    else if(pos[0]== 'B')
        x=1;
    else if(pos[0]== 'C')
        x=2;
    else if(pos[0]== 'D')
        x=3;
    else if(pos[0]== 'E')
        x=4;
    else if(pos[0]== 'F')
        x=5;
    else if(pos[0]== 'G')
        x=6;
    else if(pos[0]== 'H')
        x=7;
    else
    {
        //if anything other than these 8 alphabets is given,the compiler will ask us to enter the position again
        printf("Enter again...");
        //goto start statement will take the compiler to 89th line.
        goto start;
    }

    if(pos[1]== '1')
        y=0;
    else if(pos[1]== '2')
        y=1;
    else if(pos[1]== '3')
        y=2;
    else if(pos[1]== '4')
        y=3;
    else if(pos[1]== '5')
        y=4;
    else if(pos[1]== '6')
        y=5;
    else if(pos[1]== '7')
        y=6;
    else if(pos[1]== '8')
        y=7;
    else
    {
        //if anything other than these 8 numbers are given as input,it will ask us to enter the position again
        printf("Enter again...");
        goto start;
    }

    if(board[y][x]!=A)
    {
        //if the given position doesn't have the player-1's coin,the compiler will ask us to enter the position again
        printf("Enter again...");
        goto start;
    }
    printf("\a");
    printf("Which direction?\n1-upper left diagonal\n2-upper right diagonal\n3-lower left diagonal\n4-lower right diagonal\n");//مخالف لقواعد اللعبة محتاج تعديل
    scanf(" %d",&dir);
    A=tick;
    B=TICK;
    setclr(39);

    //direction=1 indicates the upper left diagonal
    if(dir == 1)
    {
        if(x==0 || y==0)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y-1][x-1]==A)
        {
            printf("move invlaid!");
            goto start;
        }
        if(board[y - 1][x - 1]==' ')
        {
            board[y][x]=' ';
            board[--y][--x]=A;
            goto done1;
        }
        //if the jumping position contains our opponent,the following if block takes place
        if(board[y - 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y - 2][x - 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y - 1][x - 1]=' ';
                y-=2;x-=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==2)
    {
        if(x==7 || y==0)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y - 1][x + 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y - 1][x + 1]==' ')
        {
            board[y][x]=' ';
            board[--y][++x]=A;
            goto done1;
        }
        if(board[y - 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y - 2][x + 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y - 1][x + 1]=' ';
                y-=2;x+=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==3)
    {
        if(x==0 || y==7)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x - 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x - 1]==' ')
        {
            board[y][x]=' ';
            board[++y][--x]=A;
            goto done1;
        }
        if(board[y + 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y + 2][x - 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y + 1][x - 1]=' ';
                y+=2;x-=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==4)
    {
        if(x==7 || y==7)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x + 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x + 1]==' ')
        {
            board[y][x]=' ';
            board[++y][++x]=A;
            goto done1;
        }
        if(board[y + 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y + 2][x + 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y + 1][x + 1]=' ';
                y+=2;x+=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    //after jumping to the desired position,the compiler reads the done1 statement
    done1:
        display(board);
        pla=0;opp=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==A)
                    pla+=5;//score of player-1
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==B)
                    opp+=5;//score of player-2
            }
        }
        //displays the scores of the players after each moves
        printf("\n\t\t\t\tCurrent scores:");
        printf("\n\t\t\t\t%s = %d",name1,pla);
        printf("\n\t\t\t\t%s = %d",name2,opp);
        if(pla==0 || opp==0)
            goto end;
    printf("\n");
    setclr(34);
    printf("player-2's (%c) turn...",B);
    again:
        if(limit==15)
        {
            printf("\nplayer-2 got confused:-P");
            limit=0;
            goto start;
        }
        if(yolo==15)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(board[i][j]==B);
                    {
                        y=i;
                        x=j;
                    }
                }
            }
            yolo=0;
            limit++;
        }
        else
        {
            y = rand()%8;
            x = rand()%8;
        }
        if(board[y][x]!=B)
            goto again;
            dir=(rand()%4)+1;
        if(board[y - 1][x - 1]==A && x>1 && y>1)
            dir=1;
        if(board[y - 1][x + 1]==A && x<6 && y>1)
            dir=2;
        if(board[y + 1][x - 1]==A && x>1 && y<6)
            dir=3;
        if(board[y + 1][x + 1]==A && x<6 && y<6)
            dir=4;
        A=tick;
        B=TICK;

        if(dir==1)
        {
            if(x==0 || y==0)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y - 1][x - 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y - 1][x - 1]==' ')
            {
                board[y][x]=' ';
                board[--y][--x]=B;
                goto done2;
            }
            if(board[y - 1][x - 1]==A)
            {
                if(x>=1)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(board[y - 2][x - 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    board[y][x]=' ';
                    board[y - 1][x - 1]=' ';
                    y-=2;x-=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==2)
        {
            if(x==7 || y==0)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y - 1][x + 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y - 1][x + 1]==' ')
            {
                board[y][x]=' ';
                board[--y][++x]=B;
                goto done2;
            }
            if(board[y - 1][x + 1]==A)
            {
                if(x>=6)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(board[y - 2][x + 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    board[y][x]=' ';
                    board[y - 1][x + 1]=' ';
                    y-=2;x+=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==3)
        {
            if(x==0 || y==7)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y + 1][x - 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y + 1][x - 1]==' ')
            {
                board[y][x]=' ';
                board[++y][--x]=B;
                goto done2;
            }
            if(board[y + 1][x - 1]==A)
            {
                if(x>=1)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(board[y + 2][x - 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    board[y][x]=' ';
                    board[y + 1][x - 1]=' ';
                    y+=2;x-=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==4)
        {
            if(x==7 || y==7)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y + 1][x + 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(board[y + 1][x + 1]==' ')
            {
                board[y][x]=' ';
                board[++y][++x]=B;
                goto done2;
            }
            if(board[y + 1][x + 1]==A)
            {
                if(x>=6)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(board[y + 2][x + 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    board[y][x]=' ';
                    board[y + 1][x + 1]=' ';
                    y+=2;x+=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
    done2:
        display(board);

        pla=0;
        opp=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==A)
                    pla+=5;
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==B)
                    opp+=5;
            }
        }
        /*this too displays the scores after each move.The only difference is this block is for player-2's move,
        while which we saw above is for player-1's move*/
        printf("\n\t\t\t\tCurrent scores:");
        printf("\n\t\t\t\t%s = %d",name1,pla);
        printf("\n\t\t\t\t%s = %d",name2,opp);
        if(pla==0 || opp==0)
            //if score of player-1 or player-2 is 0,the compiler goes to the end part,or else it goes to start part
            goto end;
        else
            goto start;
    end:
        setclr(40);
        if(pla>opp)
        {
            sleep(1);
            printf("\n\n");
            //displays the final score of each player and displays who won the game.This block is for player-1,if he/she wins..
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\n%s won the game.....",name1);
            sleep(1);

            //system("cls") clears the screen
            system("cls");
            if(pla>highscr)
            {
                sleep(1);
                highscr=pla;
                strcpy(nhigh,name1);
                setclr(34);

                //if player-1 wins the high score screen is displayed
                printf("\nNEW HIGH SCORE!!!!");
                f=fopen("F:\\highscore.txt","w");
                fprintf(f,"\n %s = %d",nhigh,highscr);
                fclose(f);
                printf("\nHighest score:\n%s = %d",nhigh,highscr);
            }
        }
        if(pla<opp)
        {
            sleep(1);
            printf("\n\n");
            //this displays the score and shows who won the game.This blocks gets executed when player-2 wins.
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\n%s won the game....",name2);
            sleep(1);

            system("cls");
            if(opp>highscr)
            {
                sleep(1);
                highscr=opp;
                strcpy(nhigh,name2);
                setclr(34);

                //if player-2 wins,the high score screen is displayed
                printf("\nNEW HIGH SCORE!!!");
                f=fopen("F:\\highscore.txt","w");
                fprintf(f,"\n %s = %d",nhigh,highscr);
                fclose(f);
                printf("\nHighest score:\n%s = %d",nhigh,highscr);
            }
        }
        if(pla==opp)
        {
            sleep(1);
            printf("\n\n");
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\nIt's a draw!!!!");
            sleep(1);

            system("cls");
            if(pla>highscr)
            {
                sleep(1);
                highscr=pla;
                strcpy(nhigh,name1);
                setclr(34);


                f=fopen("F:\\highscore.txt","w");
                fprintf(f,"\n %s = %d",nhigh,highscr);
                fclose(f);
                printf("\nHighest score:\n%s = %d",nhigh,highscr);
            }
            if(opp>highscr)
            {
                sleep(1);
                highscr=opp;
                strcpy(nhigh,name2);
                setclr(34);


                f=fopen("F:\\highscore.txt","w");
                fprintf(f,"\n %s = %d",nhigh,highscr);
                fclose(f);
                printf("\nHighest score:\n%s = %d",nhigh,highscr);
            }
        }

    getch();
    return 0;
}

//This is a user-defined function,created to change the color of the text...
void setclr(int F)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {

        wColor = (csbi.wAttributes & 0xF0)+(F & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
