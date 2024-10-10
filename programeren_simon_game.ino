int willekeurigLed[12];
//this is the size of the array, this array stores random value's between 2 and 6. if you want more levels you should increase the size of the array.


void setup() {
//comunication with your pc
  Serial.begin(9600);

  pinMode(2, OUTPUT); //led blue
  pinMode(3, OUTPUT); //led red
  pinMode(4, OUTPUT); //led yellow
  pinMode(5, OUTPUT); //led green

  pinMode(A3, INPUT_PULLUP); //button red
  pinMode(A1, INPUT_PULLUP); //button green
  pinMode(A0, INPUT_PULLUP); //button yellow
  pinMode(A2, INPUT_PULLUP); //button blue
//note: the buttons are connected to a analog input and are being set in software with a pullup resistor. this means the default state of these buttons is 1 not 0.
  pinMode(11, OUTPUT);
  //this is the pin were the buzzer is located

  randomSeed(analogRead(A5));
  //makes it realy random



}

void loop() {

  int spelafgelopen = 0;
  // this int is for checking if the button input is correct

  int level = 1;
  //this int resets the level back to one if the game is finnished




//if you want to increase the amount of levels you should increase this 12 in the loop the the same size as the array
  for (int i = 0 ; i < 12; i++) {
    willekeurigLed[i] = random(2, 6);
    Serial.print(willekeurigLed[i]);
    //this prints the numbers that are in the array, a great way to cheat or to debug the code
  }
  Serial.println();



  while (digitalRead(A0) && digitalRead(A1) && digitalRead(A2) && digitalRead(A3)) {
    // this while loop checks if a button is being pressed

  }


  int optel = 0;
//this int count if you have won the game or not
  welkomRidel();
  // plays welcome sound

  delay(1000);

  for (int i = 0; i <12; i++) {
    //this is the main loop. if the array size is increased you should increase this 12 to the same number of the size of the array


    for (int i = 0; i < level; i++) {
      //this loop displays the led's correctly and in the correct amount of levels

      digitalWrite(willekeurigLed[i], HIGH);
      //takes a number from the array
      tone(11, (willekeurigLed[i] * 150));
      //takes a number from the array and * 150 to create a frequentie Hz
      delay(1000);
      digitalWrite(willekeurigLed[i], LOW);
      noTone(11);
      delay(1000);
      



    }



    for (int i = 0; i < level; i++) {
      //this loop is for the input of buttons

      while (digitalRead(A0) && digitalRead(A1) && digitalRead(A2) && digitalRead(A3)) {
        //this loop checks for button inputs


      }
      delay(50);



      if (digitalRead(A0) == 0) {
        //this checks of button A0 is being pressed
        if (willekeurigLed[i] == 4) {
          //this checks if the number coresponds with the one in the array
          Serial.println("yellow");
          //for debuging
        }
        else {
          //if the button thats being pressed doesnt line up with the one in the array it follows these commands
          gameOver();
          //plays game over sound
          spelafgelopen = 1;
          //makes that int at the begining one so it knows later to break the "main" loop and restarts the game
          break;
          //breaks this loop
        }
      }
      //the rest is al the same but for different buttons
      else if (digitalRead(A1) == 0) {
        if (willekeurigLed[i] == 5) {
          Serial.println("green");
        }
        else {
          gameOver();
          spelafgelopen = 1;
          break;
        }

      }

      else if (digitalRead(A2) == 0) {
        if (willekeurigLed[i] == 2) {
          Serial.println("blue");
        }
        else {
          gameOver();
          spelafgelopen = 1;
          break;
        }
      }
      else if (digitalRead(A3) == 0) {
        if (willekeurigLed[i] == 3) {
          Serial.println("red");
        }
        else {
          gameOver();
          spelafgelopen = 1;
          break;
        }
      }
      else {}
      
      while (digitalRead(A0) == 0 || digitalRead(A1) == 0 || digitalRead(A2) == 0 || digitalRead(A3) == 0) {
      //checks if button is being let go

      }
      delay(50);
    }








    if (spelafgelopen == 0 ) {
      //if the int is unchanged it means that you finished a level, yay. know it adds plus one to the level so you can go ahead and play the next level
      optel++;
      level++;
    }

    else {
      break;
    }

    delay(1000);

    if(optel ==11){
      //this checks if you have won.IF YOU INCREASED THE ARRAY SIZE THIS ONE MUST BE CHANGED TOO. (ARRAY-1)
      winnaarRidel();
      //plays victory sound
      break;
      
    }

  }












}


void welkomRidel() {
  digitalWrite(2, HIGH);
  tone(11, 1500);
  delay(500);
  noTone(11);
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);
  tone(11, 1200);
  delay(500);
  noTone(11);
  digitalWrite(3, LOW);
  //welcome sound
}

void gameOver() {
  digitalWrite(4, HIGH);
  tone(11, 1000);
  delay(500);
  noTone(11);
  tone(11, 750);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  noTone(11);
  tone(11, 600);
  delay(500);
  digitalWrite(5, LOW);
  noTone(11);
  //game over sound

}

void winnaarRidel() {
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(3, HIGH);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(5, HIGH);
  tone(11, 700);
  delay(300);
  noTone(11);
  tone(11, 900);
  delay(200);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  noTone(11);
  //wining sound 


}

//this terrible code was writtin by jeffrey. 1st year electrical engineer student@avans 
