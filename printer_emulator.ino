const float def_hot_temp = 26.0;
const float def_bed_temp = 15.0;

float hot_temp = def_hot_temp;
float bed_temp = def_bed_temp;

int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n': // Ignore new-lines
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      case '\r': // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len-1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  // No end of line has been found, so return -1.
  return -1;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("echo Printer emulator");
  Serial.println("start");
}


void loop() {
  // put your main code here, to run repeatedly:
  static char buffer[80];
  if (readline(Serial.read(), buffer, 80) > 0) {
    if (strcmp(buffer, "M105") == 0) {
        Serial.println("ok T:26.4 /0.0 @:0");      
    } else if(strcmp(buffer, "T0") == 0) {
        Serial.println("ok");      
    } else if(strcmp(buffer, "M114") == 0) {
        Serial.println("ok C: X:0.00 Y:0.00 Z:0.00 E:0.00");      
    } else {
      Serial.println("ok");      
//      Serial.print("You entered: >");
//      Serial.print(buffer);
//      Serial.println("<");  
    }
  }

}
