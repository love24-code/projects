
import javax.swing.SwingUtilities;
import ui.ChartFrame;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ChartFrame frame = new ChartFrame(400, 424);
            frame.setVisible(true);
        });
    }
}
