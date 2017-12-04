/** 
    Added to git hub.
    Old Version
    @author Matthew Cline
    @version 1.21 10/6/17 
    
    InnerSolar Trip Calculator.
    
    Add Maximum Velocity is m/s and mph
    
    Notes: allow user to select input increments and select output.
    allow to select travel times for distance by dividing in half for space craft deceleration time. 
    display Planet or object of interest. distances
*/
    
#include <iostream>
#include <cmath>
#include <iomanip> // for rounding, in certain versions.
using namespace std;

int main()
{
    double acceleration = 0, time = 0, travelHours = 0, velocity = 0, destination = 0, velocityMiles = 0,
           timeWithFlip = 0, travelHoursFlip = 0, travelDays = 0, travelDaysFlip = 0,
           timeHalf = 0, velocityHalf = 0, velocityHalfMiles; 
    const double AU_METERS = 1.496e11; // Meters in one AU
    const double MILES_METERS = 1609.34; // Miles per Kilometer.
    const int SEC_HOUR_CONVERT = 1800, HOURS_DAY = 24;
    double mercury = .387, venus = .723, moon = 384000000 / AU_METERS, mars = 1.52, jupiter = 5.2, saturn = 9.58,
         uranus = 19.2, neptune = 30.05, pluto = 39.48;
    char repeat = 'y';
    
  while (repeat == 'y'){
    
    cout << "Welcome to Matt's innersolar space travel time calculator.\n" << endl;
    cout << "In this simulation you may travel to the listed destination\n" <<
            "1)Mercury\n2)Venus\n3)Moon\n4)Mars\n5)Jupiter\n6)Saturn\n7)Uranus\n8)Neptune\n9)Pluto\n10)User Input AU.\n"
            << "Please enter the numeric value of your destination.\n";
    cin >> destination; 
    
   do {
    if (cin.fail()){ //cin.fail for was need for some versions.
        cin.clear();
        cin.ignore(100,'\n');
        cout << "~~~~~WARNING~~~~~~ INVALID INPUT ~~~~~Please input valid numeric destination.\n";
        cin >> destination;
    } else if ( destination == 1){
        destination = mercury;
    } else if ( destination == 2 ) {
        destination = venus;
    } else if ( destination == 3 ) {
        destination = moon;   
    } else if ( destination == 4 ) {
        destination = mars;
    } else if ( destination == 4 ) {
        destination = jupiter;
    } else if ( destination == 6 ) {
        destination = saturn;
    } else if ( destination == 7 ) {
        destination = uranus;
    } else if ( destination == 8 ) {
        destination = neptune;
    } else if ( destination == 9 ) {
        destination = pluto;
    } else if ( destination == 10 ) {
        cout << "Input AU to travel ";
        cin >> destination;
    } else if ( destination > 10 || destination < 1 ) {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "~~~~~WARNING~~~~~~ INVALID INPUT ~~~~~Please input valid numeric destination.\n";
        cin >> destination;
    }
   } while (cin.fail());
    
    cout << "Input acceleration rate in m/s^2: ";
    cin >> acceleration;
    
    //cin >> inputdDistance// left off here
    /* Old code input data
    cout << "Input time traveled in hours(Hours.with decimals): ";
    cin >> travelHours;
    cout << endl;
    */
    
    time = sqrt(( (destination * AU_METERS) / (.5 * acceleration)));
    timeWithFlip = sqrt(( (destination /2 * AU_METERS) / (.5 * acceleration))) * 2;
    travelHours = time / SEC_HOUR_CONVERT;
    travelHoursFlip = timeWithFlip / SEC_HOUR_CONVERT;
    timeHalf = sqrt(( (destination /2 * AU_METERS) / (.5 * acceleration)));
    
    velocity = acceleration * time;
    velocityMiles = velocity / MILES_METERS * SEC_HOUR_CONVERT;
    velocityHalf = acceleration * timeHalf;
    velocityHalfMiles = velocityHalf / MILES_METERS * SEC_HOUR_CONVERT;
    
    travelDays = travelHours / HOURS_DAY;
    travelDaysFlip = travelHoursFlip / HOURS_DAY;
    
    cout << endl << "It would take\n" << travelHours << " Hours to fly to your destination.\n" << "or\n" 
         << travelDays << " Days" << endl;
    cout << "With a Maximum velocity of\n" << fixed << setprecision(2) << velocity << "meters/second\n" <<
         velocityMiles << "mph" << endl << endl;
    cout << "If you want to stop at your destination it would take\n" << travelHoursFlip << " Hours.\n" << "or\n"
         << travelDaysFlip << " Days" << endl << "With a Maxiumum velocity of\n" << velocityHalf << " Meter / second\n"
         << velocityHalfMiles << " MPH\n";
         
    cout << "Would you like to run this program again (y/n): ";
    cin >> repeat;
    
    
    
    
    
    /* Old Code for distance and velocity
    secondsTraveled = travelHours * SEC_HOUR_CONVERT;
    secondsTraveled = round(secondsTraveled);
    velocity = acceleration * secondsTraveled;
    distance = .5 * acceleration * secondsTraveled * secondsTraveled;
    
    cout << "In " << travelHours << " hours, traveling at " << velocity << 
        "m/s^2 your space craft would have traveled " <<
         fixed << (int) distance << " meters." << endl;
    */
    
    
  }

    return 0;
}





