																					/*header guard*/
#pragma once
#ifndef CUBE_H							
#define CUBE_H
																					/*important diffinitions*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <Windows.h>

																					/*variable initialization stage*/
float A, B, C;

float Cubewidth = 30;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCII = ' ';
int distancefromCam = 260;
int horizontaloffset;
float K1 = 40;


float incrementspeed = 0.8;

float x, y, z;
float ooz;
int xp, yp;
int idx;



																						/*function diffinition*/
/*
float RotateX(int i, int j, int k);

float RotateY(int i, int j, int k);

float RotateZ(int i, int j, int k);

void CalculateSurface(float cubeX, float cubeY, float cubeZ, int ch);
*/

#endif