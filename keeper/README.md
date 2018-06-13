simonsvossdecoder

# Description
SimonsVoss Decoder is a commandline application that is able to display and decode the simons offline data on a desfire card.  
The application works with PCSC supported readers

# Install
sudo apt-get install libnfc* libfreefare* pscsd cmake

# build
cmake . && make clean all -j8

#run 
./SVdecode

options: 
-d 		dump raw data
-f [filename]	data to file [filename]_ID.bin + [filename]_Accessfiles.bin [filename]_backup.bin
