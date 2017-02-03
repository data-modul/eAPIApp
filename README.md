EApiValidateAPI provides a simple commnad-line application to use EAPI library.

Based on the command line parameter, it will provide specific information related
only to that parameter. This information is retrieved from EApi library.

Parameters are matched to the following features:

* Board information
* Read/Write i2c
* Get/Set GPIO pins
* Watchdog
* Get/Set backlight
* Read/Write defined user space at Eeprom

The EApiValidate will be built by make command. 
The EApi library should be installed in **/usr/local**. In case of another installation
path, use the environment variable **PREFIX**.

 ~~~bash
$ export PREFIX=/usr/local
$ make
~~~

The execution file is located in  **make/bin/Linux/x86_64/rel**.


