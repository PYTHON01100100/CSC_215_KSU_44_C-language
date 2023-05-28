#include<stdio.h>
#include <string.h>
#include <stdlib.h>


char *replace_the(char* orig){
int count = 0, countV =0;
	char *p;
 for(p =orig; p != NULL && *p != '\0'; p++){
	p= strstr(p, "the");

	if(p != NULL ){
		if(*(p-1) == ' ' && *(p+3)== ' '){
		count++;
		if(*(p+4) == 'a' || *(p+4) == 'e' || *(p+4) == 'i' || *(p+4) == 'o' || *(p+4) == 'u' )
			countV++;
}
else 
	continue;
}
	else
		break;
}

int delta = strlen(orig)-(3*count)+(2*countV)+(count-countV);

char *result= (char*)malloc((delta*sizeof(char)));
if(result == NULL)
	return NULL;

int i=0;

if(*(orig) == 't' && *(orig+1) == 'h' && *(orig+2) == 'e' && *(orig+3) ==' '){
	if(*(orig+4) == 'a' ||*(orig+4) == 'e' ||*(orig+4) == 'i' ||*(orig+4) == 'o' ||*(orig+4) == 'u' ){
		strcpy(result, "an ");
	i+=3;
	result[i] ='\0';
	orig += 4;
} else {
	strcpy(result, "a ");
	i+= 2;
	orig += 4;
	result[i] ='\0';
}
	}

while(strstr(orig, "the")){
	char * theOcc = strstr(orig, "the");
if(*(theOcc-1) == ' ' && *(theOcc+3) == ' '){

	int diff = theOcc-orig;
	strncpy(result+i, orig, diff);
	i+= diff;
	if(*(theOcc+4) == 'a' ||*(theOcc+4) == 'e' ||*(theOcc+4) == 'i' ||*(theOcc+4) == 'o' ||*(theOcc+4) == 'u'){
		strcpy(result+i, "an ");
		i+= 3;
		orig+= diff+4;
		result[i] ='\0';}
	else{
		strcpy(result+i, "a ");
		i+= 2;
		orig+= diff+4;
		result[i] ='\0';}
}
else{
	int diff = (theOcc-orig)+3;
	strncpy(result+i, orig, diff);
	i+= diff;
	orig+= diff;
	continue;}
}
	
strcat(result,orig);
return result;

}


int main(){
	char* str= "the ant cant breathe the air under the sky there is the sunshine!";
	printf("BEFORE: %s \n=============================\n", str);
	printf("AFTER: %s",replace_the(str));
	
return 0;
}