#include <stdlib.h>
#include <stdio.h>

typedef struct Rectangle
{
    float width;
    float height;
} Rectangle;

double calculate_area(Rectangle *rect)
{
    return rect->width * rect->height;
}

int main(int argc, char** argv)
{
    Rectangle *rect = (Rectangle*) malloc(sizeof(Rectangle));
    printf("What is the width of the rectangle? ");
    scanf("%f", &rect->width);
    printf("What is the height of the rectangle? ");
    scanf("%f", &rect->height);
    double area = calculate_area(rect);
    printf("The area of the rectangle is %f\n", area);
    free(rect);
    return 0;
    }