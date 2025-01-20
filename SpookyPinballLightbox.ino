#include <FastLED.h>
#define NUM_LEDS 20
#define LED_PIN 2
#define BUTTON_PIN 3
int NUM_MODES = 62;

CRGBArray<NUM_LEDS> leds;

//int currentAnimation = 0; // Tracks the current animation
bool lastButtonState = LOW; // Tracks the last button state

void setup() {

  
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with internal pull-up
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

  // Initialize the first 10 LEDs to white
  for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::White;
  }

  FastLED.show(); // Show the initial state
}

void loop() {
  static int currentMode = 0; // Current animation mode
  
//  handleButtonPress();
 // Check the button state
  if (digitalRead(BUTTON_PIN) == HIGH) {
    currentMode = (currentMode + 1) % NUM_MODES; // Cycle through modes
    delay(200); // Debounce
  }
  

  switch (currentMode) {
    case 0:
      rainbowEffect();
      break;
     case 1: 
      flickeringStarsEffect();
      break;       
    case 2:
      breathingEffect(); //blue
      break;
    case 3:
      breathingEffectgreen();
      break;
    case 4:
      breathingEffectred();
      break;             
    case 5:
      chaseEffectred();
      break;
    case 6:
      chaseEffectgreen();
      break;
    case 7:
      chaseEffectblue();
      break;      
    case 8:              
      whitegreen();
      break; 
    case 9:
      rainbowEffect();
      break;  
    case 10:
      breathingEffect();
      break;
    case 11:
      breathingEffectgreen();
      break;
    case 12:
      breathingEffectred();
      break;             
    case 13:
      chaseEffectred();
      break;
    case 14:
      chaseEffectgreen();
      break;
    case 15:
      chaseEffectblue();
      break;                     
    case 16:              
      whitered();
      break;   
    case 17:
      rainbowEffect();
      break;  
    case 18:
      breathingEffect();
      break;
    case 19:
      breathingEffectgreen();
      break;
    case 20:
      breathingEffectred();
      break;             
    case 21:
      chaseEffectred();
      break;
    case 22:
      chaseEffectgreen();
      break;
    case 23:
      chaseEffectblue();
      break;      
    case 24:              
      whiteblue();
      break;
    case 25:
      rainbowEffect();
      break;  
    case 26:
      breathingEffect();
      break;
    case 27:
      breathingEffectgreen();
      break;
    case 28:
      breathingEffectred();
      break;             
    case 29:
      chaseEffectred();
      break;
    case 30:
      chaseEffectgreen();
      break;
    case 31:
      chaseEffectblue();
      break; 
    case 32:        
      whiteOrange();// Yellow
      break;                        
    case 33:        
      whitePurple();
      break;   
    case 34:                                 
      whiteHotPink();
      break;
    case 35:
      fireEffect();
      break;           
    case 36:       
      fireEffectHorizontal();    
      break;
     case 37:         
    fireEffectDynamic();
      break;        
     case 38:       
    coolFlameEffect ();
      break;  
     case 39:
    coolFlameEffectdos ();
      break;  
      case 40:
      coolFlameEffecttree ();
      break;  
      case 41:
      radarAnimation ();
      break;  
      case 42:      
      lightningEffect (); //Lightnig 
      break; 
      case 43:      
      meteorShower ();
      break; 
      case 44:      
      waterRipple ();
      break; 
      case 45:      
      rainbowWave ();
      break; 
      case 46:      
      colorPulse ();
      break; 
      case 47:      
      colorTwinkle ();
      break;  
      case 48:            
      lavaLampEffect();                           
      break;          
      case 49:              
      greenHighlightSweepRedPulse();                           
      break;       
      case 50:              
      rainbowCycleAndGreenPulse();                           
      break;
      case 51:         
      rainbowCycleAndredPulse();                           
      break;
      case 52:            
      rainbowCycleAndyellowPulse();                           
      break; 
      case 53:          
      rainbowCycleAndpurplePulse();                           
      break;  
      case 54:         
      rainbowCycleAndbluePulse();                           
      break;
      case 55:
      rainbowCycleWithoutYellowAndGreenPulse();                           
      break;   
      case 56:
      rainbowBounceWithoutYellowAndGreenPulse();                           
      break; 
      case 57:        
      theaterMode();
      break; 
      case 58:        
      reversedTheaterMode();
      break;  
      case 59:       
      circusAnimation();
      break;
      case 60:             
      PoliceAnimation();
      break;        
//    default:    
//      currentAnimation = 0; // Reset to the first animation
  }
}

// Handle button press to cycle through animations
//void handleButtonPress() {
//  bool buttonState = digitalRead(BUTTON_PIN) == LOW; // Read button (active low)
//  if (buttonState && !lastButtonState) { // Detect rising edge
//    currentAnimation = (currentAnimation + 1) % 48; // Cycle between 32 animations
//    delay(200); // Debounce delay
//  }
//  lastButtonState = buttonState;
//}

