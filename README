
README for tlist
----------------

		tlist is a template singly linked-list. It supports all functionality of a ordinary linked-list.
	All you have to do is that just implement sort of functions are responsible for fundamental operations
	of custom type. Here are these functions:

		* compare function:
			Compare function should take two const type pointer and compare them. If both are the same,
			the function returns zero "0". If the type of the first pointer points is greater then the
			second one logically, it returns 1, otherwise -1. You do not have to do null check for
			given pointers. Even if so, there is no sensible return value for it.
		
		* copy function:
			Copy function of custom type should take a const type pointer and return same of it. If any 
			error occurs during copy operation, it should return NULL pointer.
		
		* free function:
			Free function is used for deallocation for custom type. The type can include pointers. So,
			there would be problematic for memory considerations ( such as memory leaks). The function
			should take pointer type and frees this pointer gracefully.
		
		* print function:
			Print function takes a pointer type and print this structure into output. Output is redirected
			to STDOUT by default. If you think this function is unnecessary, do not put anything on it's
			body.
	
		After you implement these function above, you can create your own linked-list by calling declarator
	macro like this:
		
		E.g
			tlist(my_type_t, my, cmp_my_type, cpy_my_type, free_my_type, print_my_type)

		First parameter of the macro must be your custom type, second is up to you.
		


	Best regards.
	Mustafa CAMURLI

		
		
	
