/* Made by Tomas Kopunec
 *  24.11.2018
 *  
 *  By default SMART BLUETOOTH app
 *  sends three values in sliders tab, for example: 0,255,128\n
 *  With newline character at the end of each line
 * 
 *  If you have any questions or issues
 *  don't hesitate and send me a message here: devkopunec@gmail.com
 *  
 *  Don't forget to leave a 5-star rating and nice feedback
 *  
 *  Thanks, Kopunec
 *  
 *  Modified By Sanju's Robotics Studio
 */


const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  while (Serial.available() > 0) {
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();

    if (Serial.read() == '\n') {
      red   =   constrain(red, 0, 255);
      green =   constrain(green, 0, 255);
      blue  =   constrain(blue, 0, 255);

      analogWrite(redPin,   red);
      analogWrite(greenPin, green);
      analogWrite(bluePin,  blue);
    }  
  }
}
