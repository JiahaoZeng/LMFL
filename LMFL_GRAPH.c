#include "LMFL.h"
#ifdef _LMFL_GRAPH_
lmfl_gparam _LMFL_GRAPH_gparam_create0( unsigned cweight, lmfl_rgb color, lmfl_rectangle rectangle){
    lmfl_gparam this;
    this.cweight = cweight;
    this.color = color;
    this.rectangle = rectangle;
    return this;
}

bool _LMFL_GRAPH_graph_on( lmfl_gfunc gfunc, lmfl_gparam gparam, lmfl_plane* plane){
    if ((plane!=NULL) && (plane->whether_alive == false)){
        return false;
    }
    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    COLORREF colorref = RGB( gparam.color.r, gparam.color.g, gparam.color.b);

    lmfl_point rec;
    lmfl_point end;
    rec.x = gparam.rectangle.corner.x;
    rec.y = plane->height-(gparam.rectangle.corner.y+gparam.rectangle.height);
    end.x = rec.x+gparam.rectangle.width;
    end.y = rec.y+gparam.rectangle.height;

    while ((rec.x<end.x)&&(rec.y<end.y)){
        if (gfunc(_LMFL_MATH_point_create0( rec.x, gparam.rectangle.height-rec.y))){
            SetPixel( plane->_PRIVATE_hdc, rec.x, rec.y, colorref);
        }
        rec.x++;
        rec.y++;
    }

    plane->whether_operating = false;

    return true;
}
#endif /*_LMFL_GRAPH_*/