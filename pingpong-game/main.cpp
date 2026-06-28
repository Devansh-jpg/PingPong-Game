#include<iostream> 
#include<raylib.h>

using namespace std;

class Ball {
    public:
    float x,y;
    int speed_x, speed_y;
    int radius;

    void Draw(){
         DrawCircle(x, y, radius, WHITE);

    }
    void Update(){
        x+=speed_x;
        y+= speed_y;
        // reflection
        if(y+ radius>= GetScreenHeight() || y-radius<=0){
            speed_y*=-1;

        }
        if(x+radius>=GetScreenWidth()||x-radius<=0){
            speed_x*=-1;

        }
    }


};
Ball ball;

int main(){
    cout<<"Starting the game"<< endl;
    const int screen_width=1280;
    const int screen_height= 800;
    const int bat_size= 120;
    const int padding = 10;
    const int bat_width= 25;
    InitWindow(screen_width, screen_height, "My Pong Game");
    SetTargetFPS(60);

    ball.radius=20;
    ball.x=screen_width/2;
    ball.y=screen_height/2;
    ball.speed_x=7;
    ball.speed_y=7;

    while(WindowShouldClose()==false){
        BeginDrawing();
        // update
        ball.Update();

        //drawing
        ClearBackground(BLACK);

        ball.Draw();
        

        DrawRectangle(padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        DrawRectangle(screen_width-bat_width-padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        DrawLine(screen_width/2,0, screen_width/2,screen_height,WHITE);
       



        EndDrawing();

    }


    CloseWindow();

    


    return 0;
}