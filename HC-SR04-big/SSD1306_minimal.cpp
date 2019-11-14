/*

  SSD1306_minimal.h - SSD1306 OLED Driver Library
  2015 Copyright (c) CoPiino Electronics All right reserved.
  
  Original Author: GOF Electronics Co. Ltd.
  Modified by: CoPiino Electronics ( http://copiino.cc ) 
  
  CoPiino Electronics invests time and resources providing this open source code, 
	please support CoPiino Electronics and open-source hardware by purchasing 
	products from CoPiino Electronics!
  
  What is it?	
    This library is derived from GOFi2cOLED library, only for SSD1306 in I2C Mode.
    As the original library only supports Frame Buffered mode which requires to have
    at least 1024bytes of free RAM for a 128x64px display it is too big for smaller devices.
    
    So this a SSD1306 library that works great with ATTiny85 devices :)
    
  
  It is a free software; you can redistribute it and/or modify it 
  under the terms of BSD license, check license.txt for more information.
	All text above must be included in any redistribution.
*/

#include "SSD1306_minimal.h"

// a 5x7 font table
const unsigned char  BasicFont[] PROGMEM = {
};


unsigned char SSD1306_Mini::getFlash( const unsigned char * mem, unsigned int idx  ){
  unsigned char data= pgm_read_byte( &(mem[idx]) );
  return data;

}
 
void SSD1306_Mini::sendCommand(unsigned char command)
{
  Wire.begin();                       //initialize I2C
  Wire.beginTransmission(SlaveAddress); // begin I2C communication

  Wire.send(GOFi2cOLED_Command_Mode);	     // Set OLED Command mode
  Wire.send(command);

  Wire.endTransmission();    		     // End I2C communication
}

void SSD1306_Mini::sendData(unsigned char Data)
{
  Wire.begin();                    //initialize I2C
  Wire.beginTransmission(SlaveAddress); // begin I2C transmission
  Wire.send(GOFi2cOLED_Data_Mode);            // data mode
  Wire.send(Data);
  Wire.endTransmission();                    // stop I2C transmission
}

void SSD1306_Mini::init(uint8_t address)
{
  
 Wire.begin();
 
 delay(5);	//wait for OLED hardware init
// constructor(128, 32);
 //SlaveAddress = address;

 sendCommand(GOFi2cOLED_Display_Off_Cmd);    /*display off*/

 sendCommand(Set_Multiplex_Ratio_Cmd);    /*multiplex ratio*/
// sendCommand(0x3F);    /*duty = 1/64*/
 sendCommand(0x1F);    /*duty = 1/32*/

 sendCommand(Set_Display_Offset_Cmd);    /*set display offset*/
 sendCommand(0x00);


    sendCommand(Set_Memory_Addressing_Mode_Cmd); 	//set addressing mode
    sendCommand(HORIZONTAL_MODE); 			//set horizontal addressing mode

 sendCommand(0xB0); 			//set page address
 sendCommand(0x00); 	//set column lower address
 sendCommand(0x10); 	//set column higher address

    

 sendCommand(0x40);    /*set display starconstructort line*/

 sendCommand(Set_Contrast_Cmd);    /*contract control*/
 sendCommand(0xcf);    /*128*/

 sendCommand(Segment_Remap_Cmd);    /*set segment remap*/

 sendCommand(COM_Output_Remap_Scan_Cmd);    /*Com scan direction*/

 sendCommand(GOFi2cOLED_Normal_Display_Cmd);    /*normal / reverse*/

 sendCommand(Set_Display_Clock_Divide_Ratio_Cmd);    /*set osc division*/
 sendCommand(0x80);

 sendCommand(Set_Precharge_Period_Cmd);    /*set pre-charge period*/
 sendCommand(0xf1);

 sendCommand(Set_COM_Pins_Hardware_Config_Cmd);    /*set COM pins*/
// sendCommand(0x12);64
 sendCommand(0x02);//32

 sendCommand(Set_VCOMH_Deselect_Level_Cmd);    /*set vcomh*/
 sendCommand(0x30);

 sendCommand(Deactivate_Scroll_Cmd);

 sendCommand(Charge_Pump_Setting_Cmd);    /*set charge pump enable*/
 sendCommand(Charge_Pump_Enable_Cmd);

 sendCommand(GOFi2cOLED_Display_On_Cmd);    /*display ON*/

//亮度设置
 sendCommand(0x81);
 sendCommand(0x00);
// sendCommand(0x78);
}

void SSD1306_Mini::clipArea(unsigned char col, unsigned char row, unsigned char w, unsigned char h){
  
  TinyWireM.begin();                    //initialize I2C
  TinyWireM.beginTransmission(SlaveAddress); // begin I2C transmission
  TinyWireM.send(GOFi2cOLED_Command_Mode);            // data mode
  TinyWireM.send(Set_Column_Address_Cmd);
  TinyWireM.send(0);

  TinyWireM.send(col);
  TinyWireM.send(col+w-1);

  TinyWireM.endTransmission();                    // stop I2C transmission

  TinyWireM.begin();                    //initialize I2C
  TinyWireM.beginTransmission(SlaveAddress); // begin I2C transmission
  TinyWireM.send(GOFi2cOLED_Command_Mode);            // data mode
  TinyWireM.send(Set_Page_Address_Cmd);
  TinyWireM.send(0);

  TinyWireM.send(row); 
  TinyWireM.send(row+h-1);

  TinyWireM.endTransmission();                    // stop I2C transmission

}

