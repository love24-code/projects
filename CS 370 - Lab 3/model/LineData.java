
package model;

import java.awt.Color;

/**
 * Stores line data in grid coordinates
 */
public class LineData {
    private final double columnIndex;
    private final int heightInCells;
    private final Color color;

    public LineData(double columnIndex, int heightInCells, Color color) {
        this.columnIndex = columnIndex;
        this.heightInCells = heightInCells;
        this.color = color;
    }

    public double getColumnIndex() {
        return columnIndex;
    }

    public int getHeightInCells() {
        return heightInCells;
    }

    public Color getColor() {
        return color;
    }

    /**
     * Convert grid coordinates to pixel positions for rendering
     */
    public double getX(int panelWidth) {
        double cellWidth = (double) panelWidth / 10.0;
        return columnIndex * cellWidth;
    }

    public double getY1(int panelHeight, float lineThickness) {
        return panelHeight - lineThickness / 2;
    }

    public double getY2(int panelHeight, float lineThickness) {
        double cellHeight = (double) panelHeight / 10.0;
        double lineHeight = heightInCells * cellHeight;
        return getY1(panelHeight, lineThickness) - lineHeight;
    }
}