/**
    @author Matthew Cline
    @version 1.21 10/6/17 
    
    InnerSolar Trip Calculator.
    
    Add Maximum Velocity is m/s and mph
    
    Notes: allow user to select input increments and select output.
    allow to select travel times for distance by dividing in half for space craft deceleration time. 
    display Planet or object of interest. distances
*
    
#include <iostream>
#include <cmath>
#include <iomanip> // for rounding, in certain versions.
using namespace std;

int main()
{
    double acceleration = 0, time = 0, travelHours = 0, velocity = 0, destination = 0, velocityMiles = 0,
           timeWithFlip = 0, travelHoursFlip = 0, travelDays = 0, travelDaysFlip = 0,
           timeHalf = 0, velocityHalf = 0, velocityHalfMiles; 
    const double AU_METERS = 1.496e11; // Meters in one AU
    const double MILES_METERS = 1609.34; // Miles per Kilometer.
    const int SEC_HOUR_CONVERT = 1800, HOURS_DAY = 24;
    double mercury = .387, venus = .723, moon = 384000000 / AU_METERS, mars = 1.52, jupiter = 5.2, saturn = 9.58,
         uranus = 19.2, neptune = 30.05, pluto = 39.48;
    char repeat = 'y';
    //array
    double inputDestination[] = 0, mercury, venus, moon, mars, jupiter, saturn, uranus, neptune, pluto;
    
  while (repeat == 'y'){
    
    cout << "Welcome to Matt's innersolar space travel time calculator.\n" << endl;
    cout << "In this simulation you may travel to the listed destination\n" <<
            "1)Mercury\n2)Venus\n3)Moon\n4)Mars\n5)Jupiter\n6)Saturn\n7)Uranus\n8)Neptune\n9)Pluto\n10)User Input AU.\n"
            << "Please enter the numeric value of your destination.\n";
            
    cin >> inputDestination[];
    
    destination = inputDestination[];
    / Old code
    
    cin >> destination; 
    
   do {
    if (cin.fail()){ //cin.fail for was need for some versions.
        cin.clear();
        cin.ignore(100,'\n');
        cout << "~~~~~WARNING~~~~~~ INVALID INPUT ~~~~~Please input valid numeric destination.\n";
        cin >> destination;
    } else if ( destination == 1){
        destination = mercury;
    } else if ( destination == 2 ) {
        destination = venus;
    } else if ( destination == 3 ) {
        destination = moon;   
    } else if ( destination == 4 ) {
        destination = mars;
    } else if ( destination == 4 ) {
        destination = jupiter;
    } else if ( destination == 6 ) {
        destination = saturn;
    } else if ( destination == 7 ) {
        destination = uranus;
    } else if ( destination == 8 ) {
        destination = neptune;
    } else if ( destination == 9 ) {
        destination = pluto;
    } else if ( destination == 10 ) {
        cout << "Input AU to travel ";
        cin >> destination;
    } else {
        destination = "fail";
    }
   } while (cin.fail());
    *
    
    
    
    cout << "Input acceleration rate in m/s^2: ";
    cin >> acceleration;
    
    //cin >> inputdDistance// left off here
    / Old code input data
    cout << "Input time traveled in hours(Hours.with decimals): ";
    cin >> travelHours;
    cout << endl;
    *
    
    time = sqrt(( (destination * AU_METERS) / (.5 * acceleration)));
    timeWithFlip = sqrt(( (destination /2 * AU_METERS) / (.5 * acceleration))) * 2;
    travelHours = time / SEC_HOUR_CONVERT;
    travelHoursFlip = timeWithFlip / SEC_HOUR_CONVERT;
    timeHalf = sqrt(( (destination /2 * AU_METERS) / (.5 * acceleration)));
    
    velocity = acceleration * time;
    velocityMiles = velocity / MILES_METERS * SEC_HOUR_CONVERT;
    velocityHalf = acceleration * timeHalf;
    velocityHalfMiles = velocityHalf / MILES_METERS * SEC_HOUR_CONVERT;
    
    travelDays = travelHours / HOURS_DAY;
    travelDaysFlip = travelHoursFlip / HOURS_DAY;
    
    cout << endl << "It would take\n" << travelHours << " Hours to fly to your destination.\n" << "or\n" 
         << travelDays << " Days" << endl;
    cout << "With a Maximum velocity of\n" << fixed << setprecision(2) << velocity << "meters/second\n" <<
         velocityMiles << "mph" << endl << endl;
    cout << "If you want to stop at your destination it would take\n" << travelHoursFlip << " Hours.\n" << "or\n"
         << travelDaysFlip << " Days" << endl << "With a Maxiumum velocity of\n" << velocityHalf << " Meter / second\n"
         << velocityHalfMiles << " MPH\n";
         
    cout << "Would you like to run this program again (y/n): ";
    cin >> repeat;
    
    
    
    
    
    / Old Code for distance and velocity
    secondsTraveled = travelHours * SEC_HOUR_CONVERT;
    secondsTraveled = round(secondsTraveled);
    velocity = acceleration * secondsTraveled;
    distance = .5 * acceleration * secondsTraveled * secondsTraveled;
    
    cout << "In " << travelHours << " hours, traveling at " << velocity << 
        "m/s^2 your space craft would have traveled " <<
         fixed << (int) distance << " meters." << endl;
    *
    
    
  }

    return 0;
}

*/



























