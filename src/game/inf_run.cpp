#include "inf_run.h"
#include "point.h"
#include "rectangle.h"
#include <SDL_scancode.h>
#include <random>

// #define SCREEN_WIDTH  1024
// #define SCREEN_HEIGHT  728

//RANDOM INIT
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1024/2-25,1024/2);
    std::default_random_engine generator1;
    std::uniform_int_distribution<int> distribution1(-8,8);
    

//Initialize objekts BEGIN
 inf_run::inf_run(): Engine(1024, 768, "Infinite_runner") {

// black rectangle
    rect.reset(new Rectangle(Point(100, 100), 50, 50));
    rect->position = Point(1024/2-25, 768-100);
    rect->setColor(0, 0, 0);
    rect->velocity = Point(0, 0);

// initialize 3d illusion start    
    rect0.reset(new Rectangle(Point(1024/2-25, 768/2-25), 50, 50));
    rect0->position = Point(1024/2-25, 768/2-25);
    rect0->setColor(0, 0, 0);
    rect0->velocity = Point(-1, -1);

    rect1.reset(new Rectangle(Point(1024/2-25, 768/2-25), 50, 50));
    rect1->position = Point(1024/2-25, 768/2-25);
    rect1->setColor(0, 0, 0);
    rect1->velocity = Point(-1, -1);

    rect2.reset(new Rectangle(Point(1024/2-25, 768/2-25), 50, 50));
    rect2->position = Point(1024/2-25, 768/2-25);
    rect2->setColor(0, 0, 0);
    rect2->velocity = Point(-1, -1);

    line1.reset(new Line(Point(128, 0), Point(1024/2-25, 768/2-25)));
    line2.reset(new Line(Point(1024-128, 0), Point(1024/2-25+50, 768/2-25)));
    line3.reset(new Line(Point(128, 768), Point(1024/2-25, 768/2-25+50)));
    line4.reset(new Line(Point(1024-128, 768), Point(1024/2-25+50, 768/2-25+50)));
     // line1->setColor(0, 0, 0); with this command u might set color of lines
// finish 

//enemy, red rectangle
    rect3.reset(new Rectangle(Point(1024/2-25, 768/2-25), 10, 10));
    rect3->position = Point(1024/2-25, 768/2-25);
    rect3->setColor(255, 0, 0);
    rect3->velocity = Point(0, 4); 
   
//locate picture game over
    gameover_img.reset(new Image(renderer.get(), "pictures/game_over.bmp"));
    gameover_img->position = Point(128,0);

//locate pictures about distance
    good.reset(new Image(renderer.get(), "pictures/good.bmp"));
    good->position = Point(0,100);
    nice.reset(new Image(renderer.get(), "pictures/nice.bmp"));
    nice->position = Point(0,100);
    great.reset(new Image(renderer.get(), "pictures/great.bmp"));
    great->position = Point(0,100);
    perfect.reset(new Image(renderer.get(), "pictures/perfect.bmp"));
    perfect->position = Point(0,100);
    awensome.reset(new Image(renderer.get(), "pictures/awensome.bmp"));
    awensome->position = Point(0,100);
    ggwp.reset(new Image(renderer.get(), "pictures/ggwp.bmp"));
    ggwp->position = Point(0,0);

    }
            


