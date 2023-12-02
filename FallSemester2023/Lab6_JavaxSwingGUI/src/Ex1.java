
/* 
 * 1. Создайте Frame c компонентом меню Файл -> Создать. При 
 * нажатии на элемент меню «Создать» создается новое окно, на котором 
 * размещен компонент JRadioButton и кнопка JButton. Компонент 
 * JRadioButton состоит из 2 элементов – «отображать таблицу 
 * умножения» и «отображать таблицу сложения». При выборе 
 * конкретного пункта (умножения или сложения) и нажатии кнопки 
 * JButton окно закрывается, а на основном фрейме появляется таблица 
 * умножения или сложения соответственно.
 * 2. Окно, которое появляется при нажатии на «Файл -> Создать» 
 * можно создать по своему усмотрению одним из следующих двух 
 * способов:
 * с помощью классов JDesktopFrame и JInternalFrame (за основу 
 * можно взять файл Examples/internalframedemo.java).
 * c помощью классов Frame. 
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyVetoException;

public class Ex1 {
    public static void main(String[] args) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                var frame = new MainFrame();
                var menuBar = new JMenuBar();
                var menu = new JMenu("Файл");
                var menuItem = new JMenuItem("Создать");
                ActionListener menuListener = new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        frame.addModal();
                    }
                };
                menuItem.addActionListener(menuListener);
                menu.add(menuItem);
                menuBar.add(menu);

                frame.setJMenuBar(menuBar);
                frame.setVisible(true);
            }
        });

    }
}

class MainFrame extends JFrame implements ResultListener {
    JDesktopPane desktopPane = new JDesktopPane();
    Modal modal;

    public MainFrame() {
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(desktopPane);
    }

    public void addModal() {
        setContentPane(desktopPane);
        if (modal != null) {
            desktopPane.remove(modal);
        }
        modal = new Modal(this);
        desktopPane.add(modal);
        try {
            modal.setSelected(true);
        } catch (PropertyVetoException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onResult(Boolean result) {
        String[] columnNames = { "", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
        String[][] data = new String[10][11];
        for (int i = 0; i < 10; i++) {
            data[i][0] = String.valueOf(i + 1);
            for (int j = 1; j <= 10; j++) {
                if (result) {
                    data[i][j] = String.valueOf((i + 1) * j);

                } else {
                    data[i][j] = String.valueOf((i + 1) + j);
                }
            }
        }
        JTable table = new JTable(data, columnNames);
        JScrollPane scrollPane = new JScrollPane(table);

        JPanel desktopPane = new JPanel(new BorderLayout());
        desktopPane.add(scrollPane, BorderLayout.SOUTH);
        setContentPane(desktopPane);

        revalidate();
        repaint();
    }
}

class Menu extends JMenuBar {

    public Menu() {
        var meh = new JMenu("Файл");
        this.add(meh);
    }

}

interface ResultListener {
    void onResult(Boolean result);
}

class Modal extends JInternalFrame {
    ResultListener listener;

    public Modal(ResultListener listener) {
        setBounds(getVisibleRect());

        setLayout(new GridBagLayout());

        GridBagConstraints constraints = new GridBagConstraints();

        var mul = new JRadioButton("Построить таблицу умножения", true);
        add(mul, constraints);

        var add = new JRadioButton("Построить таблицу сложения", !true);
        add(add, constraints);

        var group = new ButtonGroup();
        group.add(mul);
        group.add(add);

        constraints.weighty = 0;
        constraints.gridx = 0;
        constraints.gridy = 1;
        constraints.gridwidth = 2;

        var btn = new JButton("Ok");
        add(btn, constraints);

        pack();
        setVisible(true);

        this.listener = listener;
        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                listener.onResult(mul.isSelected());
                // Modal.this.setVisible(false);
                try {
                    Modal.this.setClosed(true);
                } catch (PropertyVetoException ex) {
                    ex.printStackTrace();
                }
            }
        });

    }
}