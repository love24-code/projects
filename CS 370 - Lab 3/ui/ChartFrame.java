
package ui;

import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.BorderLayout;

public class ChartFrame extends JFrame {
    private ChartPanel chartPanel;
    private JButton redrawButton;

    public ChartFrame(int width, int height) {
        super("Random Line Chart");

        setLayout(new BorderLayout());

        chartPanel = new ChartPanel();
        redrawButton = new JButton("Redraw");

        redrawButton.addActionListener(e -> chartPanel.regenerateAndRepaint());

        add(chartPanel, BorderLayout.CENTER);
        add(redrawButton, BorderLayout.SOUTH);

        setSize(width, height);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