void SSD1306_Mini::cursorTo(unsigned char col, unsigned char row){
  clipArea(col, row, 128-col, 8-row);
/*  
  TinyWireM.begin();                    //initialize I2C
  TinyWireM.beginTransmission(SlaveAddress); // begin I2C transmission
  TinyWireM.send(GOFi2cOLED_Command_Mode);            // data mode
  TinyWireM.send(Set_Column_Address_Cmd);
  TinyWireM.send(0);

  TinyWireM.send(col);
  TinyWireM.send(127);

  TinyWireM.endTransmission();                    // stop I2C transmission

  TinyWireM.begin();                    //initialize I2C
  TinyWireM.beginTransmission(SlaveAddress); // begin I2C transmission
  TinyWireM.send(GOFi2cOLED_Command_Mode);            // data mode
  TinyWireM.send(Set_Page_Address_Cmd);
  TinyWireM.send(0);

  TinyWireM.send(row); 
  TinyWireM.send(7);

  TinyWireM.endTransmission();                    // stop I2C transmission
*/
}

/*
void SSD1306_Mini::cursorToX( unsigned char row, unsigned char col ){

  sendCommand(0x00 | (0x0F & col) );  // low col = 0
  sendCommand(0x10 | (0x0F & (col>>4)) );  // hi col = 0
//  sendCommand(0x40 | (0x0F & row) ); // line #0

  sendCommand(0xb0 | (0x03 & row) );  // hi col = 0
  
  
}
*/

void SSD1306_Mini::startScreen(){
  
  sendCommand(0x00 | 0x0);  // low col = 0
  sendCommand(0x10 | 0x0);  // hi col = 0
  sendCommand(0x40 | 0x0); // line #0

}

void SSD1306_Mini::clear() {
  
  sendCommand(0x00 | 0x0);  // low col = 0
  sendCommand(0x10 | 0x0);  // hi col = 0
  sendCommand(0x40 | 0x0); // line #0
    
  clipArea(0,0,128,8);
  
    for (uint16_t i=0; i<=((128*64/8)/16); i++) 
    {
      // send a bunch of data in one xmission
      Wire.beginTransmission(SlaveAddress);
      Wire.send(GOFi2cOLED_Data_Mode);            // data mode
      for (uint8_t k=0;k<16;k++){
        Wire.send( 0 );
      }
      Wire.endTransmission();
    }
}


void SSD1306_Mini::displayX(int off) {
  sendCommand(0x00 | 0x0);  // low col = 0
  sendCommand(0x10 | 0x0);  // hi col = 0
  sendCommand(0x40 | 0x0); // line #0
    
    for (uint16_t i=0; i<=((128*64/8)/16); i++) 
    {
      // send a bunch of data in one xmission
      Wire.beginTransmission(SlaveAddress);
      Wire.send(GOFi2cOLED_Data_Mode);            // data mode
      for (uint8_t k=0;k<16;k++){
        Wire.send( i*16 + k + off);
      }
      Wire.endTransmission();
    }
}



void SSD1306_Mini::printChar( char ch ){
    
    char data[5];
    unsigned char i= ch;
    
    data[0]= getFlash(BasicFont, i*5 );
    data[1]= getFlash(BasicFont, i*5 + 1);
    data[2]= getFlash(BasicFont, i*5 + 2);
    data[3]= getFlash(BasicFont, i*5 + 3);
    data[4]= getFlash(BasicFont, i*5 + 4);    
    
    Wire.beginTransmission(SlaveAddress);
    Wire.send(GOFi2cOLED_Data_Mode);            // data mode
    
    Wire.send( 0x00 );
    Wire.send( data[0] );
    Wire.send( data[1] );
    Wire.send( data[2] );
    Wire.send( data[3] );
    Wire.send( data[4] );
    Wire.send( 0x00 );
      
    Wire.endTransmission();
  
}

void SSD1306_Mini::printString( char * pText ){
  unsigned char i;
  unsigned char len = strlen( pText );
  
  for (i=0;i<len;i++){
     printChar( pText[i] ); 
  }
  
}
 
 
void SSD1306_Mini::drawImage( const unsigned char * img, unsigned char col, unsigned char row, unsigned char w, unsigned char h ){
  unsigned int i,k,data;
  
  clipArea( col, row, w, h);
  
  for (i=0;i< (w*h);i++){

      data= getFlash( img, i);
              
      Wire.beginTransmission(SlaveAddress);
      Wire.send(GOFi2cOLED_Data_Mode);            // data mode

        Wire.send( data );
      Wire.endTransmission();
      
  }
  
}
