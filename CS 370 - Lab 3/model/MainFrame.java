package model;
import javax.swing.*;
import java.awt.*;

public class MainFrame extends JFrame {

    public MainFrame() {
        setTitle("Random Lines");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        DrawingPanel drawingPanel = new DrawingPanel();
        JButton redrawButton = new JButton("Redraw");

        redrawButton.addActionListener(e -> {
            drawingPanel.generateRandomLines(); // update data
            drawingPanel.repaint();              // redraw
        });

        add(drawingPanel, BorderLayout.CENTER);
        add(redrawButton, BorderLayout.SOUTH);

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(MainFrame::new);
    }
}