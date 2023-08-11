/**
** LMFL.h - 1.0.0
** Copyright (c) 2023 JiahaoZeng.
**/

#ifndef _LMFL_
#   pragma once
#   define _LMFL_
#   define LMFL_VERSION "1.0.0"
#   define _LMFL_H
#   ifndef _LMFL_BASIC_
#       define _LMFL_BASIC_
#       include <stdbool.h>
#       include <stdlib.h>
#       include <stdio.h>
#       include <string.h>
#       include <windows.h>
#       include <vfw.h>
#       include <mmsystem.h>
#       define _USE_MATH_DEFINES
#       include <math.h>
//Obstruct.
//So that "this" can't be operate the same time in different threads.
#       define _LMFL_BASIC_OBSTRACT(this)  {\
            while( this->whether_operating);\
        }
#       define _LMFL_BASIC_PUTERROR(error)  {\
            printf("LMFL ERROR:%s(func:%s,file:%s,line:%i)\n",error,__func__,__FILE__,__LINE__);\
        }

typedef unsigned char lmfl_byte;
typedef lmfl_byte* lmfl_data;
//                             "resource" can't be a const but a var.
#       define LMFL_DATA_IMPORT(resource) ({\
            lmfl_data This;\
            This = (lmfl_byte*)memcpy(alloca(sizeof(resource)),&resource,sizeof(resource));\
            This;\
        })
//                             "resource" can't be a const but a var.
#       define LMFL_DATA_EXPORT(This,resource) ({\
            memcpy(&resource,This,sizeof(resource));\
            resource;\
        })
HDC* _LMFL_BASIC_GARBAGE_dc;
HGDIOBJ* _LMFL_BASIC_GARBAGE_obj;
void** _LMFL_BASIC_GARBAGE_pointer;
void _LMFL_BASIC_GARBAGE_dc_join( HDC);
void _LMFL_BASIC_GARBAGE_obj_join( HGDIOBJ);
void _LMFL_BASIC_GARBAGE_pointer_join( void*);
void _LMFL_BASIC_GARBAGE_free();
void _LMFL_BASIC_GARBAGE_init();

FILE* _LMFL_BASIC_console_stream;
void _LMFL_BASIC_console_open();
void _LMFL_BASIC_console_close();
void _LMFL_BASIC_console_set_title( char* title);

MSG _LMFL_BASIC_msg;
typedef void(*lmfl_afunc)(void*);
typedef LPVOID lmfl_void;

void _LMFL_BASIC_wait( unsigned time);
void _LMFL_BASIC_loop();
void _LMFL_BASIC_exit();
bool _LMFL_BASIC_whether_function_success( bool Bool);

typedef struct{
    unsigned r;
    unsigned g;
    unsigned b;
}
lmfl_rgb;
typedef struct{
    unsigned r;
    unsigned g;
    unsigned b;
    unsigned a;
}
lmfl_rgba;
lmfl_rgb _LMFL_BASIC_rgb_create0( unsigned r, unsigned g, unsigned b);
lmfl_rgba _LMFL_BASIC_rgba_create0( unsigned r, unsigned g, unsigned b, unsigned a);

unsigned _LMFL_BASIC_rgb_get_gray( lmfl_rgb);

typedef struct{
    long start;
    long stop;
    long time;
    bool whether_working;
    bool whether_operating;
}
lmfl_timer;
lmfl_timer _LMFL_BASIC_timer_create0();
bool _LMFL_BASIC_timer_init( lmfl_timer*);
bool _LMFL_BASIC_timer_start( lmfl_timer*);
bool _LMFL_BASIC_timer_stop( lmfl_timer*);
long _LMFL_BASIC_timer_get_time( lmfl_timer*);
#   endif /*_LMFL_BASIC_*/

#   ifndef _LMFL_ALGO_
#       define _LMFL_ALGO_
typedef struct{
    int deep;
    int _PRIVATE_top;
    bool _PRIVATE_whether_empty;
    void* _PRIVATE_memory;
    unsigned type_size;
    bool whether_alive;
}
lmfl_stack;
lmfl_stack _LMFL_ALGO_stack_create0( int deep, unsigned type_size);
bool _LMFL_ALGO_stack_delete( lmfl_stack*);
bool _LMFL_ALGO_stack_push( lmfl_stack*, lmfl_data);
bool _LMFL_ALGO_stack_pop( lmfl_stack*);
lmfl_data _LMFL_ALGO_stack_get_top( lmfl_stack*);
bool _LMFL_ALGO_stack_whether_empty( lmfl_stack*);

