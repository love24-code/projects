
package ui;

import generator.LineGenerator;
import model.LineData;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.List;

public class ChartPanel extends JPanel {
    private GridRenderer gridRenderer;
    private LineRenderer lineRenderer;
    private LineGenerator lineGenerator;

    private List<LineData> lines;

    public ChartPanel() {
        setBackground(Color.LIGHT_GRAY);

        gridRenderer = new GridRenderer();
        lineRenderer = new LineRenderer();
        lineGenerator = new LineGenerator();

        regenerateLines();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        gridRenderer.drawGrid(g2d, getWidth(), getHeight());
        lineRenderer.drawLines(g2d, lines, getWidth(), getHeight());
    }

    public void regenerateAndRepaint() {
        regenerateLines();
        repaint();
    }

    private void regenerateLines() {
        lines = lineGenerator.generateLines();
    }
}
