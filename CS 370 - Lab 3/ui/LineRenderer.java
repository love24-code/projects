
package ui;

import model.LineData;
import java.awt.Graphics2D;
import java.awt.BasicStroke;
import java.awt.geom.Line2D;
import java.util.List;

public class LineRenderer {
    private static final float LINE_THICKNESS = 10f;

    /**
     * Draws lines by converting grid coordinates to pixels
     */
    public void drawLines(Graphics2D g2d, List<LineData> lines, int width, int height) {
        if (lines == null || lines.isEmpty())
            return;

        g2d.setStroke(new BasicStroke(LINE_THICKNESS));

        for (LineData line : lines) {
            // Convert grid coordinates to pixel positions
            double x = line.getX(width);
            double y1 = line.getY1(height, LINE_THICKNESS);
            double y2 = line.getY2(height, LINE_THICKNESS);

            g2d.setColor(line.getColor());
            g2d.draw(new Line2D.Double(x, y1, x, y2));
        }
    }
}