typedef struct _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE_tag{
    lmfl_data value;
    bool whether_alive;
    struct _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE_tag* last;
    struct _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE_tag* next;
}
_LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE;
typedef struct{
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* front;
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* _PRIVATE_tail;
    int length;
    bool whether_alive;
}
lmfl_queue;
lmfl_queue _LMFL_ALGO_queue_create0();
bool _LMFL_ALGO_queue_delete( lmfl_queue*);
bool _LMFL_ALGO_queue_push( lmfl_queue*, lmfl_data value);
bool _LMFL_ALGO_queue_pop( lmfl_queue*);
lmfl_data _LMFL_ALGO_queue_get_front( lmfl_queue*);
bool _LMFL_ALGO_queue_whether_empty( lmfl_queue*);

typedef bool(*lmfl_cfunc)(lmfl_data,lmfl_data);

bool _LMFL_ALGO_sort( void* array, unsigned type_size, lmfl_cfunc cmp, unsigned length);

// High precision value
typedef struct{
    unsigned MSD; // Most Significant Digit
    char* _PRIVATE_memory;
    bool whether_alive;
}
lmfl_hpv;
lmfl_hpv _LMFL_ALGO_hpv_create0( unsigned MSD);
lmfl_hpv _LMFL_ALGO_hpv_create1( unsigned MSD, lmfl_data source);
bool _LMFL_ALGO_hpv_read( lmfl_hpv*, char*);
bool _LMFL_ALGO_hpv_copy( lmfl_hpv*, lmfl_hpv);
bool _LMFL_ALGO_hpv_add( lmfl_hpv*, lmfl_hpv x, lmfl_hpv y);
bool _LMFL_ALGO_hpv_sub( lmfl_hpv*, lmfl_hpv x, lmfl_hpv y);
bool _LMFL_ALGO_hpv_mult( lmfl_hpv*, lmfl_hpv x, lmfl_hpv y);
bool _LMFL_ALGO_hpv_div( lmfl_hpv*, lmfl_hpv x, lmfl_hpv y);
bool _LMFL_ALGO_hpv_pow( lmfl_hpv*, lmfl_hpv x, lmfl_hpv y);

#   endif

#   ifndef _LMFL_MATH_
#       define _LMFL_MATH_
typedef struct{
    int x;
    int y;
}
lmfl_point;

typedef struct{
    unsigned width;
    unsigned height;
    lmfl_point corner;
}
lmfl_rectangle;

typedef struct{
    int i;
    int j;
}
lmfl_vector;

typedef struct{
    lmfl_point point0;
    lmfl_point point1;
    lmfl_point point2;
}
lmfl_parallelogram;

lmfl_point _LMFL_MATH_point_create0( int x, int y);
lmfl_rectangle _LMFL_MATH_rectangle_create0( unsigned width, unsigned height, lmfl_point corner);
lmfl_vector _LMFL_MATH_vector_create0( int i, int j);
lmfl_vector _LMFL_MATH_vector_create1( double mudulus, double angle);
lmfl_vector _LMFL_MATH_vector_create2( lmfl_point start, lmfl_point end);
lmfl_parallelogram _LMFL_MATH_parallegram_create0( lmfl_point point0, lmfl_point point1, lmfl_point point2);

lmfl_point _LMFL_MATH_point_move( lmfl_point, lmfl_vector vector);
lmfl_rectangle _LMFL_MATH_rectangle_move( lmfl_rectangle, lmfl_vector vector);
lmfl_parallelogram _LMFL_MATH_parallegram_move( lmfl_parallelogram, lmfl_vector vector);

bool _LMFL_MATH_whether_rectangle_contain_point( lmfl_rectangle, lmfl_point point);
bool _LMFL_MATH_whether_rectangle_contain_rectangle( lmfl_rectangle, lmfl_rectangle rectangle);
bool _LMFL_MATH_whether_intersect_rectangle( lmfl_rectangle, lmfl_rectangle rectangle);

double _LMFL_MATH_get_vector_mudulus( lmfl_vector);
double _LMFL_MATH_get_vector_angle( lmfl_vector);
lmfl_vector _LMFL_MATH_get_vector_negtive( lmfl_vector);

