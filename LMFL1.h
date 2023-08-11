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

#ifndef _LMFL_
#   include "LMFL.h"
#endif
#ifndef _LMFL_C
#   define _LMFL_C
#define LMFL {\
    printf("[LMFL] version %s, win\n", LMFL_VERSION);\
    /*_LMFL_BASIC_ init*/\
    _LMFL_BASIC_GARBAGE_init();\
    lmfl.app.wait = &_LMFL_BASIC_wait;\
    lmfl.app.loop = &_LMFL_BASIC_loop;\
    lmfl.app.exit = &_LMFL_BASIC_exit;\
\
    lmfl.app.console.open = &_LMFL_BASIC_console_open;\
    lmfl.app.console.close = &_LMFL_BASIC_console_close;\
    lmfl.app.console.set.title = &_LMFL_BASIC_console_set_title;\
    lmfl.app.console.in = &scanf;\
    lmfl.app.console.out = &printf;\
\
    lmfl.function.whether.success = &_LMFL_BASIC_whether_function_success;\
\
    lmfl.rgb.create = &_LMFL_BASIC_rgb_create0;\
    lmfl.rgb.create0 = &_LMFL_BASIC_rgb_create0;\
    lmfl.rgb.get.gray = &_LMFL_BASIC_rgb_get_gray;\
\
    lmfl.rgba.create = &_LMFL_BASIC_rgba_create0;\
    lmfl.rgba.create0 = &_LMFL_BASIC_rgba_create0;\
\
    lmfl.timer.create = &_LMFL_BASIC_timer_create0;\
    lmfl.timer.create0 = &_LMFL_BASIC_timer_create0;\
    lmfl.timer.init = &_LMFL_BASIC_timer_init;\
    lmfl.timer.start = &_LMFL_BASIC_timer_start;\
    lmfl.timer.stop = &_LMFL_BASIC_timer_stop;\
    lmfl.timer.get.time = &_LMFL_BASIC_timer_get_time;\
    /*_LMFL_ALGO_;*/\
    lmfl.stack.create = &_LMFL_ALGO_stack_create0;\
    lmfl.stack.create0 = &_LMFL_ALGO_stack_create0;\
    lmfl.stack.del = &_LMFL_ALGO_stack_delete;\
    lmfl.stack.push = &_LMFL_ALGO_stack_push;\
    lmfl.stack.pop = &_LMFL_ALGO_stack_pop;\
    lmfl.stack.get.top = &_LMFL_ALGO_stack_get_top;\
    lmfl.stack.whether.empty = &_LMFL_ALGO_stack_whether_empty;\
\
    lmfl.queue.create = &_LMFL_ALGO_queue_create0;\
    lmfl.queue.create0 = &_LMFL_ALGO_queue_create0;\
    lmfl.queue.del = &_LMFL_ALGO_queue_delete;\
    lmfl.queue.push = &_LMFL_ALGO_queue_push;\
    lmfl.queue.pop = &_LMFL_ALGO_queue_pop;\
    lmfl.queue.get.front = &_LMFL_ALGO_queue_get_front;\
    lmfl.queue.whether.empty = &_LMFL_ALGO_queue_whether_empty;\
\
    lmfl.hpv.create = &_LMFL_ALGO_hpv_create0;\
    lmfl.hpv.create0 = &_LMFL_ALGO_hpv_create0;\
    lmfl.hpv.create1 = &_LMFL_ALGO_hpv_create1;\
    lmfl.hpv.read = &_LMFL_ALGO_hpv_read;\
    lmfl.hpv.copy = &_LMFL_ALGO_hpv_copy;\
    lmfl.hpv.add = &_LMFL_ALGO_hpv_add;\
    lmfl.hpv.sub = &_LMFL_ALGO_hpv_sub;\
    lmfl.hpv.mult = &_LMFL_ALGO_hpv_mult;\
    lmfl.hpv.div = &_LMFL_ALGO_hpv_div;\
    lmfl.hpv.pow = &_LMFL_ALGO_hpv_pow;\
