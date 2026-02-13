
package ui;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

public class GridRenderer {
    private static final int GRID_DIVISIONS = 10;

    /**
     * Draws a 10x10 grid on the given Graphics2D context
     * 
     * @param g2d    Graphics2D context to draw on
     * @param width  Width of the drawable area
     * @param height Height of the drawable area
     */
    public void drawGrid(Graphics2D g2d, int width, int height) {
        // Save original color
        Color originalColor = g2d.getColor();

        // Set color to black
        g2d.setColor(Color.BLACK);

        // Calculate cell width and height
        float cellWidth = (float) width / GRID_DIVISIONS;
        float cellHeight = (float) height / GRID_DIVISIONS;

        // Draw 10x10 grid using loops
        for (int i = 0; i <= GRID_DIVISIONS; i++) {
            // horizontal lines
            g2d.draw(new Line2D.Double(0, cellHeight * i, width, cellHeight * i));
            // g2d.drawLine(0, (int) (cellHeight * i), width, (int) (cellHeight * i));

            // vertical lines
            g2d.draw(new Line2D.Double(cellWidth * i, 0, cellWidth * i, height));
            // g2d.drawLine((int) (cellWidth * i), 0, (int) (cellWidth * i), height);
        }

        // Restore original color
        g2d.setColor(originalColor);
    }

}