lmfl_vector _LMFL_MATH_calculate_vector_sub( lmfl_vector minu, lmfl_vector subh);
lmfl_vector _LMFL_MATH_calculate_vector_add( lmfl_vector vector0, lmfl_vector vector1);

lmfl_point _LMFL_MATH_point_wound( lmfl_point, lmfl_point centre, double angle);
lmfl_parallelogram _LMFL_MATH_parallegram_wound( lmfl_parallelogram, lmfl_point centre, double angle);
#   endif /*_LMFL_MATH_*/

#   ifndef _LMFL_THREAD_
#       define _LMFL_THREAD_
#       define  lmfl_api (DWORD WINAPI)
typedef struct{
    HANDLE _PRIVATE_handle;
    bool whether_working;
    bool whether_alive;
}
lmfl_thread;
typedef LPTHREAD_START_ROUTINE lmfl_tfunc;

lmfl_thread _LMFL_THREAD_thread_create0( lmfl_tfunc func, lmfl_void param);
bool _LMFL_THREAD_thread_exit();
bool _LMFL_THREAD_thread_resume( lmfl_thread*);
bool _LMFL_THREAD_thread_suspend( lmfl_thread*);
bool _LMFL_THREAD_thread_delete( lmfl_thread*);
#   endif /*_LMFL_THREAD_*/

#   ifndef _LMFL_PLANE_
#       define _LMFL_PLANE_
typedef struct _LMFL_PLANE_lmfl_plane_tag{
    HDC _PRIVATE_hdc;
    HBITMAP _PRIVATE_map;
    unsigned width;
    unsigned height;
    bool whether_operating;
    bool whether_alive;
}
lmfl_plane;

lmfl_plane _LMFL_PLANE_plane_create0( lmfl_plane* father, unsigned width, unsigned height);
lmfl_plane _LMFL_PLANE_plane_create1( lmfl_plane* father, char* path, unsigned width, unsigned height);
bool _LMFL_PLANE_plane_delete( lmfl_plane*);
bool _LMFL_PLANE_plane_set_pixel( lmfl_plane*, lmfl_point point, lmfl_rgb color);
lmfl_rgb _LMFL_PLANE_plane_get_pixel( lmfl_plane*, lmfl_point point);

bool _LMFL_PLANE_plane_pasteTo_whole_cover( lmfl_plane*, lmfl_plane* plane, lmfl_point plane_corner);
bool _LMFL_PLANE_plane_pasteTo_rectangle_cover( lmfl_plane*, lmfl_plane* plane, lmfl_rectangle plane_rectangle);
bool _LMFL_PLANE_plane_pasteTo_parallelogram_cover( lmfl_plane*, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram);

bool _LMFL_PLANE_plane_pasteTo_whole_merge( lmfl_plane*, lmfl_plane* plane, lmfl_point plane_corner);
bool _LMFL_PLANE_plane_pasteTo_rectangle_merge( lmfl_plane*, lmfl_plane* plane, lmfl_rectangle plane_rectangle);
bool _LMFL_PLANE_plane_pasteTo_parallelogram_merge( lmfl_plane*, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram);

bool _LMFL_PLANE_plane_pasteTo_whole_cutOut( lmfl_plane*, lmfl_plane* plane, lmfl_point plane_corner, lmfl_rgb color);
bool _LMFL_PLANE_plane_pasteTo_rectangle_cutOut( lmfl_plane*, lmfl_plane* plane, lmfl_rectangle plane_rectangle, lmfl_rgb color);
bool _LMFL_PLANE_plane_pasteTo_parallelogram_cutOut( lmfl_plane* , lmfl_plane* plane, lmfl_parallelogram plane_parallelogram, lmfl_rgb color);

bool _LMFL_PLANE_plane_cutTo_whole_cover( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner);
bool _LMFL_PLANE_plane_cutTo_rectangle_cover( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle);
bool _LMFL_PLANE_plane_cutTo_parallelogram_cover( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram);

bool _LMFL_PLANE_plane_cutTo_whole_merge( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner);
bool _LMFL_PLANE_plane_cutTo_rectangle_merge( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle);
bool _LMFL_PLANE_plane_cutTo_parallelogram_merge( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram);

