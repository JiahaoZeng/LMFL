/**
** LMFL_PLANE.c - The implementation of plane-operating.
** Copyright (c) 2023 JiahaoZeng.
**/

#include "LMFL.h"
#ifdef _LMFL_PLANE_
lmfl_plane _LMFL_PLANE_plane_create0( lmfl_plane* father, unsigned width, unsigned height){
    lmfl_plane this;
    this.width = width;
    this.height = height;
    this._PRIVATE_hdc = CreateCompatibleDC( father->_PRIVATE_hdc);
    this._PRIVATE_map = CreateCompatibleBitmap( father->_PRIVATE_hdc, width, height);
    SelectObject( this._PRIVATE_hdc, this._PRIVATE_map);
    this.whether_operating = false;
    this.whether_alive = true;
    return this;
}

lmfl_plane _LMFL_PLANE_plane_create1( lmfl_plane* father, char* path, unsigned width, unsigned height){
    lmfl_plane this;
    this.width = width;
    this.height = height;
    this.whether_operating = false;
    this.whether_alive = true;
    this._PRIVATE_hdc = CreateCompatibleDC( father->_PRIVATE_hdc);
    this._PRIVATE_map = (HBITMAP)
                                LoadImage(
                                    GetModuleHandle(0),
                                    TEXT((path)),
                                    IMAGE_BITMAP,
                                    width,
                                    height,
                                    LR_LOADFROMFILE
                                );
    SelectObject( this._PRIVATE_hdc, this._PRIVATE_map);
    return this;
}

bool _LMFL_PLANE_plane_delete( lmfl_plane* this){
    if (this == NULL){
        return false;
    }
    if (this->whether_alive == false){
        return false;
    }
    _LMFL_BASIC_OBSTRACT(this);
    this->whether_alive = false;
    DeleteObject( this->_PRIVATE_map);
    DeleteDC( this->_PRIVATE_hdc);
    return true;
}

bool _LMFL_PLANE_plane_set_pixel( lmfl_plane* this, lmfl_point point, lmfl_rgb color){
    if (this == NULL){
        return false;
    }
    _LMFL_BASIC_OBSTRACT(this);
    this->whether_operating = true;
    SetPixel( this->_PRIVATE_hdc, point.x, point.y, RGB( color.r, color.g, color.b));
    this->whether_operating = false;
    return true;
}

lmfl_rgb _LMFL_PLANE_plane_get_pixel( lmfl_plane* this, lmfl_point point){
    COLORREF color = GetPixel( this->_PRIVATE_hdc, point.x, point.y);
    lmfl_rgb result;
    result.r = GetRValue(color);
    result.g = GetGValue(color);
    result.b = GetBValue(color);
    return result;
}

bool _LMFL_PLANE_plane_pasteTo_whole_cover( lmfl_plane* this, lmfl_plane* plane, lmfl_point plane_corner){
    if ((this == NULL)||(plane == NULL)){
        return false;
    }
    if (!(this->whether_alive)&&(plane->whether_alive)){
        return false;
    }

    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    StretchBlt(
        plane->_PRIVATE_hdc,
        plane_corner.x,
        plane->height - (plane_corner.y+this->height),
        this->width,
        this->height,
        this->_PRIVATE_hdc,
        0,
        0,
        this->width,
        this->height,
        SRCCOPY
    );

    plane->whether_operating = false;

    return true;
}

bool _LMFL_PLANE_plane_pasteTo_rectangle_cover( lmfl_plane* this, lmfl_plane* plane, lmfl_rectangle plane_rectangle){
    if ((this == NULL)||(plane == NULL)){
        return false;
    }
    if (!(this->whether_alive)&&(plane->whether_alive)){
        return false;
    }

    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    StretchBlt(
        plane->_PRIVATE_hdc,
        plane_rectangle.corner.x,
        plane->height - (plane_rectangle.corner.y+plane_rectangle.height),
        plane_rectangle.width,
        plane_rectangle.height,
        this->_PRIVATE_hdc,
        0,
        0,
        this->width,
        this->height,
        SRCCOPY
    );

    plane->whether_operating = false;

    return true;
}

