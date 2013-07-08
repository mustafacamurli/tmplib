

#include <stdio.h>
#include <stdlib.h>

#include "tlist.h"


#define LOAD	(20)

typedef struct my_type_s my_type_t;

struct my_type_s {
	char* cp;
	struct my_type_s* next;
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
	r_val->next  = NULL;
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

tlist_header(my_type_t,my,cmp_my_type,cpy_my_type,free_my_type,print_my_type)
tlist_source(my_type_t,my,cmp_my_type,cpy_my_type,free_my_type,print_my_type)

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
	r_val->next  = NULL;
	return r_val;
}

int main()
{
	int i,k;
	t_my_list_t list;
	my_type_t* temp;
	
	init_my_list(&list);
	
	srand(time(0));
	
	k = 0;
	
	fprintf(stderr,"trying to add %d element\n",LOAD);
	for (i=0; i<LOAD; ++i) {
		temp = generate_my_type();
		if (!temp)
			continue;
		if (!add_to_my_list(&list,temp))
			fprintf(stderr,"element exist or internal error\n");
		else
			++k;
		free(temp);
	}
	
	fprintf(stderr,"list size should be %d\n",k);
	fprintf(stderr,"size: %d\n",size_of_my_list(list));
	
	fprintf(stderr,"modifying an element\n");
	*(get_element_from_my_list(list,0)->cp) = 'Z';
	
	fprintf(stderr,"deleting an element\n");
	delete_from_my_list(&list,get_element_from_my_list(list,0));
	
	fprintf(stderr,"size: %d\n",size_of_my_list(list));
	
	fprintf(stderr,"delete whole list\n");
	free_my_list(&list);
	
	fprintf(stderr,"size: %d\n",size_of_my_list(list));
	
	return 0;
}