bool _LMFL_PLANE_plane_cutTo_whole_cutOut( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_point plane_corner, lmfl_rgb color );
bool _LMFL_PLANE_plane_cutTo_rectangle_cutOut( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_rectangle plane_rectangle, lmfl_rgb color);
bool _LMFL_PLANE_plane_cutTo_parallelogram_cutOut( lmfl_plane*, lmfl_rectangle this_rectangle, lmfl_plane* plane, lmfl_parallelogram plane_parallelogram, lmfl_rgb color);
#   endif /*_LMFL_PLANE_*/

#   ifndef _LMFL_GRAPH_
#       define _LMFL_GRAPH_
typedef bool(*lmfl_gfunc)(lmfl_point);
typedef struct{
    unsigned cweight;
    lmfl_rgb color;
    lmfl_rectangle rectangle;
}
lmfl_gparam;
lmfl_gparam _LMFL_GRAPH_gparam_create0( unsigned cweight, lmfl_rgb color, lmfl_rectangle rectangle);
bool _LMFL_GRAPH_graph_on( lmfl_gfunc gfunc, lmfl_gparam gparam, lmfl_plane* plane);
#   endif /*_LMFL_GRAPH_*/

#   ifndef _LMFL_TEXT_
#       define _LMFL_TEXT_
typedef struct{
    lmfl_rgb color;
    unsigned width;
    unsigned height;
    unsigned cweight;
    char* style;
    HFONT _PRIVATE_hfont;
    bool whether_alive;
}
lmfl_font;
lmfl_font _LMFL_TEXT_font_create0( char* style, unsigned width, unsigned height, unsigned cweight, lmfl_rgb color);
bool _LMFL_TEXT_font_delete( lmfl_font*);

bool _LMFL_TEXT_text_on( char* text, lmfl_font font, lmfl_rectangle rectangle, lmfl_plane* plane);
#   endif/*_LMFL_TEXT_*/

#   ifndef _LMFL_WINDOW_
#       define _LMFL_WINDOW_
typedef struct _LMFL_WINDOW_lmfl_window_tag{
    HWND _PRIVATE_hwnd;
    lmfl_plane _PRIVATE_plane;
    lmfl_plane plane;
    char* title;
    unsigned width;
    unsigned height;
    bool whether_alive;
    bool whether_operating;
}
lmfl_window;

lmfl_window _LMFL_WINDOW_lmfl_window_create0( char* title, char* iconPath, unsigned width, unsigned height, bool main);
lmfl_window _LMFL_WINDOW_lmfl_window_create1( char* title, char* iconPath, unsigned width, unsigned height);
lmfl_window _LMFL_WINDOW_lmfl_window_create2( char* title, char* iconPath, unsigned width, unsigned height);
lmfl_window _LMFL_WINDOW_lmfl_window_create3( char* title, unsigned width, unsigned height, bool main);
lmfl_window _LMFL_WINDOW_lmfl_window_create4( char* title, unsigned width, unsigned height);

bool _LMFL_WINDOW_lmfl_window_delete( lmfl_window*);

bool _LMFL_WINDOW_lmfl_window_hide( lmfl_window*);
bool _LMFL_WINDOW_lmfl_window_show( lmfl_window*);
bool _LMFL_WINDOW_lmfl_window_move( lmfl_window*, lmfl_vector vector);

bool _LMFL_WINDOW_lmfl_window_whether_exist( lmfl_window*);
bool _LMFL_WINDOW_lmfl_window_whether_focus( lmfl_window*);

bool _LMFL_WINDOW_lmfl_window_set_corner( lmfl_window*, lmfl_point corner);
bool _LMFL_WINDOW_lmfl_window_set_title( lmfl_window*, char* title);
bool _LMFL_WINDOW_lmfl_window_set_top( lmfl_window*);

lmfl_point _LMFL_WINDOW_lmfl_window_get_corner( lmfl_window*);
#   endif /*_LMFL_WINDOW_*/

#   ifndef _LMFL_EVENT_
#       define _LMFL_EVENT_
lmfl_point _LMFL_EVENT_event_get_mouse( lmfl_window* window);
bool _LMFL_EVENT_event_whether_check( unsigned key);
#   endif /*_LMFL_EVENT_*/