\
    lmfl.algo.sort = &_LMFL_ALGO_sort;\
    /*_LMFL_MATH_ init*/\
    lmfl.math.point.create = &_LMFL_MATH_point_create0;\
    lmfl.math.point.create0 = &_LMFL_MATH_point_create0;\
    lmfl.math.point.move = &_LMFL_MATH_point_move;\
    lmfl.math.point.wound = &_LMFL_MATH_point_wound;\
    \
    lmfl.math.rectangle.create = &_LMFL_MATH_rectangle_create0;\
    lmfl.math.rectangle.create0 = &_LMFL_MATH_rectangle_create0;\
    lmfl.math.rectangle.move = &_LMFL_MATH_rectangle_move;\
    lmfl.math.rectangle.whether.contain.point = &_LMFL_MATH_whether_rectangle_contain_point;\
    lmfl.math.rectangle.whether.contain.rectangle = &_LMFL_MATH_whether_rectangle_contain_rectangle;\
    lmfl.math.rectangle.whether.intersect.rectangle = &_LMFL_MATH_whether_intersect_rectangle;\
\
    lmfl.math.vector.create = &_LMFL_MATH_vector_create0;\
    lmfl.math.vector.create0 = &_LMFL_MATH_vector_create0;\
    lmfl.math.vector.create1 = &_LMFL_MATH_vector_create1;\
    lmfl.math.vector.create2 = &_LMFL_MATH_vector_create2;\
    lmfl.math.vector.get.mudulus = &_LMFL_MATH_get_vector_mudulus;\
    lmfl.math.vector.get.angle = &_LMFL_MATH_get_vector_angle;\
    lmfl.math.vector.get.negtive = &_LMFL_MATH_get_vector_negtive;\
    lmfl.math.vector.sub = &_LMFL_MATH_calculate_vector_sub;\
    lmfl.math.vector.add = &_LMFL_MATH_calculate_vector_add;\
\
    lmfl.math.parallelogram.create = &_LMFL_MATH_parallegram_create0;\
    lmfl.math.parallelogram.create0 = &_LMFL_MATH_parallegram_create0;\
    lmfl.math.parallelogram.move = &_LMFL_MATH_parallegram_move;\
    lmfl.math.parallelogram.wound = &_LMFL_MATH_parallegram_wound;\
    /*_LMFL_PLAY_ init*/\
    /*_LMFL_THREAD_ init*/\
    lmfl.thread.create = &_LMFL_THREAD_thread_create0;\
    lmfl.thread.create0 = &_LMFL_THREAD_thread_create0;\
    lmfl.thread.exit = &_LMFL_THREAD_thread_exit;\
    lmfl.thread.resume = &_LMFL_THREAD_thread_resume;\
    lmfl.thread.suspend = &_LMFL_THREAD_thread_suspend;\
    lmfl.thread.del = &_LMFL_THREAD_thread_delete;\
    lmfl.plane.create = &_LMFL_PLANE_plane_create0;\
    lmfl.plane.create0 = &_LMFL_PLANE_plane_create0;\
    lmfl.plane.create1 = &_LMFL_PLANE_plane_create1;\
    lmfl.plane.del = &_LMFL_PLANE_plane_delete;\
\
    lmfl.plane.paste_to.whole.cover = &_LMFL_PLANE_plane_pasteTo_whole_cover;\
    lmfl.plane.paste_to.whole.merge = &_LMFL_PLANE_plane_pasteTo_whole_merge;\
    lmfl.plane.paste_to.whole.cutout = &_LMFL_PLANE_plane_pasteTo_whole_cutOut;\
\
    lmfl.plane.paste_to.rectangle.cover = &_LMFL_PLANE_plane_pasteTo_rectangle_cover;\
    lmfl.plane.paste_to.rectangle.merge = &_LMFL_PLANE_plane_pasteTo_rectangle_merge;\
    lmfl.plane.paste_to.rectangle.cutout = &_LMFL_PLANE_plane_pasteTo_rectangle_cutOut;\
\
    lmfl.plane.paste_to.parallelogram.cover = &_LMFL_PLANE_plane_pasteTo_parallelogram_cover;\
    lmfl.plane.paste_to.parallelogram.merge = &_LMFL_PLANE_plane_pasteTo_parallelogram_merge;\
    lmfl.plane.paste_to.parallelogram.cutout = &_LMFL_PLANE_plane_pasteTo_parallelogram_cutOut;\
\
    lmfl.plane.cut_to.whole.cover = &_LMFL_PLANE_plane_cutTo_whole_cover;\
    lmfl.plane.cut_to.whole.merge = &_LMFL_PLANE_plane_cutTo_whole_merge;\
    lmfl.plane.cut_to.whole.cutout = &_LMFL_PLANE_plane_cutTo_whole_cutOut;\
