#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
//#define dodo ios_base::sync_with_stdio(false);cin.tie(nullptr)
//#define ll long long
bool gameOver;
int height=20, width=40;
int x,y,score;
int fruitX, fruitY;
enum Direction{STOP=0,RIGHT,LEFT,UP,DOWN};
Direction dir;
int tail=0;
bool head;
vector<int>tailX(100),tailY(100);
void setup(){
    score=0;
    dir=STOP;
    gameOver= false;
    x= width/2;
    y=height/2;
    srand(time(NULL));
    fruitX= rand()%width;
    srand(time(NULL));
    fruitY= rand()%height;
}
void draw(){
//    system("cls");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    head= false;
    for (int i = 0; i < width; ++i) {
        cout<<"#";
    }
    cout<<'\n';
    for (int i = 1; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j==0||j==width-1||i==height-1&&j<width)
                cout<<"#";
            else{
                if (i==y&&j==x){
                    cout<<"O";
                }else if (i==fruitY&&j==fruitX){
                    cout<<"@";
                }else{
                    bool ok= true;
                    for (int k = 0; k < tail; ++k) {
                        if (tailX[k]==j&&tailY[k]==i)
                            cout<<'o',ok= false;
                    }
                    if (ok)
                        cout<<" ";
                }
            }

        }
        cout<<'\n';
    }

    cout<<"\nSCORE: "<<score<<"\n";
}
void input(){

    if (_kbhit()){
        switch (_getch()) {
            case 'a':
                dir=LEFT;
                break;
            case 'w':
                dir=UP;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'x':
                gameOver= true;
                break;
        }
    }
    if (_kbhit()){
        switch (_getch()) {
            case 75:
                dir=LEFT;
                break;
            case 72:
                dir=UP;
                break;
            case 77:
                dir=RIGHT;
                break;
            case 80:
                dir=DOWN;
                break;
            case 'x':
                gameOver= true;
                break;
        }
    }

}
void logic(){
//    int tmx,tmy;
//    tmx=tailX[0],tmy=tailY[0];
//    for (int i = 1; i < tail; ++i) {
//        tailX[i]=tailX[i-1];
//        tailY[i]=tailY[i-1];
//    }
//    tailX[0]=x,tailY[0]=y;
    int prX=tailX[0],prY=tailY[0];
    int pr2x,pr2y;
    tailX[0]=x,tailY[0]=y;
    for (int i = 1; i < tail; ++i) {
        pr2x=tailX[i],pr2y=tailY[i];
        tailX[i]=prX;
        tailY[i]=prY;
        prX=pr2x,prY=pr2y;
    }
    switch (dir) {
        case UP:
            --y;
            break;
        case DOWN:
            ++y;
            break;
        case LEFT:
            --x;
            break;
        case RIGHT:
            ++x;
            break;
    }
    if(x==0||x==width-1||y==0||y==height-1){
        system("cls");
        cout<<y<<" "<<x<<'\n';
        cout<<"GAME OVER!\n";
        cout<<"Score: "<<score<<'\n';
        Sleep(10000);
        gameOver=true;
    }
    for (int i = 0; i < tail; ++i) {
        if (tailX[i]==x&&tailY[i]==y){
            system("cls");
            cout<<y<<" "<<x<<'\n';
            cout<<"GAME OVER!\n";
            cout<<"Score: "<<score<<'\n';
            Sleep(10000);
            gameOver=true;
            break;
        }
    }
    if(x==fruitX&&y==fruitY){
        score+=10;
        ++tail;
        srand(time(NULL));
        fruitX= rand()%width;
        srand(time(NULL));
        fruitY= rand()%height;
    }
}
int main() {
    setup();
    while (!gameOver){
        draw();
        input();
        logic();
        Sleep(110);
    }
    return 0;
}