//KEY INPUT BEGIN
bool inf_run::processEvent(SDL_Event& evt) {
    if (evt.type == SDL_KEYDOWN) {
        int key = evt.key.keysym.scancode;
        if (key == SDL_SCANCODE_D || key == SDL_SCANCODE_RIGHT) {
            /*
                Dafür bin ich besonders stolz, obwohl sieht das Code sich gar nicht so kompliziert aus, hat es eine große Auswirkung auf das Spielphysik. 
                Das imitiert eine Zielsuchlenkung, dadurch wird das Spiel nicht nur interessanter, sondern auch tricky! 
                Denn, wenn der Spieler aufmerksamm gespielt hat, kann er nach zahlreichen versuchen feststellen, dass die annähernde Objekte einfach abgestoßt sein könnten! 
                Nur so kann man die höchste Distanz erreichen und eine Gratulationsnachricht "GG WP" bekommen!
                Genial ist es, weil das ganze code nur in Paar Zeilen steht!  
            */ 
            rect->velocity = Point(5,0);
            rect3->velocity = Point(3,8);
        } else if (key == SDL_SCANCODE_A || key == SDL_SCANCODE_LEFT) {

            rect->velocity = Point(-5,0);
            rect3->velocity = Point(-3,8);
        } else if (key == SDL_SCANCODE_R){
            detected = false;
        }
    }

    return true;
}
//KEY INPUT END

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
//GAME LOGIK BEGIN
void inf_run::update() {
    rect->update();             //keep moving a black rectangle
    // 3D illusion action
    rect0->update();            
    rect0->grow();
    rect1->update();
    rect1->grow();
    // moving red one and acting, that he is growing
    rect3->update();
    rect3->grow(1, 1);
    area = rect3->calcArea();   //just need to be solved for later uses

    // stupid counter, better to use time library, but i solved it like this
    iclock++;
    if (iclock >= 1000){
        goodness = true;
    }
     
    dice_roll = distribution(generator);  // generates number in the range look at line 12
    dice_roll1 = distribution1(generator1); // generates number in the range look at line 14
    
    // create barriers 
    if (rect->position.x <= barrier_left){
        rect->velocity = Point(0,0);
        rect->position.x = barrier_left;
        rect3->velocity = Point(-8, 8); 
    }
    if (rect->position.x >= barrier_right){
        rect->velocity = Point(0,0);
        rect->position.x = barrier_right;
        rect3->velocity = Point(8, 8); 
    }

    // 3d ilusion settings
    if (rect0->position.y <= 0 || rect1->position.y <= 0){
        rect0.reset(new Rectangle(Point(1024/2-200, 768/2-200), 400, 400));
        rect0->velocity = Point(-1,-1);
        rect1.reset(new Rectangle(Point(1024/2-25, 768/2-25), 50, 50));
        rect1->velocity = Point(-1,-1);

    }

    // shuffle
    if (rect3->position.y >= 768){
        rect3->position.x = dice_roll;
        rect3->position.y = 768/2+200;
    }

    //set area limits
    if (area >= 50*50){
        rect3.reset(new Rectangle(Point(dice_roll, 768/2-25), 1, 1));
        rect3->setColor(255, 0, 0);
        rect3->velocity = Point(dice_roll1, 8);
    }

    //show game over, if kollision is detected
    if (rect3->position.x <= rect->position.x + 60 && rect3->position.y <= rect->position.y+50){
        if (rect->position.x-25  <= rect3->position.x && rect->position.y  <= rect3->position.y ){
            detected = true;
            //set player on back on start                    
            rect->position.x = 1024/2-25;
            rect->velocity.x = 0; 
            // SDL_Quit(); basicly not used, but if u want go crazy, go      
        }
    }   
}
//GAME LOGIK END


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DRAW GAME BEGIN
void inf_run::render() {
    // Fenster weiss ausmalen
    SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 0xFF);
    SDL_RenderClear(renderer.get());

    rect->draw(renderer.get());         //draw black rectangle
    rect3->draw(renderer.get());        //draw red rectangle
    rect2->draw_area(renderer.get());   //draw 3d ilusion, continue on lines 217 218, sequence of drawing is very important

    // draw lines
    line1->draw(renderer.get());
    line2->draw(renderer.get());
    line3->draw(renderer.get());
    line4->draw(renderer.get());
    
    // jede 1000m Distanz ausgeben
    if (goodness == true ){
        if (iclock >= 1000 && iclock < 2000){
            good->draw(renderer.get());
        }
        if (iclock >= 2000 && iclock < 3000){
            nice->draw(renderer.get());
        }
        if (iclock >= 3000 && iclock < 4000){
            great->draw(renderer.get());
        }
        if (iclock >= 4000 && iclock < 5000){
            perfect->draw(renderer.get());
        }
        if (iclock >= 5000 && iclock < 7000){
            awensome->draw(renderer.get());        
        }
        if (iclock >= 7000 && iclock < 1000000000){
            ggwp->draw(renderer.get()); 
            rect->position = Point(0,0);       
        }
    }

    rect0->draw_area(renderer.get());       //look at line 186
    rect1->draw_area(renderer.get());       //look at line 186

    // draw the game over 
    if (detected == true){
        gameover_img->draw(renderer.get());
        goodness = false;
        iclock = 0;     
    }

    SDL_RenderPresent(renderer.get());
}
//DRAW GAME END