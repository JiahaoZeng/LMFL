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
    LMFL;

/**
** params:
** - title
** - width
** - height
*/
    WINDOW wnd = lmfl.window.create4( "MyWnd", 300, 300);

/**
** params:
** - style
** - width
** - height
** - cweight
** - color
*/
    FONT black_font = lmfl.font.create( "Courier New", 20, 30, 5, lmfl.rgb.create(0,0,0));

/**
** params:
** - corner
** - width
** - height
*/
    RECTANGLE text_region = lmfl.rectangle.create( lmfl.point.create( 0, 300-20), 20, 30);

/**
** params:
** - text
** - font
** - region
** - plane
*/
    lmfl.text.on( "Hello, LMFL!", black_font, text_region, &wnd.plane);

    lmfl.window.show( &wnd);

    lmfl.app.loop();
}
```
## Doc
Read [doc](intro/doc.md) to know more.