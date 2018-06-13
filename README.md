# GarageDoor
Lightweight garagedoor manager with PiFace , Mifare reader, MQTT 

The garagedoor manager is a standalone function running on a  Raspberry Pi.
With the following functions
- Controlling the open-stop-close button with a relay
- monitoring the + and - lines of the DC motor driving the garagedoor to determine the current state
- scanning mifare tags on serialnumber (migration to EV1 or EV2 is needed)
- MQTT connection to connect with openhab2 or whatever system that supports MQTT actions and event (in-outbound)
- Motion(usb to webstream is running seperately on the PI to provide video but doesn't work that well.

ToDo:
- Upgrade to EV2
- manipulation of valid tag list thru MQTT
- nice to have picture on transaction over MQTT
- MQTT get last events list on request
