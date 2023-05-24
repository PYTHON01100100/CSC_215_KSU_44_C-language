#include<stdio.h>
#include<stdlib.h>
#include"mybmp.h"

//
Pixel**  create_pixels(int h, int w){
    int i; Pixel** result=(Pixel**)malloc(h*sizeof(Pixel*));
    if(result==NULL){printf("Error mallo\n"); exit(0);}
    for(i=0;i<h;i++){
        result[i]=(Pixel*)calloc(w,sizeof(Pixel));
        if(result[i]==NULL){printf("Error callo\n"); exit(0);} }
        return result; }
Pixel** load_image(char* filename, FileHead* fHead, ImageHead* iHead){ 
    FILE *file=fopen(filename,"rb");
    if(file==NULL){printf("Error opening File (%s)\n",filename); return NULL;}
    /*puts("fread FHead");*/ fread(fHead,sizeof(FileHead),1,file);
    /*puts("fread iHead");*/ fread(iHead,sizeof(ImageHead),1,file);
    /*puts("create_pixels");*/ Pixel** image=create_pixels(iHead->image_height,iHead->image_width);
    /*puts("read pixels");*/
    for(int i=0;i<iHead->image_height;i++){fread(image[i],sizeof(Pixel),iHead->image_width,file);}
    fclose(file); return image;}
void make_gray(Pixel** image,int height, int width, Channel color){int i,j;
for(i=0;i<height;i++){
    for(j=0;j<width;j++){
        switch (color){
            case cRED: image[i][j].blue=image[i][j].green=image[i][j].red; break;
            case cGREEN: image[i][j].blue=image[i][j].red=image[i][j].green; break;
            case cBLUE: image[i][j].red=image[i][j].green=image[i][j].blue; break;
        }
    }
}
}
void redify(Pixel** image, int height,int width){int i ,j;
for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      image[i][j].blue*=0.5; image[i][j].green*=0.5;
      char tr=image[i][j].red+(255-image[i][j].red)/2;
      image[i][j].red=image[i][j].red<tr?tr:255;}}
}
int save_image(char* filename, FileHead* fHead,ImageHead* iHead,Pixel** image){
     FILE *file=fopen(filename,"wb");
     if(file==NULL){printf("Error opening File (%s)\n",filename); return 0;}
     fwrite(fHead,sizeof(FileHead),1,file); fwrite(iHead,sizeof(ImageHead),1,file);
     for(int i=0;i<iHead->image_height;i++){ fwrite(image[i],sizeof(Pixel),iHead->image_width,file);}
     fclose(file); return 0;
}
void mirror(Pixel** image, int height, int width) {
    int i, j;
    Pixel temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}