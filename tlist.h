
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
 *  Fri Nov 19, 2010
/

/**
 * Author: Mustafa CAMURLI
 * Date: Fri Nov 19, 2010
 *
 * +) Template Singly-Linked List Library
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Sat Nov 20, 2010
 *
 * +) add_##name##_list function provided a new copy function
 * utility.
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Sun Mar 13, 2011
 *
 * +) documentation refreshing for all functions.
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Mon Nov 28, 2011
 *
 * +) significant bug-fixes
 * +) sorted list functionality
 * +) function name refreshing
 * +) list display utility
 * +) print_##name##_list function added
 * +) get_element_from_##name##_list function added
 * +) get_index_of_element_from_##name##_list added
 * +) merge_##name##_lists function added
*/

/**
 *
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Fri Dec 1, 2011
 *
 * +) custom structure free operation support
 *
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Fri Dec 9, 2011
 *
 * +) duplicate code parts were removed from add_to_##name##_list function
 * +) all function parameter provided with const qualifier
 *
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Sat Dec 24, 2011
 *
 * +) template list utility is provided with custom type of structure
 * +) new structure is t_##name##_list_t type is introduce
 * +) all function parameters have been changed to use new structure
 * +) init_##name##_list function implemented
 * +) complete API added to description
 * +) separate macro two part, header and source
 *
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Tue July 08, 2013
 *
 * +) white space corrections
 *
*/

/**
 * Update Notes
 * Author: Mustafa CAMURLI
 * Date: Sat July 27, 2013
 *
 * +) new core structure type is introduced
 * +) no need to user defined next pointer anymore
 * +) adding the same element into list is allowed
 * +) add_to_##name##_list function returns an integer instead of pointer
 * +) unnecessary header declarator macro parameters are removed
 * +) merge_##name##_lists function behavior is changed
 *
*/

#ifndef _T_LIST_H_
#define _T_LIST_H_

#include <stdio.h>

/**
 * @description:
 *  singly-linked list header declarator macro
 *
 * @parameters
 *  type [in] -> name of type of structure
 *       struct my_def_s or my_def_t is OKAY.
 * 
 *  name [in] -> name of new module, should be uniqe
 *       if you send MyType, the name of the function adds a element
 *       into the list would be add_MyType_list.
 *
 * #######################################################################
 *
 * @Application Programmer Interface
 *
 *  +) void init_##name##_list(t_##name##_list_t*)
 *
 *
 *  +) int add_to_##name##_list(t_##name##_list_t, const type*)
 *
 *  +) size_t size_of_##name##_list(t_##name##_list_t)
 *
 *  +) int delete_from_##name##_list(t_##name##_list_t*, const type*)
 *
 *  +) const type* get_element_from_##name##_list(t_##name##_list_t, size_t)
 *
 *  +) void free_##name##_list(t_##name##_list_t)
 *
 *  +) const type* get_same_element_from_##name##_list(t_##name##_list_t, const type*)
 *
 *  +) int get_index_of_element_from_##name##_list(t_##name##_list_t, const type*)
 *
 *  +) void print_##name##_list(t_##name##_list_t*)
 *
 *  +) t_##name##_list_t merge_##name##_lists(t_##name##_list_t, t_##name##_list_t)
 *
*/

