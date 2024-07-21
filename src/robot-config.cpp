#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;


// A global instance of brain used for printing to the V5 Brain screen.
motor leftDriveA = motor(PORT2, ratio6_1, true);
motor leftDriveB = motor(PORT1, ratio6_1, true); 
motor leftDriveC = motor(PORT4, ratio6_1, true);

motor rightDriveA = motor(PORT3, ratio6_1, false);
motor rightDriveB = motor(PORT6, ratio6_1, false); 
motor rightDriveC = motor(PORT8, ratio6_1, false);

inertial DrivetrainInertial = inertial(PORT5);

controller Controller1 = controller(primary);
brain Brain;

motor Intake = motor(PORT12, ratio6_1, true);
motor Arm = motor(PORT9, ratio6_1, true); 
digital_out Claw = digital_out(BigBrain.ThreeWirePort.A);

motor_group LeftDriveSmart = motor_group(leftDriveA, leftDriveB, leftDriveC);

motor_group RightDriveSmart = motor_group(rightDriveA, rightDriveB, rightDriveC);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 299.24, 320, 40, mm, 0.6);


/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
TANK_TWO_ENCODER,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2"

//Left Motors:
LeftDriveSmart,

//Right Motors:
RightDriveSmart,

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT4,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1.6666666666666666666666666666667,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
7, //Will do later

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
1.75,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
5,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
1.5

);

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}