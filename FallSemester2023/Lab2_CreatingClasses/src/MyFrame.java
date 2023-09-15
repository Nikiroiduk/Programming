import java.awt.*;
import java.awt.event.*;

import models.ColoredRect;
import models.DrawableRect;

public class MyFrame extends Frame {
    public MyFrame() {
        setVisible(true);
        setSize(300, 200);
        setBackground(Color.black);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void paint(Graphics g) {
        DrawableRect dr = new DrawableRect();
        dr.setX1(10);
        dr.setY1(75);
        dr.setX2(60);
        dr.setY2(150);
        dr.draw(g);

        ColoredRect cr = new ColoredRect();
        cr.setX1(80);
        cr.setY1(75);
        cr.setX2(130);
        cr.setY2(150);
        cr.draw(g);
    }

    public static void main(String[] args) {
        new MyFrame();
    }
}