#define tlist_header(type, name)\
    \
    /**
     * @description:
     *  template list custom type
    */\
    typedef struct t_##name##_list_s* t_##name##_list_t;\
    struct t_##name##_list_s {\
        type* elem;\
        struct t_##name##_list_s* next;\
    };\
    \
    \
    /**
     * @description:
     *  initialize template list
     *
     * @parameters:
     *  tlp [in] -> template list pointer
     *
     * @return
     *  nothing
    */\
    void init_##name##_list(t_##name##_list_t* tlp);\
    \
    \
    /**
     * @description:
     *  adds the given element into the given list
     *
     * @parameters
     *  tlp [in] -> template list pointer
     *  te  [in] -> pointer of new element
     *
     * @return
     *  0 if it's successful, -1 otherwise.
     *
     *
    */\
    int add_to_##name##_list(t_##name##_list_t* tlp, const type* te);\
    \
    \
    /**
     * @description:
     *   returns size of the list with
     *   given pointer of it
     *
     * @parameters
     *   t1 [in] -> template list
     *
     * @return
     *   size of the given list
     *
    */\
    size_t size_of_##name##_list(t_##name##_list_t tl);\
    \
    \
    /**
     * @description:
     *   delete the node is pointed by te.
     *
     * @parameters
     *   tlp [in] -> template list pointer
     *   te  [in] -> pointer of the data'll be deleted
     *               (data should be same, pointer is not cared!)
     *
     * @return
     *   0 if it's successful, -1 otherwise.
     *
    */\
    int delete_from_##name##_list(t_##name##_list_t* tlp, const type* te);\
    \
    \
    /**
     * @description:
     *   return an element from list with given order.
     *
     * @parameters
     *   tl    [in] -> template list
     *   order [in] -> order of the data in the given list
     *
     * @return
     *   pointer of the desired data.
     *
    */\
    const type* get_element_from_##name##_list(t_##name##_list_t tl, size_t order);\
    /**
     * @description:
     *   remove the given list.
     *
     * @parameters
     *   tl* [in] -> template list pointer
     *
     * @return
     *   nothing
    */\
    void free_##name##_list(t_##name##_list_t* tlp);\
    \
    \
    /**
     * @description:
     *   get index of the element from the list
     *
     * @parameters
     *   tl [in] -> template list
     *   te [in] -> pointer of the element (if there is an element in the list
     *                                      same as variable that te points,
     *                                      the function returns the pointer of it)
     *
     * @return
     *   pointer of the element found in the list same as that te points
     *
    */\
    const type* get_same_element_from_##name##_list(t_##name##_list_t tl, const type* te);\
    \
    \
    /**
     * @description
     *   returns index of the element in the list
     *
     * @parameters
     *   tl [in] -> template list
     *   te [in] -> pointer of the element whose index'll be returned
     *
     * @return
     *   index of the element that is the same element pointed by te
     *
    */\
    int get_index_of_element_from_##name##_list(t_##name##_list_t tl, const type* te);\
    \
    \
    /**
     * @description
     *   prints all elements of the list on display
     *
     * @parameters
     *   tl [in] -> template list
     *
     * @return
     *   nothing
     */\
    void print_##name##_list(t_##name##_list_t tl);\
    \
    \
    /**
     * @description
     *   merges two list onto new list
     *
     * @parameters
     *   tl1 [in] -> first template list
     *   tl2 [in] -> second template list
     *
     * @return
     *   new list from two lists. Duplicates will be discarded.
     *   if there is an error during copy merge process, empty list
     *   will be returned.
    */\
    t_##name##_list_t merge_##name##_lists(t_##name##_list_t tl1, t_##name##_list_t tl2);\
    \
    \

/**
 * @description:
 *  singly-linked list source declarator macro
 *
 * @parameters
 *  type   [in] -> name of type of structure
 *         struct my_def_s or my_def_t is OKAY.
 *
 *  name   [in] -> name of new module, should be uniqe
 *         if you send MyType, the name of the function adds a element
 *         into the list would be add_MyType_list.
 *
 *  cmp    [in] -> compare function for type which is sent for type parameter
 *         compare function must take two CONST type pointers.
 *         If two struct that are pointed by pointers are equal,
 *         it should return zero, If first parameter is logically
 *         bigger than the second, it should return 1,
 *         returns -1 vice versa. Do NOT try to check if given pointers
 *         are NULL. There is no suitable return for this case.
 *
 *  cpy    [in] -> copy function for type which is send for type parameters
 *         copy function takes CONST type pointer and returns a pointer that
 *         points copy of the data which is pointed by the pointer that
 *         is taken as a parameter. If any error occurs, copy function
 *         should return NULL.
 *
 *  elemfr [in] -> free function for deallocate type structure. It should take
 *         a pointer of type and return nothing
 *
 *  prnt   [in] -> print function for an element of the list. The function
 *         is used debugging purposes. It should take a CONST pointer of
 *         type and return nothing.
 *
 * memalc  [in] -> memory allocation function. It allocated memory with
 *         given size, type of size_t.
 *
 * memfr   [in] -> memory free function frees memory that allocated with
 *         memalc function before.
 *
 */
