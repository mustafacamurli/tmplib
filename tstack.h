
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

#ifndef _T_STACK_H_
#define _T_STACK_H_


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
    void init_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    void free_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    const type* peek_element_from_##name##_stack(const t_##name##_stack_t tsp);\
    \
    \
    void pop_element_from_##name##_stack(t_##name##_stack_t* tsp);\
    \
    \
    const type* push_element_into_##name##_stack(t_##name##_stack_t* tsp, const type* tp);\
    \
    \

#define tstack_source(type, name, cmp, cpy, elemfr, prnt, memalc, memfr)\
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
    const type* peek_element_from_##name##_stack(const t_##name##_stack_t tsp)\
    {\
        if (tsp)\
            return (tsp->elem);\
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
        if (node) {\
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

