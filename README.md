Setup
=====
Hardware
--------
Set voltage to ~7.5v to enable all of the motors to run at once.

Software
--------
must set up udev rules to allow connection to the oak-d lite
```bash
echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="03e7", MODE="0666"' | sudo tee /etc/udev/rules.d/80-movidius.rules
sudo udevadm control --reload-rules && sudo udevadm trigger
```
must unplug and replog the oak-d lite after running the above commands

## Install

Install the python packages (depthai, opencv) with the following command:

```
python3 -m pip install -r requirements.txt
```