bool _LMFL_PLANE_plane_pasteTo_parallelogram_cover( lmfl_plane* this, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram){
    if ((this == NULL)||(plane == NULL)){
        return false;
    }
    if (!(this->whether_alive)&&(plane->whether_alive)){
        return false;
    }

    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    while ( this->whether_operating||plane->whether_operating);
    this->whether_operating = true;
    plane->whether_operating = true;

    POINT points[3];
    points[0].x = plane_parallelogram.point0.x;
    points[1].x = plane_parallelogram.point1.x;
    points[2].x = plane_parallelogram.point2.x;
    points[0].y = plane->height - plane_parallelogram.point0.y;
    points[1].y = plane->height - plane_parallelogram.point1.y;
    points[2].y = plane->height - plane_parallelogram.point2.y;

    PlgBlt(
        plane->_PRIVATE_hdc,
        points,
        this->_PRIVATE_hdc,
		0,
		0,
		this->width,
        this->height,
        NULL,
        0,
        0
    );
    
    plane->whether_operating = false;

    return true;
}

bool _LMFL_PLANE_plane_pasteTo_whole_merge( lmfl_plane* this, lmfl_plane* plane, lmfl_point plane_corner){
    if ((this == NULL)||(plane == NULL)){
        return false;
    }
    if (!(this->whether_alive)&&(plane->whether_alive)){
        return false;
    }

    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    StretchBlt(
        plane->_PRIVATE_hdc,
        plane_corner.x,
        plane->height - (plane_corner.y+this->height),
        this->width,
        this->height,
        this->_PRIVATE_hdc,
        0,
        0,
        this->width,
        this->height,
        SRCPAINT
    );

    plane->whether_operating = false;

    return true;
}

bool _LMFL_PLANE_plane_pasteTo_rectangle_merge( lmfl_plane* this, lmfl_plane* plane, lmfl_rectangle plane_rectangle){
    if ((this == NULL)||(plane == NULL)){
        return false;
    }
    if (!(this->whether_alive)&&(plane->whether_alive)){
        return false;
    }

    _LMFL_BASIC_OBSTRACT(plane);
    plane->whether_operating = true;

    StretchBlt(
        plane->_PRIVATE_hdc,
        plane_rectangle.corner.x,
        plane->height - (plane_rectangle.corner.y+plane_rectangle.height),
        plane_rectangle.width,
        plane_rectangle.height,
        this->_PRIVATE_hdc,
        0,
        0,
        this->width,
        this->height,
        SRCPAINT
    );

    plane->whether_operating = false;

    return true;
}

bool _LMFL_PLANE_plane_pasteTo_parallelogram_merge( lmfl_plane* this, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram){
    return true;
}

bool _LMFL_PLANE_plane_pasteTo_whole_cutOut( lmfl_plane* this, lmfl_plane* plane, lmfl_point plane_corner, lmfl_rgb color){
    return true;
}

bool _LMFL_PLANE_plane_pasteTo_rectangle_cutOut( lmfl_plane* this, lmfl_plane* plane, lmfl_rectangle plane_rectangle, lmfl_rgb color){
    return true;
}

bool _LMFL_PLANE_plane_pasteTo_parallelogram_cutOut( lmfl_plane* this, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram, lmfl_rgb color){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_whole_cover( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_rectangle_cover( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_parallelogram_cover( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_whole_merge( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_rectangle_merge( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_parallelogram_merge( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_whole_cutOut( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner, lmfl_rgb color ){
    return true;
}
bool _LMFL_PLANE_plane_cutTo_rectangle_cutOut( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle, lmfl_rgb color){
    return true;
}

bool _LMFL_PLANE_plane_cutTo_parallelogram_cutOut( lmfl_plane* this, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram, lmfl_rgb color){
    return true;
}

#endif /*_LMFL_PLANE_*/