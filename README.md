![image](resource/readme_resource/LMFL.png)
# <font color = "orange">LMFL</font>
<font color = "grey">Use it to build app quikly!</font>\
<font color = "green">**Version**</font>: 1.0.0\
**LMFL** *(Lightweight Multi-Function Library)*\
**author**: [JiahaoZeng](https://github.com/JiahaoZeng)
## Requirements
**platform**:\
    Windows.\
**language**:\
    C\
**compilation environment**:\
    gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
## Example
```C
#include "LMFL1.h"

int main(){
    // init LMFL
    LMFL;

    // create window
    WINDOW my_window = ({
        const char* title = "MyWnd";
        unsigned width = 300;
        unsigned height = 300;
        lmfl.window.create4( title, width, height);
    });

    // create font
    FONT my_font = ({
        char* style = "Courier New";
        unsigned width = 20;
        unsigned height = 30;
        unsigned cweight = 5;
        RGB color = lmfl.rgb.create(0,0,0);
        lmfl.font.create( style, width, height, cweight, color);
    });

    // show text
    ({
        const char* text = "Hello, LMFL!";

        RECTANGLE region = ({
            POINT corner = lmfl.math.point.create( 0, 300-20);
            unsigned width = 20;
            unsigned height = 30;
            lmfl.math.rectangle.create( width, height, corner);
        });

        lmfl.text.on( text, my_font, region, &my_window.plane);
    });

    // update window
    lmfl.window.show( &my_window);

    // main loop
    lmfl.app.loop();
}
```
## Doc
Read [doc](intro/doc.md) to know more.