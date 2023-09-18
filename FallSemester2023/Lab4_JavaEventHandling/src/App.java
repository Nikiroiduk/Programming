/*
 * Изучить предлагаемый теоретический материал; создать апплет,
 * содержащий три кнопки, по нажатию на которые создаются
 * экземпляры классов Rect, ColoredRect, DrawableRect
 * (реализованные в лабораторной работе №2). Созданные
 * экземпляры помещаются в один массив с типом класса родителя
 * Rect. Реализовать метод захвата мышкой и перемещения по
 * графической области приложения любого прямоугольника,
 * отображенного в окне. 
 */

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import models.Rectangle;
import models.DrawableRect;
import models.ColoredRect;

public class App extends JFrame implements ActionListener {

    JButton rectBtn, coloredRectBtn, drawableRectBtn;
    GraphicPanel gp = new GraphicPanel();

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                JFrame.setDefaultLookAndFeelDecorated(true);
                JFrame frame = new App();
                frame.setPreferredSize(new Dimension(600, 400));
                frame.pack();
                frame.setLocationRelativeTo(null);
                frame.setVisible(true);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        var src = e.getSource();

        if (src == rectBtn) {
            gp.addRect(new Rectangle(0, 0, 50, 50));
            gp.repaint();
        }

        if (src == coloredRectBtn) {
            var tmp = new ColoredRect(0, 0, 50, 50);
            tmp.setInColor(Color.WHITE);
            gp.addRect(tmp);
            gp.repaint();
        }

        if (src == drawableRectBtn) {
            var tmp = new DrawableRect(0, 0, 50, 50);
            tmp.setOutColor(Color.BLUE);
            gp.addRect(tmp);
            gp.repaint();
        }
    }

    public App() {
        super("App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        JPanel buttonsPanel = new JPanel();
        rectBtn = new JButton("rectBtn");
        rectBtn.addActionListener(this);
        drawableRectBtn = new JButton("drawableRectBtn");
        drawableRectBtn.addActionListener(this);
        coloredRectBtn = new JButton("coloredRectBtn");
        coloredRectBtn.addActionListener(this);
        buttonsPanel.add(rectBtn);
        buttonsPanel.add(drawableRectBtn);
        buttonsPanel.add(coloredRectBtn);
        mainPanel.add(buttonsPanel, BorderLayout.NORTH);
        mainPanel.add(gp, BorderLayout.AFTER_LAST_LINE);
        getContentPane().add(mainPanel);
    }

    public class GraphicPanel extends JPanel {
        private static final int BOX_WIDTH = 600;
        private static final int BOX_HEIGHT = 300;

        private Point lastLocation = null;

        private java.util.List<Rectangle> components = new java.util.ArrayList<Rectangle>();

        public void addRect(Rectangle rect) {
            components.add(rect);
        }

        private boolean RectangleContains(Point p, models.Rectangle rect) {
            return p.x >= rect.getX1() &&
                    p.x <= rect.getX2() &&
                    p.y >= rect.getY1() &&
                    p.y <= rect.getY2();
        }

        public GraphicPanel() {
            this.setPreferredSize(new Dimension(BOX_WIDTH, BOX_HEIGHT));
            addMouseListener(mouseListener);
            addMouseMotionListener(mouseListener);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.GRAY);
            g.fillRect(0, 0, getBounds().width, getBounds().width);

            for (models.Rectangle rectangle : components) {
                if (rectangle instanceof ColoredRect a) {
                    a.draw(g);
                } else if (rectangle instanceof DrawableRect a) {
                    a.draw(g);
                } else {
                    g.setColor(Color.RED);
                    g.drawRect(rectangle.getX1(), rectangle.getY1(), rectangle.getWidth(), rectangle.getHeight());
                }
            }

        }

        private MouseAdapter mouseListener = new MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent e) {
                Point p = e.getPoint();
                for (models.Rectangle rectangle : components) {
                    rectangle.isSelected = RectangleContains(p, rectangle);
                    lastLocation = p;
                }

            }

            @Override
            public void mouseDragged(java.awt.event.MouseEvent e) {
                for (models.Rectangle rectangle : components) {
                    if (rectangle.isSelected) {
                        int mx, my;
                        mx = (int) (e.getX() - lastLocation.x);
                        my = (int) (e.getY() - lastLocation.y);
                        if (rectangle.getX2() + mx > BOX_WIDTH || rectangle.getY2() + my > BOX_HEIGHT)
                            return;
                        rectangle.move(mx, my);
                        lastLocation.x += mx;
                        lastLocation.y += my;
                        repaint();
                    }
                }
            }

            @Override
            public void mouseReleased(java.awt.event.MouseEvent e) {
                lastLocation = null;
            }
        };
    }
}
