package model;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DrawingPanel extends JPanel {

    private final List<Line2D.Double> lines = new ArrayList<>();
    private final List<Color> colors = new ArrayList<>();
    private static final int NUM_LINES = 10;

    public DrawingPanel() {
        generateRandomLines();
    }

    public void generateRandomLines() {
        lines.clear();
        colors.clear();
        Random rand = new Random();

        for (int i = 0; i < NUM_LINES; i++) {
            double x1 = rand.nextInt(400);
            double y1 = rand.nextInt(400);
            double x2 = rand.nextInt(400);
            double y2 = rand.nextInt(400);

            lines.add(new Line2D.Double(x1, y1, x2, y2));
            colors.add(new Color(
                    rand.nextInt(256),
                    rand.nextInt(256),
                    rand.nextInt(256)
            ));
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;

        // draw 10x10 grid
        int w = getWidth();
        int h = getHeight();
        for (int i = 0; i <= 10; i++) {
            g2.setColor(Color.LIGHT_GRAY);
            g2.drawLine(i * w / 10, 0, i * w / 10, h);
            g2.drawLine(0, i * h / 10, w, i * h / 10);
        }

        g2.setStroke(new BasicStroke(10f));

        for (int i = 0; i < lines.size(); i++) {
            g2.setColor(colors.get(i));
            g2.draw(lines.get(i));
        }
    }
}
