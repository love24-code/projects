
package test;

import ui.GridRenderer;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class GridRendererTest {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Grid Renderer Test");

            JPanel testPanel = new JPanel() {
                @Override
                protected void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    setBackground(Color.LIGHT_GRAY);

                    Graphics2D g2d = (Graphics2D) g;
                    GridRenderer gridRenderer = new GridRenderer();
                    gridRenderer.drawGrid(g2d, getWidth(), getHeight());

                    g2d.setColor(Color.RED);
                    g2d.drawString("Grid Renderer Test - 10x10 grid", 10, 20);
                }
            };

            frame.add(testPanel);
            frame.setSize(400, 400);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}
