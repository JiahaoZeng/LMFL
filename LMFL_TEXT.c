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
#ifdef _LMFL_TEXT_
lmfl_font _LMFL_TEXT_font_create0( char* style, unsigned width, unsigned height, unsigned cweight, lmfl_rgb color){
    lmfl_font this;
    this.style = style;
    this.width = width;
    this.height = height;
    this.cweight = cweight;
    this.color = color;
    this._PRIVATE_hfont =CreateFontA(
                                        height,
                                        width,
                                        0,
                                        0,
                                        cweight,
                                        0,
                                        0,
                                        0,
                                        ANSI_CHARSET,
                                        OUT_DEVICE_PRECIS,
                                        CLIP_DEFAULT_PRECIS,
                                        CLEARTYPE_QUALITY,
                                        FF_SWISS,
                                        TEXT((style))
                        );
    this.whether_alive = true;
    return this;
}

bool _LMFL_TEXT_font_delete( lmfl_font* this){
    if (this->whether_alive == false){
        return false;
    }
    
    DeleteObject(this->_PRIVATE_hfont);
    this->whether_alive = false;

    return true;
}

bool _LMFL_TEXT_text_on( char* text, lmfl_font font, lmfl_rectangle rectangle, lmfl_plane* plane){
    if ((text!=NULL) && (plane!=NULL) && (plane->whether_alive)){
        return false;
    }
    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;
    {
        RECT rect;
        rect.left = rectangle.corner.x;
        rect.right = rectangle.corner.x+rectangle.width;
        rect.bottom = plane->height-rectangle.corner.y;
        rect.top = rect.bottom+rectangle.height;

        SetBkMode( plane->_PRIVATE_hdc, TRANSPARENT);
        SetTextColor( plane->_PRIVATE_hdc, RGB( font.color.r, font.color.g, font.color.b));
        SelectObject( plane->_PRIVATE_hdc, font._PRIVATE_hfont);

        DrawText( plane->_PRIVATE_hdc, TEXT((text)), -1, &rect, DT_LEFT|DT_TOP|DT_WORDBREAK);
    }
    plane->whether_operating = false;
    return true;
}

#endif /*_LMFL_TEXT_*/