#include "../turtlec.h"

void splitLine(Turtle *, int, int);

void koch(Turtle *, int, int);

void snowflit(Turtle *, int, int, int);

void branch(Turtle *, int, int);

void fractalTree(Turtle *, int, int);

int main(void){
  TurtleApp *app = turtleAppCreate(600, 600, "Test Line"); //parametros, titulo
    //TurtleApp es un struc
  if(app == NULL) //app->puntero
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t); //Levanta su plumon ->no deja rastro
  turtleGoTo(t, 300.0f, 600.0f); //Pega un salto -- hasta
  turtlePenDown(t); //Baja la pluma
    //Dejamos a la tortuga en una posicion incial

  turtleSetColor(t, 255, 100, 0); //color del plumon
  turtleSetSpeed(t, 5.0f); //Velocidad
  //turtleForward(t, 300.0f); //dibuje una linea

  //splitLine(t, 150, 1);
    
  //koch(t, 300, 4);

  //snowflit(t, 200, 2, 3);
  
  turtleLeft(t, 90.0);
  
  //branch(t, 200, 3);
  
  fractalTree(t, 100, 7);

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
