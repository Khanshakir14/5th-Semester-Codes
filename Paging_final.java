import javax.swing.*;
import java.awt.*;

public class Paging_final extends JFrame {

    private JPanel panel;
    private JPanel panel1;
    private JPanel panel2;
    private JPanel panel3;
    private JPanel panel4;
    private JPanel panel5;
    private JLabel label;
    private JLabel label1;
    private JLabel label2;
    private JLabel label3;
    // private JFrame f;
    private JTextField textField1;
    private JTextField textField2;
    private JTextField textField3;
    //private JTextField result;
    private JButton button1;
    private JButton button2;
    private JTable jt;
    private String data[][] = { { "0", "5" }, { "1", "6" }, { "2", "1" }, { "3", "2" } };
    private String column[] = { "Page", "Frame" };

    public Paging_final() {
        panel = new JPanel();
        panel1 = new JPanel();
        panel2 = new JPanel();
        panel3 = new JPanel();
        panel4 = new JPanel();
        panel5 = new JPanel();
        label = new JLabel("Page size");
        label1 = new JLabel("Logical Address");
        label2 = new JLabel("Displacement");
        label3 = new JLabel("Page table");
        textField1 = new JTextField(10);
        textField2 = new JTextField(10);
        textField3 = new JTextField(10);
        //result = new JTextField(10);
        jt = new JTable(data, column);
        jt.setBounds(30, 40, 200, 300);
        button1 = new JButton("Calculate");
        button2 = new JButton("Clear");
        setTitle("Paging");
        setSize(400, 260);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        panel1.add(label3);
        panel1.add(jt);
        panel2.add(label);
        panel2.add(textField1);
        panel3.add(label1);
        panel3.add(textField2);
        panel4.add(label2);
        panel4.add(textField3);
        panel5.add(button1);
        panel5.add(button2);
        //panel5.add(result);
        button1.addActionListener(e -> {
            int ps =Integer.parseInt(textField1.getText());
            int val = Integer.parseInt(textField2.getText());
            int d = Integer.parseInt(textField3.getText());
            int p = val/ps;
            int fno = Integer.parseInt(data[p][1]);
            int f = ps * fno + d;
            //result.setText(Integer.toString(f));
            JOptionPane.showMessageDialog(null, "The physical address is: " + f);
        });
        button2.addActionListener(e -> {
            textField1.setText("");
            textField2.setText("");
            textField3.setText("");
        });
        panel.add(panel1);
        panel.add(panel2);
        panel.add(panel3);
        panel.add(panel4);
        panel.add(panel5);
        add(panel);
    }

    public static void main(String[] args) {
        Paging_final paging = new Paging_final();
        paging.setVisible(true);
    }
}