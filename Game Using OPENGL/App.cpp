#include "App.h"
#include <vector>
#include "math.h"
#include "Rect.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

    //Creates the grid rectangles
    Rect* r1 = new Rect(-.8, .8, .5, .5,8);
    Rect* r2 = new Rect(-.25, .8, .5, .5,1);
    Rect* r3 = new Rect(.3, .8, .5, .5,6);
    Rect* r4 = new Rect(-.8, .25, .5, .5,3);
    Rect* r5 = new Rect(-.25, .25, .5, .5,5);
    Rect* r6 = new Rect(.3, .25, .5, .5,7);
    Rect* r7 = new Rect(-.8, -.3, .5, .5,4);
    Rect* r8 = new Rect(-.25, -.3, .5, .5,9);
    Rect* r9 = new Rect(.3, -.3, .5, .5,2);

    rectangles.push_back(r1);
    rectangles.push_back(r2);
    rectangles.push_back(r3);
    rectangles.push_back(r4);
    rectangles.push_back(r5);
    rectangles.push_back(r6);
    rectangles.push_back(r7);
    rectangles.push_back(r8);
    rectangles.push_back(r9);
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    


    //Draws the X and O
    for(int i = 0; i < rectangles.size(); i++){

     if(rectangles[i]->selected == 1){
        	//Draw X
         glColor3d(0.0, 0.0, 1.0);
         glLineWidth(10);
         glBegin(GL_LINES);
         glVertex2f(rectangles[i]->x, rectangles[i]->y);
         glVertex2f(rectangles[i]->x + rectangles[i]->width, rectangles[i]->y - rectangles[i]->height);

         glVertex2f(rectangles[i]->x + rectangles[i]->width, rectangles[i]->y);
         glVertex2f(rectangles[i]->x, rectangles[i]->y - rectangles[i]->height);
         glEnd();

     }
     else if(rectangles[i]->selected ==2){
        	//Draw O
         glColor3d(1.0, 0.0, 0.0);
         glLineWidth(10);

         for(int j = 0; j < 20; j++){
          glBegin(GL_LINES);
          double x = (.2 * cos((2* M_PI *j)/20));
          double y = .2 * sin((2* M_PI *j)/20);
          glVertex2f(x+rectangles[i]->midx, y + rectangles[i]->midy);
      }
      glEnd();

  }

        //Draws the grid under the X and Os
  glColor3d(rectangles[i]->r, rectangles[i]->g, rectangles[i]->b);

  glBegin(GL_POLYGON);

  glVertex2f(rectangles[i]->x, rectangles[i]->y);
  glVertex2f(rectangles[i]->x + rectangles[i]->width, rectangles[i]->y);
  glVertex2f(rectangles[i]->x + rectangles[i]->width, rectangles[i]->y- rectangles[i]->height);
  glVertex2f(rectangles[i]->x, rectangles[i]->y - rectangles[i]->height);

  glEnd();


}

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
glFlush();
glutSwapBuffers();
}

void App::checkWin(){

    //Check for the row wins
    for(int i = 0; i < 9; i = i+3){
        if((rectangles[i]->weight + rectangles[i+1]->weight + rectangles[i+2]->weight) == 15 && rectangles[i]->selected == rectangles[i+1]->selected && rectangles[i+1]->selected == rectangles[i+2]->selected){
           char winner;
           if(rectangles[i]->selected == 1){
            winner = 'X';
        }else if(rectangles[i]->selected == 2){
            winner = 'O';
        }
        std::cout<< "The winner is "<< winner << std::endl;
        turn = -1;
    }   
}

    //Check for the Vertical wins
    for(int i = 0; i < 3; i++){
    if((rectangles[i]->weight + rectangles[i+3]->weight + rectangles[i+6]->weight) == 15 && rectangles[i]->selected == rectangles[i+3]->selected && rectangles[i+3]->selected == rectangles[i+6]->selected){
        char winner;
        if(rectangles[i]->selected == 1){
            winner = 'X';
        }else if(rectangles[i]->selected == 2){
            winner = 'O';
        }
        std::cout<< "The winner is "<< winner << std::endl;
        turn = -1;
    }
    
    //Diagonal from top left
    if(rectangles[0]->weight + rectangles[4]->weight + rectangles[8]->weight == 15 && rectangles[0]->selected == rectangles[4]->selected && rectangles[4]->selected == rectangles[8]->selected){
        char winner;
        if(rectangles[0]->selected == 1){
            winner = 'X';
        }else if(rectangles[0]->selected == 2){
            winner = 'O';
        }
        std::cout<< "The winner is "<< winner << std::endl;
        turn = -1;
    }
}
    //Diagonal from top right
if(rectangles[2]->weight + rectangles[4]->weight + rectangles[6]->weight == 15 && rectangles[2]->selected == rectangles[4]->selected && rectangles[4]->selected == rectangles[6]->selected){
    char winner;
    if(rectangles[2]->selected == 1){
        winner = 'X';
    }else if(rectangles[2]->selected == 2){
        winner = 'O';
    }
    std::cout<< "The winner is "<< winner << std::endl;
    turn = -1;
}
    //Checks for cat scratch
if(rectangles[0]->selected !=0 && rectangles[1]->selected !=0 && rectangles[2]->selected !=0 && rectangles[3]->selected !=0 && rectangles[4]->selected !=0 && rectangles[5]->selected !=0 && rectangles[6]->selected !=0 && rectangles[7]->selected !=0 && rectangles[8]->selected !=0){
    if(turn != -1){
        std::cout << "Cat Scratch" << std::endl;
        turn = -1;
    }
}
}


void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    //Button Presses
    if(turn != -1){
        for(int i = 0; i < rectangles.size(); i++){
         if(rectangles[i]->contains(mx, my)){

          if(rectangles[i]->selected != 0){
            break;
        }else{
            if ((turn%2) == 0 && numPlayer==2){
               rectangles[i]->selected = 2;
               rectangles[i]->setWeight();
               turn++;
               checkWin();
           }else{
               rectangles[i]->selected = 1;
               rectangles[i]->setWeight();
               turn++;
               checkWin();
               if(numPlayer == 1 && (turn%2) == 0){
                AIPlayer();
                turn++;
            }
        }

    }
}
checkWin();
}
}
    // Redraw the scene
redraw();
}

void App::AIPlayer(){
    if(turn != -1){
        for(int i = 0; i < 8; i++){
            if(rectangles[i]->selected == 0){
                rectangles[i]->selected = 2;
                rectangles[i]->setWeight();
                break;
            }
        }
    }   
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }

    //Sets the gamemode
    if(key == 49 ){
        numPlayer = 1;
    }
    if(key == 50){
        numPlayer = 2;
    }
}