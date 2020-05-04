#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"

char sw1_down, sw2_down, sw3_down, sw4_down, switch_state_changed, switchDown;

static char switch_update_interrupt_sense() {

  char p2val = P2IN; //take the input

  //update switch interrupt to detect the changes from buttons
  P2IES |= (p2val & SWITCHES); //if up, sense down
  P2IES &= (p2val | ~SWITCHES); //if down, sense up
  return p2val;
}

void switch_init() {
  P2REN |= SWITCHES; //enable resistors
  P2IE |= SWITCHES; //enable interrupts
  P2OUT |= SWITCHES; // pull ups for switches
  P2DIR &= ~SWITCHES; // set switches bits for input
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler() {

  char p2val = switch_update_interrupt_sense();

  //attain our button that is pressed
  sw1_down = (p2val & SW1) ? 0 : 1;
  sw2_down = (p2val & SW2) ? 0 : 1;
  sw3_down = (p2val & SW3) ? 0 : 1;
  sw4_down = (p2val & SW4) ? 0 : 1;
    //have to update with the state Machine to see what we'll do
  //we confirm the switch and then promote to the desired state

  if (sw1_down) {

    p2val = switch_update_interrupt_sense(); //update our val
    switchDown = (p2val & sw1_down) ? 0 : 1; // 0 when the switch is up
    
    stateAt = 1;
  }

  if (sw2_down) {
    p2val = switch_update_interrupt_sense();
    switchDown = (p2val & sw2_down) ? 0 : 1;
      
    stateAt = 2;
  }

  if (sw3_down) {
    p2val = switch_update_interrupt_sense();
    switchDown = (p2val & sw3_down) ? 0 : 1;
    
    stateAt = 3;
  }

  if (sw4_down) {
    p2val = switch_update_interrupt_sense();
    switchDown = (p2val & sw4_down) ? 0 : 1;
    
    stateAt = 4;
  }

  switch_state_changed = 1;
  led_update();
}


