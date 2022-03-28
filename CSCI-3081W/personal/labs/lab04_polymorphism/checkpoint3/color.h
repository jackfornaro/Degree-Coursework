#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
  float red;
  float green;
  float blue;
  float alpha;
  Color();
  Color(float r, float g, float b, float a);
  Color operator+(Color color);
  Color operator-(Color color);
  Color operator*(float scal);
  Color operator/(float scal);
};

#endif
