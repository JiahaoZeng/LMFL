rem[------LMFL BUILD------]
IF %~1% == test (
    cls
    echo [LMFL 1.1.1]
    echo Building...
    echo gcc:[
    gcc LMFL_ALGO.c LMFL_BASIC.c LMFL_EVENT.c LMFL_GRAPH.c LMFL_MATH.c LMFL_PLANE.c LMFL_TEXT.c LMFL_THREAD.c LMFL_WIDGET.c LMFL_WINDOW.c test.c -o test -mwindows -O5
    echo ]
    echo Done!
) ELSE (
    cls
    echo [LMFL 1.1.1]
    echo Building...
    echo gcc:[
    gcc -shared -o LMFL.dll LMFL_BASIC.c LMFL_ALGO.c LMFL_EVENT.c LMFL_GRAPH.c LMFL_MATH.c LMFL_PLANE.c LMFL_TEXT.c LMFL_THREAD.c LMFL_WIDGET.c LMFL_WINDOW.c -mwindows -O5
    echo ]
    echo Done!
)
