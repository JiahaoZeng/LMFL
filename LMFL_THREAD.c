#include "LMFL.h"
#ifdef _LMFL_THREAD_
lmfl_thread _LMFL_THREAD_thread_create0( lmfl_tfunc func, lmfl_void param){
    lmfl_thread this;
    this._PRIVATE_handle = CreateThread( NULL, 0, func, param, 0, 0);
    this.whether_working = true;
    this.whether_alive = true;
    return this;
}

bool _LMFL_THREAD_thread_exit(){
    ExitThread(0);
    return true;
}

bool _LMFL_THREAD_thread_resume( lmfl_thread* this){
    if ((!this->whether_alive)||(this->whether_working)){
        return false;
    }
    ResumeThread(this->_PRIVATE_handle);
    return true;
}

bool _LMFL_THREAD_thread_suspend( lmfl_thread* this){
    if ((!this->whether_alive)||(!this->whether_working)){
        return false;
    }
    SuspendThread(this->_PRIVATE_handle);
    return true;
}

bool _LMFL_THREAD_thread_delete( lmfl_thread* this){
    if (!this->whether_alive){
        return false;
    }
    _LMFL_THREAD_thread_suspend( this);
    TerminateThread( this->_PRIVATE_handle, 0);
    this->whether_alive = false;
    return true;
}

#endif /*_LMFL_THREAD_*/