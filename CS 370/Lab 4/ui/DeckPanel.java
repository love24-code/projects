package ui;

import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;
import model.DeckData;

public class DeckPanel extends JPanel {
    private DeckData deck;

    public DeckPanel() {
        setBackground(new Color(0, 81, 44));

        setLayout(new GridLayout(0, 13));

        deck = new DeckData();

        // initial cards shown to user
        drawDeck();
    }

    private void shuffleCards() {
        deck.shuffleDeck();
    }

    private void drawDeck() {
        for (JLabel card : deck.getDeck()) {
            add(card);
        }
    }

    private void removeDeck() {
        for (JLabel card : deck.getDeck()) {
            remove(card);
        }
    }

    public void shuffleAndRedrawDeck() {
        removeDeck();
        shuffleCards();
        drawDeck();

        // refresh the panel to display the changes
        repaint();
        revalidate();
    }
}
