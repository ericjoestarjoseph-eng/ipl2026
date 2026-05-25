#include <stdio.h>
#include <string.h>
#include <math.h>

#define WIDTH 81
#define HEIGHT 41

// Structure to define a circle
typedef struct {
    int centerX;
    int centerY;
    int radius;
} Circle;

// Global 2D buffer
char buffer[HEIGHT][WIDTH];

// Function to initialize the buffer with spaces
void initializeBuffer(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            buffer[i][j] = ' ';
        }
    }
}


// Function to check if a point should be on the circle
int isOnCircle(int x, int y, Circle circle) {
    int dx = x - circle.centerX;
    int dy = y - circle.centerY;
    int distSquared = dx * dx + dy * dy;
    int radiusSquared = circle.radius * circle.radius;
    
    // Check if point is within 1 unit of the circle boundary
    return (distSquared >= radiusSquared - circle.radius && 
            distSquared <= radiusSquared + circle.radius);
}

// Function to draw the circle on the buffer
void drawCircle(Circle circle) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (isOnCircle(x, y, circle)) {
                buffer[y][x] = '*';
            }
        }
    }
}

// Function to display the buffer on screen
void displayBuffer(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(void) {
    // Create a circle structure
    Circle circle;
    circle.centerX = 40;  // Center at (40, 20)
    circle.centerY = 20;
    circle.radius = 15;
    
    // Initialize the buffer
    initializeBuffer();
    
    // Draw the circle on the buffer
    drawCircle(circle);
    
    // Display the buffer
    displayBuffer();
    
    return 0;
}
