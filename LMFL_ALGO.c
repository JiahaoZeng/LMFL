#include "LMFL.h"
#ifdef _LMFL_ALGO_
lmfl_stack _LMFL_ALGO_stack_create0( int size_max){
    lmfl_stack this;
    this.size_max = size_max;
    this._PRIVATE_top = 0;
    this._PRIVATE_memory = (lmfl_data*)malloc( size_max);
    _LMFL_BASIC_GARBAGE_pointer_join( this._PRIVATE_memory);
    this._PRIVATE_whether_empty = true;
    this.whether_alive = true;
    return this;
}

bool _LMFL_ALGO_stack_delete( lmfl_stack* this){
    if ( this->whether_alive == false){
        return false;
    }
    this->whether_alive = false;
    free( this->_PRIVATE_memory);
    return true;
}

bool _LMFL_ALGO_stack_push( lmfl_stack* this, lmfl_data value){
    if ( this->whether_alive == false){
        return false;
    }
    if ( this->_PRIVATE_top == this->size_max-1){
        return false;
    }
    if ( this->_PRIVATE_whether_empty){
        this->_PRIVATE_memory[0] = value;
        this->_PRIVATE_whether_empty = false;
        return true;
    }
    this->_PRIVATE_top++;
    this->_PRIVATE_memory[ this->_PRIVATE_top] = value;
    return true;
}

bool _LMFL_ALGO_stack_pop( lmfl_stack* this){
    if ( this->whether_alive == false){
        return false;
    }
    if ( this->_PRIVATE_whether_empty){
        return false;
    }
    if ( this->_PRIVATE_top == 0){
        this->_PRIVATE_whether_empty = true;
        return true;
    }
    this->_PRIVATE_top--;
    return true;
}

lmfl_data _LMFL_ALGO_stack_get_top( lmfl_stack* this){
    if ( this->whether_alive == false){
        _LMFL_BASIC_PUTERROR("this stack is deleted");
    }
    if ( this->_PRIVATE_whether_empty){
        _LMFL_BASIC_PUTERROR("this stack is empty");
    }
    return this->_PRIVATE_memory[ this->_PRIVATE_top];
}

bool _LMFL_ALGO_stack_whether_empty( lmfl_stack* this){
    if ( this->whether_alive == false){
        _LMFL_BASIC_PUTERROR("this stack is deleted");
    }
    return this->_PRIVATE_whether_empty;
}

lmfl_queue _LMFL_ALGO_queue_create0(){
    lmfl_queue this;
    this.length = 0;
    this.front = NULL;
    this._PRIVATE_tail = NULL;
    this.whether_alive = true;
    return this;
}

bool _LMFL_ALGO_queue_delete( lmfl_queue* this){
    if ( this->whether_alive == false){
        return true;
    }
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* tmp0;
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* tmp1;
    tmp0 = this->_PRIVATE_tail;
    for ( int i = 0; i < this->length; i++){
        tmp1 = tmp0;
        free( tmp0);
        tmp0 = tmp1->next;
    }
    this->whether_alive = false;
}

bool _LMFL_ALGO_queue_push( lmfl_queue* this, lmfl_data value){
    if ( this->whether_alive == false){
        _LMFL_BASIC_PUTERROR("this queue is deleted");
    }
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* new_node =
        (_LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE*)
        malloc(sizeof(_LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE));
    _LMFL_BASIC_GARBAGE_pointer_join( new_node);

    new_node->value = value;
    new_node->last = this->_PRIVATE_tail;
    new_node->next = NULL;

    if ( this->length == 0){
        this->front = new_node;
        this->_PRIVATE_tail = new_node;
    }

    this->_PRIVATE_tail->next = new_node;
    this->_PRIVATE_tail = new_node;
    this->length++;
    return true;
}

bool _LMFL_ALGO_queue_pop( lmfl_queue* this){
    if ( this->whether_alive == false){
        _LMFL_BASIC_PUTERROR("this queue is deleted");
    }
    if ( this->length == 0){
        return false;
    }
    _LMFL_ALGO_PRIVATE_TYPE_QUEUE_NODE* rubbish_node;
    rubbish_node = this->front;
    this->front = this->front->next;
    this->length--;
    return true;
}

lmfl_data _LMFL_ALGO_queue_get_front( lmfl_queue* this){
    if ( this->whether_alive == false){
        _LMFL_BASIC_PUTERROR("this queue is deleted");
    }
    if ( this->length == 0){
        _LMFL_BASIC_PUTERROR("this queue is empty");
    }
    return this->front->value;
}

bool _LMFL_ALGO_queue_whether_empty( lmfl_queue* this){
    return ( this->length == 0);
}

bool _LMFL_ALGO_sort( void* array, unsigned length, lmfl_cfunc cmp){
// TODO
    return true;
}

lmfl_hpv _LMFL_ALGO_hpv_create0( unsigned MSD){
    lmfl_hpv result;
//TODO
    return result;
}

lmfl_hpv _LMFL_ALGO_hpv_create1( unsigned MSD, lmfl_data source){
    lmfl_hpv result;
//TODO
    return result;
}

bool _LMFL_ALGO_hpv_read( lmfl_hpv* this, char* num){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_copy( lmfl_hpv* this, lmfl_hpv hpv){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_add( lmfl_hpv* this, lmfl_hpv x, lmfl_hpv y){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_sub( lmfl_hpv* this, lmfl_hpv x, lmfl_hpv y){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_mult( lmfl_hpv* this, lmfl_hpv x, lmfl_hpv y){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_div( lmfl_hpv* this, lmfl_hpv x, lmfl_hpv y){
// TODO
    return true;
}

bool _LMFL_ALGO_hpv_pow( lmfl_hpv* this, lmfl_hpv x, lmfl_hpv y){
// TODO
    return true;
}
#endif /*_LMFL_ALGO_*/