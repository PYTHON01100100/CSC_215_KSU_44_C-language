#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myfuncs.h"

int main(){
	char sentence[256]; 
	int n,n2,n3;

	printf("Testing I.1: word_wrap function: \n");
	
    printf("Enter sentence: \n");
    fgets(sentence,sizeof(sentence),stdin);
	printf("Enter width: \n");
	scanf("%d", &n);
	printf("%s\n\n", word_wrap(sentence, n)) ;
	////////////////////////////////////////////////
	printf("Testing I.4: implode function: \n");
	
	printf("Enter number of pieces: \n");
    scanf("%d", &n);
	char *pieces[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter piece #%d: \n",i+1);
		fgets(pieces[i],sizeof(pieces[i]),stdin);
	}
	char glue[50]; 
	printf("Enter glue: \n");
	fgets(glue,sizeof(glue),stdin);
	printf("%s\n\n", implode(glue, pieces, n));
	////////////////////////////////////////////////
	printf("Testing I.6: make_pw function: \n");
	
	printf("Enter size: \n");
	scanf("%d", &n);
	printf("Enter 1 If least one digit, 0 then digits are optional: \n");
	scanf("%d", &n2);
	printf("Enter 1 If mix letters of different cap cases, 0 then is optional: \n");
	scanf("%d", &n3);
	srand(time(NULL));
	printf("%s\n\n", make_pw(n, n2, n3));
	////////////////////////////////////////////////
	linkedlist* l=(linkedlist*)calloc(sizeof(linkedlist),1);
	while(true){
		printf("Enter integer to add to the linked list (enter -1 to stop adding): \n");
		scanf("%d", &n);
		if(n==-1)
			break;
		node* no = (node*)calloc(sizeof(node),1);
		no->data = n;
		node* p = l->head;
		if (!p) 
			l->head = no;
		else {
			while (p->next) p=p->next;
			p->next = no;
		}
	}
	////////////////////////////////////////////////
	printf("printing list...\n");
	print_list(*l);
	////////////////////////////////////////////////
	printf("Testing II.1: delete_from_i function: \n");
	printf("Enter index to delete from it: \n");
	scanf("%d", &n);
	delete_from_i(*l, n);
	printf("printing list after delete...\n");
	print_list(*l);
	////////////////////////////////////////////////
	printf("Testing II.2: delete_duplicates function: \n");
	delete_duplicates(*l);
	printf("printing listafter delete duplicates...\n");
	print_list(*l);
	////////////////////////////////////////////////
	printf("Testing II.3: rev_list function: \n");
	linkedlist* l2 = rev_list(*l);
	printf("printing reversed list...\n");
	print_list(*l2);
  return 0;
}