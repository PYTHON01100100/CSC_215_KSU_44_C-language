#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncs.h"

//part I:
//I.2
char* word_wrap(char* orig, int width){
	char* result = (char*)calloc(strlen(orig)+1, 1);
	strcpy(result, orig);
	if(strlen(orig)<width)
		return result;
	int i =0, count=1;
	while(result[i]!='\0'){
		if(count == width+1){
			count = i;
			while(result[count]!=' ')
				count--;
			result[count]='\n';
			i = count;
			count =0;
		}
		count++;
		i++;
	}
	return result;
}
//I.4
char* implode(char* glue, char** pieces, int count){
	int total = 0, i = 0;
	for (i = 0; i < count; i++)
		total += strlen(pieces[i]);
	total += strlen(glue) * (count - 1);
	char* result = (char*) calloc(total+1,1);
	for (i = 0; i < count; i++) {
        strcat(result, pieces[i]);
        if (i < (count - 1))
			strcat(result, glue);
    }
	return result;
}

//I.6 auxiliary functions
char random_dig(){
	return '0' + (rand() % 10);
}
char random_letter(){
	return 'a' + (rand() % 26);
}
char random_Cletter(){
	return 'A' + (rand() % 26);
}
//I.6
char* make_pw(int min_size, int dig, int mix_cap){
	char* result = (char*)calloc(min_size+1,1);
	int i, r;
	r = rand()%2;
	switch(r){
		case '0' : result[(rand()%min_size)] = random_letter();
		   break;
		case '1' : result[(rand()%min_size)] = random_Cletter();
		   break;
		default  : break;
	}
	if(dig==1)
		while(result[r = (rand()%min_size)] != '\0');
		result[r] = random_dig();
	for(i=0; i<min_size;i++){
		if(result[i] != '\0'){
			r = rand()%3;
			switch(r){
				case '0' : result[i] = random_dig();
                   break;
				case '1' : result[i] = random_letter();
                   break;
				case '2' : result[i] = random_Cletter();
                   break;
				default  : break;
			}
		}
	}
	if(mix_cap==1){
		int even = 0;
		for(i=0; i<min_size;i++){
			if((result[i]>='a' && result[i]<='z') || (result[i]>='A' && result[i]<='Z')){
				if((even%2)==0){
					if(result[i]>='a' && result[i]<='z')
						result[i]-= 'a' - 'A';
					even++;
				}
				else{
					if(result[i]>='A' && result[i]<='Z')
						result[i]+= 'a' - 'A';
					even++;
				}
			}
		}
	}
	return result;
}

//part II:
//II.1
void delete_from_i(linkedlist ll, int i){
	node* prev = NULL;
	node* cur = ll.head;
	int count = 0;
	while (cur != NULL && count != i) {
		prev=cur;
		cur=cur->next;
	}
	if (cur != NULL) {
		if (prev == NULL)
			ll.head=cur->next;
		else
			prev->next=cur->next;
		free(cur);
	}
}

//II.2
int delete_duplicates(linkedlist ll){
	node *p1, *p2, *temp;
	int count = 0;
	p1 = ll.head;
	if(p1 != NULL)
		return 0;
	while(p1->next != NULL){
		p2=p1;
		while(p2->next != NULL){
			if(p1->data == p2->next->data){
				temp = p2->next;
				p2->next = p2->next->next;
				free(temp);
				count++;
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}
	return count;
}

//II.3
linkedlist* rev_list(linkedlist ll){
	linkedlist* l2=(linkedlist*)calloc(sizeof(linkedlist),1);
	node* p= ll.head;
	while(p){
		node* n = (node*)calloc(sizeof(node),1);
		n->data = p->data;
		n->next = l2->head;
		l2->head = n;
		p=p->next;
	}
	return l2;
}

//print
void print_list(linkedlist ll){
	node* p = ll.head;
	while(p){
		printf("%d-", p->data);
		p = p->next;
	}
	printf("|\n");
}