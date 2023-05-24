#include <stdlib.h>
#include <stdio.h>
#include "mybmp.h"
Pixel** initialize_pixels(int h, int w){
int i, j;
Pixel** result = (Pixel**)malloc(h*sizeof(Pixel*));
for (i=0; i < h; i++){
result[i] = (Pixel*)malloc(w*sizeof(Pixel));
for (j=0; j< w; j++){
result[i][j].blue = rand()%255;
result[i][j].green = rand()%255;
result[i][j].red = rand()%255;
}
}
return result;
}
Pixel** initialize_pixels_linear_interpolation(int h, int w){
int MAX_COLOR = 255;
int i, j, sj, si, sij, x0 = 0, x1 = MAX_COLOR, y0 = 0, y1 = MAX_COLOR;
Pixel** result = (Pixel**)malloc(h*sizeof(Pixel*));
for (i=0; i < h; i++){
result[i] = (Pixel*)malloc(w*sizeof(Pixel));
si = i*MAX_COLOR/(h-1);
for (j=0; j< w; j++){
sj = j*MAX_COLOR/(w-1);
sij = ((i+j)/2)*MAX_COLOR/((w+h-2)/2);
result[i][j].red = y0 + (sj-x0)*((y1-y0)/(x1-x0));
result[i][j].green= y0 + (si-x0)*((y1-y0)/(x1-x0));
result[i][j].blue = y0 + (sij-x0)*((y1-y0)/(x1-x0));
}
}
return result;
}
int main(){
FileHead fh;
ImageHead ih;
fh.format[0] = 'B';
fh.format[1] = 'M';
fh.file_size = sizeof(FileHead)+sizeof(ImageHead); /* add pixel size later*/
fh.reserved = 0;
fh.pixel_offset = sizeof(FileHead)+sizeof(ImageHead);
ih.header_size = 40; /* set to 40 */
ih.image_width = 500;
ih.image_height = 500;
ih.num_of_planes = 1; /* set to 1 */
ih.bits_per_pixel = 24; /* set to 24 */
ih.compression = 0; /* set to 0 */
/* image_height*(image_width*3 + delta) */
ih.raw_pixel_size = ih.image_height*(ih.image_width*3 + 0);
ih.h_resolution = 2835; /* set to 2835 */
ih.v_resolution = 2835; /* set to 2835 */
ih.num_of_colors = 0; /* set to 0 */
ih.important_colors = 0; /* set to 0 */
fh.file_size += sizeof(Pixel)*ih.image_height*ih.image_width;
Pixel **pixels;
puts("initialize_pixels");
pixels = initialize_pixels_linear_interpolation(ih.image_height, ih.image_width);
puts("save_image");
save_image("image.bmp", &fh, &ih, pixels);
return 0;
}