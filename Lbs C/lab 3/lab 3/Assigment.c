#include <math.h>
#include <stdio.h>

int main() {
    int Noa=0; int Noi=0;int NoO=0;int Noe=0; int Nou=0;
    char text[]="You don't know about me without you have read a book by the name of The Adventures of Tom Sawyer; but that ain't no matter";
    for(int i=0;text[i] !='\0';i++){
        if(text[i]=='a' ||text[i]=='A')
        Noa++;
        if(text[i]=='i' ||text[i]=='I')
        Noi++;
        if(text[i]=='O' ||text[i]=='o')
        NoO++;
        if(text[i]=='u' ||text[i]=='U')
        Nou++;
        if(text[i]=='E' ||text[i]=='e')
        Noe++;
    }
    printf("I:%d \tO:%d \tU:%d \tE:%d \tA:%d \t",Noi,NoO,Nou,Noe,Noa);


    return 0;
}