#   ifndef _LMFL_WIDGET_
#       define _LMFL_WIDGET_
typedef enum{
    lmfl_pushbox_released,
    lmfl_pushbox_suspended,
    lmfl_pushbox_pushed
}
lmfl_pstate;

typedef struct{
    lmfl_afunc state_released;
    lmfl_afunc state_suspended;
    lmfl_afunc state_pushed;
    lmfl_afunc command;
}
lmfl_pfuncs;

typedef struct{
    lmfl_thread _PRIVATE_thread;
    lmfl_pstate state;
    lmfl_pfuncs funcs;
    lmfl_window* window;
    lmfl_rectangle rectangle;
    bool whether_along;
    bool whether_alive;
    bool whether_operating;
}
lmfl_pushbox;

lmfl_pushbox _LMFL_WIDGET_pushbox_create0( lmfl_rectangle rectangle, lmfl_pfuncs funcs, lmfl_window* window);
bool _LMFL_WIDGET_pushbox_resume( lmfl_pushbox*);
bool _LMFL_WIDGET_pushbox_suspend( lmfl_pushbox*);
bool _LMFL_WIDGET_pushbox_delete( lmfl_pushbox*);

#   endif /*_LMFL_WIDGET_*/

struct{
#   ifdef _LMFL_BASIC_
    struct{
        void(*wait)(unsigned);
        void(*loop)();
        void(*exit)();
        struct{
            void(*open)();
            void(*close)();
            int(*in)(const char* restrict,...);
            int(*out)(const char* restrict,...);
            struct{
                void(*title)(char*);
            }
            set;
        }
        console;
    }
    app;
    struct{
        struct{
            bool(*success)(bool);
        }
        whether;
    }
    function;
    struct{
        lmfl_rgba(*create)(unsigned,unsigned,unsigned,unsigned);
        lmfl_rgba(*create0)(unsigned,unsigned,unsigned,unsigned);
    }
    rgba;
    struct{
        lmfl_rgb(*create)(unsigned,unsigned,unsigned);
        lmfl_rgb(*create0)(unsigned,unsigned,unsigned);
        struct{
            unsigned(*gray)(lmfl_rgb);
        }
        get;
    }
    rgb;
    struct{
        lmfl_timer(*create)();
        lmfl_timer(*create0)();
        bool(*init)(lmfl_timer*);
        bool(*start)(lmfl_timer*);
        bool(*stop)(lmfl_timer*);
        struct{
            long(*time)(lmfl_timer*);
        }
        get;
    }
    timer;
#   endif /*_LMFL_BASIC_*/
#   ifdef _LMFL_ALGO_
    struct{
        lmfl_stack(*create)(int,unsigned);
        lmfl_stack(*create0)(int,unsigned);
        bool(*del)(lmfl_stack*);
        bool(*push)(lmfl_stack*,lmfl_data);
        bool(*pop)(lmfl_stack*);
        struct{
            lmfl_data(*top)(lmfl_stack*);
        }
        get;
        struct{
            bool(*empty)(lmfl_stack*);
        }
        whether;
    }
    stack;
    struct{
        lmfl_queue(*create)();
        lmfl_queue(*create0)();
        bool(*del)(lmfl_queue*);
        bool(*push)(lmfl_queue*,lmfl_data);
        bool(*pop)(lmfl_queue*);
        struct{
            lmfl_data(*front)(lmfl_queue*);
        }
        get;
        struct{
            bool(*empty)(lmfl_queue*);
        }
        whether;
    }
    queue;
    struct{
        lmfl_hpv(*create)(unsigned);
        lmfl_hpv(*create0)(unsigned);
        lmfl_hpv(*create1)(unsigned,lmfl_data);
        bool(*read)(lmfl_hpv*,char*);
        bool(*copy)(lmfl_hpv*,lmfl_hpv);
        bool(*add)(lmfl_hpv*,lmfl_hpv,lmfl_hpv);
        bool(*sub)(lmfl_hpv*,lmfl_hpv,lmfl_hpv);
        bool(*mult)(lmfl_hpv*,lmfl_hpv,lmfl_hpv);
        bool(*div)(lmfl_hpv*,lmfl_hpv,lmfl_hpv);
        bool(*pow)(lmfl_hpv*,lmfl_hpv,lmfl_hpv);
    }
    hpv;
    struct{
        bool(*sort)(void*,unsigned,lmfl_cfunc,unsigned);
    }
    algo;
#   endif /*_LMFL_ALGO_*/
#   ifdef _LMFL_MATH_
    struct{
        struct{
            lmfl_point(*create)(int,int);
            lmfl_point(*create0)(int,int);
            lmfl_point(*move)(lmfl_point,lmfl_vector);
            lmfl_point(*wound)(lmfl_point,lmfl_point,double);
        }
        point;
        struct{
            lmfl_rectangle(*create)(unsigned,unsigned,lmfl_point);
            lmfl_rectangle(*create0)(unsigned,unsigned,lmfl_point);
            lmfl_rectangle(*move)(lmfl_rectangle,lmfl_vector);
            struct{
                struct{
                    bool(*point)(lmfl_rectangle,lmfl_point);
                    bool(*rectangle)(lmfl_rectangle,lmfl_rectangle);
                }
                contain;
                struct{
                    bool(*rectangle)(lmfl_rectangle,lmfl_rectangle);
                }
                intersect;
            }
            whether;
        }
        rectangle;
        struct{
            lmfl_vector(*create)(int,int);
            lmfl_vector(*create0)(int,int);
            lmfl_vector(*create1)(double,double);
            lmfl_vector(*create2)(lmfl_point,lmfl_point);
            struct{
                double(*mudulus)(lmfl_vector);
                double(*angle)(lmfl_vector);
                lmfl_vector(*negtive)(lmfl_vector);
            }
            get;
            lmfl_vector(*sub)(lmfl_vector,lmfl_vector);
            lmfl_vector(*add)(lmfl_vector,lmfl_vector);
        }
        vector;
        struct{
            lmfl_parallelogram(*create)(lmfl_point,lmfl_point,lmfl_point);
            lmfl_parallelogram(*create0)(lmfl_point,lmfl_point,lmfl_point);
            lmfl_parallelogram(*move)(lmfl_parallelogram,lmfl_vector);
            lmfl_parallelogram(*wound)(lmfl_parallelogram,lmfl_point,double);
        }
        parallelogram;
    }math;
#   endif /*_LMFL_MATH_*/
#   ifdef _LMFL_THREAD_
    struct{
        lmfl_thread(*create)(lmfl_tfunc,lmfl_void);
        lmfl_thread(*create0)(lmfl_tfunc,lmfl_void);
        bool(*exit)();
        bool(*resume)(lmfl_thread*);
        bool(*suspend)(lmfl_thread*);
        bool(*del)(lmfl_thread*);
    }
    thread;
#   endif /*_LMFL_THREAD_*/
#   ifdef _LMFL_PLANE_
    struct{
        lmfl_plane(*create)(lmfl_plane*,unsigned,unsigned);
        lmfl_plane(*create0)(lmfl_plane*,unsigned,unsigned);
        lmfl_plane(*create1)(lmfl_plane*,char*,unsigned,unsigned);
        bool(*del)(lmfl_plane*);
        struct{
            struct{
                bool(*cover)(lmfl_plane*,lmfl_plane*,lmfl_point);
                bool(*merge)(lmfl_plane*,lmfl_plane*,lmfl_point);
                bool(*cutout)(lmfl_plane*,lmfl_plane*,lmfl_point,lmfl_rgb);
            }
            whole;
            struct{
                bool(*cover)(lmfl_plane*,lmfl_plane*,lmfl_rectangle);
                bool(*merge)(lmfl_plane*,lmfl_plane*,lmfl_rectangle);
                bool(*cutout)(lmfl_plane*,lmfl_plane*,lmfl_rectangle,lmfl_rgb);
            }
            rectangle;
            struct{
                bool(*cover)(lmfl_plane*,lmfl_plane*,lmfl_parallelogram);
                bool(*merge)(lmfl_plane*,lmfl_plane*,lmfl_parallelogram);
                bool(*cutout)(lmfl_plane*,lmfl_plane*,lmfl_parallelogram,lmfl_rgb);
            }
            parallelogram;
        }
        paste_to;
        struct{
            struct{
                bool(*cover)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_point);
                bool(*merge)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_point);
                bool(*cutout)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_point,lmfl_rgb);
            }
            whole;
            struct{
                bool(*cover)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_rectangle);
                bool(*merge)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_rectangle);
                bool(*cutout)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_rectangle,lmfl_rgb);
            }
            rectangle;
            struct{
                bool(*cover)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_parallelogram);
                bool(*merge)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_parallelogram);
                bool(*cutout)(lmfl_plane*,lmfl_rectangle,lmfl_plane*,lmfl_parallelogram,lmfl_rgb);
            }
            parallelogram;
        }
        cut_to;
        struct{
            bool(*pixel)(lmfl_plane*,lmfl_point,lmfl_rgb);
        }
        set;
        struct{
            lmfl_rgb(*pixel)(lmfl_plane*,lmfl_point);
        }
        get;
    }
    plane;
