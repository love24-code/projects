import javax.swing.SwingUtilities;
import ui.DeckFrame;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            DeckFrame frame = new DeckFrame(1000, 624);
            frame.setVisible(true);
        });
    }
}
