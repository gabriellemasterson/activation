//activation thread

//DESCRIPTION: this is a branch off of the code for the RockSat mission in which we are ejecting
//a payload from NASA's rocketship in order to collect re-entry data
//
//GOAL: the code for the last ISS flight had a different activation where the capsule was powered on 
//by the astronaut pulling out a tab. Following this, the capsule was programmed to enter a dormant, 
//low-power state in which the flight computer was just checking whether or not full activation should 
//occur. For this flight, we are skipping the low-power state and we want the capsule to activate 
//fully after the pull tab is removed (the pints attached to the ejection mechanism raher than an 
//astronaut pulling out a tab). We will be adding one more function where the capsule is to remain 
//in a low power state for 5 seconds after activation. Therefore, if there are vibarations during 
//launch between the capsule and the activation pins, we are not turning on and off the capsule 
//repeatedly.
//
//MAIN DIFFERENCE: Conditions for full activation. In the current code, the flight computer does a 
//continuity check between the outside shell to see if activation should occur. In our current
//flight, there is no continuity check, it should just wait 5 seconds because we want to ensure
//that it does not fully activate until its confirmed to be ejected.
//
//AUTHOR: Gabrielle Masterson (Note that orginal code that I am referencing was developed by Matt Rufner)
//
//DATE: April 4th, 2022

// have we detected activation
volatile bool activation = false;
Threads::Mutex act_lock;

// activation condition detected on thermocouples
volatile bool tcAct = false;
Threads::Mutex tcAct_lock;

// activation detected on capacitive sensor
volatile bool capAct = false;
Threads::Mutex capAct_lock;

   if( !mAct ){
      safeUpdate(&mAct, &activation, &act_lock);
    }



