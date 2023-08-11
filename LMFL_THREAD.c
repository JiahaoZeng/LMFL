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