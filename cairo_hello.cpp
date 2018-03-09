#include <cairo/cairo.h>
#include <iostream>
#include <string>

using std::string;
using namespace std;

int main(int argc, char* argv[]) {
  int x,y,width,height;         
  float size_font;              
 
  x = 20;                       
  y = 20;                       
  width = 800;                  
  height = 800;                  
  string file_path(argv[1]);    
 
  cairo_surface_t *surface;     
  cairo_t *cr;                  

  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
  cr = cairo_create (surface);
 
  cairo_text_extents_t te;
  cairo_set_line_width (cr, 1.0);

  // BG
  cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
  cairo_rectangle(cr, 0, 0, width, height);
  cairo_fill(cr);

  for(int i=10; i<=width-40; i+=40) {
    for(int j=10; j<=height-40; j+=40) {
      int color_choice = rand() % 3 + 1;

      if(color_choice==1) {
  	cairo_set_source_rgb (cr, 0.0, 0.0, 0.5);
      } else if(color_choice==2) {
  	cairo_set_source_rgb (cr, 0.0, 0.5, 0.5);
      } else {
  	cairo_set_source_rgb (cr, 0.8, 0.5, 0.5);
      }

      cairo_rectangle(cr, i, j, 30.0, 30.0);
      cairo_fill(cr);
    }
  }
  cairo_surface_write_to_png(surface , file_path.c_str());

  return 0;
}