// Rainbow effect for the last 10 LEDs
void rainbowEffect() {
  static uint8_t hue = 0;
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 10), 255, 255);
  }
  hue++;
  FastLED.show();
  delay(50);
}

// Breathing effect for the last 10 LEDs
void breathingEffect() {
  static uint8_t brightness = 0;
  static int direction = 1;

  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i] = CHSV(160, 255, brightness); // Blue hue
  }

  brightness += direction;
  if (brightness == 0 || brightness == 255) {
    direction = -direction; // Reverse direction at min/max brightness
  }

  FastLED.show();
  delay(30);
}

void breathingEffectgreen() {
static uint8_t brightness = 0;  // Brightness level
  static int direction = 1;       // Direction of brightness change (1 = up, -1 = down)

  // Update the last 10 LEDs to a green hue with the current brightness
  for (int i = NUM_LEDS -12; i < NUM_LEDS; i++) {
    leds[i] = CHSV(96, 255, brightness); // Hue 96 = Green, Saturation 255 = Full, Brightness varies
  }

  // Adjust brightness for the next frame
  brightness += direction;

  // Reverse direction at max and min brightness
  if (brightness == 0 || brightness == 255) {
    direction = -direction;
  }

  FastLED.show();
  delay(30); // Adjust delay for breathing speed
}

void breathingEffectred() {
static uint8_t brightness = 0;  // Brightness level
  static int direction = 1;       // Direction of brightness change (1 = up, -1 = down)

  // Update the last 10 LEDs to a green hue with the current brightness
  for (int i = NUM_LEDS -12; i < NUM_LEDS; i++) {
    leds[i] = CHSV(255, 255, brightness); // Hue 96 = Green, Saturation 255 = Full, Brightness varies
  }

  // Adjust brightness for the next frame
  brightness += direction;

  // Reverse direction at max and min brightness
  if (brightness == 0 || brightness == 255) {
    direction = -direction;
  }

  FastLED.show();
  delay(30); // Adjust delay for breathing speed
}

// Knight Rider effect for the last 12 LEDs
void chaseEffectred() {
  static int pos = 0;
  static int direction = 1; // 1 for forward, -1 for backward

  // Fade only the last 12 LEDs
  for (int i = 8; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(80);
  }

  // Set the current position to red
  leds[8 + pos] = CRGB::Red;

  // Update the position
  pos += direction;

  // Reverse direction at the ends of the last 12 LEDs
  if (pos == 0 || pos == (NUM_LEDS - 8 - 1)) {
    direction = -direction;
  }

  FastLED.show();
  delay(50);
}

void chaseEffectgreen() {
  static int pos = 0;
  static int direction = 1; // 1 for forward, -1 for backward

  // Fade only the last 12 LEDs
  for (int i = 8; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(80);
  }

  // Set the current position to Green
  leds[8 + pos] = CRGB::Green;

  // Update the position
  pos += direction;

  // Reverse direction at the ends of the last 12 LEDs
  if (pos == 0 || pos == (NUM_LEDS - 8 - 1)) {
    direction = -direction;
  }

  FastLED.show();
  delay(50);
}

void chaseEffectblue() {
  static int pos = 0;
  static int direction = 1; // 1 for forward, -1 for backward

  // Fade only the last 12 LEDs
  for (int i = 8; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(80);
  }

  // Set the current position to Blue
  leds[8 + pos] = CRGB::Blue;

  // Update the position
  pos += direction;

  // Reverse direction at the ends of the last 12 LEDs
  if (pos == 0 || pos == (NUM_LEDS - 8 - 1)) {
    direction = -direction;
  }

  FastLED.show();
  delay(50);
}

void whitegreen() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::Green;
  }
  FastLED.show();
  delay(100);
}

void whitered() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(100);
}

void whiteblue() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::Blue;
  }
  FastLED.show();
  delay(100);
}
void whiteOrange() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::Gold;
  }
  FastLED.show();
  delay(100);
}

void whitePurple() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::DarkViolet;
  }
  FastLED.show();
  delay(100);
}

void whiteHotPink() {
  
  for (int i = NUM_LEDS - 12; i < NUM_LEDS; i++) {
    leds[i]  = CRGB::White;
  }
  
    for (int i = 0; i < NUM_LEDS -12; i++) {
    leds[i] = CRGB::DeepPink;
  }
  FastLED.show();
  delay(100);
}
// Flickering stars or fireworks effect for the last 12 LEDs
void flickeringStarsEffect() {
  // Fade all LEDs in the range slightly to create a gradual fade-out
  for (int i = 8; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(80); // Adjust fade speed as desired
  }

  // Randomly select LEDs to "spark"
  for (int i = 0; i < 3; i++) { // Control the number of sparks at a time
    int randomLED = random(8, NUM_LEDS); // Pick a random LED in the last 12
    leds[randomLED] = CHSV(random(0, 255), 255, random(150, 255)); // Random colors and brightness
  }

  FastLED.show();
  delay(50); // Adjust delay for effect speed
}

