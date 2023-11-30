/*
 * Расширить программу (апплет, на котором размещены кнопки для
 * создания экземпляров Rectangle, ColoredRect, DrawableRect и
 * реализована функция по перетаскиванию объектов мышью),
 * созданную на прошлом лабораторном занятии, следующим образом.
 * Добавить на апплет 2 кнопки – LoadFromFile и SaveToFile,
 * одна из которых сериализует созданные объекты прямоугольников
 * и сохраняет их в файл, другая – считывает из файла и
 * продолжает работу программы с того момента, когда была
 * осуществлена сериализация. Если программа была закрыта сразу
 * после сериализации, то при повторном запуске программы и 
 * десериализации объектов, объекты должны располагаться на 
 * том же месте (обладать тем же состоянием), что и до закрытия 
 * программы. Программа должна позволять неограниченное число раз 
 * считывать объекты из файла, не удаляя при этом уже 
 * существующие. (SaveRect/Saverect)
 */

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.List;
import java.util.ArrayList;

import java.io.*;

import models.Rectangle;
import models.DrawableRect;
import models.ColoredRect;

public class Ex2 extends JFrame implements ActionListener {

    JButton rectBtn, coloredRectBtn, drawableRectBtn;
    JButton SaveToFileBtn, LoadFromFileBtn;
    GraphicPanel gp = new GraphicPanel();

    private static final String STATE_FILE_NAME = "state.rect";

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                JFrame.setDefaultLookAndFeelDecorated(true);
                JFrame frame = new Ex2();
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
        if (!(src instanceof JButton clickedBtn))
            return;

        switch (clickedBtn.getText()) {
            case "rectBtn":
                gp.addRect(new Rectangle(0, 0, 50, 50));
                gp.repaint();
                break;
            case "coloredRectBtn":
                var coloredRB = new ColoredRect(0, 0, 50, 50);
                coloredRB.setOutColor(Color.BLUE);
                coloredRB.setInColor(Color.WHITE);
                gp.addRect(coloredRB);
                gp.repaint();
                break;
            case "drawableRectBtn":
                var drawableRB = new DrawableRect(0, 0, 50, 50);
                drawableRB.setOutColor(Color.GREEN);
                gp.addRect(drawableRB);
                gp.repaint();
                break;

            case "SaveToFile":
                SaveToFile((new File(STATE_FILE_NAME)));
                break;

            case "LoadFromFile":
                LoadFromFile((new File(STATE_FILE_NAME)));
                break;
        }
    }

    private void SaveToFile(File file) {
        try (var str = new FileOutputStream(file)) {
            var time = System.currentTimeMillis();
            var objOutStream = new ObjectOutputStream(str);
            objOutStream.writeObject(gp.components);
            objOutStream.close();
            str.close();
            System.out.println("Object serialized in " + (System.currentTimeMillis() - time) + " ms.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void LoadFromFile(File file) {
        try (var str = new FileInputStream(file)) {
            var time = System.currentTimeMillis();
            var objInStream = new ObjectInputStream(str);
            var components = objInStream.readObject();
            objInStream.close();
            str.close();
            gp.components.addAll((List<Rectangle>)components);
            gp.repaint();
            System.out.println("Object deserialized in " + (System.currentTimeMillis() - time) + " ms.");
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public Ex2() {
        super("Ex2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());
        JPanel buttonsPanel = new JPanel();
        JPanel fileBtnsPanel = new JPanel();
        rectBtn = new JButton("rectBtn");
        rectBtn.addActionListener(this);
        drawableRectBtn = new JButton("drawableRectBtn");
        drawableRectBtn.addActionListener(this);
        coloredRectBtn = new JButton("coloredRectBtn");
        coloredRectBtn.addActionListener(this);
        SaveToFileBtn = new JButton("SaveToFile");
        SaveToFileBtn.addActionListener(this);
        LoadFromFileBtn = new JButton("LoadFromFile");
        LoadFromFileBtn.addActionListener(this);
        buttonsPanel.add(rectBtn);
        buttonsPanel.add(drawableRectBtn);
        buttonsPanel.add(coloredRectBtn);
        fileBtnsPanel.add(SaveToFileBtn);
        fileBtnsPanel.add(LoadFromFileBtn);
        mainPanel.add(buttonsPanel, BorderLayout.NORTH);
        mainPanel.add(fileBtnsPanel, BorderLayout.CENTER);
        mainPanel.add(gp, BorderLayout.AFTER_LAST_LINE);
        getContentPane().add(mainPanel);
    }

    public class GraphicPanel extends JPanel {
        private static final int BOX_WIDTH = 600;
        private static final int BOX_HEIGHT = 300;

        private Point lastLocation = null;

        public List<Rectangle> components = new ArrayList<Rectangle>();

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
            g.setColor(Color.getHSBColor(0f, 0f, 0.93f));
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
