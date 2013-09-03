

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tlist.h"
#include "tstack.h"


#define TLIST_LOAD (20)
#define TSTACK_LOAD (20)

typedef struct my_type_s my_type_t;

struct my_type_s {
    char* cp;
};

int cmp_my_type(const my_type_t* t1, const my_type_t* t2)
{
    return *(t1->cp)>*(t2->cp)?1:
            (*(t1->cp)==*(t2->cp)?0:-1);
}

my_type_t* cpy_my_type(const my_type_t* t)
{
    my_type_t* r_val;
    r_val = (my_type_t*)malloc(sizeof(my_type_t));
    if (!r_val) {
        return NULL;
    }
    r_val->cp = (char*)malloc(sizeof(char));
    if (!(r_val->cp)) {
        free(r_val);
        return NULL;
    }
    *(r_val->cp) = *(t->cp);
    return r_val;
}

void free_my_type(my_type_t* t)
{
    free(t->cp);
}

void print_my_type(const my_type_t* t)
{
    /* nothing */;
}

my_type_t* generate_my_type()
{
    my_type_t* r_val;
    r_val = (my_type_t*)malloc(sizeof(my_type_t));
    if (!r_val) {
        return NULL;
    }
    r_val->cp = (char*)malloc(sizeof(char));
    if (!(r_val->cp)) {
        free(r_val);
        return NULL;
    }
    *(r_val->cp) = (rand()%26)+'A';
    return r_val;
}

tlist_header(my_type_t, my)
tlist_source(my_type_t, my, cmp_my_type, cpy_my_type, free_my_type, print_my_type, malloc, free)


tstack_header(my_type_t, my)
tstack_source(my_type_t, my, cpy_my_type, free_my_type, malloc, free)

void tlist_test()
{
    int i,k;
    t_my_list_t list;
    my_type_t* temp;
    
    k = 0;
    srand(time(0));
    
    init_my_list(&list);
    
    for (i = 0; i < TLIST_LOAD; ++i) {
        
        temp = generate_my_type();
        if (!temp) {
            continue;
        }
        
        assert(add_to_my_list(&list,temp) == 0);
        free(temp);
        ++k;
    }
    
    assert(size_of_my_list(list) == k);
    assert(delete_from_my_list(&list,get_element_from_my_list(list,0)) == 0);
    assert(size_of_my_list(list) == (k - 1));
    free_my_list(&list);
    assert(size_of_my_list(list) == 0);
}

void tstack_test()
{
    int i;
    t_my_stack_t stack;
    my_type_t* temp;
    
    srand(time(0));
    
    init_my_stack(&stack);
    
    for (i = 0; i < TSTACK_LOAD; ++i) {
        temp = generate_my_type();
        
        if (!temp) {
            continue;
        }
        
        assert(push_element_into_my_stack(&stack, temp) != NULL);
        assert(cmp_my_type(peek_element_from_my_stack(stack), temp) == 0);
        
        free(temp);
    }
    
    pop_element_from_my_stack(&stack);
    free_my_stack(&stack);
}

int main()
{
    tlist_test();
    tstack_test();
    printf("\"too good to be true\".\n");
    return 0;
}














