
#ifndef Rect_h
#define Rect_h

struct Rect{
    float x, y, midx, midy, width, height,r,g,b;
    int selected, weight, weightValue;

    Rect(){
        x = 0;
        y = 0;
        midx = 0;
        midy = 0;
        width = 0;
        height = 0;
        selected = 0;
        weight = 0;
    }

    Rect(float x, float y, float width, float height, int weight){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        midx = x +(width/2);
        midy = y-(width/2);
        selected = 0;
        r = 1;
        g = 1;
        b = 1;
        weightValue = weight;
    }

    void setWeight(){
        if(selected != 0){
            weight = weightValue;
        }
    }

    bool contains(float xx, float yy){
        if(xx >= x && xx <= (x+width) && yy <= y && yy >= (y-height)){
            return true;
        }

        return false;
    }

};

#endif