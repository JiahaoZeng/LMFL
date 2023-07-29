//Hello.c
#include "LMFL1.h"

int main(){                                  //enter function
    LMFL                                     //init LMFL
    lmfl.app.console.open();                 //create a console
    lmfl.app.console.set.title("LMFL test"); //set title
    lmfl.app.console.out("Hello LMFL!");     //print 
    lmfl.app.loop();                         //main loop
    return 0;
}