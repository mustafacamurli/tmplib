
/**
 * This file is part of TmpltLib.
 *
 *  TmpltLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  TmpltLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TmpltLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Mustafa CAMURLI - mustafacamurli@gmail.com
 *  Mon July 08, 2013
*/

/**
 * Author: Mustafa CAMURLI
 * Date: Mon July 08, 2013
 *
 * +) Template Stack Library
*/

/**
 * Author: Mustafa CAMURLI
 * Date: Mon Sep 02, 2013
 * 
 * +) initial implementation of template stack library
 **/



#ifndef _T_STACK_H_
#define _T_STACK_H_


/**
 * @description:
 *  template stack header declarator macro
 * 
 * @parameters
 *  type [in] -> name of type of structure
 *               struct my_def_s or my_def_t is fine.
 * 
 *  name [in] -> name of the new module, should be uniqe
 *               if you send MyType, name of the function pushs an element
 *               onto stack would be push_element_into_MyType_stack.
 *               
 * ##############################################################################
 * 
 * @API
 * 
 *  +) void init_##name##_stack(t_##name##_stack_t* tsp)
 *  
 *  +) void free_##name##_stack(t_##name##_stack_t* tsp)
 *  
 *  +) const type* peek_element_from_##name##_stack(const t_##name##_stack_t tsp)
 *  
 *  +) void pop_element_from_##name##_stack(t_##name##_stack_t* tsp)
 *  
 *  +) const type* push_element_into_##name##_stack(t_##name##_stack_t* tsp, const type* tp)
 *  
 **/
#define tstack_header(type, name)\
    \
    /**
     * @description:
     *  template stack custom type
    */\
    typedef struct t_##name##_stack_s* t_##name##_stack_t;\
    struct t_##name##_stack_s {\
        type* elem;\
        struct t_##name##_stack_s* down;\
    };\
    \
    \
    /**
     * @description:
     *  initializes template stack
     * 
     * @parameeters:
     *  tsp [out] -> template stack pointer
     * 
     * @return:
     *  nothing
    */\
    void init_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    /**
     * @description:
     *  delete the stack with given pointer
     * 
     * @parameters:
     *  tsp [in] -> template stack pointer
     *  
     * @return:
     *  nothing
    */\
    void free_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    /**
     * @description:
     *  returns the element which is top element on the stack
     * 
     * @parameters:
     *  ts [in] -> template stack
     * 
     * @return:
     *  type pointer if stack is not empty, NULL if so
    */\
    const type* peek_element_from_##name##_stack(const t_##name##_stack_t ts);\
    \
    \
    /**
     * @description:
     *  removes an element from top of the stack
     * 
     * @parameters:
     *  tsp [in] -> template stack pointer
     *  
     * @return
     *  nothing
    */\
    void pop_element_from_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    /**
     * @description:
     *  pushs (adds) an element onto stack
     * 
     * @parameters:
     *  tsp [in] -> template stack pointer
     *  tp  [in] -> element pointer
     * 
     * @return:
     *  newly pushed element if push is successful, NULL if not.
     *  
    */\
    const type* push_element_into_##name##_stack(t_##name##_stack_t* tsp, const type* tp);\
    \
    \

/**
 * @description:
 *  template stack source code declarator macro
 * 
 * @parameters
 *  type   [in] -> name of type of structure
 *                 struct my_def_s or my_def_t is fine.
 * 
 *  name   [in] -> name of the new module, should be uniqe
 *                 if you send MyType, name of the function pushs an element
 *                 onto stack would be push_element_into_MyType_stack.
 * 
 *  cpy    [in] -> copy function for type which is send for type parameters
 *                 copy function takes CONST type pointer and returns a pointer that
 *                 points copy of the data which is pointed by the pointer that
 *                 is taken as a parameter. If any error occurs, copy function
 *                 should return NULL.
 * 
 *  elemfr [in] -> free function for deallocate type structure. It should take
 *                 a pointer of type and return nothing.
 * 
 *  memalc [in] -> memory allocation function. It allocated memory with
 *                 given size, type of size_t.
 * 
 *  memfr  [in] -> memory free function frees memory that allocated with
 *                 memalc function before.
 **/
#define tstack_source(type, name, cpy, elemfr, memalc, memfr)\
    \
    void init_##name##_stack(t_##name##_stack_t* tsp)\
    {\
        *tsp = NULL;\
    }\
    \
    \
    void free_##name##_stack(t_##name##_stack_t* tsp)\
    {\
        t_##name##_stack_t tmps;\
        while (*tsp) {\
            tmps = (*tsp)->down;\
            elemfr((*tsp)->elem);\
            memfr(*tsp);\
            (*tsp) = tmps;\
        }\
    }\
    \
    \
    const type* peek_element_from_##name##_stack(const t_##name##_stack_t ts)\
    {\
        if (ts)\
            return (ts->elem);\
        return (NULL);\
    }\
    \
    \
    void pop_element_from_##name##_stack(t_##name##_stack_t* tsp)\
    {\
        t_##name##_stack_t tmps;\
        if (tsp && *tsp) {\
            tmps = (*tsp)->down;\
            elemfr((*tsp)->elem);\
            memfr(*tsp);\
            (*tsp) = tmps;\
        }\
    }\
    \
    \
    const type* push_element_into_##name##_stack(t_##name##_stack_t* tsp, const type* tp)\
    {\
        t_##name##_stack_t node;\
        if (!tsp || !tp) {\
            return (NULL);\
        }\
        node = (t_##name##_stack_t)memalc(sizeof(struct t_##name##_stack_s));\
        if (!node) {\
            return (NULL);\
        }\
        node->elem = cpy(tp);\
        if (!(node->elem)){\
            memfr(node);\
            return (NULL);\
        }\
        node->down = *tsp;\
        *tsp = node;\
        return ((*tsp)->elem);\
    }\
    \
    \

#endif  /* _T_STACK_H_ */

