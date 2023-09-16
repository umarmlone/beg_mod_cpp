#include "cube.h"

/*creating the rotating equations*/
float RotateX(int i, int j, int k)
{

    return j * sin(A) * sin(B) *cos(C)- k * cos(A) * sin(B) * cos(C) + 
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float RotateY(int i, int j, int k)
{

    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
           j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);


}

float RotateZ(int i, int j, int k)
{

    return k * cos(A) * cos(B) -
           j * sin(A) * cos(B) +
           i * sin(B);
}

/*creating a function to calculate the surface of one face of the cube*/
void CalculateSurface(float cubeX, float cubeY, float cubeZ, int ch)
{
    x = RotateX(cubeX, cubeY, cubeZ);
    y = RotateY(cubeX, cubeY, cubeZ);
    z = RotateZ(cubeX, cubeY, cubeZ) + distancefromCam;

    ooz = 1 / z; 

    xp = (int)(width / 2 + horizontaloffset + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    idx = xp + yp * width;
    if (idx >= 0 && idx < width * height)
    {
        if (ooz > zBuffer[idx])
        {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }

}

int main()
{
    printf("\x1b[2J");
    while (1)
    {
        memset(buffer, backgroundASCII, width * height);
        memset(zBuffer, 0, width * height * 4);
        Cubewidth = 30; //initiating the first cube 
        horizontaloffset = -2 * Cubewidth; //getting offset between the first cube;

        //first cube rotating
        for (float cubeX = -Cubewidth ; cubeX < Cubewidth ; cubeX += incrementspeed)
        {
            for (float cubeY = -Cubewidth ; cubeY < Cubewidth ; cubeY += incrementspeed)
            {
                CalculateSurface(cubeX, cubeY, -Cubewidth, '#');       //x y z
                CalculateSurface(Cubewidth, cubeY, cubeX, '#');       //-z y x
                CalculateSurface(-Cubewidth, cubeY, -cubeX, '#');    //z y -x
                CalculateSurface(-cubeX, cubeY, Cubewidth, '#');    //-x y -z
                CalculateSurface(cubeX, -Cubewidth, -cubeY, '#');  //x -z y
                CalculateSurface(cubeX, Cubewidth, cubeY, '#');   //x -z y
            }
        }
        Cubewidth = 20; //initiating the first cube 
        horizontaloffset = 1 * Cubewidth; //getting offset between the first cube;

        //second cube rotating
        for (float cubeX = -Cubewidth; cubeX < Cubewidth; cubeX += incrementspeed)
        {
            for (float cubeY = -Cubewidth; cubeY < Cubewidth; cubeY += incrementspeed)
            {
                CalculateSurface(cubeX, cubeY, -Cubewidth, '#');       //x y z
                CalculateSurface(Cubewidth, cubeY, cubeX, '#');       //-z y x
                CalculateSurface(-Cubewidth, cubeY, -cubeX, '#');    //z y -x
                CalculateSurface(-cubeX, cubeY, Cubewidth, '#');    //-x y -z
                CalculateSurface(cubeX, -Cubewidth, -cubeY, '#');  //x -z y
                CalculateSurface(cubeX, Cubewidth, cubeY, '#');   //x -z y
            }
        }
        Cubewidth = 8; //initiating the first cube 
        horizontaloffset = 8 * Cubewidth; //getting offset between the first cube;

        //third cube rotating
        for (float cubeX = -Cubewidth; cubeX < Cubewidth; cubeX += incrementspeed)
        {
            for (float cubeY = -Cubewidth; cubeY < Cubewidth; cubeY += incrementspeed)
            {
                CalculateSurface(cubeX, cubeY, -Cubewidth, '#');       //x y z
                CalculateSurface(Cubewidth, cubeY, cubeX, '#');       //-z y x
                CalculateSurface(-Cubewidth, cubeY, -cubeX, '#');    //z y -x
                CalculateSurface(-cubeX, cubeY, Cubewidth, '#');    //-x y -z
                CalculateSurface(cubeX, -Cubewidth, -cubeY, '#');  //x -z y
                CalculateSurface(cubeX, Cubewidth, cubeY, '#');   //x -z y
            }
        }

        printf("\x1b[H");
        for (int k = 0; k < width * height; k++)
        {
            putchar(k % width ? buffer[k] : 10);
        }
        A += 0.26;
        B += 0.26;
        C += 0.26;
        Sleep(10);

    }

    return 0;

}