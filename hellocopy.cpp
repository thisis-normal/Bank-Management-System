#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

const double PI = 3.141592653589793;
const float x0 = 40.0;
const float yy = 19.0;
const float a = 15.0;
const float b = 7.0;

short marginLeft = 25;
short marginDown = 3;
int speed = 20;

short frameIn[25][35][78];
short frame[50][35][78];

void TextColor(short color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getHeartShapeIn(short frameIndex, short k);
void getHeartShape(short frameIndex, short k, short value);
void frameInitialize();
void heartIn();
void heartTransform();
void heartStart();
void heartLoop();

int main()
{
    srand(time(0));
    frameInitialize();
    system("cls");
    heartStart();
    while (1)
    {
        heartLoop();
    }
    return 0;
}

void getHeartShape(short frameIndex, short k, short value)
{
    for (short x = 1; x < 78; x++)
    {
        double coordinate1 = yy - b * (0.35 * fabs((x - x0) / a) - cos(k * PI / 12.0) - 0.5 * sqrt(4.0 * pow(cos(k * PI / 12.0), 2) - 3.51 * pow((x - x0) / a, 2.0) - 2.8 * fabs((x - x0) / a) * cos(k * PI / 12.0) - 8.0 * ((x - x0) / a) * sin(k * PI / 12.0)));
        double coordinate2 = yy - b * (0.35 * fabs((x - x0) / a) - cos(k * PI / 12.0) + 0.5 * sqrt(4.0 * pow(cos(k * PI / 12.0), 2) - 3.51 * pow((x - x0) / a, 2.0) - 2.8 * fabs((x - x0) / a) * cos(k * PI / 12.0) - 8.0 * ((x - x0) / a) * sin(k * PI / 12.0)));
        short y1 = (short)round(coordinate1);
        short y2 = (short)round(coordinate2);
        if (y1 != 0 && y2 != 0)
        {
            frame[frameIndex][y1][x] = value;
            frame[frameIndex][y2][x] = value;
        }
    }
}

void getHeartShapeIn(short frameIndex, short k)
{
    for (short x = 1; x < 78; x++)
    {
        double coordinate1 = yy - b * (0.35 * fabs((x - x0) / a) - cos(k * PI / 12.0) - 0.5 * sqrt(4.0 * pow(cos(k * PI / 12.0), 2) - 3.51 * pow((x - x0) / a, 2.0) - 2.8 * fabs((x - x0) / a) * cos(k * PI / 12.0) - 8.0 * ((x - x0) / a) * sin(k * PI / 12.0)));
        double coordinate2 = yy - b * (0.35 * fabs((x - x0) / a) - cos(k * PI / 12.0) + 0.5 * sqrt(4.0 * pow(cos(k * PI / 12.0), 2) - 3.51 * pow((x - x0) / a, 2.0) - 2.8 * fabs((x - x0) / a) * cos(k * PI / 12.0) - 8.0 * ((x - x0) / a) * sin(k * PI / 12.0)));
        short y1 = (short)round(coordinate1);
        short y2 = (short)round(coordinate2);
        if (y1 != 0 && y2 != 0)
        {
            frameIn[frameIndex][y1][x] = 1;
            frameIn[frameIndex][y2][x] = 1;
        }
    }
}

void heartIn()
{
    for (int k = 0; k < 25; k++)
        for (int i = 0; i <= k; i++)
            getHeartShapeIn(k, i);
}

void heartTransform()
{
    for (short k = 0; k < 25; k++)
    {
        for (short i = 0; i < 35; i++)
            for (short j = 0; j < 78; j++)
                frame[k][i][j] = frameIn[24][i][j];
        for (short i = 24; i > 23 - k; i--)
            getHeartShape(k, i, 2);
    }
    for (short k = 25; k < 50; k++)
        for (short i = 0; i < 35; i++)
            for (short j = 0; j < 78; j++)
                frame[k][i][j] = frame[49 - k][i][j];
}

void printPointA(short frameIndex, short x, short y);

void frameInitialize()
{
    for (short k = 0; k < 25; k++)
        for (short i = 0; i < 35; i++)
            for (short j = 0; j < 78; j++)
                frameIn[k][i][j] = 0;
    heartIn();
    heartTransform();
}

void heartStart()
{
    TextColor(5);
    for (short k = 0; k < 25; k++)
    {
        for (short i = 0; i < 35; i++)
            for (short j = 0; j < 78; j++)
                if (frameIn[k][i][j] == 1)
                {
                    gotoXY(j + marginLeft, i + marginDown);
                    printf("%c", (rand() % 2) ? 3 : '.');
                }
        Sleep(speed);
    }
}

void heartLoop()
{
    for (short t = 0; t < 8; t++)
    {
        for (short i = 0; i < 35; i++)
            for (short j = 0; j < 78; j++)
                if (frame[24][i][j] == 1)
                {
                    gotoXY(j + marginLeft, i + marginDown);
                    printf("%c", (rand() % 2) ? 3 : '.');
                }
        Sleep(speed);
    }

    short previousColor = 5;
    short nextColor;
    char previousChar = 3;
    char nextChar;
    do
    {
        nextColor = rand() % 5 + 2;
    } while (nextColor == previousColor);
    do
    {
        nextChar = rand() % 21 + 1;
    } while (nextChar == previousChar || (nextChar > 6 && nextChar < 11) || nextChar == 13);

    while (1)
    {
        for (short k = 0; k < 25; k++)
        {
            for (short i = 0; i < 35; i++)
            {
                for (short j = 0; j < 78; j++)
                {
                    if (frame[k][i][j] != 0)
                    {
                        gotoXY(j + marginLeft, i + marginDown);
                        if (frame[k][i][j] == 1)
                        {
                            if (previousColor != 2)
                            {
                                TextColor(previousColor);
                                printf("%c", (rand() % 2) ? '.' : previousChar);
                            }
                            else
                            {
                                TextColor(rand() % 8);
                                printf("%c", (rand() % 2) ? '.' : previousChar);
                            }
                        }
                        else
                        {
                            if (nextColor != 2)
                            {
                                TextColor(nextColor);
                                printf("%c", (rand() % 2) ? '.' : nextChar);
                            }
                            else
                            {
                                TextColor(rand() % 8);
                                printf("%c", (rand() % 2) ? '.' : nextChar);
                            }
                        }
                    }
                }
            }
            Sleep(speed);
        }
        for (short t = 0; t < 8; t++)
        {
            for (short i = 0; i < 35; i++)
            {
                for (short j = 0; j < 78; j++)
                {
                    if (frame[24][i][j] != 0)
                    {
                        gotoXY(j + marginLeft, i + marginDown);
                        if (nextColor != 2)
                        {
                            TextColor(nextColor);
                            printf("%c", (rand() % 2) ? '.' : nextChar);
                        }
                        else
                        {
                            TextColor(rand() % 8);
                            printf("%c", (rand() % 2) ? '.' : nextChar);
                        }
                    }
                }
            }
            Sleep(speed);
        }
        previousColor = nextColor;
        previousChar = nextChar;
        do
        {
            nextColor = rand() % 5 + 2;
        } while (nextColor == previousColor);
        do
        {
            nextChar = rand() % 21 + 1;
        } while (nextChar == previousChar || (nextChar > 6 && nextChar < 11) || nextChar == 13);

        for (short k = 25; k < 50; k++)
        {
            for (short i = 0; i < 35; i++)
            {
                for (short j = 0; j < 78; j++)
                {
                    if (frame[k][i][j] != 0)
                    {
                        gotoXY(j + marginLeft, i + marginDown);
                        if (frame[k][i][j] == 2)
                        {
                            if (previousColor != 2)
                            {
                                TextColor(previousColor);
                                printf("%c", (rand() % 2) ? '.' : previousChar);
                            }
                            else
                            {
                                TextColor(rand() % 8);
                                printf("%c", (rand() % 2) ? '.' : previousChar);
                            }
                        }
                        else
                        {
                            if (nextColor != 2)
                            {
                                TextColor(nextColor);
                                printf("%c", (rand() % 2) ? '.' : nextChar);
                            }
                            else
                            {
                                TextColor(rand() % 8);
                                printf("%c", (rand() % 2) ? '.' : nextChar);
                            }
                        }
                    }
                }
            }
            Sleep(speed);
        }
        for (short t = 0; t < 8; t++)
        {
            for (short i = 0; i < 35; i++)
            {
                for (short j = 0; j < 78; j++)
                {
                    if (frame[49][i][j] != 0)
                    {
                        gotoXY(j + marginLeft, i + marginDown);
                        if (nextColor != 2)
                        {
                            TextColor(nextColor);
                            printf("%c", (rand() % 2) ? '.' : nextChar);
                        }
                        else
                        {
                            TextColor(rand() % 8);
                            printf("%c", (rand() % 2) ? '.' : nextChar);
                        }
                    }
                }
            }
            Sleep(speed);
        }
        previousColor = nextColor;
        previousChar = nextChar;
        do
        {
            nextColor = rand() % 5 + 2;
        } while (nextColor == previousColor);
        do
        {
            nextChar = rand() % 21 + 1;
        } while (nextChar == previousChar || (nextChar > 6 && nextChar < 11) || nextChar == 13);
    }
}