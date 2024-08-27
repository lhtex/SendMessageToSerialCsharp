using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Project1_Teste
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void comboBox_serial_DropDown(object sender, EventArgs e)
        {
            string[] portlists = SerialPort.GetPortNames();
            comboBox_serial.Items.Clear();
            comboBox_serial.Items.AddRange(portlists);
        }

        private void button_connect_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = comboBox_serial.Text;
                serialPort1.BaudRate = 57600;
                serialPort1.Open();

                MessageBox.Show("Success Connected to Arduino Board" + "\n" +
                    "This App Created by LHT" + "\n");
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                serialPort1.Close();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string txtMessage = "";

            if (serialPort1.IsOpen)
            {
                serialPort1.Write(txtMessage + "\n");
            }
        }

        private void button_message_Click(object sender, EventArgs e)
        {
            serialPort1.Write(textBox_message.Text + "\n");
        }
    }
}
