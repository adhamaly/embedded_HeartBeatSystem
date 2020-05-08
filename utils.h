/*
 * utils.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */


#ifndef UTILS_H_
#define UTILS_H_
/*
  SET current bit used for (Direction and Output "write voltage" HIGH)
  set the current using bit and does not affect other bits in Register..set bit only(       ÊÎáí Çí ÈÊ ÊÓÇæí 1  )
operation ... PORTX = PORTX OR (left shift of pinnum for 1)
EX:-
 SET_BIT(PORT,pin0)
*/
#define SET_BIT(x,b) (x |= (1<<b))
#define TOG_BIT(x,b) (x^= (1<<b))
/*
   clear current bit == used for (Direction and output voltage value LOW)
   Operation ..  PORTX = PORTX AND NOT(LEFT SHIFT FOR PINNUM) Îáí Çí ÈÊ ÊÓÇæí 0
   ex:-
   CLR_BIT(PORTA,Pin0)
 */
#define CLR_BIT(x,b) (x&= ~(1<<b))
#define GET_BIT(x,b) ((x & (1<<b))>>b)
/*
  read current bit
operation ..( PINX AND (left shift of pinnum for 1) ) >> PinNum
EX:-
 GET_BIT(PINA,pin0)
*/


#endif /* UTILS_H_ */
