/**
** Copyright 2023 JiahaoZeng
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
** http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**/

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