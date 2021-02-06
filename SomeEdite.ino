// Trafic Ligth With Arduino UNO
// This code write by me Ahmed Elshimy
// for any reason call me 01123908016

int red = A0;
int yellow = A1;
int green = A2;

int yellowTime = 0; // 1 Means 20 sec, 0 means 10 sec
int TransfireTime = 1; //Means 20 sec for delay betwhen green and red

void setup()
{
  for (int i = 0; i <= 13; i++) {
    pinMode(i, OUTPUT); //Set all pins from 0 to 13 as OUTPUT
  }


  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}
//The line below is the array containing all the binary numbers for the digits on a SSD from 0 to 9
const int number[11] = {0b0111111, 0b0000110, 0b1011011,
                        0b1001111, 0b1100110, 0b1101101,
                        0b1111101, 0b0000111, 0b1111111,
                        0b1101111};
void loop()
{
  Red();
  Yellow();
  Green();
  Yellow();
}

void display(const int from)
{
  for (int tens = from; tens >= 0; tens--)

  {
    display_tens(tens);
  }
}

void display_tens(const int tens)
{
  int pin1, a, ones;
  //pin1 is just used to deal with pins of the 1st SSD which desplays the tens digit

  for (pin1 = 0, a = 0; pin1 < 7; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[tens], a));
  }
  for (ones = 10; ones >= 0; ones--)
  {
    display_ones(ones);
    delay(1000);
    //I have given a delay of 1 seconds. You can put your own Time!!
  }
}


void display_ones(const int x)
{
  int pin2, b;
  //pin2 is just used to deal with pins of the 2nd SSD which desplays the ones digit

  for (pin2 = 7, b = 0; pin2 <= 13; pin2++, b++)
  {
    digitalWrite(pin2, bitRead(number[x], b));

  }

}

void Red()
{

  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  display(TransfireTime);

}

void Green()
{

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  display(TransfireTime);

}

void Yellow()
{
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  display(yellowTime);
}
