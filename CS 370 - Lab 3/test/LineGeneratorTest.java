
package test;

import generator.LineGenerator;
import model.LineData;
import java.util.List;

public class LineGeneratorTest {
    public static void main(String[] args) {
        LineGenerator generator = new LineGenerator();

        System.out.println("Line Generator Test\n");

        List<LineData> lines = generator.generateLines();

        System.out.println("Generated " + lines.size() + " lines:");
        for (int i = 0; i < lines.size(); i++) {
            LineData line = lines.get(i);
            System.out.printf("Line %2d: column=%.2f, height=%d cells, color=rgb(%d,%d,%d)%n",
                    i + 1,
                    line.getColumnIndex(),
                    line.getHeightInCells(),
                    line.getColor().getRed(),
                    line.getColor().getGreen(),
                    line.getColor().getBlue());
        }
        System.out.println("\nTest complete");
    }
}
