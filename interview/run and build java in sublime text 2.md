#Compile and run java in Sublime Text 2 (for Ubuntu)

###Step1. echo $PATH and find the JDK bin directory(example: /usr/local/java/jdk1.7.0_51/bin)

###Step2. create a file named runJava.sh into bin, then chmod 755 runJava.sh 
	(runJava.sh)
	#!/bin/sh
	[ -f "$1.class" ] && rm $1.class
	for file in $1.java
	do
	echo "Compiling $file.........."
	javac $file
	done
	if [ -f "$1.class" ]
	then 
	echo "-------------OUTPUT--------------"
	java $1
	else
	echo " "
	fi

###Step3. open the Sublime Text 2, open tools -- build system -- New Build System, open it find Preference -- Browse Packages, in Java folder copy the JavaC.sublime-build content to your new build system file. 
	change the
	"cmd": ["javac", "$file"],
	into
	"cmd": ["runJava.sh", "$file_base_name"],
	