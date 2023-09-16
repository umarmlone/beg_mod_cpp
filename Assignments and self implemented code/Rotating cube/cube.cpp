
/*creating the rotating equations*
float RotateX(int i, int j, int k)
{

    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
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


*creating a function to calculate the surface of one face of the cube*
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
*/