#define tlist_source(type, name, cmp, cpy, elemfr, prnt, memalc, memfr)\
    \
    void init_##name##_list(t_##name##_list_t* tlp)\
    {\
        *tlp = NULL;\
    }\
    \
    \
    int add_to_##name##_list(t_##name##_list_t* tlp, const type* te)\
    {\
        t_##name##_list_t node;\
        t_##name##_list_t tmpl;\
        t_##name##_list_t tmplp;\
        \
        if ((!te) || (!tlp)) {\
            return (-1);\
        }\
        node = (t_##name##_list_t)memalc(sizeof(struct t_##name##_list_s));\
        if (!node) {\
            return (-1);\
        }\
        node->elem = cpy(te);\
        if (!(node->elem)) {\
            memfr(node);\
            return (-1);\
        }\
        node->next = NULL;\
        /* empty list */\
        if (!(*tlp)) {\
            *tlp = node;\
            return (0);\
        }\
        tmplp = NULL;\
        tmpl = *tlp;\
        while (tmpl && (cmp(tmpl->elem, te) < 0)) {\
            tmplp = tmpl;\
            tmpl  = tmpl->next;\
        }\
        if (!tmplp) {\
            tmplp = tmpl->next;\
            *tlp = node;\
        }\
        else {\
            tmplp->next = node;\
        }\
        node->next  = tmpl;\
        return (0);\
    }\
    \
    \
    size_t size_of_##name##_list(t_##name##_list_t tl)\
    {\
        size_t r_val;\
        for (r_val = 0; tl; ++r_val, tl = tl->next);\
        return r_val;\
    }\
    \
    \
    int delete_from_##name##_list(t_##name##_list_t* tlp, const type* te)\
    {\
        t_##name##_list_t tmpl;\
        t_##name##_list_t tmplp;\
        \
        if ((!te) || (!tlp)) {\
            return (-1);\
        }\
        tmplp = NULL;\
        tmpl = *tlp;\
        while (tmpl) {\
            if (!cmp(tmpl->elem, te)) {\
                /* first element */\
                if (!tmplp) {\
                    *tlp = tmpl->next;\
                }\
                else {\
                    tmplp->next = tmpl->next;\
                }\
                elemfr(tmpl->elem);\
                memfr(tmpl);\
                return (0);\
            }\
            tmplp = tmpl;\
            tmpl = tmpl->next;\
        }\
        return (-1); /* also fail */\
    }\
    \
    \
    const type* get_element_from_##name##_list(t_##name##_list_t tl, size_t order)\
    {\
        if (!tl) {\
            return (NULL);\
        }\
        while (tl && order) {\
            --order;\
            tl = tl->next;\
        }\
        return (tl->elem);\
    }\
    \
    \
    void free_##name##_list(t_##name##_list_t* tlp)\
    {\
        t_##name##_list_t tmpl;\
        while (*tlp) {\
            tmpl = (*tlp)->next;\
            elemfr((*tlp)->elem);\
            memfr((*tlp));\
            (*tlp) = tmpl;\
        }\
    }\
    \
    \
    const type* get_same_element_from_##name##_list(t_##name##_list_t tl, const type* te)\
    {\
        while(tl) {\
            if (!cmp(tl->elem, te)) {\
                return (tl->elem);\
            }\
            tl = tl->next;\
        }\
        return (NULL);\
    }\
    \
    \
    int get_index_of_element_from_##name##_list(t_##name##_list_t tl, const type* te)\
    {\
        int i = 0;\
        while (tl) {\
            if (!cmp(tl->elem, te)) {\
                return (i);\
            }\
            tl = tl->next;\
            ++i;\
        }\
        return (-1);\
    }\
    \
    \
    void print_##name##_list(t_##name##_list_t tl)\
    {\
        while(tl) {\
            prnt(tl->elem);\
            tl = tl->next;\
        }\
    }\
    \
    \
    t_##name##_list_t merge_##name##_lists(t_##name##_list_t tl1, t_##name##_list_t tl2)\
    {\
        t_##name##_list_t r_val;\
        init_##name##_list(&r_val);\
        while (tl1) {\
            if (add_to_##name##_list(&r_val, tl1->elem)) {\
                goto err;\
            }\
            tl1 = tl1->next;\
        }\
        while (tl2) {\
            if (add_to_##name##_list(&r_val, tl2->elem)) {\
                goto err;\
            }\
            tl2 = tl2->next;\
        }\
        return (r_val);\
    err:\
        free(r_val);\
        init_##name##_list(&r_val);\
        return (r_val);\
    }\
    \
    \

#endif /* _T_LIST_H_ */
