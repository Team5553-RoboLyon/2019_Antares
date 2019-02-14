#pragma once

// PWM MOTORS
#define PWM_ROUES_PINCE_1 0
#define PWM_ROUES_PINCE_2 1

#define PWM_BASE_DROITE_1 3
#define PWM_BASE_DROITE_2 5
#define PWM_BASE_DROITE_3 7

#define PWM_BASE_GAUCHE_1 2
#define PWM_BASE_GAUCHE_2 4
#define PWM_BASE_GAUCHE_3 6

// CAN MOTORS
#define CAN_PIVOT 0

// DIO ENCODEURS
#define DIO_ENCODEUR_GAUCHE_A 0
#define DIO_ENCODEUR_GAUCHE_B 1

#define DIO_ENCODEUR_DROIT_A 2
#define DIO_ENCODEUR_DROIT_B 3

// PCM PNEUMATICS
#define PCM_HATCH_PINCE_A 0
#define PCM_HATCH_PINCE_B 1

#define PCM_PISTONS_PINCE_A 2
#define PCM_PISTONS_PINCE_B 3

#define PCM_VERIN_PINCE_A 4
#define PCM_VERIN_PINCE_B 5

#define PCM_BALLSHIFTER_A 6
#define PCM_BALLSHIFTER_B 7


/* TABLEAU DE CABLAGE du ROBORIO
 *
 * 	RS-232	->
 *
 * 	DIO-0	->    Encodeur Base Gauche A
 * 	DIO-1	->    Encodeur Base Gauche B
 * 	DIO-2	->    Encodeur Base Droite A
 * 	DIO-3	->    Encodeur Base Droite B
 * 	DIO-4	->
 * 	DIO-5	->
 * 	DIO-6	->
 * 	DIO-7	->
 * 	DIO-8	->
 * 	DIO-9	->
 *
 *  RELAY-0	->
 *  RELAY-1	->
 *  RELAY-2	->
 *  RELAY-3	->
 *
 *  ANALOG IN -0 	->
 *  ANALOG IN -1 	->
 *  ANALOG IN -2 	->
 *  ANALOG IN -3 	->
 *
 *
 * 	PWM-0	->    Roues Pince 1
 * 	PWM-1	->    Roues Pince 2
 * 	PWM-2	->    Base Gauche 1
 * 	PWM-3	->    Base Droite 1
 * 	PWM-4	->    Base Gauche 2
 * 	PWM-5	->    Base Droite 2
 * 	PWM-6	->    Base Gauche 3
 * 	PWM-7	->    Base Droite 3
 * 	PWM-8	->
 * 	PWM-9	->
 *
 *
 * TABLEAU DE CABLAGE du PCM (Pneumatic Control Module)
 *
 *  PCM-0	->    Pince Hatch A
 *  PCM-1	->    Pince Hatch B
 *  PCM-2	->    Pistons Hatch A
 *  PCM-3	->    Pistons Hatch B
 *  PCM-4	->    Verin Pince A
 *  PCM-5	->    Verin Pince B
 *  PCM-6	->    Ballshifter A
 *  PCM-7	->    Ballshifter B
 *
 * 
 * TABLEAU DES ID DU CAN BUS
 * 
 *  Neo n°0 ->    Pivot
 */