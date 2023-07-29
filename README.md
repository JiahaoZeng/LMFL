![image](https://github.com/JiahaoZeng/LMFL/raw/main/resource/readme_resource/LMFL.png)
# LMFL
**Version**: 1.1.1\
**LMFL** *(Lightweight Multi-Function Library)*\
**author**: [JiahaoZeng](https://github.com/JiahaoZeng)
## Requirements
**platform**:\
    Windows.\
**language**:\
    C\
**compilation environment**:\
    gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
## Example0
### code
```C
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
```
### compile
>    gcc Hello.c LMFL.dll -o Hello -mwindows
### run
>   Hello
### result
![image](https://github.com/JiahaoZeng/LMFL/raw/main/resource/readme_resource/Hello.png)