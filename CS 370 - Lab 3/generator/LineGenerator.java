
package generator;

import model.LineData;
import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class LineGenerator {
    private static final int NUMBER_OF_LINES = 12;
    private static final int MAX_GRID_CELLS = 9;
    private Random random;

    public LineGenerator() {
        random = new Random();
    }

    /**
     * Generates lines in grid coordinates
     */
    public List<LineData> generateLines() {
        List<LineData> lines = new ArrayList<>();

        for (int i = 0; i < NUMBER_OF_LINES; i++) {
            // Position line in center of a grid column
            double columnIndex = 1 + (i * 8.0 / (NUMBER_OF_LINES - 1));

            // Random height in GRID CELLS
            int heightInCells = 1 + random.nextInt(MAX_GRID_CELLS);

            // Random color
            int r = random.nextInt(256);
            int g = random.nextInt(256);
            int b = random.nextInt(256);
            Color color = new Color(r, g, b);

            lines.add(new LineData(columnIndex, heightInCells, color));
        }

        return lines;
    }
}