// Fire effect for the first 8 LEDs
void fireEffect() {
  static uint8_t heat[8]; // Array to hold "heat" values for each LED

  // Cool down each cell a little
  for (int i = 0; i < 8; i++) {
    heat[i] = qsub8(heat[i], random(0, 10)); // Cool by a random amount
  }

  // Heat up new sparks near the bottom
  if (random(0, 5) == 0) { // Occasionally create a spark
    int sparkIndex = random(0, 2); // Restrict sparks to the first 2 LEDs
    heat[sparkIndex] = qadd8(heat[sparkIndex], random(160, 255)); // Add heat
  }

  // Propagate heat upward
  for (int i = 7; i > 0; i--) {
    heat[i] = (heat[i - 1] + heat[i - 1] + heat[i]) / 3;
  }

  // Map heat to LED colors
  for (int i = 0; i < 8; i++) {
    CRGB color = HeatColor(heat[i]); // Convert heat to color
    leds[i] = color; // Set the LED color
  }

  FastLED.show();
  delay(50); // Adjust for flame flickering speed
}
// Horizontal fire effect for the first 8 LEDs
void fireEffectHorizontal() {
  static uint8_t heat[8]; // Array to hold "heat" values for each LED

  // Cool down each LED a little
  for (int i = 0; i < 8; i++) {
    heat[i] = qsub8(heat[i], random(0, 10)); // Cool by a random amount
  }

  // Heat up new sparks at the left (bottom of the fire)
  if (random(0, 5) == 0) { // Occasionally create a spark
    int sparkIndex = random(0, 2); // Restrict sparks to the first 2 LEDs
    heat[sparkIndex] = qadd8(heat[sparkIndex], random(160, 255)); // Add heat
  }

  // Propagate heat to the right (rising flames horizontally)
  for (int i = 7; i > 0; i--) {
    heat[i] = (heat[i - 1] + heat[i - 1] + heat[i]) / 3;
  }

  // Map heat to LED colors
  for (int i = 0; i < 8; i++) {
    CRGB color = HeatColor(heat[i]); // Convert heat to fire-like color
    leds[i] = color; // Set the LED color
  }

  FastLED.show();
  delay(50); // Adjust for flickering speed
}

// Dynamic fire effect for 8 LEDs on the bottom row and 12 LEDs on the top row
// Dynamic fire effect for 8 LEDs on the bottom row and 12 LEDs on the top row
void fireEffectDynamic() {
  static uint8_t heatLow[8];   // Heat array for the lowest row
  static uint8_t heatHigh[12]; // Heat array for the highest row

  // Cool down the heat for the bottom row (first 8 LEDs)
  for (int i = 0; i < 8; i++) {
    heatLow[i] = qsub8(heatLow[i], random(5, 15)); // Increase cooling slightly
  }

  // Cool down the heat for the top row (last 12 LEDs)
  for (int i = 0; i < 12; i++) {
    heatHigh[i] = qsub8(heatHigh[i], random(2, 10)); // Cooling slower for lingering effect
  }

  // Add new sparks to the bottom row
  if (random(0, 6) == 0) { // Lower chance for sparks
    int sparkIndex = random(0, 3); // Sparks in the first 3 LEDs
    heatLow[sparkIndex] = qadd8(heatLow[sparkIndex], random(140, 200)); // Reduced max heat
  }

  // Propagate heat for the bottom row
  for (int i = 7; i > 0; i--) {
    heatLow[i] = (heatLow[i - 1] + heatLow[i - 1] + heatLow[i]) / 3;
  }

  // Propagate heat from the bottom row to the top row
  for (int i = 0; i < 12; i++) {
    int src = i / 2; // Map top-row LEDs to bottom-row LEDs (1:2 ratio)
    heatHigh[i] = (heatLow[src] + heatHigh[i] + heatHigh[i]) / 3;
  }

  // Map heat to LED colors for the bottom row
  for (int i = 0; i < 8; i++) {
    leds[i] = HeatColor(constrain(heatLow[i], 0, 180)); // Constrain to avoid bright whites
  }

  // Map heat to LED colors for the top row
  for (int i = 0; i < 12; i++) {
    leds[8 + i] = HeatColor(constrain(heatHigh[i], 0, 180)); // Constrain to avoid bright whites
  }

  // Show the LEDs
  FastLED.show();
  delay(50); // Adjust for flickering speed
}
void coolFlameEffect() {
  static uint8_t heatLow[8];   // Heat array for the lowest row
  static uint8_t heatHigh[12]; // Heat array for the highest row

  // Cool down the heat for the bottom row (first 8 LEDs)
  for (int i = 0; i < 8; i++) {
    heatLow[i] = qsub8(heatLow[i], random(5, 15)); // Increase cooling slightly
  }

  // Cool down the heat for the top row (last 12 LEDs)
  for (int i = 0; i < 12; i++) {
    heatHigh[i] = qsub8(heatHigh[i], random(2, 10)); // Cooling slower for lingering effect
  }

  // Add new sparks to the bottom row
  if (random(0, 6) == 0) { // Lower chance for sparks
    int sparkIndex = random(0, 8); // Sparks in the first 3 LEDs
    heatLow[sparkIndex] = qadd8(heatLow[sparkIndex], random(140, 200)); // Reduced max heat
  }

  // Propagate heat for the bottom row
  for (int i = 7; i > 0; i--) {
    heatLow[i] = (heatLow[i - 1] + heatLow[i - 1] + heatLow[i]) / 3;
  }

  // Propagate heat from the bottom row to the top row
  for (int i = 0; i < 12; i++) {
    int src = i / 2; // Map top-row LEDs to bottom-row LEDs (1:2 ratio)
    heatHigh[i] = (heatLow[src] + heatHigh[i] + heatHigh[i]) / 3;
  }

  // Map heat to green/blue colors for the bottom row
  for (int i = 0; i < 8; i++) {
    uint8_t heat = constrain(heatLow[i], 0, 180); // Limit heat values
    leds[i] = blend(CRGB::Gold, CRGB::Orange, heat); // Blend from blue to green
  }

  // Map heat to green/blue colors for the top row
  for (int i = 0; i < 12; i++) {
    uint8_t heat = constrain(heatHigh[i], 0, 180); // Limit heat values
    leds[8 + i] = blend(CRGB::Lime, CRGB::Maroon, heat); // Blend from blue to green
  }

  // Show the LEDs
  FastLED.show();
  delay(50); // Adjust for flickering speed
}

