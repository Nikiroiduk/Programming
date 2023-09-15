package models;

import java.awt.*;

public class DrawableRect extends Rectangle {

    Color outColor = Color.red;

    public void draw(Graphics g) {
        g.setColor(outColor);
        g.drawRect(getX1(), getY1(), getWidth(), getHeight());
    }
}