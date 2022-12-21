#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct pixel
{
    short int R = 255;
    short int G = 255;
    short int B = 255;
};

void draw(pixel image[100][100], int x, int y, int l, int h, pixel color)
{
    for (int i = y; i < y + h; i++)
    {
        for (int j = x; j < x + l; j++)
        {
            image[i][j] = color;
        }
    }
}

int main()
{
    pixel image[100][100];
    int n;
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    duom >> n;
    int x_min = 100, y_min = 100, y_max = 0, x_max = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, l, h;
        pixel color;
        duom >> x >> y >> l >> h >> color.R >> color.G >> color.B;
        //x--;
        //y--;
        draw(image, x, y, l, h, color);
        if (x_min > x) { x_min = x; }
        if (y_min > y) { y_min = y; }
        if (x_max < x + l) { x_max = x + l; }
        if (y_max < y + h) { y_max = y + h; }
    }
    cout << x_min << ' ' << x_max << ' ' << y_min << ' ' << y_max << '\n';
    rez << y_max - y_min << ' ' << x_max - x_min << '\n';

    for (int i = y_min; i < y_max; i++)
    {
        for (int j = x_min; j < x_max; j++)
        {
            rez << image[i][j].R << ' ' << image[i][j].G << ' ' << image[i][j].B << '\n';
        }
    }


    duom.close();
    rez.close();
    return 0;
}