/***********************************
 * Author: Nkeng Newton            *
 * Date  : 10/08/2016              *
 * Title : Density Traffic Control *
 ***********************************/
// let's define analog variables to hold the analog values
#define analogPin0 A0   
#define analogPin1 A1
#define analogPin2 A2
#define analogPin3 A3

//let's define traffic lights variables
int red1    = 13;   //initialize the variable red1 to pin 13 and same with others
int yellow1 = 12;
int green1  = 11;
int red2    = 10;
int yellow2 = 9;
int green2  = 8;
int red3    = 7;
int yellow3 = 6;
int green3  = 5;
int red4    = 4;
int yellow4 = 3;
int green4  = 2; 

//let's define sensor variables
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;

 // let's counter variables for both direction of the road
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;

// let's define an array to store at least 5 sensor variables
int sensorValues[5];

// setup function to be use in configuring the arduino pins
void setup()  {
      // set the data rate for the Serial port
       Serial.begin(9600);
        pinMode(red1,OUTPUT);    //configure red1 pin as output pin
        pinMode(yellow1,OUTPUT);
        pinMode(green1,OUTPUT);
        pinMode(red2,OUTPUT);
        pinMode(green2,OUTPUT);
        pinMode(yellow2,OUTPUT);
        pinMode(analogPin0, INPUT);
        pinMode(analogPin1, INPUT);
        pinMode(analogPin2, INPUT);
        pinMode(analogPin3, INPUT);

}

void loop()
{    
    // variables to store read sensor values
    sensorValue1 = IRread1(4);
    sensorValue2 = IRread2(4);
    sensorValue3 = IRread3(4);
    sensorValue4 = IRread4(4);

    // let's print the values on serial monitor to check them
    Serial.print("Sensor1 Value: ");
    Serial.println(sensorValue1);
    Serial.print("count1 Value ");
    Serial.println(count1);

    Serial.print("Sensor2 Value: ");
    Serial.println(sensorValue2);
    Serial.print("count2 Value ");
    Serial.println(count2);

    Serial.print("Sensor3 Value: ");
    Serial.println(sensorValue3);
    Serial.print("count3 Value ");
    Serial.println(count3);

    Serial.print("Sensor4 Value: ");
    Serial.println(sensorValue4);
    Serial.print("count4 Value ");
    Serial.println(count4);
    
    if(sensorValue1>=80){
        count1++;
      }
    if(sensorValue2>=80){
        count2++;
      }
    if(sensorValue3>=80){
        count3++;
      }
    if(sensorValue4>=80){
        count4++;
      }
      if(count1 > count2 && count1 > count3 && count1 > count4){
        
        // turn off yellows, then turn red2 and green1 on for 15 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,LOW);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,HIGH);
          digitalWrite(green2,LOW);
          digitalWrite(green3,LOW);
          digitalWrite(green4,LOW);
          delay(15000);
            count1 = 0;

        }

      if(count2 > count1 && count2 > count3 && count2 > count4){
           
          // turn off yellows, then turn red1,red3,red4 and green2 on for 15 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,LOW);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,LOW);
          digitalWrite(green2,HIGH);
          digitalWrite(green3,LOW);
          digitalWrite(green4,LOW);
          delay(15000);
            count2 = 0;
        }

     if(count3 > count1 && count3 > count2 && count3 > count4){
           
          // turn off yellows, then turn red2,red1,red4 and green3 on for 5 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,LOW);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,LOW);
          digitalWrite(green2,LOW);
          digitalWrite(green3,HIGH);
          digitalWrite(green4,LOW);
          delay(15000);
            count3 = 0;
        }

    if(count4 > count1 && count4 > count2 && count4 > count3){
           
          // turn off yellows, then turn red1,red2,red3 and green4 on for 15 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,LOW);
          digitalWrite(green1,LOW);
          digitalWrite(green2,LOW);
          digitalWrite(green3,LOW);
          digitalWrite(green4,HIGH);
          delay(15000);
            count4 = 0;
        }
        
       else{
        
          // turn off yellows, then turn red2 and green1 on for 5 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,LOW);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,HIGH);
          digitalWrite(green2,LOW);
          digitalWrite(green3,LOW);
          digitalWrite(green4,LOW);
          delay(5000);

          // we have to always read sensor values
          sensorValue1 = IRread1(4);
          sensorValue2 = IRread2(4);
          sensorValue3 = IRread3(4);
          sensorValue4 = IRread4(4); 
            
          // yellow1 and yellow2 on for 3 seconds (red is already on though)
          digitalWrite(yellow1,HIGH);
          digitalWrite(green1,LOW);
          delay(2000);
          
          // turn off yellows, then turn red1,red3,red4 and green2 on for 5 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,LOW);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,LOW);
          digitalWrite(green2,HIGH);
          digitalWrite(green3,LOW);
          digitalWrite(green4,LOW);
          delay(5000);

          // we have to always read sensor values
          sensorValue1 = IRread1(4);
          sensorValue2 = IRread2(4);
          sensorValue3 = IRread3(4);
          sensorValue4 = IRread4(4); 
          
          // turn on yellow2 and off green2 for 2 seconds
          digitalWrite(yellow2,HIGH);
          digitalWrite(green2,LOW);
          delay(2000);

          // turn off yellows, then turn red2,red1,red4 and green3 on for 5 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,LOW);
          digitalWrite(red4,HIGH);
          digitalWrite(green1,LOW);
          digitalWrite(green2,LOW);
          digitalWrite(green3,HIGH);
          digitalWrite(green4,LOW);
          delay(5000);

          // we have to always read sensor values
          sensorValue1 = IRread1(4);
          sensorValue2 = IRread2(4);
          sensorValue3 = IRread3(4);
          sensorValue4 = IRread4(4); 

          // turn on yellow3 and off green3 for 2 seconds
          digitalWrite(yellow3,HIGH);
          digitalWrite(green3,LOW);
          delay(2000);

          // turn off yellows, then turn red1,red2,red3 and green4 on for 5 seconds
          digitalWrite(yellow1,LOW);
          digitalWrite(yellow2,LOW);
          digitalWrite(yellow3,LOW);
          digitalWrite(yellow4,LOW);
          digitalWrite(red1,HIGH);
          digitalWrite(red2,HIGH);
          digitalWrite(red3,HIGH);
          digitalWrite(red4,LOW);
          digitalWrite(green1,LOW);
          digitalWrite(green2,LOW);
          digitalWrite(green3,LOW);
          digitalWrite(green4,HIGH);
          delay(5000);

          // we have to always read sensor values
          sensorValue1 = IRread1(4);
          sensorValue2 = IRread2(4);
          sensorValue3 = IRread3(4);
          sensorValue4 = IRread4(4); 

          // turn on yellow4 and OFF green4 for 2 seconds
          digitalWrite(yellow4,HIGH);
          digitalWrite(green4,LOW);
          delay(2000);

          
              
        }
    
         
}

