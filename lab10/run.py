#!/usr/bin/python
import dirwatch, os, sys

global command

if __name__ == '__main__':
    
    command = ""
  
    def f (changed_files, removed_files):
      print changed_files
      print 'Removed', removed_files

  
    def runCmd (changed_files, removed_files):
      print "*"	
      for fName in changed_files:
	os.system(command + " " + fName)
      for remFile in removed_files:
	print remFile + " removed."

    
    if (len(sys.argv) < 2):
      print "Correct syntax: run.py <Path> <Command>"
      sys.exit(1)
    else:
      dirs = [sys.argv[1]]
      print("Watching directory: "+dirs[0])
      commandArr = sys.argv[2:]
      for cmdArr in commandArr:
	command = command + " " + cmdArr
      command = command[1:]
      
      print "Command: " + command
      
    dirwatch.Dirwatch(dirs, runCmd, 1).watch()
    sys.exit(0)
    #dirwatch.Dirwatch(dirs, f, 1).watch()