void coolFlameEffectdos() {
  static uint8_t heatLow[8];   // Heat array for the lowest row
  static uint8_t heatHigh[12]; // Heat array for the highest row

  // Cool down the heat for the bottom row (first 8 LEDs)
  for (int i = 0; i < 8; i++) {
    heatLow[i] = qsub8(heatLow[i], random(4, 15)); // Increase cooling slightly
  }

  // Cool down the heat for the top row (last 12 LEDs)
  for (int i = 0; i < 12; i++) {
    heatHigh[i] = qsub8(heatHigh[i], random(5, 10)); // Cooling slower for lingering effect
  }

  // Add new sparks to the bottom row
  if (random(0, 6) == 0) { // Lower chance for sparks
    int sparkIndex = random(0, 3); // Sparks in the first 3 LEDs
    heatLow[sparkIndex] = qadd8(heatLow[sparkIndex], random(140, 200)); // Reduced max heat
  }

  // Propagate heat for the bottom row
  for (int i = 7; i > 0; i--) {
    heatLow[i] = (heatLow[i - 1] + heatLow[i - 1] + heatLow[i]) / 3;
  }

  // Propagate heat from the bottom row to the top row
  for (int i = 0; i < 12; i++) {
    int src = i / 2; // Map top-row LEDs to bottom-row LEDs (1:2 ratio)
    heatHigh[i] = (heatLow[src] + heatHigh[i] + heatHigh[i]) / 3;
  }

  // Map heat to green/blue colors for the bottom row
  for (int i = 0; i < 8; i++) {
    uint8_t heat = constrain(heatLow[i], 0, 180); // Limit heat values
    leds[i] = blend(CRGB::Blue, CRGB::DarkBlue, heat); // Blend from blue to green
  }

  // Map heat to green/blue colors for the top row
  for (int i = 0; i < 12; i++) {
    uint8_t heat = constrain(heatHigh[i], 0, 180); // Limit heat values
    leds[8 + i] = blend(CRGB::DarkViolet, CRGB::DarkBlue, heat); // Blend from blue to green
  }

  // Show the LEDs
  FastLED.show();
  delay(50); // Adjust for flickering speed
}
void coolFlameEffecttree() {
  static uint8_t heatLow[8];   // Heat array for the lowest row
  static uint8_t heatHigh[12]; // Heat array for the highest row

  // Cool down the heat for the bottom row (first 8 LEDs)
  for (int i = 0; i < 8; i++) {
    heatLow[i] = qsub8(heatLow[i], random(4, 15)); // Increase cooling slightly
  }

  // Cool down the heat for the top row (last 12 LEDs)
  for (int i = 0; i < 12; i++) {
    heatHigh[i] = qsub8(heatHigh[i], random(5, 10)); // Cooling slower for lingering effect
  }

  // Add new sparks to the bottom row
  if (random(0, 6) == 0) { // Lower chance for sparks
    int sparkIndex = random(0, 3); // Sparks in the first 3 LEDs
    heatLow[sparkIndex] = qadd8(heatLow[sparkIndex], random(140, 200)); // Reduced max heat
  }

  // Propagate heat for the bottom row
  for (int i = 7; i > 0; i--) {
    heatLow[i] = (heatLow[i - 1] + heatLow[i - 1] + heatLow[i]) / 3;
  }

  // Propagate heat from the bottom row to the top row
  for (int i = 0; i < 12; i++) {
    int src = i / 2; // Map top-row LEDs to bottom-row LEDs (1:2 ratio)
    heatHigh[i] = (heatLow[src] + heatHigh[i] + heatHigh[i]) / 3;
  }

  // Map heat to green/blue colors for the bottom row
  for (int i = 0; i < 8; i++) {
    uint8_t heat = constrain(heatLow[i], 0, 180); // Limit heat values
    leds[i] = blend(CRGB::Red, CRGB::Maroon, heat); // Blend from blue to green
  }

  // Map heat to green/blue colors for the top row
  for (int i = 0; i < 12; i++) {
    uint8_t heat = constrain(heatHigh[i], 0, 180); // Limit heat values
    leds[8 + i] = blend(CRGB::Blue, CRGB::Indigo, heat); // Blend from blue to green
  }

  // Show the LEDs
  FastLED.show();
  delay(50); // Adjust for flickering speed
}

