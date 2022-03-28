#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
  float red;
  float green;
  float blue;
  float alpha;

  Color();
  Color(float red, float green, float blue, float alpha);
  ~Color();

  Color operator+ (const Color &color);
  Color operator+ (const float num);
  Color operator- (const Color &color);
  Color operator* (const Color &color);
  Color operator* (const float num);
  Color operator/ (const Color &color);
  void operator= (const Color &color);
  float GetLuminance();
};

#endif
