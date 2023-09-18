import java.awt.*;
import java.awt.Dimension;
import java.awt.event.*;
import javax.swing.*;

 
public class TestFrame extends JFrame  implements ActionListener{
 
    JButton button1; 
    public TestFrame() {
          super("Test frame");
          setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
          JPanel mainPanel = new JPanel();
          mainPanel.setLayout(new BorderLayout());
          JPanel buttonsPanel = new JPanel();
          button1 = new JButton("Button 1");
          button1.addActionListener(this);
          buttonsPanel.add(button1);
          mainPanel.add(buttonsPanel, BorderLayout.NORTH);
          mainPanel.add(new GraphicPanel(), BorderLayout.SOUTH);
          getContentPane().add(mainPanel);
    }

    public void actionPerformed (ActionEvent e) {
        if (e.getSource() == button1) {
            JOptionPane.showMessageDialog(this, new String("\"Button 1\" pressed"));
        }
       
    }
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                JFrame.setDefaultLookAndFeelDecorated( true );
                JFrame frame = new TestFrame();
                frame.setPreferredSize(new Dimension(300, 300));
                frame.pack();
                frame.setLocationRelativeTo(null);
                frame.setVisible(true);
            }
        });
    }

    public class GraphicPanel extends JPanel  {
        private static final int BOX_WIDTH = 200;
        private static final int BOX_HEIGHT = 200;

        private Point Center = new Point(120,120);
        private Point lastLocation = null;
        private int R = 20;

        private boolean CercleContains(Point p){
            float dist = (Center.x-p.x)*(Center.x-p.x) + (Center.y-p.y)*(Center.y-p.y);
            float R2 = (float)R*R;
            if (dist<=R2)
                return true;
            else
                return false;
        };

        // Настройка и инициализация объектов
        public GraphicPanel() {
            this.setPreferredSize(new Dimension(BOX_WIDTH, BOX_HEIGHT));
            Center.x=120;
            Center.y=100;
            addMouseListener(mouseListener);
            addMouseMotionListener(mouseListener);     
        }
        // прорисовка компонентов на панели рисования
        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);// Paint backgr-d
            g.setColor(Color.GRAY);
            g.fillRect(0, 0, getBounds().width, getBounds().width);
            // Draw the box oval
            g.setColor(Color.BLACK);
            g.fillOval((int) (Center.x - R), (int) (Center.y - R), 
(int)(2 *R), (int)(2 * R));    
        }
       
        private MouseAdapter mouseListener = new MouseAdapter() {  
            public void mousePressed(java.awt.event.MouseEvent e) {
                Point p=e.getPoint();
                if(CercleContains(p)){
                    lastLocation = p;
                }
            }
            @Override
            public void mouseDragged(java.awt.event.MouseEvent e) {
                int NewX, NewY;
                if (lastLocation != null) {
                    int mX, mY;
                    mX = (int) (e.getX() - lastLocation.x);
                    mY = (int) (e.getY() - lastLocation.y);
                    NewX=Center.x+mX;
                    NewY=Center.y+mY;
                    if ((NewX - R < 0) || (NewX + R > getBounds().width) || (NewY - R < 0) || (NewY + R > getBounds().height))
                        return;
                    Center.x=NewX;
                    Center.y=NewY;
                    lastLocation.x += mX;
                    lastLocation.y += mY;
                    repaint();
                }
            }
            @Override
            public void mouseReleased( java.awt.event.MouseEvent e) {
                lastLocation = null;
            }
        };
    }
}
