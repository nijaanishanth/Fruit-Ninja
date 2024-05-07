#include "FEHLCD.h" 
#include "FEHUtility.h" 
#include <FEHImages.h> 
#define YMAX 239 
#define BUTTON1TEXT "Play" 
#define BUTTON2TEXT "Stats" 
#define BUTTON3TEXT "Instructions" 
#define BUTTON4TEXT "Credits" 
 
//class for the game to function 
class game 
{ 
    public: 
    void DISPLAYBACKGROUND(); 
    void DISPLAYGAME(); 
    void THROW(); 
    void LIVES(); 
    void banana(); 
    void apple(); 
    void pineapple(); 
    void watermelon(); 
    void orange(); 
    void bomb(); 
}; 
//class for the stats to function 
class stats 
{  
    public: 
    stats(); 
    void DISPLAYSTATS(); 
    int highscore,recentscore; 
}; 
 
//initialize the variables and functions needed to run menu  
int points,lives; 
float fruitspeed; 
void DISPLAYINSTRUCTIONS(); 
void DISPLAYCREDITS(); 
void DRAWMENU(); 
int main() 
{ 
    //make variables and create objects from classes 
    int x,y; 
    game fruitninja; 
    stats gameStats; 
    //while loop displaying the menu until button is clicked then redirecting to function for each button 
    while (true) 
    { 
        DRAWMENU(); 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y<(YMAX/4)) 
        { 
            fruitninja.DISPLAYGAME(); 
        } 
        else if (y<(YMAX/2)) 
        { 
             gameStats.DISPLAYSTATS(); 
        } 
        else if (y<(3*YMAX/4)) 
        { 
            DISPLAYINSTRUCTIONS(); 
        } 
        else  
        { 
            DISPLAYCREDITS(); 
        } 
    } 
} 
// function do display the game to the screen when the play button is clicked
void game::DISPLAYGAME() 
{ 
    //while loop showing a start button and back button  
    while (true) 
    { 
        int x,y; 
        LCD.Clear(BLACK); 
        LCD.SetFontColor(WHITE); 
        LCD.WriteAt("Play Game Here", 73,(YMAX/4)); 
        LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
        LCD.WriteAt("Back to Menu",108,(7*YMAX/8)); 
        LCD.Update(); 
 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y>(3*YMAX/4)) 
        { 
        break; 
        } 
        else if (y<(3*YMAX/4)) 
        { 
        //if the play button is clicked the game shows the background and begins throwing fruit and bombs 
            game fruitninja; 
            fruitninja.DISPLAYBACKGROUND(); 
            fruitninja.THROW(); 
        } 
    } 
} 
//function to show the background of the game
void game::DISPLAYBACKGROUND() 
{ 
    FEHImage background; 
    background.Open("fruitninjabackgroundFEH.pic");   
     while (true) 
    { 
        background.Draw(0,0); 
        LCD.Update(); 
        LCD.Write(points); 
        break; 
    } 
    background.Close(); 
} 
//function to throw the fruit and bombs to be used in the game
void game::THROW() 
{  
    //initialize the variables and files to be opened and used as images in the game 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage banana; 
    FEHImage apple; 
    FEHImage orange; 
    FEHImage pineapple; 
    FEHImage watermelon; 
    FEHImage bomb; 
    background.Open("fruitninjabackgroundFEH.pic"); 
    apple.Open("AppleFEH.pic"); 
    orange.Open("OrangeFEH.pic"); 
    banana.Open("BananaFEH.pic"); 
    pineapple.Open("PinappleFEH.pic"); 
    watermelon.Open("WatermelonFEH.pic"); 
    bomb.Open("BombFEH.pic"); 
    //make variables to be used to randomize the fruits and movements. 
    int a,b,c,fruittype; 
    points=0; 
    b=(rand()); 
    c=b%310; 
    game fruitninja; 
    lives=3; 
    fruitspeed=3; 
    //while loop to keep game going while the user has lives left using random number to decide which fruit to throw 
    while (lives!=0) 
    { 
        a=rand(); 
        fruittype=a%6; 
        if (fruittype==0) 
        { 
            fruitninja.banana(); 
        } 
        else if(fruittype==1) 
        { 
            fruitninja.apple(); 
        } 
        else if (fruittype==2) 
        { 
            fruitninja.orange(); 
        } 
        else if (fruittype==3) 
        { 
            fruitninja.pineapple(); 
        } 
        else if (fruittype==4) 
        { 
            fruitninja.watermelon(); 
        } 
        else if (fruittype==5) 
        { 
            fruitninja.bomb(); 
        } 
        fruitspeed+=0.125; 
    } 
    //close all the image files 
    background.Close(); 
    apple.Close(); 
    orange.Close(); 
    pineapple.Close(); 
    watermelon.Close(); 
    banana.Close(); 
    bomb.Close(); 
    //after game is over display end screen with final score and button back to start of the game 
    while (true) 
    { 
        int x,y; 
        LCD.Clear(BLACK); 
        LCD.SetFontColor(WHITE); 
        LCD.WriteAt("GAME OVER",117,(YMAX/8)); 
        LCD.WriteAt("Score:", 60,(YMAX/4)); 
        LCD.WriteAt(points,190,(YMAX/4)); 
        LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
        LCD.WriteAt("Back to Start",108,(7*YMAX/8)); 
        LCD.Update(); 
 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y>(3*YMAX/4)) 
        { 
            break; 
        } 
    } 
} 
 
