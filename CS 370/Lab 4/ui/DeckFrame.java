
package ui;

import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class DeckFrame extends JFrame {
    private DeckPanel deckPanel;
    private JButton shuffleButton;

    public DeckFrame(int width, int height) {
        super("Random Line Chart");

        setLayout(new BorderLayout());

        deckPanel = new DeckPanel();
        shuffleButton = new JButton("Shuffle");

        shuffleButton.addActionListener(e -> deckPanel.shuffleAndRedrawDeck());

        add(deckPanel, BorderLayout.CENTER);
        add(shuffleButton, BorderLayout.SOUTH);

        setSize(width, height);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