void radarAnimation() {
  static uint8_t radarPos = 0; // Current position of the radar sweep
  static uint8_t spread[12] = {0}; // Array for the spreading effect

  // Clear all LEDs
  leds.fill_solid(CRGB::Black);

  // Radar sweep for the bottom row (first 8 LEDs)
  for (int i = 0; i < 8; i++) {
    if (i == radarPos) {
      leds[i] = CRGB::Lime; // Bright green for the radar position
    } else {
      leds[i] = CRGB::Black; // Dim green for trailing effect
    }
  }

  // Update spreading effect for the top row (last 12 LEDs)
  for (int i = 0; i < 12; i++) {
    if (i == radarPos % 9) { // Synchronize spread with radar position
      spread[i] = 255; // Start a new pulse
    }
    spread[i] = qsub8(spread[i], 50); // Fade out the pulse
    leds[8 + i] = CHSV(96, 255, spread[i]); // Map spread to green hue (96)
  }

  // Move radar position
  radarPos = (radarPos + 1) % 8; // Loop the position within the bottom row

  // Show the LEDs
  FastLED.show();
  delay(85); // Adjust speed of the radar sweep
}


void lightningEffect() {
  static int state = 0; // Tracks the current state of the lightning effect
  static int strikeCount = 0;
  static int numStrikes = random(2, 3);
  static unsigned long lastUpdate = 0;
  static unsigned long pauseStart = 0;
  static unsigned long pauseDuration = random(1000, 3000);
  static bool blueTransition = false; // Tracks if blue transition should start

  unsigned long currentTime = millis();

  switch (state) {
    case 0: // Start a new lightning sequence
      strikeCount = 0;
      numStrikes = random(2, 6);
      state = 1;
      break;

    case 1: // Perform a single lightning strike
      if (strikeCount < numStrikes) {
        if (currentTime - lastUpdate > random(50, 300)) { // Random delay between strikes
          lastUpdate = currentTime;

          // Create the strike
          uint8_t brightness = random(150, 255);
          for (int i = 0; i < NUM_LEDS; i++) {
            if (random(0, 10) > 8) { // Random chance for each LED to light up
              leds[i] = CRGB::White; // Bright white for the strike
            }
          }
          FastLED.show();

          // Mark blue transition to start after a short delay
          blueTransition = true;
          lastUpdate = currentTime;
          strikeCount++;
        }
      } else {
        state = 2; // Move to the pause between sequences
        pauseStart = currentTime;
        pauseDuration = random(1000, 3000);
      }
      break;

    case 2: // Pause between sequences
      if (currentTime - pauseStart >= pauseDuration) {
        state = 0; // Start a new sequence
      }
      break;
  }

  // Handle blue transition with delay
  if (blueTransition && currentTime - lastUpdate > 200) { // Short delay before blue fade
    for (int fadeStep = 0; fadeStep < 10; fadeStep++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        if (leds[i] == CRGB::White) {
          leds[i] = CHSV(160, 255, random(75, 150)); // Transition to blue
        } else {
          // Fade some LEDs to black completely
          if (random(0, 10) > 8) {
            leds[i].fadeToBlackBy(90); // Aggressive fade to black
          } else {
            leds[i].fadeToBlackBy(75); // Softer fade
          }
        }
      }
      FastLED.show();
      delay(50); // Short delay for smooth fading
    }
    blueTransition = false; // Reset blue transition
  }
}