//function to display the lives to the top right of the screen
void game::LIVES() 
{ 
    int lifecounter; 
    lifecounter=lives; 
    LCD.WriteAt("Lives:",235,0); 
    LCD.WriteAt(lives,305,0); 
} 
 
//function to throw banana
void game::banana() 
{ 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage banana; 
    background.Open("fruitninjabackgroundFEH.pic"); 
    banana.Open("BananaFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the fruit until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%320; 
        //randomly generating the start x value and direction of movement 
        if (c>160)  
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=220; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the banana moving while its on screen 
        while (y1<=220 && disappear == 0) 
        { 
            // draw the banana moving up while y value is higher than 50 
            banana.Draw(c,y1); 
            while(y1>=50 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                banana.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the banana was cut if it was add a point and make the banana disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
 
            } 
            //start moving the banana down until it goes off screen 
            while (y1<=220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                banana.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the banana was cut if it was add a point and make the banana disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //if the banana does offscreen without being cut lose a life 
            if(y1>221) 
            { 
                lives-=1; 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//function to throw apple
void game::apple() 
{ 
    float x,y; 
    float y1=219,x1; 
    FEHImage background; 
    FEHImage apple; 
    background.Open("fruitninjabackgroundFEH.pic"); 
    apple.Open("AppleFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the fruit until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%310; 
        //randomly generating the start x value and direction of movement 
        if (c>160) 
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=220; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the apple moving while its on screen 
        while (y1<=220 && disappear == 0) 
        { 
            // draw the apple moving up while y value is higher than 50 
            apple.Draw(c,y1); 
            while(y1>=50 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                apple.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the apple was cut if it was add a point and make the apple disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            // start moving the apple down until it goes off screen 
            while (y1<=220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                     c+=(fruitspeed/3); 
                } 
                apple.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the apple was cut if it was add a point and make the apple disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //if the apple does offscreen without being cut lose a life 
            if(y1>221) 
            { 
                lives-=1; 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//function to throw orange
void game::orange() 
{ 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage orange; 
    background.Open("fruitninjabackgroundFEH.pic");  
    orange.Open("OrangeFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the fruit until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%310; 
        //randomly generating the start x value and direction of movement 
        if (c>160) 
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=220; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the orange moving while its on screen 
        while (y1<=220 && disappear == 0) 
        { 
            // draw the orange moving up while y value is higher than 50 
            orange.Draw(c,y1); 
            while(y1>=50 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                orange.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the orange was cut if it was add a point and make the orange disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //start moving the orange down until it goes off screen 
            while (y1<=220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                orange.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the orange was cut if it was add a point and make the orange disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //if the orange does offscreen without being cut lose a life 
            if(y1>221) 
            { 
                lives-=1; 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//function to throw pineapple
void game::pineapple() 
{ 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage pineapple; 
    background.Open("fruitninjabackgroundFEH.pic");
    pineapple.Open("PinappleFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the fruit until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%310; 
        //randomly generating the start x value and direction of movement 
        if (c>160) 
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=220; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the pineapple moving while its on screen 
        while (y1<=220 && disappear == 0) 
        { 
            // draw the pineapple moving up while y value is higher than 50 
            pineapple.Draw(c,y1); 
            while(y1>=50 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                pineapple.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the pineapple was cut if it was add a point and make the pineapple disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //start moving the pineapple down until it goes off screen 
            while (y1<=220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                pineapple.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the pineapple was cut if it was add a point and make the pineapple disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //if the pineapple does offscreen without being cut lose a life 
            if(y1>221) 
            { 
                lives-=1; 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//function to throw watermelon
void game::watermelon() 
{ 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage watermelon; 
    background.Open("fruitninjabackgroundFEH.pic"); 
    watermelon.Open("WatermelonFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the fruit until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%310; 
        //randomly generating the start x value and direction of movement 
        if (c>160) 
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=220; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the watermelon moving while its on screen 
        while (y1<=220 && disappear == 0) 
        { 
            // draw the watermelon moving up while y value is higher than 50 
            watermelon.Draw(c,y1); 
            while(y1>=50 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                watermelon.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the watermelon was cut if it was add a point and make the watermelon disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //start moving the watermelon down until it goes off screen 
            while (y1<=220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=fruitspeed; 
                if (start==0) 
                { 
                    c-=(fruitspeed/3); 
                } 
                else if (start==1) 
                { 
                    c+=(fruitspeed/3); 
                } 
                watermelon.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the watermelon was cut if it was add a point and make the watermelon disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    points++; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=220; 
                    break; 
                } 
            } 
            //if the watermelon does offscreen without being cut lose a life 
            if(y1>221) 
            { 
                lives-=1; 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//function to throw bomb
void game::bomb() 
{ 
    int x,y,y1=219,x1; 
    FEHImage background; 
    FEHImage bomb; 
    background.Open("fruitninjabackgroundFEH.pic"); 
    bomb.Open("BombFEH.pic"); 
    int a,b,c,fruittype,start; 
    a=rand(); 
    fruittype=a%6; 
    game fruitninja; 
    //while loop to continue updating the bomb until it reaches the bottom of the screen 
    while(true) 
    {  
        b=(rand()); 
        c=b%310; 
        //randomly generating the start x value and direction of movement 
        if (c>160) 
        { 
            start=0; 
        } 
        else if (c<=160) 
        { 
            start=1; 
        } 
        //draw the background with lives and points counter 
        y1=219; 
        background.Draw(0,0); 
        LCD.SetFontColor(WHITE); 
        fruitninja.LIVES(); 
        LCD.WriteAt(points,0,0); 
        int disappear = 0; 
        //draw the bomb moving while its on screen 
        while (y1<220 && disappear == 0) 
        { 
            // draw the bomb moving up while y value is higher than 50 
            bomb.Draw(c,y1); 
            while(y1>70 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1-=10; 
                if (start==0) 
                { 
                    c-=6; 
                } 
                else if (start==1) 
                { 
                    c+=6; 
                } 
                bomb.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the bomb was cut if it was make lives 0 and make the bomb disappear 
                while (LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    lives=0; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            //start moving the bomb down until it goes off screen 
            while (y1<220 && disappear == 0) 
            { 
                background.Draw(0,0); 
                LCD.SetFontColor(WHITE); 
                fruitninja.LIVES(); 
                LCD.WriteAt(points,0,0); 
                LCD.Update(); 
                y1+=10; 
                if (start==0) 
                { 
                    c-=3; 
                } 
                else if (start==1) 
                { 
                    c+=3; 
                } 
                bomb.Draw(c,y1); 
                Sleep(50); 
                LCD.ClearBuffer(); 
                //check if the bomb was cut if it was make lives 0 and make the bomb disappear 
                while(LCD.Touch(&x,&y)) 
                {} 
                if (x>c&& x<(c+40) &&y>y1 &&y<(y1+40)) 
                { 
                    lives=0; 
                    background.Draw(0,0); 
                    LCD.SetFontColor(WHITE); 
                    fruitninja.LIVES(); 
                    LCD.WriteAt(points,0,0); 
                    LCD.Update(); 
                    disappear = 1; 
                    y1=221; 
                    break; 
                } 
            } 
            // update the lives on the screen 
            background.Draw(0,0); 
            LCD.SetFontColor(WHITE); 
            fruitninja.LIVES(); 
            LCD.WriteAt(points,0,0); 
            LCD.Update(); 
            break; 
        } 
        break; 
    } 
} 
//constructor to make scores start at 0 in the stats button 
stats::stats() 
{ 
    highscore=0; 
    recentscore=0; 
} 
//function to display the stats to the screen
void stats::DISPLAYSTATS() 
{ 
    //update the recent score 
    recentscore=points; 
    //if the recent score is more than the highscore make it the highscore 
    if (points>highscore) 
    { 
        highscore=points; 
    } 
    //display the values to the screen 
    while (true) 
    { 
        int x,y; 
        LCD.Clear(BLACK); 
        LCD.SetFontColor(WHITE); 
        LCD.WriteAt("Stats",117,(YMAX/8)); 
        LCD.WriteAt("High Score:", 60,(YMAX/4)); 
        LCD.WriteAt(highscore,190,(YMAX/4)); 
        LCD.WriteAt("Recent Score:",50,((YMAX/4)+20)); 
        LCD.WriteAt(recentscore,205,((YMAX/4)+20)); 
        LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
        LCD.WriteAt("Back",138,(7*YMAX/8)); 
        LCD.Update(); 
        //add a button to go back to the menu 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y>(3*YMAX/4)) 
        { 
            break; 
        } 
    } 
 
} 
// function to draw the menu of the game
void DRAWMENU() 
{ 
    LCD.Clear(BLACK); 
    LCD.SetFontColor(WHITE); 
    LCD.DrawHorizontalLine((YMAX/4),0,320); 
    LCD.DrawHorizontalLine((YMAX/2),0,320); 
    LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
    LCD.WriteAt(BUTTON1TEXT,111,(YMAX/8)); 
    LCD.WriteAt(BUTTON2TEXT,111,(3*YMAX/8)); 
    LCD.WriteAt(BUTTON3TEXT,111,(5*YMAX/8)); 
    LCD.WriteAt(BUTTON4TEXT,111,(7*YMAX/8)); 
} 
// function to show the instructions of the game
void DISPLAYINSTRUCTIONS() 
{ 
    while (true) 
    { 
        int x,y; 
        LCD.Clear(BLACK); 
        LCD.SetFontColor(WHITE); 
        LCD.WriteLine(""); 
        LCD.Write("Swipe on the fruits to    gain points. Miss 3 fruitsand the game is over.     Don't swipe on bombs      because they end the game."); 
        LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
        LCD.WriteAt("Back",138,(7*YMAX/8)); 
        LCD.Update(); 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y>(3*YMAX/4)) 
        { 
            break; 
        } 
    } 
} 
//function to display the credits of the game to the screen
void DISPLAYCREDITS() 
{ 
    while (true) 
    { 
        int x,y; 
        LCD.Clear(BLACK); 
        LCD.SetFontColor(WHITE); 
        LCD.WriteAt("Credits",117,0); 
        LCD.WriteAt("Michael Grogan", 73,16); 
        LCD.WriteAt("Nijaa Nishanth",73,32); 
        LCD.WriteAt("wallpapers.mi9.com/wallpa-",0,48); 
        LCD.WriteAt("per/fruit-ninja_91747",0,64); 
        LCD.WriteAt("purepng.com/photo/6474",0,80); 
        LCD.WriteAt("pngimg.com/image/12407",0,96); 
        LCD.WriteAt("purepng.com/photo/6419",0,112); 
        LCD.WriteAt("purepng.com/photo/15804",0,128); 
        LCD.WriteAt("purepng.com/photo/7843",0,144); 
        LCD.WriteAt("pngimg.com/image/24060",0,160); 
        LCD.DrawHorizontalLine((3*YMAX/4),0,320); 
        LCD.WriteAt("Back",138,(7*YMAX/8)); 
        LCD.Update(); 
 
        while (!LCD.Touch(&x,&y)) 
        {} 
        while (LCD.Touch(&x,&y)) 
        {} 
        if (y>(3*YMAX/4)) 
        { 
            break; 
        } 
    } 
}
