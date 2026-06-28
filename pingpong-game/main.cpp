#include<iostream> 
#include<raylib.h>

using namespace std;

int main(){
    cout<<"Starting the game"<< endl;
    const int screen_width=1280;
    const int screen_height= 800;
    const int bat_size= 120;
    const int padding = 10;
    const int bat_width= 25;
    InitWindow(screen_width, screen_height, "My Pong Game");
    SetTargetFPS(60);
    while(WindowShouldClose()==false){
        BeginDrawing();

        DrawRectangle(padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        DrawRectangle(screen_width-bat_width-padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        DrawLine(screen_width/2,0, screen_width/2,screen_height,WHITE);
        DrawCircle(screen_width/2, screen_height/2, 20, WHITE);



        EndDrawing();

    }


    CloseWindow();

    


    return 0;
}