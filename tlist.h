
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
 *	Mustafa CAMURLI - mustafacamurli@gmail.com
 *	Fri Nov 19, 2010
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

#ifndef _T_LIST_H_
#define _T_LIST_H_

#include <stdio.h>

/**
 * @description:
 *	singly-linked list declarator macro
 *
 * @parameters
 * 	type [in] -> name of type of structure
 *		 struct my_def_s or my_def_t is OKAY.
 * 
 * 	name [in] -> name of new module, should be uniqe
 *		 if you send MyType, the name of the function adds a element
 *		 into the list would be add_MyType_list.
 *
 * 	cmp  [in] -> compare function for type which is sent for type parameter
 *		 compare function must take two CONST type pointers.
 *		 If two struct that are pointed by pointers are equal,
 *		 it should return zero, If first parameter is logically
 *		 bigger than the second, it should return 1,
 *		 returns -1 vice versa. Do NOT try to check if given pointers
 *		 are NULL. There is no suitable return for this case.
 *
 *	cpy  [in] -> copy function for type which is send for type parameters
 *		 copy function takes CONST type pointer and returns a pointer that
 *		 points copy of the data which is pointed by the pointer that
 *       is taken as a parameter. If any error occurs, copy function
 *		 should return NULL.
 *
 *  fr   [in] -> free function for deallocate type structure. It should take
 *       a pointer of type and return nothing
 *
 *  prnt [in] -> print function for an element of the list. The function
 *       is used debugging purposes. It should take a CONST pointer of
 *       type and return nothing.
 *
 * @limitations
 *	+)	type has to have a next variables that is supposed to
 *		point next node.
 *
 * #######################################################################
 *
 * @Application Programmer Interface
 *
 * 	+) void init_##name##_list(t_##name##_list_t*)
 *
 *
 * 	+) const type* add_to_##name##_list(t_##name##_list_t*, const type*)
 *
 * 	+) size_t size_of_##name##_list(t_##name##_list_t)
 *
 * 	+) int delete_from_##name##_list(t_##name##_list_t*, const type*)
 *
 * 	+) const type* get_element_from_##name##_list(t_##name##_list_t, size_t)
 *
 * 	+) void free_##name##_list(t_##name##_list_t*)
 *
 * 	+) const type* get_same_element_from_##name##_list(t_##name##_list_t, const type*)
 *
 * 	+) int get_index_of_element_from_##name##_list(t_##name##_list_t, const type*)
 *
 * 	+) void print_##name##_list(t_##name##_list_t)
 *
 * 	+) t_##name##_list_t merge_##name##_lists(t_##name##_list_t, t_##name##_list_t)
 *
*/

#define tlist_header(type,name,cmp,cpy,fr,prnt)\
	\
	/**
	 * @description:
	 *	template list custom type
	*/\
	typedef struct t_##name##_list_s t_##name##_list_t;\
	struct t_##name##_list_s {\
		type* head;\
	};\
	\
	\
	/**
	 * @description:
	 * 	initialize template list
	 *
	 * @parameters:
	 * 	tlp [in] -> template list pointer
	 *
	 * @return
	 *	nothing
	*/\
	void init_##name##_list(t_##name##_list_t* tlp);\
	\
	\
	/**
	 * @description:
	 * 	adds the given element into the given list
	 *
	 * @parameters
	 * 	tlp [in] -> template list pointer
	 * 	te  [in] -> pointer of new element
	 *
	 * @return
	 *  added element if successful, NULL otherwise.
	 *
	 * @warnings
	 *   + new data'll be pointed with a new internal
	 *     pointer. te'll be no longer required for the list.
	 *
	*/\
	const type* add_to_##name##_list(t_##name##_list_t* tlp, const type* te);\
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
	 *   tlp [in] -> template list pointer
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
	*/\
	t_##name##_list_t merge_##name##_lists(t_##name##_list_t tl1, t_##name##_list_t tl2);\
	\
	\

