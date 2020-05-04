#include <msp430.h>
#include "stateMachine.h"

void
__interrupt_vec(WDT_VECTOR) WDT() {

  static char blink_count = 0;

  //here we attempt to dim the lights
  if (stateAt == 4) {
    if (++blink_count == 1) {
      state_advance();
      blink_count = 0;
    }
  }

  //we go back to normal for the rest
  else{
    if (++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }
}
