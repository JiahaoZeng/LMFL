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
#ifdef _LMFL_BASIC_
void _LMFL_BASIC_GARBAGE_init(){
    _LMFL_BASIC_GARBAGE_dc = (HDC*)malloc(0);
    _LMFL_BASIC_GARBAGE_obj = (HGDIOBJ*)malloc(0);
    _LMFL_BASIC_GARBAGE_pointer = (void*)malloc(0);
}

void _LMFL_BASIC_GARBAGE_free(){
    for ( int i = 0; i < sizeof( _LMFL_BASIC_GARBAGE_dc)/sizeof( HDC); i++){
        DeleteDC( _LMFL_BASIC_GARBAGE_dc[i]);
        ReleaseDC( (HWND)0, _LMFL_BASIC_GARBAGE_dc[i]);
    }
    free( _LMFL_BASIC_GARBAGE_dc);

    for ( int i = 0; i < sizeof( _LMFL_BASIC_GARBAGE_obj)/sizeof( HGDIOBJ); i++){
        DeleteObject( _LMFL_BASIC_GARBAGE_obj[i]);
    }
    free( _LMFL_BASIC_GARBAGE_obj);

    for ( int i = 0; i < sizeof( _LMFL_BASIC_GARBAGE_pointer)/sizeof( void*) - 1; i++)
        free( _LMFL_BASIC_GARBAGE_pointer[i]);
    free( _LMFL_BASIC_GARBAGE_pointer);
}

void _LMFL_BASIC_GARBAGE_dc_join( HDC this){
    _LMFL_BASIC_GARBAGE_dc=
        ( HDC*)realloc( _LMFL_BASIC_GARBAGE_dc, sizeof( _LMFL_BASIC_GARBAGE_dc) + sizeof( HDC));
    _LMFL_BASIC_GARBAGE_dc[ sizeof( _LMFL_BASIC_GARBAGE_dc)/sizeof( HDC) - 1] = this;
}

void _LMFL_BASIC_GARBAGE_obj_join( HGDIOBJ this){
    _LMFL_BASIC_GARBAGE_obj=
        ( HGDIOBJ*)realloc( _LMFL_BASIC_GARBAGE_obj, sizeof( _LMFL_BASIC_GARBAGE_obj) + sizeof( HGDIOBJ));
    _LMFL_BASIC_GARBAGE_obj[ sizeof( _LMFL_BASIC_GARBAGE_obj)/sizeof( HGDIOBJ) - 1] = this;
}

void _LMFL_BASIC_GARBAGE_pointer_join( void* this){
    _LMFL_BASIC_GARBAGE_pointer=
        ( void**)realloc( _LMFL_BASIC_GARBAGE_pointer, sizeof( _LMFL_BASIC_GARBAGE_pointer) + sizeof( void*));
    _LMFL_BASIC_GARBAGE_pointer[ sizeof( _LMFL_BASIC_GARBAGE_pointer)/sizeof( void*) - 1] = this;
}

void _LMFL_BASIC_wait( unsigned time){
    Sleep( time);
}

void _LMFL_BASIC_loop(){
    while (GetMessage( &_LMFL_BASIC_msg, NULL, 0, 0) ){
        TranslateMessage( &_LMFL_BASIC_msg);
        DispatchMessage( &_LMFL_BASIC_msg);
    }
    _LMFL_BASIC_exit();
}

void _LMFL_BASIC_exit(){
    _LMFL_BASIC_GARBAGE_free();
    PostQuitMessage(0);
}

void _LMFL_BASIC_console_open(){
    AllocConsole();
    freopen_s(&_LMFL_BASIC_console_stream, "CON", "r", stdin);
    freopen_s(&_LMFL_BASIC_console_stream, "CON", "w", stdout);
}

void _LMFL_BASIC_console_close(){
    FreeConsole();
}

void _LMFL_BASIC_console_set_title( char* title){
    SetConsoleTitle( TEXT((title)));
}

bool _LMFL_BASIC_whether_function_success( bool Bool){
    return Bool;
}

lmfl_rgb _LMFL_BASIC_rgb_create0( unsigned r, unsigned g, unsigned b){
    lmfl_rgb this;
    this.r = r;
    this.g = g;
    this.b = b;
    return this;
}

unsigned _LMFL_BASIC_rgb_get_gray( lmfl_rgb this){
    return ((this.r*28+this.g*151+this.b*77)>>8);
}

lmfl_rgba _LMFL_BASIC_rgba_create0( unsigned r, unsigned g, unsigned b, unsigned a){
    lmfl_rgba this;
    this.r = r;
    this.g = g;
    this.b = b;
    this.a = a;
    return this;
}

lmfl_timer _LMFL_BASIC_timer_create0(){
    lmfl_timer this;
    this.whether_working = false;
    return this;
}

bool _LMFL_BASIC_timer_init( lmfl_timer* this){
    _LMFL_BASIC_OBSTRACT( this);

    this->whether_working = false;
    return true;
}

bool _LMFL_BASIC_timer_start( lmfl_timer* this){
    _LMFL_BASIC_OBSTRACT( this);

    if (this->whether_working == true){
        return false;
    }
    this->start = GetTickCount();
    this->whether_working = true;
    return true;
}

bool _LMFL_BASIC_timer_stop( lmfl_timer* this){
    _LMFL_BASIC_OBSTRACT( this);

    if (this->whether_working == false){
        return false;
    }
    this->stop = GetTickCount();
    this->time = this->stop - this->start;
    this->whether_working = false;
    return true;
}

long _LMFL_BASIC_timer_get_time( lmfl_timer* this){
    _LMFL_BASIC_OBSTRACT( this);

    if (this->whether_working == true){
        return GetTickCount() - this->start;
    }else{
        return this->time;
    }
}
#endif /*_LMFL_BASIC_*/