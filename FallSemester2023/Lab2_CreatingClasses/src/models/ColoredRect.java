package models;

import java.awt.*;

public class ColoredRect extends DrawableRect {
    Color inColor = Color.gray;

    public void draw(Graphics g) {
        g.setColor(outColor);
        g.drawRect(getX1(), getY1(), getWidth(), getHeight());
        g.setColor(inColor);
        g.fillRect(getX1() + 1, getY1() + 1, getWidth() - 1, getHeight() - 1);

    }
}
