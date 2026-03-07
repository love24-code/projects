
package model;

import java.awt.Image;
import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class DeckData {
    private List<JLabel> deckJLabels;
    
    public DeckData() {
        deckJLabels = new ArrayList<JLabel>();

        File cardFolder = new File("./Google-PNG-cards-1.3");
        File[] cardFiles = cardFolder.listFiles();


        for (File cardFile : cardFiles) {
            ImageIcon icon = new ImageIcon(cardFile.getPath());
            Image image = icon.getImage();
            // -1 maintains aspect ratio of image
            icon = new ImageIcon(image.getScaledInstance(60, -1, Image.SCALE_SMOOTH));
            // add the complete label object, ready to be added
            deckJLabels.add(new JLabel(icon));
        }
    }

    public List<JLabel> getDeck() {
        return deckJLabels;
    }

    public void shuffleDeck() {
        Collections.shuffle(deckJLabels);
    }
}