#   endif /*_LMFL_PLANE_*/
#   ifdef _LMFL_GRAPH_
    struct{
        struct{
            lmfl_gparam(*create)(unsigned,lmfl_rgb,lmfl_rectangle);
            lmfl_gparam(*create0)(unsigned,lmfl_rgb,lmfl_rectangle);
        }
        gparam;
        bool(*on)(lmfl_gfunc,lmfl_gparam,lmfl_plane*);
    }
    graph;
#   endif /*_LMFL_GRAPH_*/
#   ifdef _LMFL_TEXT_
    struct{
        lmfl_font(*create)(char*,unsigned,unsigned,unsigned,lmfl_rgb);
        lmfl_font(*create0)(char*,unsigned,unsigned,unsigned,lmfl_rgb);
        bool(*del)(lmfl_font*);
    }
    font;
    struct{
        bool(*on)(char*,lmfl_font,lmfl_rectangle,lmfl_plane*);
    }
    text;
#   endif /*_LMFL_TEXT_*/
#   ifdef _LMFL_WINDOW_
    struct{
        lmfl_window(*create)(char*,char*,unsigned,unsigned,bool);
        lmfl_window(*create0)(char*,char*,unsigned,unsigned,bool);
        lmfl_window(*create1)(char*,char*,unsigned,unsigned);
        lmfl_window(*create2)(char*,char*,unsigned,unsigned);
        lmfl_window(*create3)(char*,unsigned,unsigned,bool);
        lmfl_window(*create4)(char*,unsigned,unsigned);
        bool(*del)(lmfl_window*);
        bool(*hide)(lmfl_window*);
        bool(*show)(lmfl_window*);
        bool(*move)(lmfl_window*,lmfl_vector);

        struct{
            bool(*exist)(lmfl_window*);
            bool(*focus)(lmfl_window*);
        }
        whether;

        struct{
            bool(*corner)(lmfl_window*,lmfl_point);
            bool(*title)(lmfl_window*,char*);
            bool(*top)(lmfl_window*);
        }
        set;
    }
    window;
