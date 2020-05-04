#include <msp430.h>
#include "lcdutils.h"
#include"lcddraw.h"
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "state_1.h"

char stateAt = 0; //allows us to use it outside the method

void state_advance() {
  //here we begin our state machine
  switch (stateAt) {

    //these are the states and are deined below
  case 1:
    state1();
    led_update();
    break;

  case 2:    
    state2();
    led_update();
    break;
    
  case 3:
    state3();
    led_update();
    break;
    
  case 4:
    state4();
    led_update();
    break;
  }
  
}

void state1() {
  //here we add the functions for the new lcd addition to the program
  clearScreen(COLOR_BLUE);
  drawString8x12(30, 80, "Hola", COLOR_BLACK, COLOR_WHITE);
  drawString8x12(30, 110, "Como Estas ?", COLOR_BLACK, COLOR_WHITE);
  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
  
  buzzer_set_period(700);
  stateBegin();
  //static char next = 0;
  /*
  switch(next) { //this will then allows us to repeat within the same state performing different actions    
  case 0:
    green_on = 1;
    red_on = 1;
    next = 1;
    break;
    
  case 1:
    green_on = 0;
    next = 2;
    break;

  case 2:
    red_on = 0;
    next = 3;
    break;

  case 3:
    red_on = 1;
    next = 0; // repeat
    break;
  }
  */
}

void state2() {
  
  static char next2 = 0;
  buzzer_set_period(800);
  
  //setting things to draw within this state
  clearScreen(COLOR_BLUE);//clearing the screen 
  drawTriangle(20, COLOR_BLACK, 30);
  drawString5x7(20, 20, "Im Pretty Good", COLOR_RED, COLOR_WHITE);
 
  switch (next2){
  case 0:
    red_on = 0;
    green_on = 0;
    next2 = 1;
    break;

  case 1:
    red_on = 1;
    green_on = 1;
    next2 = 2;
    break;

  case 2:
    red_on = 0;
    green_on = 0;
    next2 = 0;
    break;
  }
}

void state3() {

  buzzer_set_period(500);
  static char next3 = 0;

  //including methods for the lcd
  clearScreen(COLOR_BLUE);
  drawCustom(30, 50, COLOR_RED);
  drawString8x12(40, 80, "Enter the Matrix", COLOR_GREEN, COLOR_BLACK);
  
  switch(next3) {

  case 0:
    green_on = 1;
    red_on = 0;
    next3 = 1;
    break;

  case 1:
    red_on = 1;
    next3 = 2;
    break;

  case 2:
    green_on = 0;
    next3 = 3;
    break;

  case 3:
    red_on = 0;
    green_on = 0;
    next3 = 0;
    break;
  }
}

void state4() {

  buzzer_set_period(400);
  static char next4 = 0;

  //last but not least, here we may try to make the shapes move
  clearScreen(COLOR_BLUE);
  fillRectangle(50, 20, 20, 50, COLOR_RED);
  drawString5x7(10, 10, "That is", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(20, 10, "All Folks", COLOR_BLACK, COLOR_WHITE);
  
  switch (next4) {
  case 0:
    red_on = 0;
    green_on = 0;
    next4 = 1;
    break;

  case 1:
    next4 = 2;
    break;

  case 2:
    next4 = 3;
    break;

  case 3:
    next4 = 4;
    break;

  case 4:
    green_on = 1;
    next4 = 0;
    break;
  }
}