\
    lmfl.plane.cut_to.rectangle.cover = &_LMFL_PLANE_plane_cutTo_rectangle_cover;\
    lmfl.plane.cut_to.rectangle.merge = &_LMFL_PLANE_plane_cutTo_rectangle_merge;\
    lmfl.plane.cut_to.rectangle.cutout = &_LMFL_PLANE_plane_cutTo_rectangle_cutOut;\
\
    lmfl.plane.cut_to.parallelogram.cover = &_LMFL_PLANE_plane_cutTo_parallelogram_cover;\
    lmfl.plane.cut_to.parallelogram.merge = &_LMFL_PLANE_plane_cutTo_parallelogram_merge;\
    lmfl.plane.cut_to.parallelogram.cutout = &_LMFL_PLANE_plane_cutTo_parallelogram_cutOut;\
\
    lmfl.plane.set.pixel = &_LMFL_PLANE_plane_set_pixel;\
    lmfl.plane.get.pixel = &_LMFL_PLANE_plane_get_pixel;\
    /*_LMFL_GRAPH_ init*/\
    lmfl.graph.gparam.create = &_LMFL_GRAPH_gparam_create0;\
    lmfl.graph.gparam.create0 = &_LMFL_GRAPH_gparam_create0;\
    lmfl.graph.on = &_LMFL_GRAPH_graph_on;\
    /*_LMFL_TEXT_ init*/\
    lmfl.font.create = &_LMFL_TEXT_font_create0;\
    lmfl.font.create0 = &_LMFL_TEXT_font_create0;\
    lmfl.font.del = &_LMFL_TEXT_font_delete;\
    lmfl.text.on = &_LMFL_TEXT_text_on;\
    /*_LMFL_WINDOW_ init*/\
    lmfl.window.create = &_LMFL_WINDOW_lmfl_window_create0;\
    lmfl.window.create0 = &_LMFL_WINDOW_lmfl_window_create0;\
    lmfl.window.create1 = &_LMFL_WINDOW_lmfl_window_create1;\
    lmfl.window.create2 = &_LMFL_WINDOW_lmfl_window_create2;\
    lmfl.window.create3 = &_LMFL_WINDOW_lmfl_window_create3;\
    lmfl.window.create4 = &_LMFL_WINDOW_lmfl_window_create4;\
    lmfl.window.del = &_LMFL_WINDOW_lmfl_window_delete;\
\
    lmfl.window.hide = &_LMFL_WINDOW_lmfl_window_hide;\
    lmfl.window.show = &_LMFL_WINDOW_lmfl_window_show;\
    lmfl.window.move = &_LMFL_WINDOW_lmfl_window_move;\
\
    lmfl.window.whether.exist = &_LMFL_WINDOW_lmfl_window_whether_exist;\
    lmfl.window.whether.focus = &_LMFL_WINDOW_lmfl_window_whether_focus;\
    lmfl.window.set.corner = &_LMFL_WINDOW_lmfl_window_set_corner;\
    lmfl.window.set.top = &_LMFL_WINDOW_lmfl_window_set_top;\
    lmfl.window.set.corner = &_LMFL_WINDOW_lmfl_window_set_corner;\
    /*_LMFL_EVENT_ init*/\
    lmfl.key.board.space = 32;\
    lmfl.key.board.left = 36;\
    lmfl.key.board.up = 33;\
    lmfl.key.board.down = 34;\
    lmfl.key.board.esc = 27;\
    lmfl.key.board.tab = 9;\
    lmfl.key.board.capsLock = 20;\
    lmfl.key.board.shift = 16;\
    lmfl.key.board.del = 46;\
    lmfl.key.board.zero = 48;\
    lmfl.key.board.one = 49;\
    lmfl.key.board.two = 50;\
    lmfl.key.board.three = 51;\
    lmfl.key.board.four = 52;\
    lmfl.key.board.six = 54;\
    lmfl.key.board.seven = 55;\
    lmfl.key.board.eight = 56;\
    lmfl.key.board.nine = 57;\
    lmfl.key.board.A = 65;\
    lmfl.key.board.B = 66;\
    lmfl.key.board.C = 67;\
    lmfl.key.board.D = 68;\
    lmfl.key.board.E = 69;\
    lmfl.key.board.F = 70;\
    lmfl.key.board.G = 71;\
    lmfl.key.board.H = 72;\
    lmfl.key.board.I = 73;\
    lmfl.key.board.J = 74;\
    lmfl.key.board.K = 75;\
    lmfl.key.board.L = 76;\
    lmfl.key.board.M = 77;\
    lmfl.key.board.N = 78;\
    lmfl.key.board.O = 79;\
    lmfl.key.board.P = 80;\
    lmfl.key.board.Q = 81;\
    lmfl.key.board.R = 82;\
    lmfl.key.board.S = 83;\
    lmfl.key.board.T = 84;\
    lmfl.key.board.U = 85;\
    lmfl.key.board.V = 86;\
    lmfl.key.board.W = 87;\
    lmfl.key.board.X = 88;\
    lmfl.key.board.Y = 89;\
    lmfl.key.board.Z = 90;\
    lmfl.key.mouse.left = 1;\
    lmfl.key.mouse.right = 2;\
    lmfl.key.mouse.middle = 4;\