#   endif /*_LMFL_WINDOW_*/
#   ifdef _LMFL_EVENT_
    struct{
        struct{
            int space;
            int left;
            int up;
            int right;
            int down;
            int esc;
            int tab;
            int capsLock;
            int shift;
            int backSpace;
            int clear;
            int enter;
            int alt;
            int pause;
            int end;
            int home;
            int del;

            int zero;
            int one;
            int two;
            int three;
            int four;
            int five;
            int six;
            int seven;
            int eight;
            int nine;

            int A;
            int B;
            int C;
            int D;
            int E;
            int F;
            int G;
            int H;
            int I;
            int J;
            int K;
            int L;
            int M;
            int N;
            int O;
            int P;
            int Q;
            int R;
            int S;
            int T;
            int U;
            int V;
            int W;
            int X;
            int Y;
            int Z;
        }
        board;
        struct{
            int left;
            int right;
            int middle;
        }
        mouse;
    }
    key;
    struct{
        struct{
            lmfl_point(*mouse)(lmfl_window*);
        }
        get;
        struct{
            bool(*check)(unsigned);
        }
        whether;
    }
    event;
#   endif /*_LMFL_EVENT_*/
#   ifdef _LMFL_WIDGET_
    struct{
        lmfl_pushbox(*create)(lmfl_rectangle,lmfl_pfuncs,lmfl_window*);
        lmfl_pushbox(*create0)(lmfl_rectangle,lmfl_pfuncs,lmfl_window*);
        bool(*del)(lmfl_pushbox*);
        bool(*resume)(lmfl_pushbox*);
        bool(*suspend)(lmfl_pushbox*);
    }
    pushbox;
#   endif /*_LMFL_WIDGET_*/
}lmfl;

#endif /*_LMFL_*/