//sensor 1 read function
int IRread1(int times){
  
       // let's get at least 5 sensor values
       int totalValue = 0;
       
      for(int x=0; x<times; x++){
        
          sensorValues[x] = analogRead(analogPin0);
          
        }

        // let' compute the average of the values
        for(int x=0; x<times; x++){
          
              totalValue+= sensorValues[x];
          }
          
          return(totalValue/times);
  }

  //sensor 2 read function
  int IRread2(int times){
  
       // let's get at least 5 sensor values
       int totalValue = 0;
       
      for(int x=0; x<times; x++){
        
          sensorValues[x] = analogRead(analogPin1);
          
        }

        // let' compute the average of the values
        for(int x=0; x<times; x++){
          
              totalValue+= sensorValues[x];
          }
          
          return(totalValue/times);
  }

//sensor 3 read function
  int IRread3(int times){
  
       // let's get at least 5 sensor values
       int totalValue = 0;
       
      for(int x=0; x<times; x++){
        
          sensorValues[x] = analogRead(analogPin2);
          
        }

        // let' compute the average of the values
        for(int x=0; x<times; x++){
          
              totalValue+= sensorValues[x];
          }
          
          return(totalValue/times);
  }

// sensor 4 read function
  int IRread4(int times){
  
       // let's get at least 5 sensor values
       int totalValue = 0;
       
      for(int x=0; x<times; x++){
        
          sensorValues[x] = analogRead(analogPin3);
          
        }

        // let' compute the average of the values
        for(int x=0; x<times; x++){
          
              totalValue+= sensorValues[x];
          }
          
          return(totalValue/times);
  }