void meteorShower() {
  const int meteorSize = 4;
  const uint8_t trailDecay = 64; // How quickly the trail fades
  const uint8_t brightness = 255; // Brightness of the meteor
  const uint8_t hue = 96; // Greenish hue for the meteor
  
  for (int i = 0; i < NUM_LEDS + meteorSize; i++) {
    // Fade out all LEDs
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j].fadeToBlackBy(trailDecay);
    }
    
    // Draw the meteor
    for (int j = 0; j < meteorSize; j++) {
      if (i - j >= 0 && i - j < NUM_LEDS) {
        leds[i - j] = CHSV(hue, 255, brightness);
      }
    }
    
    FastLED.show();
    delay(30); // Adjust speed of the meteor
  }
}

void waterRipple() {
  static int center = NUM_LEDS / 2; // Center of the ripple
  static uint8_t rippleRadius = 0;
  static uint8_t fadeRate = 60;

  // Clear all LEDs
  leds.fadeToBlackBy(fadeRate);

  // Light up LEDs in a ripple pattern
  if (center - rippleRadius >= 0) leds[center - rippleRadius] = CHSV(160, 255, 255);
  if (center + rippleRadius < NUM_LEDS) leds[center + rippleRadius] = CHSV(160, 255, 255);

  rippleRadius++;
  if (rippleRadius > NUM_LEDS / 2) {
    rippleRadius = 0; // Reset ripple
    center = random(0, NUM_LEDS); // New ripple center
  }

  FastLED.show();
  delay(50);
}

void rainbowWave() {
  static uint8_t startHue = 0;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(startHue + (i * 10), 255, 255);
  }

  startHue++; // Shift the rainbow
  FastLED.show();
  delay(20); // Adjust wave speed
}

void colorPulse() {
  static uint8_t brightness = 0;
  static int8_t direction = 5;

  brightness += direction; // Brightness oscillates
  if (brightness == 255 || brightness == 0) direction = -direction; // Reverse at limits

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(96, 255, brightness); // Green pulse
  }

  FastLED.show();
  delay(20);
}

void colorTwinkle() {
  for (int i = 0; i < NUM_LEDS; i++) {
    if (random(0, 10) > 8) { // Random chance to twinkle
      leds[i] = CHSV(96, 255, random(128, 255)); // Bright green twinkle
    }
    leds[i].fadeToBlackBy(20); // Fade out twinkles
  }

  FastLED.show();
  delay(50);
}

  void lavaLampEffect() {
  static uint8_t lavaPos[5] = {0, 4, 8, 12, 16}; // Initial positions for blobs
  static uint8_t lavaDirection[5] = {1, -1, 1, -1, 1}; // Directions for blob movement
  static uint8_t blobSize = 5; // Size of each blob
  static uint8_t hueStart = 200; // Base hue for purple tones
  static unsigned long lastUpdate = 0; // Tracks last update time

  unsigned long currentTime = millis();

  if (currentTime - lastUpdate > 100) { // Update every 100ms
    lastUpdate = currentTime;

    // Fade all LEDs slightly for smooth transitions
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i].fadeToBlackBy(30);
    }

    // Update each lava blob
    for (int b = 0; b < 5; b++) {
      // Draw the blob
      for (int i = 0; i < blobSize; i++) {
        int pos = (lavaPos[b] + i) % NUM_LEDS; // Ensure positions wrap around
        leds[pos] = CHSV(hueStart + random(-10, 10), 255, 150 + random(-30, 30)); // Purple tones
      }

      // Move the blob
      lavaPos[b] += lavaDirection[b];

      // Change direction at edges
      if (lavaPos[b] <= 0 || lavaPos[b] >= NUM_LEDS - blobSize) {
        lavaDirection[b] = -lavaDirection[b];
      }
    }

    FastLED.show();
  }
}

void greenHighlightSweepRedPulse() {
  static uint8_t greenPos = 0; // Current position of the brighter green LED
  static int greenDirection = 1; // Direction of the moving green LED (1 = right, -1 = left)
  static uint8_t pulseBrightness = 150; // Initial brightness for the red pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 150) {
    lastUpdate = currentTime;

    // Set the lower row (8 LEDs) to a dim green
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(96, 255, 100); // Dim green
    }

    // Make the current green position brighter
    leds[greenPos] = CHSV(42, 255, 190); // Bright green

    // Move the green highlight
    greenPos += greenDirection;
    if (greenPos == 7 || greenPos == 0) {
      greenDirection = -greenDirection; // Change direction at the edges
    }

    // Update the top row (12 LEDs) with the pulsing red effect
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(85, 255, pulseBrightness); // Red hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 100 || pulseBrightness <= 50) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}
void rainbowCycleAndGreenPulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Set the lower row (first 8 LEDs) to a rainbow color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Increment the hue to cycle through the rainbow
    hue += 2; // Adjust this value to control the speed of the rainbow

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(96, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}


void rainbowCycleAndredPulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Set the lower row (first 8 LEDs) to a rainbow color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Increment the hue to cycle through the rainbow
    hue += 2; // Adjust this value to control the speed of the rainbow

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(0, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}



void rainbowCycleAndyellowPulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Set the lower row (first 8 LEDs) to a rainbow color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Increment the hue to cycle through the rainbow
    hue += 2; // Adjust this value to control the speed of the rainbow

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(42, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void rainbowCycleAndpurplePulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Set the lower row (first 8 LEDs) to a rainbow color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Increment the hue to cycle through the rainbow
    hue += 2; // Adjust this value to control the speed of the rainbow

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(213, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void rainbowCycleAndbluePulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Set the lower row (first 8 LEDs) to a rainbow color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Increment the hue to cycle through the rainbow
    hue += 2; // Adjust this value to control the speed of the rainbow

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(171, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void rainbowCycleWithoutYellowAndGreenPulse() {
  static uint8_t hue = 0; // Hue value for the rainbow effect
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1; // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 50) {
    lastUpdate = currentTime;

    // Adjust the hue to skip yellow
    hue += 2; // Adjust this value to control the speed of the rainbow
    if (hue >= 32 && hue <= 64) {
      hue = 75; // Skip yellow range
    }

    // Set the lower row (first 8 LEDs) to a rainbow color excluding yellow
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(96, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void rainbowBounceWithoutYellowAndGreenPulse() {
  static uint8_t hue = 0;               // Hue value for the rainbow effect
  static int hueDirection = 1;          // Direction of hue change (1 = forward, -1 = backward)
  static uint8_t pulseBrightness = 150; // Initial brightness for the green pulse
  static int pulseDirection = 1;        // Direction of the brightness change (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0;  // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 50ms
  if (currentTime - lastUpdate > 100) {
    lastUpdate = currentTime;

    // Adjust hue with direction
    hue += hueDirection * 2; // Change this value to control the speed of the rainbow
    if (hue >= 15 && hue <= 85) {
      hueDirection = -hueDirection; // Reverse direction near yellow range
      delay(200);
      hue += hueDirection * 2;      // Step back immediately to avoid yellow
      delay(200);
    }

    // Set the lower row (first 8 LEDs) to a rainbow color excluding yellow
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(hue, 255, 255); // Full saturation and brightness
    }

    // Set the upper row (last 12 LEDs) to pulsing green
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(96, 255, pulseBrightness); // Green hue with current brightness
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void theaterMode() {
  static uint8_t dimmer = 255; // Controls the dimming effect (0 = off, 255 = full brightness)
  static int dimDirection = -1; // Direction of dimming (1 = brightening, -1 = dimming)
  static uint8_t pulseBrightness = 100; // Initial brightness for pulsing LEDs
  static int pulseDirection = 1; // Direction of pulsing (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 30ms for a smooth effect
  if (currentTime - lastUpdate > 30) {
    lastUpdate = currentTime;

    // Adjust dimmer value for the bottom 8 LEDs (create a theater fade effect)
    dimmer += dimDirection * 5; // Slowly fade in or out
    if (dimmer >= 255 || dimmer <= 50) {
      dimDirection = -dimDirection; // Reverse direction once it reaches the limits
    }

    // Set the bottom 8 LEDs (theater mode fade)
    for (int i = 0; i < 8; i++) {
      leds[i] = CRGB(dimmer, dimmer, dimmer); // Dim LEDs equally for a soft fade
    }

    // Pulse the top 12 LEDs with soft green or any color you prefer
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CHSV(96, 255, pulseBrightness); // Green hue for a gentle pulse
    }

    // Adjust pulse brightness
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void reversedTheaterMode() {
  static uint8_t dimmer = 255; // Controls the dimming effect (0 = off, 255 = full brightness)
  static int dimDirection = -1; // Direction of dimming (1 = brightening, -1 = dimming)
  static uint8_t pulseBrightness = 100; // Initial brightness for pulsing LEDs
  static int pulseDirection = 1; // Direction of pulsing (1 = brighter, -1 = dimmer)
  static unsigned long lastUpdate = 0; // Last update time for animation

  unsigned long currentTime = millis();

  // Update animation every 30ms for a smooth effect
  if (currentTime - lastUpdate > 30) {
    lastUpdate = currentTime;

    // Adjust dimmer value for the top 12 LEDs (create a theater fade effect)
    dimmer += dimDirection * 5; // Slowly fade in or out
    if (dimmer >= 255 || dimmer <= 50) {
      dimDirection = -dimDirection; // Reverse direction once it reaches the limits
    }

    // Set the top 12 LEDs (theater mode fade to white)
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i] = CRGB(dimmer, dimmer, dimmer); // Fade in/out with white
    }

    // Pulse the bottom 8 LEDs with soft green color
    for (int i = 0; i < 8; i++) {
      leds[i] = CHSV(96, 255, pulseBrightness); // Green hue for a gentle pulse
    }

    // Adjust pulse brightness for bottom row
    pulseBrightness += pulseDirection * 5; // Change brightness smoothly
    if (pulseBrightness >= 200 || pulseBrightness <= 100) {
      pulseDirection = -pulseDirection; // Reverse direction when reaching limits
    }

    // Show the updated LEDs
    FastLED.show();
  }
}

void circusAnimation() {
  static unsigned long lastUpdate = 0; // Last update time for animation
  static uint8_t colorIndex = 0; // Index to cycle through colors
  static uint8_t bottomColorIndex = 0; // Index for the bottom row flashing effect
  static uint8_t flashCounter = 0; // Flash counter for bottom row
  
  unsigned long currentTime = millis();

  // Update every 100ms for fast, energetic animation
  if (currentTime - lastUpdate > 200) {
    lastUpdate = currentTime;

    // Update top row (12 LEDs) with alternating bright colors (Red, Yellow, Green, Blue)
    for (int i = 8; i < NUM_LEDS; i++) {
      switch (colorIndex) {
        case 0: leds[i] = CRGB::Red; break;
        case 1: leds[i] = CRGB::Purple; break;
        case 2: leds[i] = CRGB::Crimson; break;
        case 3: leds[i] = CRGB::Blue; break;
      }
    }

    // Update bottom row (8 LEDs) with flashing lights (Yellow and Red)
    if (flashCounter < 5) {
      for (int i = 0; i < 8; i++) {
        switch (bottomColorIndex) {
          case 0: leds[i] = CRGB::Purple; break;
          case 1: leds[i] = CRGB::Red; break;
        }
      }
      flashCounter++;
    } else {
      // Change flash every 5 counts to alternate between colors
      bottomColorIndex = (bottomColorIndex + 1) % 2;
      flashCounter = 0; // Reset flash counter
    }

    // Cycle colors for the top row
    colorIndex = (colorIndex + 1) % 4;

    // Show the updated LEDs
    FastLED.show();
  }
}

void PoliceAnimation() {
  static unsigned long lastUpdate = 0; // Last update time for animation
  static uint8_t colorIndex = 0; // Index to cycle through colors
  static uint8_t bottomColorIndex = 0; // Index for the bottom row flashing effect
  static uint8_t flashCounter = 0; // Flash counter for bottom row
  static unsigned long lastStrobeUpdate = 0; // Last time strobe effect was updated
  static bool strobeEffect = false; // Strobe effect toggle
  unsigned long currentTime = millis();

  // Update every 100ms for fast, energetic animation
  if (currentTime - lastUpdate > 150) {
    lastUpdate = currentTime;

    // Create the random strobe effect (changing colors quickly)
    if (currentTime - lastStrobeUpdate > random(50, 150)) { // Random strobe interval
      strobeEffect = !strobeEffect;
      lastStrobeUpdate = currentTime;
    }

    // Top Row (12 LEDs): Random strobe effect with cycling colors
    if (strobeEffect) {
      for (int i = 8; i < NUM_LEDS; i++) {
        switch (random(0, 4)) { // Randomly pick one of the four colors
          case 0: leds[i] = CRGB::Red; break;
          case 1: leds[i] = CRGB::Blue; break;
          case 2: leds[i] = CRGB::DarkRed; break;
          case 3: leds[i] = CRGB::Blue; break;
        }
      }
    } else {
      // Slowly cycle through the colors
      for (int i = 8; i < NUM_LEDS; i++) {
        switch (colorIndex) {
          case 0: leds[i] = CRGB::Red; break;
          case 1: leds[i] = CRGB::Blue; break;
          case 2: leds[i] = CRGB::DarkRed; break;
          case 3: leds[i] = CRGB::Blue; break;
        }
      }
    }

    // Bottom Row (8 LEDs): Flashing between Yellow and Red, with a strobe effect
    if (strobeEffect) {
      for (int i = 0; i < 8; i++) {
        leds[i] = (random(0, 2) == 0) ? CRGB::Blue : CRGB::Red; // Random flash between Yellow and Red
      }
    } else {
      // Flash between Yellow and Red at a regular pace
      if (flashCounter < 5) {
        for (int i = 0; i < 8; i++) {
          leds[i] = (bottomColorIndex == 0) ? CRGB::Blue : CRGB::Red;
        }
        flashCounter++;
      } else {
        // Change flash every 5 counts to alternate between colors
        bottomColorIndex = (bottomColorIndex + 1) % 2;
        flashCounter = 0; // Reset flash counter
      }
    }

    // Cycle colors for the top row slowly when not in strobe mode
    if (!strobeEffect) {
    for (int i = 8; i < NUM_LEDS; i++) {
      leds[i].fadeToBlackBy(10); // Adjust fade speed as desired
      
      }

      colorIndex = (colorIndex + 1) % 4;
    }

    // Show the updated LEDs
    FastLED.show();
  }
}
