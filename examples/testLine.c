#include "../turtlec.h"
#include <math.h>

void splitLine(Turtle *, int, int);

void koch(Turtle *, int, int);

void snowflit(Turtle *, int, int, int);

void branch(Turtle *, int, int);

void fractalTree(Turtle *, int, int);

void levy(Turtle *, float, int);

void fractalTreeM(Turtle *, float, int);

void fractalTreeD(Turtle *, float, int);

void fractalTreeP(Turtle *, float, int);

void levyM(Turtle *, float, int);

int main(void){
  TurtleApp *app = turtleAppCreate(600, 600, "Test Line :3");
  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 300.0f, 300.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0); 
  turtleSetSpeed(t, 5.0f);
  //turtleLeft(t, 90.0);
    
  levyM(t, 100, 2);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void splitLine(Turtle *t, int length, int count){
    if (count == 0){
        turtleForward(t, length);
        return;
        }

    splitLine(t, length / 2.0, count - 1);
    turtleLeft(t, 60.0);
    
    splitLine(t, length / 2.0, count - 1);
    turtleRight(t, 60.0);
    }

void koch(Turtle *t, int length, int count){
    if (count == 0){
        turtleForward(t, length);
        return;
        }
    
    koch(t, length / 3.0, count - 1);
    
    turtleLeft(t, 60.0);
    koch(t, length / 3.0, count - 1);
    
    turtleRight(t, 120.0);
    koch(t, length / 3.0, count - 1);
    
    turtleLeft(t, 60.0);
    koch(t, length / 3.0, count - 1);
    }

void snowflit(Turtle *t, int length, int level, int count){
    
    for(int i = 0; i < count; i++){
        
        koch(t, length, level);
        
        turtleRight(t, 120.0);
        
        }
    }

void branch(Turtle *t, int length, int level){
    if (level == 0)
        return;
    
    turtleForward(t, length);
    
    turtleLeft(t, 30.0);
    branch(t, length * 0.7f, level - 1);
    
    turtleRight(t, 60.0);
    branch(t, length * 0.7f, level - 1);

    turtleLeft(t, 30.0);
    turtleBackward(t, length);

    }

void fractalTree(Turtle *t, int length, int depth){
    if (depth == 0  || length < 10)  //Diferentes profundiades
        return;
    
    turtleForward(t, length);

    turtleLeft(t, 30.0);    //20 - 30
    fractalTree(t, length * 0.8, depth - 1); //Resolucion 0.6 - 0.7 - 0.8

    turtleRight(t, 60.0);   //40 - 60
    fractalTree(t, length * 0.8, depth - 1);

    turtleLeft(t, 30.0);
    
    if (depth > 5)
        turtleSetColor(t, 128, 64, 0); //Marron

    else 
        turtleSetColor(t, 0, 200, 10); //Verde
    
    turtleBackward(t, length);

    }

void levy(Turtle *t, float length, int depth){
    
    if (depth == 0){
        turtleForward(t, length);
        return;
        }
    
    turtleLeft(t, 45.0);
    levy(t, length / sqrt(2), depth - 1);

    turtleRight(t, 90.0);
    levy(t, length / sqrt(2), depth - 1);

    turtleLeft(t, 45.0);
    }

void fractalTreeM(Turtle *t, float length, int depth){
    if (depth == 0){
        return;
        }
    
    turtleForward(t, length);
    
    turtleLeft(t, 30.0);
    fractalTreeM(t, length * 0.6, depth - 1);

    turtleRight(t, 30.0);
    fractalTreeM(t, length * 0.6, depth - 1);

    turtleRight(t, 30.0);
    fractalTreeM(t, length * 0.6, depth - 1);

    turtleLeft(t, 30.0);
    turtleBackward(t, length);

    }

void fractalTreeD(Turtle *t, float length, int depth){
    if (depth == 0)
        return;

   turtleForward(t, length);

   turtleLeft(t, 30.0);
   fractalTreeD(t, length * 0.8, depth - 1);

   turtleRight(t, 60.0);
   fractalTreeD(t, length * 0.5, depth - 1);
    
   turtleLeft(t, 30.0);

   turtleBackward(t, length);
    }    

void fractalTreeP(Turtle *t, float length, int depth){ 
    if (depth == 0)
        return;

    int red = (255 - depth * 40) < 0 ? 255 : (255 - depth * 40);
    int green = (200 - depth * 25) < 0 ? 0 : (20 - depth * 25);
    int blue = depth * 35 > 255 ? 255 : depth * 35;
    
    turtleForward(t, length);

    turtleLeft(t, 30.0);
    fractalTreeP(t, length * 0.7, depth -1);
    
    turtleRight(t, 60.0);
    fractalTreeP(t, length * 0.7, depth -1);

    turtleLeft(t, 30.0);
   
    turtleSetColor(t, red, green, blue);
    turtleBackward(t, length);
    
    }

void levyM(Turtle *t, float length, int depth){
    
    int red = (255 - depth * 40) < 0 ? 0 : (255 - depth * 40);
    int green = (200 - depth * 25) < 0 ? 0 : (200 - depth * 25);
    int blue = depth * 35 > 255 ? 255 : depth * 35;

    turtleSetColor(t, red, green, blue);

    //turtleSetColor(t, depth * 40, depth * 50, 255 - depth * 30);
    
    if (depth == 0){
        //turtleSetColor(t, red, green, blue);
        turtleForward(t, length);
        return;
        }
     

    turtleLeft(t, 45.0);
    //turtleSetColor(t, 120, 0, 60);
    levyM(t, length / sqrt(2), depth - 1);

    turtleRight(t, 90.0);
    //turtleSetColor(t, 34, 250, 140);
    levyM(t, length / sqrt(2), depth - 1);

    turtleLeft(t, 45.0);
    

    }
