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
#ifdef _LMFL_MATH_
lmfl_point _LMFL_MATH_point_create0( int x, int y){
    lmfl_point this;
    this.x = x;
    this.y = y;
    return this;
}

lmfl_rectangle _LMFL_MATH_rectangle_create0( unsigned width, unsigned height, lmfl_point corner){
    lmfl_rectangle this;
    this.width = width;
    this.height = height;
    this.corner = corner;
    return this;
}

lmfl_vector _LMFL_MATH_vector_create0( int i, int j){
    lmfl_vector this;
    this.i = i;
    this.j = j;
    return this;
}

lmfl_vector _LMFL_MATH_vector_create1( double mudulus, double angle){
    lmfl_vector this;
    angle = (angle/180)*M_PI;
    this.i = mudulus*cos(angle);
    this.j = mudulus*sin(angle);
    return this;
}

lmfl_vector _LMFL_MATH_vector_create2( lmfl_point start, lmfl_point end){
    lmfl_vector this;
    this.i = end.x-start.x;
    this.j = end.y-start.y;
    return this;
}

lmfl_parallelogram _LMFL_MATH_parallegram_create0( lmfl_point point0, lmfl_point point1, lmfl_point point2){
    lmfl_parallelogram this;
    this.point0 = point0;
    this.point1 = point1;
    this.point2 = point2;
    return this;
}

lmfl_point _LMFL_MATH_point_move( lmfl_point this, lmfl_vector vector){
    lmfl_point result;
    result.x = this.x+vector.i;
    result.y = this.y+vector.j;
    return result;
}

lmfl_rectangle _LMFL_MATH_rectangle_move( lmfl_rectangle this, lmfl_vector vector){
    lmfl_rectangle result;
    result.width = this.width;
    result.height = this.height;
    result.corner = _LMFL_MATH_point_move( result.corner, vector);
    return result;
}

lmfl_parallelogram _LMFL_MATH_parallegram_move( lmfl_parallelogram this, lmfl_vector vector){
    lmfl_parallelogram result;
    result.point0 = _LMFL_MATH_point_move( this.point0, vector);
    result.point1 = _LMFL_MATH_point_move( this.point1, vector);
    result.point2 = _LMFL_MATH_point_move( this.point2, vector);
    return result;
}

bool _LMFL_MATH_whether_rectangle_contain_point( lmfl_rectangle this, lmfl_point point){
    int x_min = this.corner.x;
    int y_min = this.corner.y;
    int x_max = x_min+this.width;
    int y_max = y_min+this.height;
    return ((point.x >= x_min)&&(point.x <= x_max)&&(point.y >= y_min)&&(point.y <= y_max));
}

bool _LMFL_MATH_whether_rectangle_contain_rectangle( lmfl_rectangle this, lmfl_rectangle rectangle){
    int x_min0 = this.corner.x;
    int y_min0 = this.corner.y;
    int x_max0 = x_min0+this.width;
    int y_max0 = y_min0+this.height;

    int x_min1 = rectangle.corner.x;
    int y_min1 = rectangle.corner.y;
    int x_max1 = x_min1+rectangle.width;
    int y_max1 = y_min1+rectangle.height;

    return ((x_min1 >= x_min0)&&(x_max1 <= x_max0)&&(y_min1 >= y_min0)&&(y_max1 <= y_max0));
}

bool _LMFL_MATH_whether_intersect_rectangle( lmfl_rectangle this, lmfl_rectangle rectangle){
    int x_min0 = this.corner.x;
    int y_min0 = this.corner.y;
    int x_max0 = x_min0+this.width;
    int y_max0 = y_min0+this.height;

    int x_min1 = rectangle.corner.x;
    int y_min1 = rectangle.corner.y;
    int x_max1 = x_min1+rectangle.width;
    int y_max1 = y_min1+rectangle.height;

    int judge = 0;
    if ((x_min1 >= x_min0)&&(y_min1 >= y_min0)){
        judge++;
    }
    if ((x_max1 <= x_max0)&&(y_max1 <= y_max0)){
        judge++;
    }

    if (judge == 1){
        return true;
    }
    return false;
}

double _LMFL_MATH_get_vector_mudulus( lmfl_vector this){
    return sqrt( this.i*this.i + this.j*this.j);
}

double _LMFL_MATH_get_vector_angle( lmfl_vector this){
    return acos(this.i/_LMFL_MATH_get_vector_mudulus(this))*180/M_PI;
}

lmfl_vector _LMFL_MATH_get_vector_negtive( lmfl_vector this){
    lmfl_vector result;
    result.i = 0-this.i;
    result.j = 0-this.j;
    return result;
}

lmfl_vector _LMFL_MATH_calculate_vector_sub( lmfl_vector minu, lmfl_vector subh){
    lmfl_vector result;
    result.i = minu.i - subh.i;
    result.j = minu.j - subh.j;
    return result;
}

lmfl_vector _LMFL_MATH_calculate_vector_add( lmfl_vector vector0, lmfl_vector vector1){
    lmfl_vector result;
    result.i = vector0.i + vector1.i;
    result.j = vector0.j + vector1.j;
    return result;
}

lmfl_point _LMFL_MATH_point_wound( lmfl_point this, lmfl_point centre, double angle){
    lmfl_point result;
    lmfl_vector vector0 = _LMFL_MATH_vector_create2( centre, this);
    angle += _LMFL_MATH_get_vector_angle( vector0);
    lmfl_vector vector1 = _LMFL_MATH_vector_create1( _LMFL_MATH_get_vector_mudulus( vector0), angle);
    result.x = vector1.i + centre.x;
    result.y = vector1.j + centre.y;
    return result;
}

lmfl_parallelogram _LMFL_MATH_parallegram_wound( lmfl_parallelogram this, lmfl_point centre, double angle){
    lmfl_parallelogram result;
    result.point0 = _LMFL_MATH_point_wound( this.point0, centre, angle);
    result.point1 = _LMFL_MATH_point_wound( this.point1, centre, angle);
    result.point2 = _LMFL_MATH_point_wound( this.point2, centre, angle);
    return result;
}
#endif /*_LMFL_MATH_*/