\
    lmfl.event.get.mouse = &_LMFL_EVENT_event_get_mouse;\
    lmfl.event.whether.check = &_LMFL_EVENT_event_whether_check;\
    /*_LMFL_WIDGET_*/\
    lmfl.pushbox.create = &_LMFL_WIDGET_pushbox_create0;\
    lmfl.pushbox.create0 = &_LMFL_WIDGET_pushbox_create0;\
    lmfl.pushbox.resume = &_LMFL_WIDGET_pushbox_resume;\
    lmfl.pushbox.suspend = &_LMFL_WIDGET_pushbox_suspend;\
    lmfl.pushbox.del = &_LMFL_WIDGET_pushbox_delete;\
\
    true;\
}
#endif /*_LMFL_C*/
#ifndef _ALE_
#   pragma once
#   define _ALE_
#   define _ALE_H
#   ifndef _LMFL_
#       include "LMFL.h"
#   endif
#   ifdef BYTE
#       undef BYTE
#   endif
#   define BYTE lmfl_byte
#   ifdef DATA
#       undef DATA
#   endif
#   define DATA lmfl_data
#   ifdef AFUNC
#       undef AFUNC
#   endif
#   define AFUNC lmfl_afunc
#   ifdef VOID
#       undef VOID
#   endif
#   define VOID lmfl_void
#   ifdef STACK
#       undef STACK
#   endif
#   define STACK lmfl_stack
#   ifdef QUEUE
#       undef QUEUE
#   endif
#   define QUEUE lmfl_queue
#   ifdef CFUNC
#       undef CFUNC
#   endif
#   define CFUNC lmfl_cfunc
#   ifdef RGB
#       undef RGB
#   endif
#   define RGB lmfl_rgb
#   ifdef RGBA
#       undef RGBA
#   endif
#   define RGBA lmfl_rgba
#   ifdef TIMER
#       undef TIMER
#   endif
#   define TIMER lmfl_timer
#   ifdef POINT
#       undef POINT
#   endif
#   define POINT lmfl_point
#   ifdef RECTANGLE
#       undef RECTANGLE
#   endif
#   define RECTANGLE lmfl_rectangle
#   ifdef VECTOR
#       undef VECTOR
#   endif
#   define VECTOR lmfl_vector
#   ifdef PLG
#       undef PLG
#   endif
#   define PLG lmfl_parallelogram
#   ifdef TFUNC
#       undef TFUNC
#   endif
#   define TFUNC lmfl_tfunc
#   ifdef THREAD
#       undef THREAD
#   endif
#   define THREAD lmfl_thread
#   ifdef PLANE
#       undef PLANE
#   endif
#   define PLANE lmfl_plane
#   ifdef GFUNC
#       undef GFUNC
#   endif
#   define GFUNC lmfl_gfunc
#   ifdef GPARAM
#       undef GPARAM
#   endif
#   define GPARAM lmfl_gparam
#   ifdef FONT
#       undef FONT
#   endif
#   define FONT lmfl_font
#   ifdef WINDOW
#       undef WINDOW
#   endif
#   define WINDOW lmfl_window
#   ifdef PSTATE
#       undef PSTATE
#   endif
#   define PSTATE lmfl_pstate
#   ifdef PFUNC
#       undef PFUNC
#   endif
#   define PFUNC lmfl_pfuncs
#   ifdef PUSHBOX
#       undef PUSHBOX
#   endif
#   define PUSHBOX lmfl_pushbox
#endif /*_ALE_*/