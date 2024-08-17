import serial
from time import sleep

# connect to arduino
ser = serial.Serial('/dev/ttyACM0', 9600)
msg = "0,0;1,0;2,0;3,0;4,0;5,0"
# msg = "0,90;1,90;2,90;3,90;4,90;5,90"

while msg != "q":
    # send message
    ser.write(msg.encode())
    sleep(5)

    # check for response message
    while ser.in_waiting > 0:
        response = ser.readline()
        print(response)
    msg = input("Enter message (ind1,val1;ind2,val2;...): ")

# close connection
ser.close()
print("Connection closed")
