
package test;

import ui.LineRenderer;
import model.LineData;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.ArrayList;
import java.util.List;

public class LineRendererTest {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Line Renderer Test");

            List<LineData> testLines = createTestLines();

            JPanel testPanel = new JPanel() {
                @Override
                protected void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    setBackground(Color.LIGHT_GRAY);

                    Graphics2D g2d = (Graphics2D) g;
                    LineRenderer lineRenderer = new LineRenderer();
                    lineRenderer.drawLines(g2d, testLines, getWidth(), getHeight());

                    g2d.setColor(Color.BLACK);
                    g2d.drawString("Line Renderer Test - Resize to see scaling!", 10, 20);
                }
            };

            frame.add(testPanel);
            frame.setSize(400, 400);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }

    private static List<LineData> createTestLines() {
        List<LineData> lines = new ArrayList<>();
        lines.add(new LineData(1.0, 2, Color.RED));
        lines.add(new LineData(2.5, 4, Color.GREEN));
        lines.add(new LineData(4.0, 6, Color.BLUE));
        lines.add(new LineData(5.5, 3, Color.YELLOW));
        lines.add(new LineData(7.0, 5, Color.MAGENTA));
        return lines;
    }
}
