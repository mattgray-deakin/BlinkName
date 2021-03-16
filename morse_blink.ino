// Modifed Blink Code by Matthew Gray - Deakin University

// Note with regards to Morse Code.  A dash is three units long, a dot is one.  Each letter is separated by one unit.  In this program, the unit length is 200.

int led1 = D6; // Particle Argon D6 - Connected to the positive side of a white LED

int led2 = D7; // Particle Argon D7 - Blue LED the is beside the USB interface.

int unit = 200;

// Setup function - it is preferable that the modes for all the pins are defined within this function

void setup() {

	// We are going to tell our device that D6 and D7 (which we named led1 and led2 respectively) are going to be output

	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);

}

// This function causes the led's to conduct a long blink - or a morse code dash
void dash_blink() {
    // Turn led's on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    
    // medium length delay
    delay(3 * unit);
    
    // Turn LED's off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    
    // Short delay for post blink
    delay(1 * unit);
}

void dot_blink() {
    // Turn led's on
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    
    // Short delay
    delay(unit);
    
    // Turn LED's off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

    // Short delay for post blink
    delay(unit);
}

void blink_letter(char letter){     // This function uses a switch .. case statement to illuminate the LED's according to the requested letter. . . .
    
    switch (letter) {
        
        case 'A':             // Code for the letter A is dot dash
            dot_blink();
            dash_blink();
            break;
            
        case 'E':             // Code for the letter E is dot
            dot_blink();
            break;
            
        case 'G':             // Code for the letter G is dash dash dot
            dash_blink();
            dot_blink();
            dot_blink();
            break;
            
        case 'H':             // You get the idea . . . .
            dot_blink();
            dot_blink();
            dot_blink();
            dash_blink();
            break;
            
        case 'M':
            dash_blink();
            dash_blink();
            break;
            
        case 'R':
            dot_blink();
            dash_blink();
            dot_blink();
            break;
            
        case 'T':
            dash_blink();
            break;
            
        case 'W':
            dot_blink();
            dash_blink();
            dash_blink();
            break;
            
        case 'Y':
            dash_blink();
            dot_blink();
            dash_blink();
            dash_blink();
            break;
    
        default:
            break;
    
    }
    // Break between characters is three units, thus 600
    
    delay (3 * unit);
}


// Main Program loop begins here .. In this case the loop will spell out my full name using Morse Code

void loop() {
    // A function call for each of the letters in my name
    blink_letter('M');
    blink_letter('A');
    blink_letter('T');
    blink_letter('T');
    blink_letter('H');
    blink_letter('E');
    blink_letter('W');
    
    // There is a 7 unit break between words in Morse Code
    delay(7 * unit);
    
    /*  This Section of code will blink my last name, however it is commented out as it is not required.
    blink_letter('G');
    blink_letter('R');
    blink_letter('A');
    blink_letter('Y');
    
    
    // Another 7 unit delay to finish the word, and the loop
    delay(7 * unit);
    */
	

}
