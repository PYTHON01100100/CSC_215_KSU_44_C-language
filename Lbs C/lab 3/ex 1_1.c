#include <stdio.h>


int main() {

printf("enter text >>");

char text[100];

gets(text);

char diff ='a' - 'A';

for(int i=0;text[i] !='\0';i++){
    if(i==0){
        if(text[i]>='a'&&text[i]<='z')
        text[i]=text[i]-diff;
    }
    else{
        if(text[i-1]==' '){
        if(text[i]>='a'&&text[i]<='z')
        text[i]=text[i]-diff;
        }
        else{
            if(text[i]>='A'&&text[i]<='Z')
            text[i]=text[i]+diff;
           
        }
    }


}


printf("the result : %s",text);


return 0;

}