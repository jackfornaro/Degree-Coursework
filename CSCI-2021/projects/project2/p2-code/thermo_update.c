#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "thermo.h"

int set_temp_from_ports(temp_t *temp){
  //error checking if a legal temperature
  if(THERMO_SENSOR_PORT > 64000){
    return 1;
  }
  //temporary temp tracking THERMO_SENSOR_PORT/64,
  //as we are counting in tenths not ones
  int tempTemp = (THERMO_SENSOR_PORT / 64);
  //remainder value, telling us if we must add .1 or continue
  int rem = THERMO_SENSOR_PORT % 64;
  if(rem > 31){
    tempTemp++;
  }
  //offset current temperature to -50.0 degrees celcius
  tempTemp = tempTemp - 500;
  int mask = 0b0001;
  //fahrenheit case
  if(THERMO_STATUS_PORT & mask){
    //error check for fahrenheit by checking if
    //the temperature is out of bounds
    if(tempTemp < -580 || tempTemp > 1220){
      return 1;
    }
    temp->is_fahrenheit = 1;
    temp->tenths_degrees = (tempTemp * 90) / 50 + 320;
  }
  //celcius case
  else{
    //error check for celcius by checking if
    //the temperature is out of bounds
    if(tempTemp < -500 || tempTemp > 500){
      return 1;
    }
    temp->is_fahrenheit = 0;
    temp->tenths_degrees = tempTemp;
  }
  return 0;
}

int set_display_from_temp(temp_t temp, int *display){
  //set initial display
  *display = 0; //32 zeros
  //error checking the if temp.is_fahrenheit is out of bounds
  if(temp.is_fahrenheit < 0 || temp.is_fahrenheit > 1){
    *display = 0b11111111111111111111111111111111;
    return 1;
  }
  //error checking if temp.tenths_degrees is out of bounds for fahrenheit
  if(temp.is_fahrenheit == 1){
    if(temp.tenths_degrees < -580 || temp.tenths_degrees > 1220){
      *display = 0b11111111111111111111111111111111;
      return 1;
    }
  }
  //error checking if temp.tenths_degrees is out of bounds for celcius
  if(temp.is_fahrenheit == 0){
    if(temp.tenths_degrees < -500 || temp.tenths_degrees > 500){
      *display = 0b11111111111111111111111111111111;
      return 1;
    }
  }

  int neg = 0b0000001;
  int far = 0b10;
  int cel = 0b01;
  int zero = 0b1111110;
  int one = 0b0001100;
  int two = 0b0110111;
  int three = 0b0011111;
  int four = 0b1001101;
  int five = 0b1011011;
  int six = 0b1111011;
  int seven = 0b0001110;
  int eight = 0b1111111;
  int nine = 0b1011111;

  //creating a mask array of integers in binary
  int maskArray[10] = {zero, one, two, three, four,
                       five, six, seven, eight, nine};

  int iterator = temp.tenths_degrees;
  //if the temp is negative, change the iterator to negative
  if(temp.tenths_degrees < 0){
    iterator = -iterator;
  }
  //system that returns the digit of the _____'s place (tens, ones, etc)
  int temp_tenths = iterator % 10;
  iterator = iterator / 10;
  int temp_ones = iterator % 10;
  iterator = iterator / 10;
  int temp_tens = iterator % 10;
  iterator = iterator / 10;
  int temp_hundreds = iterator % 10;

  //setting the digits in binary to each _____'s place
  int bit_hundreds = maskArray[temp_hundreds];
  int bit_tens = maskArray[temp_tens];
  int bit_ones = maskArray[temp_ones];
  int bit_tenths = maskArray[temp_tenths];

  //always have the two leading digits be 00
  *display = *display | 0<<30;
  //negative temp case
  if(temp.tenths_degrees < 0){
    if(temp_hundreds == 0 && temp_tens == 0){
      *display = *display | neg<<14;
    }
    if(temp_hundreds == 0 && temp_tens != 0){
      *display = *display | bit_tens<<14;
      *display = *display | neg<<21;
    }
  }
  //positive temp case
  else{
    if(temp_hundreds != 0){
      *display = *display | bit_hundreds<<21;
    }
    if(temp_hundreds != 0 || temp_tens != 0){
      *display = *display | bit_tens<<14;
    }
  }
  *display = *display | bit_ones<<7;
  *display = *display | bit_tenths;

  //shifting over the correct bits, determined by temp.is_fahrenheit
  if(temp.is_fahrenheit == 0){
    *display = *display | cel<<28;
  }
  else{
    *display = *display | far<<28;
  }
  return 0;
}

int thermo_update(){
  //creating a temp_t
  temp_t temp;
  //error checking if set_temp_from_ports returns 1 (error value)
  if(set_temp_from_ports(&temp) == 1){
    return 1;
  }
  else{
    //sets the display with the given temperature and the address of THERMO_DISPLAY_PORT
    set_display_from_temp(temp, &THERMO_DISPLAY_PORT);
  }
  return 0;
}
