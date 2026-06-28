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
class Paddle{
    public:
    float x,y;
    float width,height;
    int speed;

    void Draw(){
        DrawRectangle(x,y, width, height, WHITE);

    }
    void Update(){
        if(y<=0){
            y=0;
        }
        if(y>=GetScreenHeight()-height){
            y= GetScreenHeight()-height;
        }
        if(IsKeyDown(KEY_UP)){
            y -= speed;

        }
        if(IsKeyDown(KEY_DOWN)){
            y+=speed;
        }
    }

};
Ball ball;
Paddle player;

int main(){
    cout<<"Starting the game"<< endl;
    const float screen_width=1280;
    const float screen_height= 800;
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

    player.x=padding;
    player.y=(screen_height-bat_size)/2;
    player.width=bat_width;
    player.height=bat_size;
    player.speed=6;

    while(WindowShouldClose()==false){
        BeginDrawing();
        // update
        ball.Update();
        player.Update();

        //drawing
        ClearBackground(BLACK);

        ball.Draw();
        

        // DrawRectangle(padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        player.Draw();
        DrawRectangle(screen_width-bat_width-padding,(screen_height-bat_size)/2,bat_width, bat_size, WHITE);
        DrawLine(screen_width/2,0, screen_width/2,screen_height,WHITE);
       



        EndDrawing();

    }


    CloseWindow();

    


    return 0;
}