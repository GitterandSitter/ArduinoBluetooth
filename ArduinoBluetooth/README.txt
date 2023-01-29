Original Android Code from: https://github.com/bauerjj/Android-Simple-Bluetooth-Example
Credits to Justin (https://github.com/bauerjj)

Changelog:	

29/02/2013: Added EditText widget and send Button. EditText content is read as a String. The Handler object looping in the main activity, reads the Message content
	    if containing the correct Message Status. This is sent to the ConnectedThread along with the BluetoothSocket to the respective device.
	    
	    Simple Arduino code reading SoftwareSerial input, displaying over Serial. Version using byte array to String conversion included but deactivated.