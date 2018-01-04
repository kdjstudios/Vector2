/*
 * main.cpp
 *
 *  Created on: Dec 12, 2011
 *      Author: kyle
 */
#include "Vector2.h"
#include <iostream>
using namespace AO::Vector2;
using namespace std;

int main()
{
// Demonstrates other copy constructor, static member variable usage, and unary operator-
//const Vector3 backward(-Vector3::Forward);
const Vector2 backward(Vector2::Zero);
// Demonstrates cross product
const Vector2 right( crossVec(Vector2::Zero,Vector2::One));

// Demonstrates constructor
Vector2 testVect(10.0f, 30.0f);

// Demonstrates operator<<
cout << testVect << '\n';
// Demonstrates clamp/truncate method
truncate(testVect,3);
cout << "truncated at 3: " << testVect << '\n';

// Demonstrates reflect method
const Vector2 reflection( reflect(testVect,backward) );
cout << "Reflected off surface with 'backward' as the normal, " << reflection << '\n';

// Demonstrates operator*, we don't const 'doubleFwd' because we want to use normalize later.
Vector2 doubleFwd(Vector2::One* 2);

cout << "Double Forward, " << doubleFwd << '\n';
cout << "Double Forward Length: " << mag(doubleFwd) << '\n';
norm(doubleFwd);
cout << "Normalized Double Forward, now what is the length?: " << mag(doubleFwd) << '\n';
zero(doubleFwd);
cout << "Zero out Double Forward, now what is the length?: " << doubleFwd << '\n';
//My compiler confuses 'distance' with an c iterator
cout << "Distance from Double Forward to Reflection: " << (float)AO::Vector2::dist(doubleFwd,reflection) << '\n';
Vector2 per( perp(backward) );
cout << "Perpendicular to 'backward':" << per << '\n';
cout << "Sign of Perpendicular and double(Not Working) " << sign(per,doubleFwd) << '\n';
// uncomment the following three lines for user input before closing
//cout << "Press any key to quit. ";
//char blah = ' ';
//cin.get(blah);

return 0;
}
