
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
/

/**
 * Author: Mustafa CAMURLI
 * Date: Mon July 08, 2013
 *
 * +) Template Stack Library
*/

#ifndef _T_STACK_H_
#define _T_STACK_H_


#define tstack_header(type,name,cpy,fr)\
    \
    /**
     * @description:
     *  template stack custom type
    */\
    typedef struct t_##name##_stack_s t_##name##_stack_t;\
    struct t_##name##_stack_s {\
        type* top;\
    };\
    \
    \
    void init_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    void free_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    const type* peek_element_from_##name##_stack(const t_##name##_stack_t* tsp);\
    \
    \
    void pop_element_from_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    const type* push_element_into_##name##_stack(t_##name##_stack_t* tsp, const type* tp);\
    \
    \

#define tstack_source(type,name,cpy,fr)\
    \
    void init_##name##_stack(t_##name##_stack_t* tsp)\
    {\
        if (tsp)\
            tsp->top = NULL;\
    }\
    \
    \
    void free_##name##_stack(t_##name##_stack_t* tsp)\
    {\
        /*remove 1 by 1 */;\
    }\

#endif  /* _T_STACK_H_ */

