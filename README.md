# Custom-Shell
Basic Linux/Unix shell
System:
• It functions as a Basic Linux Shell which implements the following commands:
◦ Internal:
▪ cd (Change the shell working directory.)
• -P (use directory without following symbolic links)
• -L (force symbolic links to be followed)
• --help
▪ echo (display a line of text)
• -n (do not output the trailing newline)
• --help
▪ pwd (print name of current/working directory)
• -P (avoiding symbolic links)
• --help
◦ External:
▪ ls (list directory contents)
• -a (do not ignore entries starting with ‘.’)
▪ cat (concatenate files and print the output)
▪ date (print or set the system date and time)
• -u (print the Coordinated Universal Time (UTC))
▪ rm (remove files or directories)
• -d (remove empty directories)
• -v (explain what is being done)
▪ mkdir (make directory)
• -v (print a message for each created directory)


Errors handled in the program are:

◦ Wrong commands
◦ Directory doesn’t exist/ already exists
◦ File not present
◦ The user would always enter a command and code will detect if it is wrong or right.
◦ And more..





Testcase:
◦ cat -E file1
◦ ls -a
◦ cat file2 file3
◦ls
◦ date
◦ date -u
◦ rm file1 file2
◦ mkdir a
◦ rm -v file3
◦ rm -d a
◦ mkdir -v d
◦ cd
◦ rm -d d
◦ cd --help
◦ echo text
◦ echo -n text
◦ echo --help
◦ pwd
◦ pwd -P
◦ pwd --help
◦ ctrl + c to forcefully terminate the shell