#define tlist_source(type,name,cmp,cpy,fr,prnt)\
	\
	void init_##name##_list(t_##name##_list_t* tlp)\
	{\
		if (tlp) {\
			tlp->head = NULL;\
		}\
	}\
	\
	\
	const type* add_to_##name##_list(t_##name##_list_t* tlp, const type* te)\
	{\
		type* tmp = NULL;\
		type* prev = NULL;\
		type* head = NULL;\
		if ((!te)||(!tlp))\
			return NULL;\
		head = tlp->head;\
		while(head && (cmp(head,te)<0)) {\
			prev = head;\
			head = head->next;\
		}\
		/* same element can't be added.*/\
		if (head && !cmp(head,te))\
			return NULL;\
		tmp = cpy(te);\
		if (!tmp)\
			return NULL;\
		/* head of the list */\
		if (!prev) {\
			tmp->next = tlp->head;\
			tlp->head = tmp;\
		}\
		else {\
			prev->next = tmp;\
			tmp->next = head;\
		}\
		return tmp;\
	}\
	\
	\
	size_t size_of_##name##_list(t_##name##_list_t tl)\
	{\
		size_t r_val;\
		for (r_val=0; tl.head; ++r_val,\
			tl.head = tl.head->next);\
		return r_val;\
	}\
	\
	\
	int delete_from_##name##_list(t_##name##_list_t* tlp, const type* te)\
	{\
		type* head = NULL;\
		type* prev = NULL;\
		if ((!te)||(!tlp))\
			return -1;\
		head = tlp->head;\
		while (head) {\
			if (!cmp(head,te)) {\
				/* first element */\
				if (!prev) {\
					prev = head->next;\
					fr(head); \
					tlp->head = prev;\
				}\
				else {\
					prev->next = head->next;\
					fr(head); \
				}\
				return 0;\
			}\
			prev = head;\
			head = head->next;\
		}\
		return -1; /* also fail */\
	}\
	\
	\
	const type* get_element_from_##name##_list(t_##name##_list_t tl, size_t order)\
	{\
		while (tl.head && order) {\
			--order;\
			tl.head = tl.head->next;\
		}\
		return tl.head;\
	}\
	\
	\
	void free_##name##_list(t_##name##_list_t* tlp)\
	{\
		type* temp;\
		if (!tlp) {\
			return;\
		}\
		while (tlp->head) {\
			temp = tlp->head;\
			tlp->head = tlp->head->next;\
			fr(temp); \
		}\
	}\
	\
	\
	const type* get_same_element_from_##name##_list(t_##name##_list_t tl, const type* te)\
	{\
		while(tl.head) {\
			if (!cmp(tl.head,te)) {\
				return tl.head;\
			}\
			tl.head = tl.head->next;\
		}\
		return NULL;\
	}\
	\
	\
	int get_index_of_element_from_##name##_list(t_##name##_list_t tl, const type* te)\
	{\
		int i = 0;\
		while(tl.head) {\
			if (!cmp(tl.head,te)) {\
				return i;\
			}\
			tl.head = tl.head->next;\
			++i;\
		} \
		return -1;\
	}\
	\
	\
	void print_##name##_list(t_##name##_list_t tl)\
	{\
		while(tl.head) {\
			prnt(tl.head);\
			tl.head = tl.head->next;\
		}\
	}\
	\
	\
	t_##name##_list_t merge_##name##_lists(t_##name##_list_t tl1, t_##name##_list_t tl2)\
	{\
		t_##name##_list_t r_val;\
		init_##name##_list(&r_val);\
		while(tl1.head) {\
			add_to_##name##_list(&r_val,tl1.head);\
			tl1.head = tl1.head->next;\
		}\
		while(tl2.head) {\
			add_to_##name##_list(&r_val,tl2.head);\
			tl2.head = tl2.head->next;\
		}\
		return r_val;\
	}\
	\
	\


#endif /* _T_LIST_H_ */
