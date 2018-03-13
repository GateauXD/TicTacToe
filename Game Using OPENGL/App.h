#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include <vector>
#include "Rect.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    int turn = 1;
    int numPlayer = 2;
    std::vector<Rect*> rectangles;

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void checkWin();
    void AIPlayer();
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);

};

#endif
